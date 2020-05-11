<?php

namespace Drupal\os2web_spotbox\Controller;

use Drupal\Component\Utility\Xss;
use Drupal\Core\Controller\ControllerBase;
use Drupal\Core\DependencyInjection\ContainerInjectionInterface;
use Drupal\Core\Url;
use Drupal\Core\Link;
use Drupal\os2web_spotbox\Entity\SpotboxInterface;
use Symfony\Component\DependencyInjection\ContainerInterface;

/**
 * Class SpotboxController.
 *
 *  Returns responses for OS2Web Spotbox routes.
 */
class SpotboxController extends ControllerBase implements ContainerInjectionInterface {

  /**
   * The date formatter.
   *
   * @var \Drupal\Core\Datetime\DateFormatter
   */
  protected $dateFormatter;

  /**
   * The renderer.
   *
   * @var \Drupal\Core\Render\Renderer
   */
  protected $renderer;

  /**
   * {@inheritdoc}
   */
  public static function create(ContainerInterface $container) {
    $instance = parent::create($container);
    $instance->dateFormatter = $container->get('date.formatter');
    $instance->renderer = $container->get('renderer');
    return $instance;
  }

  /**
   * Displays a OS2Web Spotbox revision.
   *
   * @param int $os2web_spotbox_revision
   *   The OS2Web Spotbox revision ID.
   *
   * @return array
   *   An array suitable for drupal_render().
   */
  public function revisionShow($os2web_spotbox_revision) {
    $os2web_spotbox = $this->entityTypeManager()->getStorage('os2web_spotbox')
      ->loadRevision($os2web_spotbox_revision);
    $view_builder = $this->entityTypeManager()->getViewBuilder('os2web_spotbox');

    return $view_builder->view($os2web_spotbox);
  }

  /**
   * Page title callback for a OS2Web Spotbox revision.
   *
   * @param int $os2web_spotbox_revision
   *   The OS2Web Spotbox revision ID.
   *
   * @return string
   *   The page title.
   */
  public function revisionPageTitle($os2web_spotbox_revision) {
    $os2web_spotbox = $this->entityTypeManager()->getStorage('os2web_spotbox')
      ->loadRevision($os2web_spotbox_revision);
    return $this->t('Revision of %title from %date', [
      '%title' => $os2web_spotbox->label(),
      '%date' => $this->dateFormatter->format($os2web_spotbox->getRevisionCreationTime()),
    ]);
  }

  /**
   * Generates an overview table of older revisions of a OS2Web Spotbox.
   *
   * @param \Drupal\os2web_spotbox\Entity\SpotboxInterface $os2web_spotbox
   *   A OS2Web Spotbox object.
   *
   * @return array
   *   An array as expected by drupal_render().
   */
  public function revisionOverview(SpotboxInterface $os2web_spotbox) {
    $account = $this->currentUser();
    $os2web_spotbox_storage = $this->entityTypeManager()->getStorage('os2web_spotbox');

    $langcode = $os2web_spotbox->language()->getId();
    $langname = $os2web_spotbox->language()->getName();
    $languages = $os2web_spotbox->getTranslationLanguages();
    $has_translations = (count($languages) > 1);
    $build['#title'] = $has_translations ? $this->t('@langname revisions for %title', ['@langname' => $langname, '%title' => $os2web_spotbox->label()]) : $this->t('Revisions for %title', ['%title' => $os2web_spotbox->label()]);

    $header = [$this->t('Revision'), $this->t('Operations')];
    $revert_permission = (($account->hasPermission("revert all os2web spotbox revisions") || $account->hasPermission('administer os2web spotbox entities')));
    $delete_permission = (($account->hasPermission("delete all os2web spotbox revisions") || $account->hasPermission('administer os2web spotbox entities')));

    $rows = [];

    $vids = $os2web_spotbox_storage->revisionIds($os2web_spotbox);

    $latest_revision = TRUE;

    foreach (array_reverse($vids) as $vid) {
      /** @var \Drupal\os2web_spotbox\SpotboxInterface $revision */
      $revision = $os2web_spotbox_storage->loadRevision($vid);
      // Only show revisions that are affected by the language that is being
      // displayed.
      if ($revision->hasTranslation($langcode) && $revision->getTranslation($langcode)->isRevisionTranslationAffected()) {
        $username = [
          '#theme' => 'username',
          '#account' => $revision->getRevisionUser(),
        ];

        // Use revision link to link to revisions that are not active.
        $date = $this->dateFormatter->format($revision->getRevisionCreationTime(), 'short');
        if ($vid != $os2web_spotbox->getRevisionId()) {
          $link = Link::fromTextAndUrl($date, new Url('entity.os2web_spotbox.revision', [
            'os2web_spotbox' => $os2web_spotbox->id(),
            'os2web_spotbox_revision' => $vid,
          ]));
        }
        else {
          $link = $os2web_spotbox->toLink($date)->toString();
        }

        $row = [];
        $column = [
          'data' => [
            '#type' => 'inline_template',
            '#template' => '{% trans %}{{ date }} by {{ username }}{% endtrans %}{% if message %}<p class="revision-log">{{ message }}</p>{% endif %}',
            '#context' => [
              'date' => $link,
              'username' => $this->renderer->renderPlain($username),
              'message' => [
                '#markup' => $revision->getRevisionLogMessage(),
                '#allowed_tags' => Xss::getHtmlTagList(),
              ],
            ],
          ],
        ];
        $row[] = $column;

        if ($latest_revision) {
          $row[] = [
            'data' => [
              '#prefix' => '<em>',
              '#markup' => $this->t('Current revision'),
              '#suffix' => '</em>',
            ],
          ];
          foreach ($row as &$current) {
            $current['class'] = ['revision-current'];
          }
          $latest_revision = FALSE;
        }
        else {
          $links = [];
          if ($revert_permission) {
            $links['revert'] = [
              'title' => $this->t('Revert'),
              'url' => $has_translations ?
              Url::fromRoute('entity.os2web_spotbox.translation_revert', [
                'os2web_spotbox' => $os2web_spotbox->id(),
                'os2web_spotbox_revision' => $vid,
                'langcode' => $langcode,
              ]) :
              Url::fromRoute('entity.os2web_spotbox.revision_revert', [
                'os2web_spotbox' => $os2web_spotbox->id(),
                'os2web_spotbox_revision' => $vid,
              ]),
            ];
          }

          if ($delete_permission) {
            $links['delete'] = [
              'title' => $this->t('Delete'),
              'url' => Url::fromRoute('entity.os2web_spotbox.revision_delete', [
                'os2web_spotbox' => $os2web_spotbox->id(),
                'os2web_spotbox_revision' => $vid,
              ]),
            ];
          }

          $row[] = [
            'data' => [
              '#type' => 'operations',
              '#links' => $links,
            ],
          ];
        }

        $rows[] = $row;
      }
    }

    $build['os2web_spotbox_revisions_table'] = [
      '#theme' => 'table',
      '#rows' => $rows,
      '#header' => $header,
    ];

    return $build;
  }

}

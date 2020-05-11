<?php

namespace Drupal\os2web_spotbox\Form;

use Drupal\Core\Form\ConfirmFormBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Url;
use Symfony\Component\DependencyInjection\ContainerInterface;

/**
 * Provides a form for deleting a OS2Web Spotbox revision.
 *
 * @ingroup os2web_spotbox
 */
class SpotboxRevisionDeleteForm extends ConfirmFormBase {

  /**
   * The OS2Web Spotbox revision.
   *
   * @var \Drupal\os2web_spotbox\Entity\SpotboxInterface
   */
  protected $revision;

  /**
   * The OS2Web Spotbox storage.
   *
   * @var \Drupal\Core\Entity\EntityStorageInterface
   */
  protected $spotboxStorage;

  /**
   * The database connection.
   *
   * @var \Drupal\Core\Database\Connection
   */
  protected $connection;

  /**
   * {@inheritdoc}
   */
  public static function create(ContainerInterface $container) {
    $instance = parent::create($container);
    $instance->spotboxStorage = $container->get('entity_type.manager')->getStorage('os2web_spotbox');
    $instance->connection = $container->get('database');
    return $instance;
  }

  /**
   * {@inheritdoc}
   */
  public function getFormId() {
    return 'os2web_spotbox_revision_delete_confirm';
  }

  /**
   * {@inheritdoc}
   */
  public function getQuestion() {
    return $this->t('Are you sure you want to delete the revision from %revision-date?', [
      '%revision-date' => \Drupal::service('date.formatter')->format($this->revision->getRevisionCreationTime()),
    ]);
  }

  /**
   * {@inheritdoc}
   */
  public function getCancelUrl() {
    return new Url('entity.os2web_spotbox.version_history', ['os2web_spotbox' => $this->revision->id()]);
  }

  /**
   * {@inheritdoc}
   */
  public function getConfirmText() {
    return $this->t('Delete');
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state, $os2web_spotbox_revision = NULL) {
    $this->revision = $this->SpotboxStorage->loadRevision($os2web_spotbox_revision);
    $form = parent::buildForm($form, $form_state);

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
    $this->SpotboxStorage->deleteRevision($this->revision->getRevisionId());

    $this->logger('content')->notice('OS2Web Spotbox: deleted %title revision %revision.', ['%title' => $this->revision->label(), '%revision' => $this->revision->getRevisionId()]);
    $this->messenger()->addMessage(t('Revision from %revision-date of OS2Web Spotbox %title has been deleted.', ['%revision-date' => \Drupal::service('date.formatter')->format($this->revision->getRevisionCreationTime()), '%title' => $this->revision->label()]));
    $form_state->setRedirect(
      'entity.os2web_spotbox.canonical',
       ['os2web_spotbox' => $this->revision->id()]
    );
    if ($this->connection->query('SELECT COUNT(DISTINCT vid) FROM {os2web_spotbox_field_revision} WHERE id = :id', [':id' => $this->revision->id()])->fetchField() > 1) {
      $form_state->setRedirect(
        'entity.os2web_spotbox.version_history',
         ['os2web_spotbox' => $this->revision->id()]
      );
    }
  }

}

<?php

namespace Drupal\os2web_spotbox\Form;

use Drupal\Core\Entity\ContentEntityForm;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Render\Element;
use Symfony\Component\DependencyInjection\ContainerInterface;

/**
 * Form controller for OS2Web Spotbox edit forms.
 *
 * @ingroup os2web_spotbox
 */
class SpotboxForm extends ContentEntityForm {

  /**
   * The current user account.
   *
   * @var \Drupal\Core\Session\AccountProxyInterface
   */
  protected $account;

  /**
   * {@inheritdoc}
   */
  public static function create(ContainerInterface $container) {
    // Instantiates this form class.
    $instance = parent::create($container);
    $instance->account = $container->get('current_user');
    return $instance;
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
    /* @var \Drupal\os2web_spotbox\Entity\Spotbox $entity */
    $form = parent::buildForm($form, $form_state);
    $form['type']['widget']['#ajax'] = [
      'callback' => '::ajaxCallback',
      'wrapper' => 'os2web-spotbox-form-wrapper',
    ];
    $types = $this->entity->getTypes();
    $type_value = $form_state->getValue('type');
    $type = empty($type_value[0]['value']) ? NULL : $type_value[0]['value'];
    $disabled_fields = isset($types[$type]['disabled_fields']) ? $types[$type]['disabled_fields'] : [];
    if (empty($type)) {
      $form['actions']['submit']['#disabled'] = TRUE;
    }

    $form['field_os2web_spotbox_link_title']['#states'] = [
      'invisible' => [
        'select[name="field_os2web_spotbox_link"]' => ['value' => 'no_link'],
      ]
    ];
    $form['field_os2web_spotbox_link_int']['#states'] = [
      'visible' => [
        'select[name="field_os2web_spotbox_link"]' => ['value' => 'internal'],
      ]
    ];
    $form['field_os2web_spotbox_link_ext']['#states'] = [
      'visible' => [
        'select[name="field_os2web_spotbox_link"]' => ['value' => 'external'],
      ]
    ];
    $form['os2web-spotbox-form-wrapper'] = [
      '#type' => 'container',
      '#attributes' => ['id' => 'os2web-spotbox-form-wrapper'],
    ];
    foreach (Element::children($form) as $element) {
      if ($element == 'os2web-spotbox-form-wrapper') {
        continue;
      }
      if (strpos($element, 'field_os2web_spotbox') === FALSE
        || (!in_array($element, $disabled_fields) && !empty($disabled_fields))) {
        $form['os2web-spotbox-form-wrapper'][$element] = $form[$element];
        unset($form[$element]);
        continue;
      }
      $form[$element]['#access'] = FALSE;
    }

    if (!$this->entity->isNew()) {
      $form['new_revision'] = [
        '#type' => 'checkbox',
        '#title' => $this->t('Create new revision'),
        '#default_value' => FALSE,
        '#weight' => 10,
      ];
    }

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function save(array $form, FormStateInterface $form_state) {
    $entity = $this->entity;

    // Save as a new revision if requested to do so.
    if (!$form_state->isValueEmpty('new_revision') && $form_state->getValue('new_revision') != FALSE) {
      $entity->setNewRevision();

      // If a new revision is created, save the current user as revision author.
      $entity->setRevisionCreationTime($this->time->getRequestTime());
      $entity->setRevisionUserId($this->account->id());
    }
    else {
      $entity->setNewRevision(FALSE);
    }

    $status = parent::save($form, $form_state);

    switch ($status) {
      case SAVED_NEW:
        $this->messenger()->addMessage($this->t('Created the %label OS2Web Spotbox.', [
          '%label' => $entity->label(),
        ]));
        break;

      default:
        $this->messenger()->addMessage($this->t('Saved the %label OS2Web Spotbox.', [
          '%label' => $entity->label(),
        ]));
    }
    $form_state->setRedirect('entity.os2web_spotbox.canonical', ['os2web_spotbox' => $entity->id()]);
  }

  public function ajaxCallback(array $form, FormStateInterface $form_state) {
    return $form['os2web-spotbox-form-wrapper'];
  }
}

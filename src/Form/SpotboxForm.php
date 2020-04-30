<?php

namespace Drupal\os2web_spotbox\Form;

use Drupal\Component\Utility\NestedArray;
use Drupal\Core\Entity\ContentEntityForm;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Render\Element;
use Drupal\os2web_spotbox\Entity\Spotbox;
use Drupal\os2web_spotbox\Entity\SpotboxInterface;
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

    self::adjustForm($form, $form_state);

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
    $triggering_element = $form_state->getTriggeringElement();
    $spotbox_form_parents = [];
    foreach ($triggering_element['#field_parents'] as $key) {
      $spotbox_form_parents[] = $key;
      if (strpos($key, 'field_') === 0) {
        $spotbox_form_parents[] = 'widget';
      }
    }
    // @TODO Integration with Inline entity forms still works not well
    // on edit mode.
    $spotbox_form = NestedArray::getValue($form, $spotbox_form_parents);
    $wrapper = static::getFormWrapperId($spotbox_form);
    return $spotbox_form[$wrapper];
  }

  /**
   * Function that do adjust form for custom view.
   *
   * @param array $form
   * @param \Drupal\Core\Form\FormStateInterface $form_state
   */
  public static function adjustForm(array &$form, FormStateInterface $form_state) {
    if (!empty($form['#type']) && $form['#default_value'] instanceof SpotboxInterface) {
      $entity = $form['#default_value'];
    }
    elseif ($form_state->getFormObject()->getEntity() instanceof SpotboxInterface) {
      $entity = $form_state->getFormObject()->getEntity();
    }
    $wrapper_id = static::getFormWrapperId($form);
    $form['type']['widget']['#ajax'] = [
      'callback' => [static::class, 'ajaxCallback'],
      'wrapper' => $wrapper_id,
    ];

    // Removing None option.
    if (!empty($form['background_color']['widget']['#options']['_none'])) {
      unset($form['background_color']['widget']['#options']['_none']);
    }

    $types = Spotbox::getTypes();
    $type =  NestedArray::getValue($form_state->getUserInput(), $form['type']['widget']['#parents']);
    if (empty($type)) {
      if ($entity instanceof SpotboxInterface && !$entity->get('type')->isEmpty()) {
        $type = $entity->get('type')->first()->value;
      }
    }

    $form['actions']['submit']['#disabled'] = empty($type);

    $disabled_fields = isset($types[$type]['disabled_fields']) ? $types[$type]['disabled_fields'] : [];

    $form[$wrapper_id] = [
      '#type' => 'container',
      '#attributes' => ['id' => $wrapper_id],
    ];
    foreach (Element::children($form) as $element) {
      if ($element == $wrapper_id) {
        continue;
      }
      if (strpos($element, 'field_os2web_spotbox') === FALSE
        || (!in_array($element, $disabled_fields) && !empty($disabled_fields))) {
        $form[$wrapper_id][$element] = $form[$element];
        unset($form[$element]);
        continue;
      }
      $form[$element]['#access'] = FALSE;
    }
  }

  /**
   * Gets forms wrapper id.
   *
   * @param array $form
   *
   * @return string
   *   Forms wrapper id.
   */
  public static function getFormWrapperId(array $form) {
    $wrapper_id = 'os2web-spotbox-form-wrapper';
    if (!empty($form['#ief_id'])) {
      $wrapper_id .= '-'. $form['#ief_id'];
    }

    return $wrapper_id;
  }

}

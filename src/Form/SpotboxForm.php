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
    /** @var \Drupal\os2web_spotbox\Entity\Spotbox $entity */
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

  /**
   * Implements ajax callback for spotbox form.
   */
  public function ajaxCallback(array $form, FormStateInterface $form_state) {
    // Getting trigger element.
    $triggerElement = $form_state->getTriggeringElement();

    // Getting element parents.
    $arrayParents = $triggerElement['#array_parents'];

    // Removing last two elements from parent tree.
    //
    // We cannot return the entire form because the entire form is not always the same as spotbox create form
    //
    // Example 1:
    // Array
    // (
    //    [0] => type
    //    [1] => widget
    // )
    //
    // In this case getting value is the same as returning the entire form.
    //
    // Example 2:
    // Array
    // (
    //     ...
    //     [4] => field_os2web_spotbox_reference
    //     [5] => widget
    //     [6] => form
    //     [7] => inline_entity_form -> that is the level which we want to return
    //     [8] => type
    //     [9] => widget
    // )
    // It's not the case here, as spotbox form is part of other form, for example Inline Entity form.
    // So we must get two levels up the tree relative to the trigger element.
    array_pop($arrayParents);
    array_pop($arrayParents);

    // The form element, which is a second parent of a triggering element.
    $formsElement = NestedArray::getValue($form, $arrayParents);

    // Returning the container, which is a widget with a correct delta of a
    // parent element.
    return $formsElement;
  }

  /**
   * Function that do adjust form for custom view.
   *
   * @param array $form
   *   Form array.
   * @param \Drupal\Core\Form\FormStateInterface $form_state
   *   Form state object.
   */
  public static function adjustForm(array &$form, FormStateInterface $form_state) {
    if (!empty($form['#type']) && $form['#default_value'] instanceof SpotboxInterface) {
      $entity = $form['#default_value'];
    }
    elseif ($form_state->getFormObject()->getEntity() instanceof SpotboxInterface) {
      $entity = $form_state->getFormObject()->getEntity();
    }

    $wrapper_id = static::getFormWrapperId($form);

    // Adding wrapper for replacing the entire form via ajax.
    $form['#id'] = $wrapper_id;

    $form['type']['widget']['#ajax'] = [
      'callback' => '::ajaxCallback',
      'wrapper' => $wrapper_id,
    ];

    // Removing None option.
    if (!empty($form['background_color']['widget']['#options']['_none'])) {
      unset($form['background_color']['widget']['#options']['_none']);
    }

    $types = Spotbox::getTypes();
    $type = NestedArray::getValue($form_state->getUserInput(), $form['type']['widget']['#parents']);
    if (empty($type)) {
      if ($entity instanceof SpotboxInterface && !$entity->get('type')->isEmpty()) {
        $type = $entity->get('type')->first()->value;
      }
    }

    // Disabling the fields depending on the type.
    $disabled_fields = isset($types[$type]['disabled_fields']) ? $types[$type]['disabled_fields'] : [];
    foreach (Element::children($form) as $element) {
      if (in_array($element, $disabled_fields)) {
        $form[$element]['#access'] = FALSE;
      }
    }
  }

  /**
   * Gets forms wrapper id.
   *
   * @param array $form
   *   Form array.
   *
   * @return string
   *   Forms wrapper id.
   */
  public static function getFormWrapperId(array $form) {
    $wrapper_id = 'os2web-spotbox-form-wrapper';
    if (!empty($form['#ief_id'])) {
      $wrapper_id .= '-' . $form['#ief_id'];
    }

    return $wrapper_id;
  }

}

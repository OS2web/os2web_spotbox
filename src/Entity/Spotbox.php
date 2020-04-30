<?php

namespace Drupal\os2web_spotbox\Entity;

use Drupal\Core\Entity\EntityStorageInterface;
use Drupal\Core\Field\BaseFieldDefinition;
use Drupal\Core\Entity\EditorialContentEntityBase;
use Drupal\Core\Entity\RevisionableInterface;
use Drupal\Core\Entity\EntityChangedTrait;
use Drupal\Core\Entity\EntityPublishedTrait;
use Drupal\Core\Entity\EntityTypeInterface;
use Drupal\user\UserInterface;

/**
 * Defines the OS2Web Spotbox entity.
 *
 * @ingroup os2web_spotbox
 *
 * @ContentEntityType(
 *   id = "os2web_spotbox",
 *   label = @Translation("Spotbox"),
 *   handlers = {
 *     "storage" = "Drupal\os2web_spotbox\SpotboxStorage",
 *     "view_builder" = "Drupal\Core\Entity\EntityViewBuilder",
 *     "list_builder" = "Drupal\os2web_spotbox\SpotboxListBuilder",
 *     "views_data" = "Drupal\os2web_spotbox\Entity\SpotboxViewsData",
 *     "translation" = "Drupal\os2web_spotbox\SpotboxTranslationHandler",
 *
 *     "form" = {
 *       "default" = "Drupal\os2web_spotbox\Form\SpotboxForm",
 *       "add" = "Drupal\os2web_spotbox\Form\SpotboxForm",
 *       "edit" = "Drupal\os2web_spotbox\Form\SpotboxForm",
 *       "delete" = "Drupal\os2web_spotbox\Form\SpotboxDeleteForm",
 *     },
 *     "route_provider" = {
 *       "html" = "Drupal\os2web_spotbox\SpotboxHtmlRouteProvider",
 *     },
 *     "access" = "Drupal\os2web_spotbox\SpotboxAccessControlHandler",
 *   },
 *   base_table = "os2web_spotbox",
 *   data_table = "os2web_spotbox_field_data",
 *   revision_table = "os2web_spotbox_revision",
 *   revision_data_table = "os2web_spotbox_field_revision",
 *   translatable = TRUE,
 *   admin_permission = "administer os2web spotbox entities",
 *   entity_keys = {
 *     "id" = "id",
 *     "revision" = "vid",
 *     "label" = "name",
 *     "uuid" = "uuid",
 *     "uid" = "user_id",
 *     "langcode" = "langcode",
 *     "published" = "status",
 *   },
 *   links = {
 *     "canonical" = "/admin/content/os2web_spotbox/{os2web_spotbox}",
 *     "add-form" = "/admin/content/os2web_spotbox/add",
 *     "edit-form" = "/admin/content/os2web_spotbox/{os2web_spotbox}/edit",
 *     "delete-form" = "/admin/content/os2web_spotbox/{os2web_spotbox}/delete",
 *     "version-history" = "/admin/content/os2web_spotbox/{os2web_spotbox}/revisions",
 *     "revision" = "/admin/content/os2web_spotbox/{os2web_spotbox}/revisions/{os2web_spotbox_revision}/view",
 *     "revision_revert" = "/admin/content/os2web_spotbox/{os2web_spotbox}/revisions/{os2web_spotbox_revision}/revert",
 *     "revision_delete" = "/admin/content/os2web_spotbox/{os2web_spotbox}/revisions/{os2web_spotbox_revision}/delete",
 *     "translation_revert" = "/admin/content/os2web_spotbox/{os2web_spotbox}/revisions/{os2web_spotbox_revision}/revert/{langcode}",
 *     "collection" = "/admin/content/os2web_spotbox",
 *   },
 *   field_ui_base_route = "os2web_spotbox.settings"
 * )
 */
class Spotbox extends EditorialContentEntityBase implements SpotboxInterface {

  use EntityChangedTrait;
  use EntityPublishedTrait;

  /**
   * {@inheritdoc}
   */
  public static function preCreate(EntityStorageInterface $storage_controller, array &$values) {
    parent::preCreate($storage_controller, $values);
    $values += [
      'user_id' => \Drupal::currentUser()->id(),
    ];
  }

  /**
   * {@inheritdoc}
   */
  protected function urlRouteParameters($rel) {
    $uri_route_parameters = parent::urlRouteParameters($rel);

    if ($rel === 'revision_revert' && $this instanceof RevisionableInterface) {
      $uri_route_parameters[$this->getEntityTypeId() . '_revision'] = $this->getRevisionId();
    }
    elseif ($rel === 'revision_delete' && $this instanceof RevisionableInterface) {
      $uri_route_parameters[$this->getEntityTypeId() . '_revision'] = $this->getRevisionId();
    }

    return $uri_route_parameters;
  }

  /**
   * {@inheritdoc}
   */
  public function preSave(EntityStorageInterface $storage) {
    parent::preSave($storage);

    foreach (array_keys($this->getTranslationLanguages()) as $langcode) {
      $translation = $this->getTranslation($langcode);

      // If no owner has been set explicitly, make the anonymous user the owner.
      if (!$translation->getOwner()) {
        $translation->setOwnerId(0);
      }
    }

    // If no revision author has been set explicitly,
    // make the os2web_spotbox owner the revision author.
    if (!$this->getRevisionUser()) {
      $this->setRevisionUserId($this->getOwnerId());
    }
  }

  /**
   * {@inheritdoc}
   */
  public function getName() {
    return $this->get('name')->value;
  }

  /**
   * {@inheritdoc}
   */
  public function setName($name) {
    $this->set('name', $name);
    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public function getType() {
    return $this->get('type')->value;
  }

  /**
   * {@inheritdoc}
   */
  public function setType($type) {
    $this->set('type', $type);
    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public function getCreatedTime() {
    return $this->get('created')->value;
  }

  /**
   * {@inheritdoc}
   */
  public function setCreatedTime($timestamp) {
    $this->set('created', $timestamp);
    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public function getOwner() {
    return $this->get('user_id')->entity;
  }

  /**
   * {@inheritdoc}
   */
  public function getOwnerId() {
    return $this->get('user_id')->target_id;
  }

  /**
   * {@inheritdoc}
   */
  public function setOwnerId($uid) {
    $this->set('user_id', $uid);
    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public function setOwner(UserInterface $account) {
    $this->set('user_id', $account->id());
    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public static function baseFieldDefinitions(EntityTypeInterface $entity_type) {
    $fields = parent::baseFieldDefinitions($entity_type);

    // Add the published field.
    $fields += static::publishedBaseFieldDefinitions($entity_type);

    $fields['user_id'] = BaseFieldDefinition::create('entity_reference')
      ->setLabel(t('Authored by'))
      ->setDescription(t('The user ID of author of the OS2Web Spotbox entity.'))
      ->setRevisionable(TRUE)
      ->setSetting('target_type', 'user')
      ->setSetting('handler', 'default')
      ->setTranslatable(TRUE)
      ->setDisplayOptions('view', [
        'label' => 'hidden',
        'type' => 'author',
        'weight' => 0,
      ])
      ->setDisplayOptions('form', [
        'type' => 'entity_reference_autocomplete',
        'weight' => 5,
        'settings' => [
          'match_operator' => 'CONTAINS',
          'size' => '60',
          'placeholder' => '',
        ],
      ])
      ->setDisplayConfigurable('form', TRUE)
      ->setDisplayConfigurable('view', TRUE);

    $fields['name'] = BaseFieldDefinition::create('string')
      ->setLabel(t('Name'))
      ->setDescription(t('The name of the OS2Web Spotbox entity.'))
      ->setRevisionable(TRUE)
      ->setSettings([
        'max_length' => 50,
        'text_processing' => 0,
      ])
      ->setDefaultValue('')
      ->setRequired(TRUE)
      ->setDisplayConfigurable('form', TRUE);

    $allowed_values = [];
    foreach (self::getTypes() as $key => $type) {
      $allowed_values[$key] = $type['label'];
    }
    $fields['type'] = BaseFieldDefinition::create('list_string')
      ->setLabel(t('Type'))
      ->setDescription(t('Select type for new spotbox.'))
      ->setRequired(TRUE)
      ->setDefaultValue('')
      ->setReadOnly(TRUE)
      ->setDisplayOptions('form', [
        'type' => 'options_select',
        'weight' => -5,
      ])
      ->setSetting('allowed_values', $allowed_values)
      ->setDisplayConfigurable('form', TRUE);

    $allowed_values = [
      'transparent' => t('Ingen'),
      'primary' => t('Primær'),
      'secondary' => t('Sekundær'),
      'tertiary' => t('Tertiær'),
    ];
    $fields['background_color'] = BaseFieldDefinition::create('list_string')
      ->setLabel(t('Baggrundfarve'))
      ->setDescription(t('Vælg baggrundsfarve.'))
      ->setRequired(TRUE)
      ->setDefaultValue('')
      ->setReadOnly(TRUE)
      ->setDisplayOptions('form', [
        'type' => 'options_select',
        'weight' => -4,
      ])
      ->setSetting('allowed_values', $allowed_values)
      ->setDisplayConfigurable('form', TRUE);

    $fields['status']->setDescription(t('A boolean indicating whether the OS2Web Spotbox is published.'))
      ->setDisplayOptions('form', [
        'type' => 'boolean_checkbox',
        'weight' => -3,
      ])
      ->setDisplayConfigurable('form', TRUE);

    $fields['created'] = BaseFieldDefinition::create('created')
      ->setLabel(t('Created'))
      ->setDescription(t('The time that the entity was created.'));

    $fields['changed'] = BaseFieldDefinition::create('changed')
      ->setLabel(t('Changed'))
      ->setDescription(t('The time that the entity was last edited.'));

    $fields['revision_translation_affected'] = BaseFieldDefinition::create('boolean')
      ->setLabel(t('Revision translation affected'))
      ->setDescription(t('Indicates if the last edit of a translation belongs to current revision.'))
      ->setReadOnly(TRUE)
      ->setRevisionable(TRUE)
      ->setTranslatable(TRUE);

    return $fields;
  }

  /**
   * {@inheritdoc}
   */
  static function getTypes() {
    return [
      'default' => [
        'label' => t('Standard'),
        'disabled_fields' => [
          'field_os2web_spotbox_link_text',
          'field_os2web_spotbox_video',
          'field_os2web_spotbox_link_butt',
        ],
      ],
      'text' => [
        'label' => t('Tekst'),
        'disabled_fields' => [
          'field_os2web_spotbox_video',
          'field_os2web_spotbox_link_butt',
        ],
      ],
      'image' => [
        'label' => t('Billede'),
        'disabled_fields' => [
          'field_os2web_spotbox_video',
          'field_os2web_spotbox_link_butt',
        ],
      ],
      'video' => [
        'label' => t('Video'),
        'disabled_fields' => [
          'field_os2web_spotbox_link_text',
          'field_os2web_spotbox_link_butt',
        ],
      ],
      'button' => [
        'label' => t('Knap'),
        'disabled_fields' => [
          'field_os2web_spotbox_video',
        ],
      ],
      'icon' => [
        'label' => t('Ikon'),
        'disabled_fields' => [
          'field_os2web_spotbox_video',
          'field_os2web_spotbox_link_butt',
        ],
      ],
    ];
  }
}

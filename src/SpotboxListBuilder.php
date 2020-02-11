<?php

namespace Drupal\os2web_spotbox;

use Drupal\Core\Entity\EntityInterface;
use Drupal\Core\Entity\EntityListBuilder;
use Drupal\Core\Link;

/**
 * Defines a class to build a listing of OS2Web Spotbox entities.
 *
 * @ingroup os2web_spotbox
 */
class SpotboxListBuilder extends EntityListBuilder {

  /**
   * {@inheritdoc}
   */
  public function buildHeader() {
    $header['id'] = $this->t('OS2Web Spotbox ID');
    $header['name'] = $this->t('Name');
    return $header + parent::buildHeader();
  }

  /**
   * {@inheritdoc}
   */
  public function buildRow(EntityInterface $entity) {
    /* @var \Drupal\os2web_spotbox\Entity\Spotbox $entity */
    $row['id'] = $entity->id();
    $row['name'] = Link::createFromRoute(
      $entity->label(),
      'entity.os2web_spotbox.edit_form',
      ['os2web_spotbox' => $entity->id()]
    );
    return $row + parent::buildRow($entity);
  }

}

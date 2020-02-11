<?php

namespace Drupal\os2web_spotbox;

use Drupal\Core\Entity\EntityAccessControlHandler;
use Drupal\Core\Entity\EntityInterface;
use Drupal\Core\Session\AccountInterface;
use Drupal\Core\Access\AccessResult;

/**
 * Access controller for the OS2Web Spotbox entity.
 *
 * @see \Drupal\os2web_spotbox\Entity\Spotbox.
 */
class SpotboxAccessControlHandler extends EntityAccessControlHandler {

  /**
   * {@inheritdoc}
   */
  protected function checkAccess(EntityInterface $entity, $operation, AccountInterface $account) {
    /** @var \Drupal\os2web_spotbox\Entity\SpotboxInterface $entity */

    switch ($operation) {

      case 'view':

        if (!$entity->isPublished()) {
          return AccessResult::allowedIfHasPermission($account, 'view unpublished os2web spotbox entities');
        }


        return AccessResult::allowedIfHasPermission($account, 'view published os2web spotbox entities');

      case 'update':

        return AccessResult::allowedIfHasPermission($account, 'edit os2web spotbox entities');

      case 'delete':

        return AccessResult::allowedIfHasPermission($account, 'delete os2web spotbox entities');
    }

    // Unknown operation, no opinion.
    return AccessResult::neutral();
  }

  /**
   * {@inheritdoc}
   */
  protected function checkCreateAccess(AccountInterface $account, array $context, $entity_bundle = NULL) {
    return AccessResult::allowedIfHasPermission($account, 'add os2web spotbox entities');
  }


}

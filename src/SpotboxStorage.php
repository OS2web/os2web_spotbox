<?php

namespace Drupal\os2web_spotbox;

use Drupal\Core\Entity\Sql\SqlContentEntityStorage;
use Drupal\Core\Session\AccountInterface;
use Drupal\Core\Language\LanguageInterface;
use Drupal\os2web_spotbox\Entity\SpotboxInterface;

/**
 * Defines the storage handler class for OS2Web Spotbox entities.
 *
 * This extends the base storage class, adding required special handling for
 * OS2Web Spotbox entities.
 *
 * @ingroup os2web_spotbox
 */
class SpotboxStorage extends SqlContentEntityStorage implements SpotboxStorageInterface {

  /**
   * {@inheritdoc}
   */
  public function revisionIds(SpotboxInterface $entity) {
    return $this->database->query(
      'SELECT vid FROM {os2web_spotbox_revision} WHERE id=:id ORDER BY vid',
      [':id' => $entity->id()]
    )->fetchCol();
  }

  /**
   * {@inheritdoc}
   */
  public function userRevisionIds(AccountInterface $account) {
    return $this->database->query(
      'SELECT vid FROM {os2web_spotbox_field_revision} WHERE uid = :uid ORDER BY vid',
      [':uid' => $account->id()]
    )->fetchCol();
  }

  /**
   * {@inheritdoc}
   */
  public function countDefaultLanguageRevisions(SpotboxInterface $entity) {
    return $this->database->query('SELECT COUNT(*) FROM {os2web_spotbox_field_revision} WHERE id = :id AND default_langcode = 1', [':id' => $entity->id()])
      ->fetchField();
  }

  /**
   * {@inheritdoc}
   */
  public function clearRevisionsLanguage(LanguageInterface $language) {
    return $this->database->update('os2web_spotbox_revision')
      ->fields(['langcode' => LanguageInterface::LANGCODE_NOT_SPECIFIED])
      ->condition('langcode', $language->getId())
      ->execute();
  }

}

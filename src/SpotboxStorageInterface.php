<?php

namespace Drupal\os2web_spotbox;

use Drupal\Core\Entity\ContentEntityStorageInterface;
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
interface SpotboxStorageInterface extends ContentEntityStorageInterface {

  /**
   * Gets a list of OS2Web Spotbox revision IDs for a specific OS2Web Spotbox.
   *
   * @param \Drupal\os2web_spotbox\Entity\SpotboxInterface $entity
   *   The OS2Web Spotbox entity.
   *
   * @return int[]
   *   OS2Web Spotbox revision IDs (in ascending order).
   */
  public function revisionIds(SpotboxInterface $entity);

  /**
   * Gets a list of revision IDs having a given user as OS2Web Spotbox author.
   *
   * @param \Drupal\Core\Session\AccountInterface $account
   *   The user entity.
   *
   * @return int[]
   *   OS2Web Spotbox revision IDs (in ascending order).
   */
  public function userRevisionIds(AccountInterface $account);

  /**
   * Counts the number of revisions in the default language.
   *
   * @param \Drupal\os2web_spotbox\Entity\SpotboxInterface $entity
   *   The OS2Web Spotbox entity.
   *
   * @return int
   *   The number of revisions in the default language.
   */
  public function countDefaultLanguageRevisions(SpotboxInterface $entity);

  /**
   * Unsets the language for all OS2Web Spotbox with the given language.
   *
   * @param \Drupal\Core\Language\LanguageInterface $language
   *   The language object.
   */
  public function clearRevisionsLanguage(LanguageInterface $language);

}

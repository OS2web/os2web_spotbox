<?php

namespace Drupal\os2web_spotbox\Entity;

use Drupal\Core\Entity\ContentEntityInterface;
use Drupal\Core\Entity\RevisionLogInterface;
use Drupal\Core\Entity\EntityChangedInterface;
use Drupal\Core\Entity\EntityPublishedInterface;
use Drupal\user\EntityOwnerInterface;

/**
 * Provides an interface for defining OS2Web Spotbox entities.
 *
 * @ingroup os2web_spotbox
 */
interface SpotboxInterface extends ContentEntityInterface, RevisionLogInterface, EntityChangedInterface, EntityPublishedInterface, EntityOwnerInterface {

  /**
   * Add get/set methods for your configuration properties here.
   */

  /**
   * Gets the OS2Web Spotbox name.
   *
   * @return string
   *   Name of the OS2Web Spotbox.
   */
  public function getName();

  /**
   * Sets the OS2Web Spotbox name.
   *
   * @param string $name
   *   The OS2Web Spotbox name.
   *
   * @return \Drupal\os2web_spotbox\Entity\SpotboxInterface
   *   The called OS2Web Spotbox entity.
   */
  public function setName($name);

  /**
   * Gets the OS2Web Spotbox type.
   *
   * @return string
   *   Type of the OS2Web Spotbox.
   */
  public function getType();

  /**
   * Sets the OS2Web Spotbox type.
   *
   * @param string $type
   *   The OS2Web Spotbox type.
   *
   * @return \Drupal\os2web_spotbox\Entity\SpotboxInterface
   *   The called OS2Web Spotbox entity.
   */
  public function setType($type);

  /**
   * Gets the OS2Web Spotbox background color.
   *
   * @return string
   *   Background color of the OS2Web Spotbox.
   */
  public function getBackgroundColor();

  /**
   * Sets the OS2Web Spotbox background color.
   *
   * @param string $background_color
   *   The OS2Web Spotbox background color.
   *
   * @return \Drupal\os2web_spotbox\Entity\SpotboxInterface
   *   The called OS2Web Spotbox entity.
   */
  public function setBackgroundColor($background_color);

  /**
   * Gets the OS2Web Spotbox creation timestamp.
   *
   * @return int
   *   Creation timestamp of the OS2Web Spotbox.
   */
  public function getCreatedTime();

  /**
   * Sets the OS2Web Spotbox creation timestamp.
   *
   * @param int $timestamp
   *   The OS2Web Spotbox creation timestamp.
   *
   * @return \Drupal\os2web_spotbox\Entity\SpotboxInterface
   *   The called OS2Web Spotbox entity.
   */
  public function setCreatedTime($timestamp);

  /**
   * Gets the OS2Web Spotbox revision creation timestamp.
   *
   * @return int
   *   The UNIX timestamp of when this revision was created.
   */
  public function getRevisionCreationTime();

  /**
   * Sets the OS2Web Spotbox revision creation timestamp.
   *
   * @param int $timestamp
   *   The UNIX timestamp of when this revision was created.
   *
   * @return \Drupal\os2web_spotbox\Entity\SpotboxInterface
   *   The called OS2Web Spotbox entity.
   */
  public function setRevisionCreationTime($timestamp);

  /**
   * Gets the OS2Web Spotbox revision author.
   *
   * @return \Drupal\user\UserInterface
   *   The user entity for the revision author.
   */
  public function getRevisionUser();

  /**
   * Sets the OS2Web Spotbox revision author.
   *
   * @param int $uid
   *   The user ID of the revision author.
   *
   * @return \Drupal\os2web_spotbox\Entity\SpotboxInterface
   *   The called OS2Web Spotbox entity.
   */
  public function setRevisionUserId($uid);

  /**
   * Defines types for spotbox entity.
   *
   * @return array
   */
  static function getTypes();
}

<?php

/**
 * @file
 * Contains os2web_spotbox.page.inc.
 *
 * Page callback for OS2Web Spotbox entities.
 */

use Drupal\Core\Render\Element;

/**
 * Prepares variables for OS2Web Spotbox templates.
 *
 * Default template: os2web_spotbox.html.twig.
 *
 * @param array $variables
 *   An associative array containing:
 *   - elements: An associative array containing the user information and any
 *   - attributes: HTML attributes for the containing element.
 */
function template_preprocess_os2web_spotbox(array &$variables) {
  // Fetch Spotbox Entity Object.
  $os2web_spotbox = $variables['elements']['#os2web_spotbox'];

  // Helpful $content variable for templates.
  foreach (Element::children($variables['elements']) as $key) {
    $variables['content'][$key] = $variables['elements'][$key];
  }
}

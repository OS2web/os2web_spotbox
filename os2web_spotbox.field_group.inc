<?php
/**
 * @file
 * os2web_spotbox.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function os2web_spotbox_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_billeder|node|os2web_spotbox_box|form';
  $field_group->group_name = 'group_billeder';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_spotbox_box';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_spotbox';
  $field_group->data = array(
    'label' => 'Spotbox',
    'weight' => '1',
    'children' => array(
      0 => 'field_os2web_spotbox_lead_image',
      1 => 'field_os2web_spotbox_sitestruct',
      2 => 'field_os2web_spotbox_image_tall',
      3 => 'field_os2web_spotbox_ref_kle',
      4 => 'title',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Spotbox',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_billeder|node|os2web_spotbox_box|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_links|node|os2web_spotbox_box|form';
  $field_group->group_name = 'group_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_spotbox_box';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_spotbox';
  $field_group->data = array(
    'label' => 'Links',
    'weight' => '3',
    'children' => array(
      0 => 'field_os2web_spotbox_text',
      1 => 'field_os2web_spotbox_url',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_links|node|os2web_spotbox_box|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_spotbox|node|os2web_spotbox_box|form';
  $field_group->group_name = 'group_spotbox';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_spotbox_box';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Spotbox',
    'weight' => '0',
    'children' => array(
      0 => 'group_billeder',
      1 => 'group_links',
      2 => 'group_taksonomi',
      3 => 'group_tekst',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_spotbox|node|os2web_spotbox_box|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taksonomi|node|os2web_spotbox_box|form';
  $field_group->group_name = 'group_taksonomi';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_spotbox_box';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_spotbox';
  $field_group->data = array(
    'label' => 'Emneord',
    'weight' => '4',
    'children' => array(
      0 => 'field_os2web_spotbox_editor_tags',
      1 => 'field_os2web_spotbox_organizati',
      2 => 'field_os2web_spotbox_politics',
      3 => 'field_os2web_spotbox_promote_to',
      4 => 'field_os2web_spotbox_ref_place',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_taksonomi|node|os2web_spotbox_box|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tekst|node|os2web_spotbox_box|form';
  $field_group->group_name = 'group_tekst';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_spotbox_box';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_spotbox';
  $field_group->data = array(
    'label' => 'Tekst og video',
    'weight' => '2',
    'children' => array(
      0 => 'body',
      1 => 'field_os2web_spotbox_video',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Tekst og video',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_tekst|node|os2web_spotbox_box|form'] = $field_group;

  return $export;
}

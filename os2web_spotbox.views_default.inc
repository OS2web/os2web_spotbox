<?php
/**
 * @file
 * os2web_spotbox.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function os2web_spotbox_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'os2web_spotbox_view_spot';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'SpotBox view';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'spotbox-indhold';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Udfør';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Spotboxe (field_os2web_base_field_spotbox) */
  $handler->display->display_options['relationships']['field_os2web_base_field_spotbox_nid']['id'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['relationships']['field_os2web_base_field_spotbox_nid']['table'] = 'field_data_field_os2web_base_field_spotbox';
  $handler->display->display_options['relationships']['field_os2web_base_field_spotbox_nid']['field'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['relationships']['field_os2web_base_field_spotbox_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_os2web_base_field_spotbox_nid']['delta'] = '-1';
  /* Field: Content: Billede */
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['id'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['table'] = 'field_data_field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['field'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['text'] = '<img src="[field_os2web_spotbox_lead_image]" alt="[title]" />
<span class="zoom-icon"></span>';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['link_class'] = 'overlayclass';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['settings'] = array(
    'image_style' => 'os2web_spotbox_image_right',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_os2web_spotbox_lead_image]<br />
[title]';
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '24';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['text'] = '<div class="spotImage">[field_os2web_spotbox_lead_image]</div>
<div class="spotTitle">[title]</div>

';
  $handler->display->display_options['fields']['title_1']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['title_1']['alter']['max_length'] = '20';
  $handler->display->display_options['fields']['title_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['id'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['table'] = 'field_data_field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['field'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['element_label_colon'] = FALSE;
  /* Field: Content: Indhold */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'os2web_spotbox_box' => 'os2web_spotbox_box',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'spotbox-2-vertical';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Global: Contextual Links */
  $handler->display->display_options['fields']['contextual_links']['id'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['table'] = 'views';
  $handler->display->display_options['fields']['contextual_links']['field'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['label'] = '';
  $handler->display->display_options['fields']['contextual_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contextual_links']['fields'] = array(
    'edit_node' => 'edit_node',
    'body' => 0,
    'field_os2web_spotbox_lead_image' => 0,
    'title' => 0,
    'title_1' => 0,
    'field_os2web_spotbox_url' => 0,
  );
  /* Field: Content: Indhold */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  /* Field: Content: Billede */
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['id'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['table'] = 'field_data_field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['field'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['text'] = '<img src="[field_os2web_spotbox_lead_image]" alt="[title]" />
<span class="zoom-icon"></span>';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['link_class'] = 'overlayclass';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['empty'] = '<div class="spotbox_no_picture"><div class="spotbox_no_picture_text"><a href=[field_os2web_spotbox_url]>[body]</a></div></div>';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['settings'] = array(
    'image_style' => 'os2web_spotbox_image_right',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_os2web_spotbox_lead_image]<br />
[title]';
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '24';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['text'] = '<div class="spotImage">[field_os2web_spotbox_lead_image]</div>
<div class="spotTitle">[title]</div>

';
  $handler->display->display_options['fields']['title_1']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['title_1']['alter']['max_length'] = '20';
  $handler->display->display_options['fields']['title_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['id'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['table'] = 'field_data_field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['field'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['element_label_colon'] = FALSE;

  /* Display: Spotbox */
  $handler = $view->new_display('block', 'Spotbox', 'block_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Indhold */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['id'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['table'] = 'field_data_field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['field'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['alter']['text'] = '[field_os2web_spotbox_url] ';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['type'] = 'text_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_os2web_spotbox_lead_image]<br />
[title]';
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '20';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_class'] = 'pane-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Billede */
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['id'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['table'] = 'field_data_field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['field'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['text'] = '[field_os2web_spotbox_lead_image]
<span class="zoom-icon"></span>';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['link_class'] = 'overlayclass';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['empty'] = '<div class="spotbox_no_picture"><div class="spotbox_no_picture_text"><a href=[field_os2web_spotbox_url]>[body]</a></div></div>';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['type'] = 'slideshow';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['settings'] = array(
    'image_style' => 'os2web_spotbox_image_right',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['alter']['text'] = '<h3><a href=[field_os2web_spotbox_url]>[title]';
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['title_1']['alter']['max_length'] = '20';
  $handler->display->display_options['fields']['title_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title_1']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  /* Field: Global: Contextual Links */
  $handler->display->display_options['fields']['contextual_links']['id'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['table'] = 'views';
  $handler->display->display_options['fields']['contextual_links']['field'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['label'] = '';
  $handler->display->display_options['fields']['contextual_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contextual_links']['fields'] = array(
    'edit_node' => 'edit_node',
    'body' => 0,
    'field_os2web_spotbox_url' => 0,
    'field_os2web_spotbox_lead_image' => 0,
    'title' => 0,
    'title_1' => 0,
  );
  $translatables['os2web_spotbox_view_spot'] = array(
    t('Master'),
    t('mere'),
    t('Udfør'),
    t('Gendan'),
    t('Sortér efter'),
    t('Stigende'),
    t('Faldende'),
    t('field_os2web_base_field_spotbox'),
    t('<img src="[field_os2web_spotbox_lead_image]" alt="[title]" />
<span class="zoom-icon"></span>'),
    t('[field_os2web_spotbox_lead_image]<br />
[title]'),
    t('<div class="spotImage">[field_os2web_spotbox_lead_image]</div>
<div class="spotTitle">[title]</div>

'),
    t('Indhold'),
    t('Alle'),
    t('Content pane'),
    t('more'),
    t('<div class="spotbox_no_picture"><div class="spotbox_no_picture_text"><a href=[field_os2web_spotbox_url]>[body]</a></div></div>'),
    t('View panes'),
    t('Spotbox'),
    t('[field_os2web_spotbox_url] '),
    t('[field_os2web_spotbox_lead_image]
<span class="zoom-icon"></span>'),
    t('<h3><a href=[field_os2web_spotbox_url]>[title]'),
    t('Edit link'),
  );
  $export['os2web_spotbox_view_spot'] = $view;

  $view = new view();
  $view->name = 'os2web_spotbox_view_spots';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Spotboxe';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Spotboxe';
  $handler->display->display_options['css_class'] = 'spotbox spotbox-normal';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '60';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Udfør';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Antal elementer';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Forskydning';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« første';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ forrige';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'næste ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'sidste »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'grid-3 omega';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['id'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['table'] = 'field_data_field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['field'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Indhold */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_type'] = 'p';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  /* Field: Content: Billede */
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['id'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['table'] = 'field_data_field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['field'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['text'] = '<img src="[field_os2web_spotbox_lead_image]" alt="[title_1]" />';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['settings'] = array(
    'image_style' => 'os2web_spotbox_image_right',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Link tekst */
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['id'] = 'field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['table'] = 'field_data_field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['field'] = 'field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_type'] = 'h4';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_default_classes'] = FALSE;
  /* Field: Content: Egenavne / Stednavne */
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['id'] = 'field_os2web_spotbox_ref_place';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['table'] = 'field_data_field_os2web_spotbox_ref_place';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['field'] = 'field_os2web_spotbox_ref_place';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['delta_offset'] = '0';
  /* Field: Content: Forfrem til */
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['id'] = 'field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['table'] = 'field_data_field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['field'] = 'field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['delta_offset'] = '0';
  /* Field: Content: KL Emneord */
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['id'] = 'field_os2web_spotbox_ref_kle';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['table'] = 'field_data_field_os2web_spotbox_ref_kle';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['field'] = 'field_os2web_spotbox_ref_kle';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['delta_offset'] = '0';
  /* Field: Content: Organisation */
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['id'] = 'field_os2web_spotbox_organizati';
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['table'] = 'field_data_field_os2web_spotbox_organizati';
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['field'] = 'field_os2web_spotbox_organizati';
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['delta_offset'] = '0';
  /* Field: Content: Politik */
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['id'] = 'field_os2web_spotbox_politics';
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['table'] = 'field_data_field_os2web_spotbox_politics';
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['field'] = 'field_os2web_spotbox_politics';
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['delta_offset'] = '0';
  /* Field: Content: Portalkategori */
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['id'] = 'field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['table'] = 'field_data_field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['field'] = 'field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['exclude'] = TRUE;
  /* Field: Content: Stikord */
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['id'] = 'field_os2web_spotbox_editor_tags';
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['table'] = 'field_data_field_os2web_spotbox_editor_tags';
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['field'] = 'field_os2web_spotbox_editor_tags';
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['delta_offset'] = '0';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Portalkategori (field_os2web_spotbox_sitestruct) */
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['id'] = 'field_os2web_spotbox_sitestruct_tid';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['table'] = 'field_data_field_os2web_spotbox_sitestruct';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['field'] = 'field_os2web_spotbox_sitestruct_tid';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['default_argument_options']['node'] = TRUE;
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['default_argument_options']['limit'] = TRUE;
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['default_argument_options']['vocabularies'] = array(
    'os2web_base_tax_site_structure' => 'os2web_base_tax_site_structure',
  );
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['validate_options']['vocabularies'] = array(
    'os2web_base_tax_site_structure' => 'os2web_base_tax_site_structure',
  );
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'os2web_spotbox_box' => 'os2web_spotbox_box',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['nid_type'] = 'nids';
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'field_os2web_base_field_spotbox_nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'os2web_spotbox_box' => 'os2web_spotbox_box',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'spotboxe';

  /* Display: Spotbox på node */
  $handler = $view->new_display('panel_pane', 'Spotbox på node', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['id'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['table'] = 'field_data_field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['field'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Indhold */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_type'] = 'p';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  /* Field: Content: Billede */
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['id'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['table'] = 'field_data_field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['field'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['text'] = '<a href=[field_os2web_spotbox_url] title=[title] ><img src="[field_os2web_spotbox_lead_image]" alt="[title_1]" /></a>';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['empty'] = '<div class="spotbox_no_picture"><div class="spotbox_no_picture_text"><a href=[field_os2web_spotbox_url]>[body]</a></div></div>';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['settings'] = array(
    'image_style' => 'os2web_spotbox_image_right',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a href=[field_os2web_spotbox_url] title=[title]>[title]</a>';
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Link tekst */
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['id'] = 'field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['table'] = 'field_data_field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['field'] = 'field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_type'] = 'h4';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_default_classes'] = FALSE;
  /* Field: Content: Egenavne / Stednavne */
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['id'] = 'field_os2web_spotbox_ref_place';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['table'] = 'field_data_field_os2web_spotbox_ref_place';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['field'] = 'field_os2web_spotbox_ref_place';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['delta_offset'] = '0';
  /* Field: Content: Forfrem til */
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['id'] = 'field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['table'] = 'field_data_field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['field'] = 'field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['delta_offset'] = '0';
  /* Field: Content: KL Emneord */
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['id'] = 'field_os2web_spotbox_ref_kle';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['table'] = 'field_data_field_os2web_spotbox_ref_kle';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['field'] = 'field_os2web_spotbox_ref_kle';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['delta_offset'] = '0';
  /* Field: Content: Organisation */
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['id'] = 'field_os2web_spotbox_organizati';
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['table'] = 'field_data_field_os2web_spotbox_organizati';
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['field'] = 'field_os2web_spotbox_organizati';
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['delta_offset'] = '0';
  /* Field: Content: Politik */
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['id'] = 'field_os2web_spotbox_politics';
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['table'] = 'field_data_field_os2web_spotbox_politics';
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['field'] = 'field_os2web_spotbox_politics';
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['delta_offset'] = '0';
  /* Field: Content: Portalkategori */
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['id'] = 'field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['table'] = 'field_data_field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['field'] = 'field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['exclude'] = TRUE;
  /* Field: Content: Stikord */
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['id'] = 'field_os2web_spotbox_editor_tags';
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['table'] = 'field_data_field_os2web_spotbox_editor_tags';
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['field'] = 'field_os2web_spotbox_editor_tags';
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['delta_offset'] = '0';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;

  /* Display: Spotboxe / forside - 2tv */
  $handler = $view->new_display('panel_pane', 'Spotboxe / forside - 2tv', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'spotbox spotbox-normal spotbox-2-vertical grid-3 alpha';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'spotbox-row grid-3 alpha omega';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['link_class'] = 'redigerlink';
  $handler->display->display_options['fields']['edit_node']['element_type'] = '0';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['id'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['table'] = 'field_data_field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['field'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['alter']['max_length'] = '35';
  $handler->display->display_options['fields']['title_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title_1']['element_class'] = 'pane-title';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Indhold */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_type'] = 'p';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  /* Field: Content: Billede */
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['id'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['table'] = 'field_data_field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['field'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['text'] = '<a href=[field_os2web_spotbox_url] title=[title_1]>[field_os2web_spotbox_lead_image]
<span class="zoom-icon"></span></a>';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['link_class'] = 'overlayclass';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['empty'] = '<div class="spotbox_no_picture"><div class="spotbox_no_picture_text"><a href=[field_os2web_spotbox_url]>[body]</a></div></div>';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['settings'] = array(
    'image_style' => '960_grid3',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '50';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Link tekst */
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['id'] = 'field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['table'] = 'field_data_field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['field'] = 'field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['alter']['text'] = '<a href=[field_os2web_spotbox_url] title=[field_os2web_spotbox_text]>[field_os2web_spotbox_text]</a>';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_type'] = 'h3';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['empty'] = '[title]';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['hide_alter_empty'] = FALSE;
  /* Field: Content: Egenavne / Stednavne */
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['id'] = 'field_os2web_spotbox_ref_place';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['table'] = 'field_data_field_os2web_spotbox_ref_place';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['field'] = 'field_os2web_spotbox_ref_place';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['delta_offset'] = '0';
  /* Field: Content: Forfrem til */
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['id'] = 'field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['table'] = 'field_data_field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['field'] = 'field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['delta_offset'] = '0';
  /* Field: Content: KL Emneord */
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['id'] = 'field_os2web_spotbox_ref_kle';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['table'] = 'field_data_field_os2web_spotbox_ref_kle';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['field'] = 'field_os2web_spotbox_ref_kle';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['delta_offset'] = '0';
  /* Field: Content: Organisation */
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['id'] = 'field_os2web_spotbox_organizati';
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['table'] = 'field_data_field_os2web_spotbox_organizati';
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['field'] = 'field_os2web_spotbox_organizati';
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['delta_offset'] = '0';
  /* Field: Content: Politik */
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['id'] = 'field_os2web_spotbox_politics';
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['table'] = 'field_data_field_os2web_spotbox_politics';
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['field'] = 'field_os2web_spotbox_politics';
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['delta_offset'] = '0';
  /* Field: Content: Portalkategori */
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['id'] = 'field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['table'] = 'field_data_field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['field'] = 'field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['exclude'] = TRUE;
  /* Field: Content: Stikord */
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['id'] = 'field_os2web_spotbox_editor_tags';
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['table'] = 'field_data_field_os2web_spotbox_editor_tags';
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['field'] = 'field_os2web_spotbox_editor_tags';
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'os2web_spotbox_box' => 'os2web_spotbox_box',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['nid_type'] = 'nids';
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'os2web_spotbox_box' => 'os2web_spotbox_box',
  );
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  /* Filter criterion: Content: Video (field_os2web_spotbox_video:fid) */
  $handler->display->display_options['filters']['field_os2web_spotbox_video_fid']['id'] = 'field_os2web_spotbox_video_fid';
  $handler->display->display_options['filters']['field_os2web_spotbox_video_fid']['table'] = 'field_data_field_os2web_spotbox_video';
  $handler->display->display_options['filters']['field_os2web_spotbox_video_fid']['field'] = 'field_os2web_spotbox_video_fid';
  $handler->display->display_options['filters']['field_os2web_spotbox_video_fid']['operator'] = 'empty';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'user',
      'context' => 'entity:user.uid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'ID på Spotboxe',
    ),
  );

  /* Display: Spotboxe / forside - 2th */
  $handler = $view->new_display('panel_pane', 'Spotboxe / forside - 2th', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'spotbox spotbox-horisontal alpha omega';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '2';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'spotbox-row';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['link_class'] = 'redigerlink';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['id'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['table'] = 'field_data_field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['field'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['element_wrapper_type'] = 'h2';
  $handler->display->display_options['fields']['title_1']['element_wrapper_class'] = 'pane-title';
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Indhold */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_type'] = 'p';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  /* Field: Content: Billede */
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['id'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['table'] = 'field_data_field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['field'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['text'] = '<a href=[field_os2web_spotbox_url] title=[title_1]><img src="[field_os2web_spotbox_lead_image]" alt="[title_1]" />
<span class="zoom-icon"></span></a>';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['alt'] = '[title_1]';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['link_class'] = 'overlayclass';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['empty'] = '<div class="spotbox_no_picture"><div class="spotbox_no_picture_text"><a href=[field_os2web_spotbox_url]  title=[title_1]>[body]</a></div></div>';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['type'] = 'slideshow';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['settings'] = array(
    'image_style' => 'os2web_spotbox_image_right',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '50';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Link tekst */
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['id'] = 'field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['table'] = 'field_data_field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['field'] = 'field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['alter']['text'] = '<a href=[field_os2web_spotbox_url] title=[title_1]>[field_os2web_spotbox_text]</a>';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_type'] = 'h3';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['empty'] = '[title]';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['hide_alter_empty'] = FALSE;
  /* Field: Content: Forfrem til */
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['id'] = 'field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['table'] = 'field_data_field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['field'] = 'field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['delta_offset'] = '0';
  /* Field: Global: Contextual Links */
  $handler->display->display_options['fields']['contextual_links']['id'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['table'] = 'views';
  $handler->display->display_options['fields']['contextual_links']['field'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['label'] = '';
  $handler->display->display_options['fields']['contextual_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contextual_links']['fields'] = array(
    'edit_node' => 'edit_node',
    'field_os2web_spotbox_url' => 'field_os2web_spotbox_url',
    'title_1' => 'title_1',
    'body' => 'body',
    'field_os2web_spotbox_text' => 'field_os2web_spotbox_text',
    'field_os2web_spotbox_lead_image' => 0,
    'title' => 0,
    'field_os2web_spotbox_ref_place' => 0,
    'field_os2web_spotbox_promote_to' => 0,
    'field_os2web_spotbox_ref_kle' => 0,
    'field_os2web_spotbox_organizati' => 0,
    'field_os2web_spotbox_politics' => 0,
    'field_os2web_spotbox_sitestruct' => 0,
    'field_os2web_spotbox_editor_tags' => 0,
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'os2web_spotbox_box' => 'os2web_spotbox_box',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['nid_type'] = 'nids';
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'os2web_spotbox_box' => 'os2web_spotbox_box',
  );
  /* Filter criterion: Content: Forfrem til (field_os2web_spotbox_promote_to) */
  $handler->display->display_options['filters']['field_os2web_spotbox_promote_to_tid']['id'] = 'field_os2web_spotbox_promote_to_tid';
  $handler->display->display_options['filters']['field_os2web_spotbox_promote_to_tid']['table'] = 'field_data_field_os2web_spotbox_promote_to';
  $handler->display->display_options['filters']['field_os2web_spotbox_promote_to_tid']['field'] = 'field_os2web_spotbox_promote_to_tid';
  $handler->display->display_options['filters']['field_os2web_spotbox_promote_to_tid']['value'] = array(
    5800 => '5800',
  );
  $handler->display->display_options['filters']['field_os2web_spotbox_promote_to_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_os2web_spotbox_promote_to_tid']['vocabulary'] = 'os2web_base_tax_promoteto';
  /* Filter criterion: Content: Video (field_os2web_spotbox_video:fid) */
  $handler->display->display_options['filters']['field_os2web_spotbox_video_fid']['id'] = 'field_os2web_spotbox_video_fid';
  $handler->display->display_options['filters']['field_os2web_spotbox_video_fid']['table'] = 'field_data_field_os2web_spotbox_video';
  $handler->display->display_options['filters']['field_os2web_spotbox_video_fid']['field'] = 'field_os2web_spotbox_video_fid';
  $handler->display->display_options['filters']['field_os2web_spotbox_video_fid']['operator'] = 'empty';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 'offset';
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'user',
      'context' => 'entity:user.uid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Indhold: Nid',
    ),
  );

  /* Display: Spotboxe / forside - Høj */
  $handler = $view->new_display('panel_pane', 'Spotboxe / forside - Høj', 'panel_pane_12');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'spotbox os2web_spotbox_image_tall';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'spotbox-row-tall';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['link_class'] = 'redigerlink';
  $handler->display->display_options['fields']['edit_node']['element_type'] = '0';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['id'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['table'] = 'field_data_field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['field'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['alter']['max_length'] = '35';
  $handler->display->display_options['fields']['title_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title_1']['element_class'] = 'pane-title';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Indhold */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_type'] = 'p';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  /* Field: Content: Højt billede */
  $handler->display->display_options['fields']['field_os2web_spotbox_image_tall']['id'] = 'field_os2web_spotbox_image_tall';
  $handler->display->display_options['fields']['field_os2web_spotbox_image_tall']['table'] = 'field_data_field_os2web_spotbox_image_tall';
  $handler->display->display_options['fields']['field_os2web_spotbox_image_tall']['field'] = 'field_os2web_spotbox_image_tall';
  $handler->display->display_options['fields']['field_os2web_spotbox_image_tall']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_image_tall']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_image_tall']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_os2web_spotbox_image_tall']['settings'] = array(
    'image_style' => 'os2web_spotbox_image_tall',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '50';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Link tekst */
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['id'] = 'field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['table'] = 'field_data_field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['field'] = 'field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['alter']['text'] = '<a href=[field_os2web_spotbox_url] title=[field_os2web_spotbox_text]>[field_os2web_spotbox_text]</a>';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_type'] = 'h3';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['empty'] = '[title]';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['hide_alter_empty'] = FALSE;
  /* Field: Content: Egenavne / Stednavne */
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['id'] = 'field_os2web_spotbox_ref_place';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['table'] = 'field_data_field_os2web_spotbox_ref_place';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['field'] = 'field_os2web_spotbox_ref_place';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['delta_offset'] = '0';
  /* Field: Content: Forfrem til */
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['id'] = 'field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['table'] = 'field_data_field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['field'] = 'field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['delta_offset'] = '0';
  /* Field: Content: KL Emneord */
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['id'] = 'field_os2web_spotbox_ref_kle';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['table'] = 'field_data_field_os2web_spotbox_ref_kle';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['field'] = 'field_os2web_spotbox_ref_kle';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['delta_offset'] = '0';
  /* Field: Content: Organisation */
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['id'] = 'field_os2web_spotbox_organizati';
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['table'] = 'field_data_field_os2web_spotbox_organizati';
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['field'] = 'field_os2web_spotbox_organizati';
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['delta_offset'] = '0';
  /* Field: Content: Politik */
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['id'] = 'field_os2web_spotbox_politics';
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['table'] = 'field_data_field_os2web_spotbox_politics';
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['field'] = 'field_os2web_spotbox_politics';
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['delta_offset'] = '0';
  /* Field: Content: Portalkategori */
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['id'] = 'field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['table'] = 'field_data_field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['field'] = 'field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['exclude'] = TRUE;
  /* Field: Content: Stikord */
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['id'] = 'field_os2web_spotbox_editor_tags';
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['table'] = 'field_data_field_os2web_spotbox_editor_tags';
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['field'] = 'field_os2web_spotbox_editor_tags';
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'os2web_spotbox_box' => 'os2web_spotbox_box',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['nid_type'] = 'nids';
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'os2web_spotbox_box' => 'os2web_spotbox_box',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Højt billede (field_os2web_spotbox_image_tall:fid) */
  $handler->display->display_options['filters']['field_os2web_spotbox_image_tall_fid']['id'] = 'field_os2web_spotbox_image_tall_fid';
  $handler->display->display_options['filters']['field_os2web_spotbox_image_tall_fid']['table'] = 'field_data_field_os2web_spotbox_image_tall';
  $handler->display->display_options['filters']['field_os2web_spotbox_image_tall_fid']['field'] = 'field_os2web_spotbox_image_tall_fid';
  $handler->display->display_options['filters']['field_os2web_spotbox_image_tall_fid']['operator'] = 'not empty';
  /* Filter criterion: Content: Video (field_os2web_spotbox_video:fid) */
  $handler->display->display_options['filters']['field_os2web_spotbox_video_fid']['id'] = 'field_os2web_spotbox_video_fid';
  $handler->display->display_options['filters']['field_os2web_spotbox_video_fid']['table'] = 'field_data_field_os2web_spotbox_video';
  $handler->display->display_options['filters']['field_os2web_spotbox_video_fid']['field'] = 'field_os2web_spotbox_video_fid';
  $handler->display->display_options['filters']['field_os2web_spotbox_video_fid']['operator'] = 'empty';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'user',
      'context' => 'entity:user.uid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'ID på Spotboxe',
    ),
  );

  /* Display: Spotboxe / forside - Video */
  $handler = $view->new_display('panel_pane', 'Spotboxe / forside - Video', 'panel_pane_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'spotbox spotbox-video';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'spotbox-row-video';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['link_class'] = 'redigerlink';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['id'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['table'] = 'field_data_field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['field'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['element_label_colon'] = FALSE;
  /* Field: Content: Indhold */
  $handler->display->display_options['fields']['body_1']['id'] = 'body_1';
  $handler->display->display_options['fields']['body_1']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_1']['field'] = 'body';
  $handler->display->display_options['fields']['body_1']['label'] = '';
  $handler->display->display_options['fields']['body_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body_1']['alter']['text'] = '[body_1-value]';
  $handler->display->display_options['fields']['body_1']['alter']['max_length'] = '180';
  $handler->display->display_options['fields']['body_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body_1']['element_label_colon'] = FALSE;
  /* Field: Content: Link tekst */
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['id'] = 'field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['table'] = 'field_data_field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['field'] = 'field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_type'] = 'h4';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_default_classes'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title_1']['element_class'] = 'pane-title';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<div class="video-text"><a href=[field_os2web_spotbox_url] title=[title_1]>[body_1]</a>
<h4><a href=[field_os2web_spotbox_url] title=[title_1]>[field_os2web_spotbox_text]</a></h4></div>';
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Video */
  $handler->display->display_options['fields']['field_os2web_spotbox_video']['id'] = 'field_os2web_spotbox_video';
  $handler->display->display_options['fields']['field_os2web_spotbox_video']['table'] = 'field_data_field_os2web_spotbox_video';
  $handler->display->display_options['fields']['field_os2web_spotbox_video']['field'] = 'field_os2web_spotbox_video';
  $handler->display->display_options['fields']['field_os2web_spotbox_video']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_video']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_video']['alter']['text'] = '<img src="[field_os2web_spotbox_lead_image]" alt="[title_1]" />
<span class="zoom-icon-video"></span>';
  $handler->display->display_options['fields']['field_os2web_spotbox_video']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_video']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_os2web_spotbox_video']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_os2web_spotbox_video']['settings'] = array(
    'file_view_mode' => 'default',
  );
  /* Field: Content: Billede */
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['id'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['table'] = 'field_data_field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['field'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['text'] = '<img src="[field_os2web_spotbox_lead_image]" alt="[title_1]" />
<span class="zoom-icon-video"></span>';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['link_class'] = 'overlayclass';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['empty'] = '[field_os2web_spotbox_video]';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['settings'] = array(
    'image_style' => 'os2web_spotbox_image_video_front',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['delta_offset'] = '0';
  /* Field: Content: Indhold */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_type'] = 'p';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  /* Field: Content: Egenavne / Stednavne */
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['id'] = 'field_os2web_spotbox_ref_place';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['table'] = 'field_data_field_os2web_spotbox_ref_place';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['field'] = 'field_os2web_spotbox_ref_place';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['delta_offset'] = '0';
  /* Field: Content: Forfrem til */
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['id'] = 'field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['table'] = 'field_data_field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['field'] = 'field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['delta_offset'] = '0';
  /* Field: Content: KL Emneord */
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['id'] = 'field_os2web_spotbox_ref_kle';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['table'] = 'field_data_field_os2web_spotbox_ref_kle';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['field'] = 'field_os2web_spotbox_ref_kle';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['delta_offset'] = '0';
  /* Field: Content: Organisation */
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['id'] = 'field_os2web_spotbox_organizati';
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['table'] = 'field_data_field_os2web_spotbox_organizati';
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['field'] = 'field_os2web_spotbox_organizati';
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['delta_offset'] = '0';
  /* Field: Content: Politik */
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['id'] = 'field_os2web_spotbox_politics';
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['table'] = 'field_data_field_os2web_spotbox_politics';
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['field'] = 'field_os2web_spotbox_politics';
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['delta_offset'] = '0';
  /* Field: Content: Portalkategori */
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['id'] = 'field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['table'] = 'field_data_field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['field'] = 'field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['exclude'] = TRUE;
  /* Field: Content: Stikord */
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['id'] = 'field_os2web_spotbox_editor_tags';
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['table'] = 'field_data_field_os2web_spotbox_editor_tags';
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['field'] = 'field_os2web_spotbox_editor_tags';
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['delta_offset'] = '0';
  /* Field: Global: Contextual Links */
  $handler->display->display_options['fields']['contextual_links']['id'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['table'] = 'views';
  $handler->display->display_options['fields']['contextual_links']['field'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['label'] = '';
  $handler->display->display_options['fields']['contextual_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contextual_links']['fields'] = array(
    'edit_node' => 'edit_node',
    'field_os2web_spotbox_url' => 'field_os2web_spotbox_url',
    'title_1' => 'title_1',
    'field_os2web_spotbox_text' => 'field_os2web_spotbox_text',
    'body_1' => 0,
    'title' => 0,
    'field_os2web_spotbox_video' => 0,
    'field_os2web_spotbox_lead_image' => 0,
    'delta' => 0,
    'body' => 0,
    'field_os2web_spotbox_ref_place' => 0,
    'field_os2web_spotbox_promote_to' => 0,
    'field_os2web_spotbox_ref_kle' => 0,
    'field_os2web_spotbox_organizati' => 0,
    'field_os2web_spotbox_politics' => 0,
    'field_os2web_spotbox_sitestruct' => 0,
    'field_os2web_spotbox_editor_tags' => 0,
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'os2web_spotbox_box' => 'os2web_spotbox_box',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['nid_type'] = 'nids';
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'os2web_spotbox_box' => 'os2web_spotbox_box',
  );
  /* Filter criterion: Content: Forfrem til (field_os2web_spotbox_promote_to) */
  $handler->display->display_options['filters']['field_os2web_spotbox_promote_to_tid']['id'] = 'field_os2web_spotbox_promote_to_tid';
  $handler->display->display_options['filters']['field_os2web_spotbox_promote_to_tid']['table'] = 'field_data_field_os2web_spotbox_promote_to';
  $handler->display->display_options['filters']['field_os2web_spotbox_promote_to_tid']['field'] = 'field_os2web_spotbox_promote_to_tid';
  $handler->display->display_options['filters']['field_os2web_spotbox_promote_to_tid']['value'] = array(
    5800 => '5800',
    5801 => '5801',
  );
  $handler->display->display_options['filters']['field_os2web_spotbox_promote_to_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_os2web_spotbox_promote_to_tid']['vocabulary'] = 'os2web_base_tax_promoteto';
  $handler->display->display_options['filters']['field_os2web_spotbox_promote_to_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Video (field_os2web_spotbox_video:fid) */
  $handler->display->display_options['filters']['field_os2web_spotbox_video_fid']['id'] = 'field_os2web_spotbox_video_fid';
  $handler->display->display_options['filters']['field_os2web_spotbox_video_fid']['table'] = 'field_data_field_os2web_spotbox_video';
  $handler->display->display_options['filters']['field_os2web_spotbox_video_fid']['field'] = 'field_os2web_spotbox_video_fid';
  $handler->display->display_options['filters']['field_os2web_spotbox_video_fid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_os2web_spotbox_video_fid']['expose']['operator_id'] = 'field_os2web_spotbox_video_fid_op';
  $handler->display->display_options['filters']['field_os2web_spotbox_video_fid']['expose']['label'] = 'Video (field_os2web_spotbox_video:fid)';
  $handler->display->display_options['filters']['field_os2web_spotbox_video_fid']['expose']['operator'] = 'field_os2web_spotbox_video_fid_op';
  $handler->display->display_options['filters']['field_os2web_spotbox_video_fid']['expose']['identifier'] = 'field_os2web_spotbox_video_fid';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'user',
      'context' => 'entity:user.uid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Indhold: Nid',
    ),
  );

  /* Display: Blok - Spotbox node */
  $handler = $view->new_display('block', 'Blok - Spotbox node', 'block_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['id'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['table'] = 'field_data_field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['field'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Indhold */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_type'] = 'p';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  /* Field: Content: Billede */
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['id'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['table'] = 'field_data_field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['field'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['text'] = '<a href=[field_os2web_spotbox_url] title=[title_1]><img src="[field_os2web_spotbox_lead_image]" alt="[title_1]" /></a>';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['empty'] = '<div class="spotbox_no_picture"><div class="spotbox_no_picture_text"><a href=[field_os2web_spotbox_url]>[body]</a></div></div>';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['settings'] = array(
    'image_style' => 'os2web_spotbox_image_right',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a href=[field_os2web_spotbox_url] title=[title_1]>[title]</a>';
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_class'] = 'hest';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Link tekst */
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['id'] = 'field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['table'] = 'field_data_field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['field'] = 'field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_type'] = 'h4';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_default_classes'] = FALSE;
  /* Field: Content: Egenavne / Stednavne */
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['id'] = 'field_os2web_spotbox_ref_place';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['table'] = 'field_data_field_os2web_spotbox_ref_place';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['field'] = 'field_os2web_spotbox_ref_place';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['delta_offset'] = '0';
  /* Field: Content: Forfrem til */
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['id'] = 'field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['table'] = 'field_data_field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['field'] = 'field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['delta_offset'] = '0';
  /* Field: Content: KL Emneord */
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['id'] = 'field_os2web_spotbox_ref_kle';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['table'] = 'field_data_field_os2web_spotbox_ref_kle';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['field'] = 'field_os2web_spotbox_ref_kle';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['delta_offset'] = '0';
  /* Field: Content: Organisation */
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['id'] = 'field_os2web_spotbox_organizati';
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['table'] = 'field_data_field_os2web_spotbox_organizati';
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['field'] = 'field_os2web_spotbox_organizati';
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['delta_offset'] = '0';
  /* Field: Content: Politik */
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['id'] = 'field_os2web_spotbox_politics';
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['table'] = 'field_data_field_os2web_spotbox_politics';
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['field'] = 'field_os2web_spotbox_politics';
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['delta_offset'] = '0';
  /* Field: Content: Portalkategori */
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['id'] = 'field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['table'] = 'field_data_field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['field'] = 'field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['exclude'] = TRUE;
  /* Field: Content: Stikord */
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['id'] = 'field_os2web_spotbox_editor_tags';
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['table'] = 'field_data_field_os2web_spotbox_editor_tags';
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['field'] = 'field_os2web_spotbox_editor_tags';
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['delta_offset'] = '0';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Portalkategori (field_os2web_spotbox_sitestruct) */
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['id'] = 'field_os2web_spotbox_sitestruct_tid';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['table'] = 'field_data_field_os2web_spotbox_sitestruct';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['field'] = 'field_os2web_spotbox_sitestruct_tid';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['default_argument_options']['node'] = TRUE;
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['default_argument_options']['limit'] = TRUE;
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['default_argument_options']['vocabularies'] = array(
    'os2web_base_tax_site_structure' => 'os2web_base_tax_site_structure',
  );
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['validate_options']['vocabularies'] = array(
    'os2web_base_tax_site_structure' => 'os2web_base_tax_site_structure',
  );
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'os2web_spotbox_box' => 'os2web_spotbox_box',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['nid_type'] = 'nids';
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;

  /* Display: Spotboxe subfront */
  $handler = $view->new_display('panel_pane', 'Spotboxe subfront', 'panel_pane_11');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'spotbox spotbox-subsite-frontpage';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'spotbox-row';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['link_class'] = 'redigerlink';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['id'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['table'] = 'field_data_field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['field'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Indhold */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['element_type'] = 'p';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  /* Field: Content: Billede */
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['id'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['table'] = 'field_data_field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['field'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['text'] = '<a href=[field_os2web_spotbox_url] title=[title_1]><img src="[field_os2web_spotbox_lead_image]" alt="[title_1]" />
<div class="w80bg"><h3>[title_1]</h3>
<div class="spotbody">[body]</div>
</div>
<span class="zoom-icon"></span></a>';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['link_class'] = 'overlayclass';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['element_wrapper_class'] = 'spotbox-subfront';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['empty'] = '<div class="spotbox_no_picture"><div class="spotbox_no_picture_text"><a href=[field_os2web_spotbox_url]>[body]</a></div></div>';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['settings'] = array(
    'image_style' => 'os2web_spotbox_image_300',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '50';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Link tekst */
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['id'] = 'field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['table'] = 'field_data_field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['field'] = 'field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_type'] = 'h4';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_default_classes'] = FALSE;
  /* Field: Content: Portalkategori */
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['id'] = 'field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['table'] = 'field_data_field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['field'] = 'field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['exclude'] = TRUE;
  /* Field: Global: Contextual Links */
  $handler->display->display_options['fields']['contextual_links']['id'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['table'] = 'views';
  $handler->display->display_options['fields']['contextual_links']['field'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['label'] = '';
  $handler->display->display_options['fields']['contextual_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contextual_links']['fields'] = array(
    'edit_node' => 'edit_node',
    'field_os2web_spotbox_url' => 'field_os2web_spotbox_url',
    'title_1' => 0,
    'body' => 0,
    'field_os2web_spotbox_lead_image' => 0,
    'title' => 0,
    'field_os2web_spotbox_text' => 0,
    'field_os2web_spotbox_sitestruct' => 0,
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'os2web_spotbox_box' => 'os2web_spotbox_box',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['nid_type'] = 'nids';
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'os2web_spotbox_box' => 'os2web_spotbox_box',
  );
  /* Filter criterion: Content: Forfrem til (field_os2web_spotbox_promote_to) */
  $handler->display->display_options['filters']['field_os2web_spotbox_promote_to_tid']['id'] = 'field_os2web_spotbox_promote_to_tid';
  $handler->display->display_options['filters']['field_os2web_spotbox_promote_to_tid']['table'] = 'field_data_field_os2web_spotbox_promote_to';
  $handler->display->display_options['filters']['field_os2web_spotbox_promote_to_tid']['field'] = 'field_os2web_spotbox_promote_to_tid';
  $handler->display->display_options['filters']['field_os2web_spotbox_promote_to_tid']['value'] = array(
    5800 => '5800',
  );
  $handler->display->display_options['filters']['field_os2web_spotbox_promote_to_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_os2web_spotbox_promote_to_tid']['vocabulary'] = 'os2web_base_tax_promoteto';
  $handler->display->display_options['filters']['field_os2web_spotbox_promote_to_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Video (field_os2web_spotbox_video:fid) */
  $handler->display->display_options['filters']['field_os2web_spotbox_video_fid']['id'] = 'field_os2web_spotbox_video_fid';
  $handler->display->display_options['filters']['field_os2web_spotbox_video_fid']['table'] = 'field_data_field_os2web_spotbox_video';
  $handler->display->display_options['filters']['field_os2web_spotbox_video_fid']['field'] = 'field_os2web_spotbox_video_fid';
  $handler->display->display_options['filters']['field_os2web_spotbox_video_fid']['operator'] = 'empty';
  /* Filter criterion: Content: Billede (field_os2web_spotbox_lead_image:fid) */
  $handler->display->display_options['filters']['field_os2web_spotbox_lead_image_fid']['id'] = 'field_os2web_spotbox_lead_image_fid';
  $handler->display->display_options['filters']['field_os2web_spotbox_lead_image_fid']['table'] = 'field_data_field_os2web_spotbox_lead_image';
  $handler->display->display_options['filters']['field_os2web_spotbox_lead_image_fid']['field'] = 'field_os2web_spotbox_lead_image_fid';
  $handler->display->display_options['filters']['field_os2web_spotbox_lead_image_fid']['operator'] = 'not empty';
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'user',
      'context' => 'entity:user.uid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Indhold: Nid',
    ),
  );

  /* Display: Spotboxe / forside - 1 */
  $handler = $view->new_display('panel_pane', 'Spotboxe / forside - 1', 'panel_pane_10');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'spotbox os2web_spotbox_image_spot5';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'spotbox-row';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['link_class'] = 'redigerlink';
  $handler->display->display_options['fields']['edit_node']['element_type'] = '0';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['id'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['table'] = 'field_data_field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['field'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['alter']['max_length'] = '35';
  $handler->display->display_options['fields']['title_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title_1']['element_class'] = 'pane-title';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Indhold */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['element_type'] = 'p';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  /* Field: Content: Link tekst */
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['id'] = 'field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['table'] = 'field_data_field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['field'] = 'field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_type'] = 'h3';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['empty'] = '[title]';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['hide_alter_empty'] = FALSE;
  /* Field: Content: Billede */
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['id'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['table'] = 'field_data_field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['field'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['text'] = '<a href=[field_os2web_spotbox_url] title=[title_1]><img src="[field_os2web_spotbox_lead_image]" alt="[title_1]" />
<div class="spotbody">[body]</div>
<span class="zoom-icon"></span></a>';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['link_class'] = 'overlayclass';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['empty'] = '<div class="spotbox_no_picture"><div class="spotbox_no_picture_text"><a href=[field_os2web_spotbox_url]>[body]</a></div></div>';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['settings'] = array(
    'image_style' => 'os2web_spotbox_image_spot5',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['delta_offset'] = '0';
  /* Field: Content: Stort billede */
  $handler->display->display_options['fields']['field_os2web_spotbox_big_image']['id'] = 'field_os2web_spotbox_big_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_big_image']['table'] = 'field_data_field_os2web_spotbox_big_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_big_image']['field'] = 'field_os2web_spotbox_big_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_big_image']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_big_image']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_big_image']['alter']['text'] = '<a href=[field_os2web_spotbox_url] title=[title_1]>[field_os2web_spotbox_big_image]
<div class="spotbody">[body]</div>
<span class="zoom-icon"></span></a>



';
  $handler->display->display_options['fields']['field_os2web_spotbox_big_image']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['field_os2web_spotbox_big_image']['alter']['link_class'] = 'overlayclass';
  $handler->display->display_options['fields']['field_os2web_spotbox_big_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_big_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_big_image']['empty'] = '<div class="spotbox_no_picture"><div class="spotbox_no_picture_text"><a href=[field_os2web_spotbox_url]>[body]</a></div></div>';
  $handler->display->display_options['fields']['field_os2web_spotbox_big_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_os2web_spotbox_big_image']['settings'] = array(
    'image_style' => 'os2web_spotbox_image_spot5',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '50';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Egenavne / Stednavne */
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['id'] = 'field_os2web_spotbox_ref_place';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['table'] = 'field_data_field_os2web_spotbox_ref_place';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['field'] = 'field_os2web_spotbox_ref_place';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['delta_offset'] = '0';
  /* Field: Content: Forfrem til */
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['id'] = 'field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['table'] = 'field_data_field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['field'] = 'field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['delta_offset'] = '0';
  /* Field: Content: KL Emneord */
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['id'] = 'field_os2web_spotbox_ref_kle';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['table'] = 'field_data_field_os2web_spotbox_ref_kle';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['field'] = 'field_os2web_spotbox_ref_kle';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['delta_offset'] = '0';
  /* Field: Content: Organisation */
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['id'] = 'field_os2web_spotbox_organizati';
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['table'] = 'field_data_field_os2web_spotbox_organizati';
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['field'] = 'field_os2web_spotbox_organizati';
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['delta_offset'] = '0';
  /* Field: Content: Politik */
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['id'] = 'field_os2web_spotbox_politics';
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['table'] = 'field_data_field_os2web_spotbox_politics';
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['field'] = 'field_os2web_spotbox_politics';
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['delta_offset'] = '0';
  /* Field: Content: Portalkategori */
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['id'] = 'field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['table'] = 'field_data_field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['field'] = 'field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['exclude'] = TRUE;
  /* Field: Content: Stikord */
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['id'] = 'field_os2web_spotbox_editor_tags';
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['table'] = 'field_data_field_os2web_spotbox_editor_tags';
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['field'] = 'field_os2web_spotbox_editor_tags';
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['delta_offset'] = '0';
  /* Field: Global: Contextual Links */
  $handler->display->display_options['fields']['contextual_links']['id'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['table'] = 'views';
  $handler->display->display_options['fields']['contextual_links']['field'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['label'] = '';
  $handler->display->display_options['fields']['contextual_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contextual_links']['fields'] = array(
    'edit_node' => 'edit_node',
    'field_os2web_spotbox_url' => 'field_os2web_spotbox_url',
    'title_1' => 'title_1',
    'field_os2web_spotbox_text' => 'field_os2web_spotbox_text',
    'body' => 0,
    'field_os2web_spotbox_lead_image' => 0,
    'title' => 0,
    'field_os2web_spotbox_ref_place' => 0,
    'field_os2web_spotbox_promote_to' => 0,
    'field_os2web_spotbox_ref_kle' => 0,
    'field_os2web_spotbox_organizati' => 0,
    'field_os2web_spotbox_politics' => 0,
    'field_os2web_spotbox_sitestruct' => 0,
    'field_os2web_spotbox_editor_tags' => 0,
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'os2web_spotbox_box' => 'os2web_spotbox_box',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['nid_type'] = 'nids';
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'os2web_spotbox_box' => 'os2web_spotbox_box',
  );
  /* Filter criterion: Content: Forfrem til (field_os2web_spotbox_promote_to) */
  $handler->display->display_options['filters']['field_os2web_spotbox_promote_to_tid']['id'] = 'field_os2web_spotbox_promote_to_tid';
  $handler->display->display_options['filters']['field_os2web_spotbox_promote_to_tid']['table'] = 'field_data_field_os2web_spotbox_promote_to';
  $handler->display->display_options['filters']['field_os2web_spotbox_promote_to_tid']['field'] = 'field_os2web_spotbox_promote_to_tid';
  $handler->display->display_options['filters']['field_os2web_spotbox_promote_to_tid']['value'] = array(
    5800 => '5800',
  );
  $handler->display->display_options['filters']['field_os2web_spotbox_promote_to_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_os2web_spotbox_promote_to_tid']['vocabulary'] = 'os2web_base_tax_promoteto';
  $handler->display->display_options['filters']['field_os2web_spotbox_promote_to_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Video (field_os2web_spotbox_video:fid) */
  $handler->display->display_options['filters']['field_os2web_spotbox_video_fid']['id'] = 'field_os2web_spotbox_video_fid';
  $handler->display->display_options['filters']['field_os2web_spotbox_video_fid']['table'] = 'field_data_field_os2web_spotbox_video';
  $handler->display->display_options['filters']['field_os2web_spotbox_video_fid']['field'] = 'field_os2web_spotbox_video_fid';
  $handler->display->display_options['filters']['field_os2web_spotbox_video_fid']['operator'] = 'empty';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'user',
      'context' => 'entity:user.uid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'ID på Spotboxe',
    ),
  );

  /* Display: Spotboxe sektion - 1 */
  $handler = $view->new_display('panel_pane', 'Spotboxe sektion - 1', 'panel_pane_9');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'spotbox spotbox-sektion-1';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'spotbox-row grid-3 alpha omega';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['link_class'] = 'redigerlink';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['id'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['table'] = 'field_data_field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['field'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title_1']['element_class'] = 'pane-title';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Indhold */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_type'] = 'p';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  /* Field: Content: Billede */
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['id'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['table'] = 'field_data_field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['field'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['text'] = '<a href=[field_os2web_spotbox_url] title=[title_1]>[field_os2web_spotbox_lead_image]
<span class="zoom-icon"></span></a>';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['link_class'] = 'overlayclass';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['empty'] = '<div class="spotbox_no_picture"><div class="spotbox_no_picture_text"><a href=[field_os2web_spotbox_url]>[body]</a></div></div>';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['type'] = 'slideshow';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['delta_offset'] = '0';
  /* Field: Content: Fokus sektionsforside */
  $handler->display->display_options['fields']['field_os2web_spotbox_focus_sect']['id'] = 'field_os2web_spotbox_focus_sect';
  $handler->display->display_options['fields']['field_os2web_spotbox_focus_sect']['table'] = 'field_data_field_os2web_spotbox_focus_sect';
  $handler->display->display_options['fields']['field_os2web_spotbox_focus_sect']['field'] = 'field_os2web_spotbox_focus_sect';
  $handler->display->display_options['fields']['field_os2web_spotbox_focus_sect']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_focus_sect']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_focus_sect']['alter']['text'] = '<img src="[field_os2web_spotbox_focus_sect] " alt="[title_1]" />
<span class="zoom-icon"></span>';
  $handler->display->display_options['fields']['field_os2web_spotbox_focus_sect']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_focus_sect']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['field_os2web_spotbox_focus_sect']['alter']['link_class'] = 'overlayclass';
  $handler->display->display_options['fields']['field_os2web_spotbox_focus_sect']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_focus_sect']['empty'] = '<div class="spotbox_no_picture"><div class="spotbox_no_picture_text"><a href=[field_os2web_spotbox_url]>[body]</a></div></div>';
  $handler->display->display_options['fields']['field_os2web_spotbox_focus_sect']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_os2web_spotbox_focus_sect']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_focus_sect']['settings'] = array(
    'image_style' => 'sektion-160',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a href=[field_os2web_spotbox_url] title=[title]>[title]</a>';
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Link tekst */
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['id'] = 'field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['table'] = 'field_data_field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['field'] = 'field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_type'] = 'h4';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_default_classes'] = FALSE;
  /* Field: Content: Egenavne / Stednavne */
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['id'] = 'field_os2web_spotbox_ref_place';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['table'] = 'field_data_field_os2web_spotbox_ref_place';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['field'] = 'field_os2web_spotbox_ref_place';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['delta_offset'] = '0';
  /* Field: Content: Forfrem til */
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['id'] = 'field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['table'] = 'field_data_field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['field'] = 'field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['delta_offset'] = '0';
  /* Field: Content: KL Emneord */
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['id'] = 'field_os2web_spotbox_ref_kle';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['table'] = 'field_data_field_os2web_spotbox_ref_kle';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['field'] = 'field_os2web_spotbox_ref_kle';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['delta_offset'] = '0';
  /* Field: Content: Organisation */
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['id'] = 'field_os2web_spotbox_organizati';
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['table'] = 'field_data_field_os2web_spotbox_organizati';
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['field'] = 'field_os2web_spotbox_organizati';
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['delta_offset'] = '0';
  /* Field: Content: Politik */
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['id'] = 'field_os2web_spotbox_politics';
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['table'] = 'field_data_field_os2web_spotbox_politics';
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['field'] = 'field_os2web_spotbox_politics';
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['delta_offset'] = '0';
  /* Field: Content: Portalkategori */
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['id'] = 'field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['table'] = 'field_data_field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['field'] = 'field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['exclude'] = TRUE;
  /* Field: Content: Stikord */
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['id'] = 'field_os2web_spotbox_editor_tags';
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['table'] = 'field_data_field_os2web_spotbox_editor_tags';
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['field'] = 'field_os2web_spotbox_editor_tags';
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Portalkategori (field_os2web_spotbox_sitestruct) */
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['id'] = 'field_os2web_spotbox_sitestruct_tid';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['table'] = 'field_data_field_os2web_spotbox_sitestruct';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['field'] = 'field_os2web_spotbox_sitestruct_tid';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['default_argument_options']['node'] = TRUE;
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['default_argument_options']['limit'] = TRUE;
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['default_argument_options']['vocabularies'] = array(
    'os2web_base_tax_site_structure' => 'os2web_base_tax_site_structure',
  );
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['validate_options']['vocabularies'] = array(
    'os2web_base_tax_site_structure' => 'os2web_base_tax_site_structure',
  );
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'os2web_spotbox_box' => 'os2web_spotbox_box',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['nid_type'] = 'nids';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'os2web_spotbox_box' => 'os2web_spotbox_box',
  );

  /* Display: Spotboxe sektion - 3 */
  $handler = $view->new_display('panel_pane', 'Spotboxe sektion - 3', 'panel_pane_8');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'spotbox spotbox-horisontal-3';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'spotbox-row grid-3 alpha omega';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['link_class'] = 'redigerlink';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['id'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['table'] = 'field_data_field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['field'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title_1']['element_class'] = 'pane-title';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Indhold */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_type'] = 'p';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  /* Field: Content: Billede */
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['id'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['table'] = 'field_data_field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['field'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['text'] = '[field_os2web_spotbox_lead_image]
<span class="zoom-icon"></span>';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['link_class'] = 'overlayclass';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['empty'] = '<div class="spotbox_no_picture"><div class="spotbox_no_picture_text"><a href=[field_os2web_spotbox_url]>[body]</a></div></div>';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['settings'] = array(
    'image_style' => 'os2web_spotbox_image_spot5',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '60';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Billede (field_os2web_spotbox_lead_image:delta) */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'field_data_field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
  $handler->display->display_options['fields']['delta']['label'] = '';
  $handler->display->display_options['fields']['delta']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delta']['element_label_colon'] = FALSE;
  /* Field: Content: Link tekst */
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['id'] = 'field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['table'] = 'field_data_field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['field'] = 'field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_type'] = 'h4';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_default_classes'] = FALSE;
  /* Field: Content: Egenavne / Stednavne */
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['id'] = 'field_os2web_spotbox_ref_place';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['table'] = 'field_data_field_os2web_spotbox_ref_place';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['field'] = 'field_os2web_spotbox_ref_place';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['delta_offset'] = '0';
  /* Field: Content: Forfrem til */
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['id'] = 'field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['table'] = 'field_data_field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['field'] = 'field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['delta_offset'] = '0';
  /* Field: Content: KL Emneord */
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['id'] = 'field_os2web_spotbox_ref_kle';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['table'] = 'field_data_field_os2web_spotbox_ref_kle';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['field'] = 'field_os2web_spotbox_ref_kle';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['delta_offset'] = '0';
  /* Field: Content: Organisation */
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['id'] = 'field_os2web_spotbox_organizati';
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['table'] = 'field_data_field_os2web_spotbox_organizati';
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['field'] = 'field_os2web_spotbox_organizati';
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['delta_offset'] = '0';
  /* Field: Content: Politik */
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['id'] = 'field_os2web_spotbox_politics';
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['table'] = 'field_data_field_os2web_spotbox_politics';
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['field'] = 'field_os2web_spotbox_politics';
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['delta_offset'] = '0';
  /* Field: Content: Portalkategori */
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['id'] = 'field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['table'] = 'field_data_field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['field'] = 'field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['exclude'] = TRUE;
  /* Field: Content: Stikord */
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['id'] = 'field_os2web_spotbox_editor_tags';
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['table'] = 'field_data_field_os2web_spotbox_editor_tags';
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['field'] = 'field_os2web_spotbox_editor_tags';
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Portalkategori (field_os2web_spotbox_sitestruct) */
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['id'] = 'field_os2web_spotbox_sitestruct_tid';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['table'] = 'field_data_field_os2web_spotbox_sitestruct';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['field'] = 'field_os2web_spotbox_sitestruct_tid';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['default_argument_options']['node'] = TRUE;
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['default_argument_options']['limit'] = TRUE;
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['default_argument_options']['vocabularies'] = array(
    'os2web_base_tax_site_structure' => 'os2web_base_tax_site_structure',
  );
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['validate_options']['vocabularies'] = array(
    'os2web_base_tax_site_structure' => 'os2web_base_tax_site_structure',
  );
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'os2web_spotbox_box' => 'os2web_spotbox_box',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['nid_type'] = 'nids';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'os2web_spotbox_box' => 'os2web_spotbox_box',
  );

  /* Display: Spotboxe portal - 3 */
  $handler = $view->new_display('panel_pane', 'Spotboxe portal - 3', 'panel_pane_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'spotbox spotbox-horisontal-3';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'spotbox-row grid-3 alpha omega';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['link_class'] = 'redigerlink';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['id'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['table'] = 'field_data_field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['field'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title_1']['element_class'] = 'pane-title';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Indhold */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_type'] = 'p';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  /* Field: Content: Billede */
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['id'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['table'] = 'field_data_field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['field'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['text'] = '<a href=[field_os2web_spotbox_url] title=[title_1]>[field_os2web_spotbox_lead_image]
<span class="zoom-icon"></span></a>';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['link_class'] = 'overlayclass';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['empty'] = '<div class="spotbox_no_picture"><div class="spotbox_no_picture_text"><a href=[field_os2web_spotbox_url]>[body]</a></div></div>';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['type'] = 'slideshow';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['settings'] = array(
    'image_style' => 'os2web_spotbox_image_right',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a href=[field_os2web_spotbox_url] title=[title_1]>[title]</a>';
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Billede (field_os2web_spotbox_lead_image:delta) */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'field_data_field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
  $handler->display->display_options['fields']['delta']['label'] = '';
  $handler->display->display_options['fields']['delta']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delta']['element_label_colon'] = FALSE;
  /* Field: Content: Link tekst */
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['id'] = 'field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['table'] = 'field_data_field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['field'] = 'field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_type'] = 'h4';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_default_classes'] = FALSE;
  /* Field: Content: Egenavne / Stednavne */
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['id'] = 'field_os2web_spotbox_ref_place';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['table'] = 'field_data_field_os2web_spotbox_ref_place';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['field'] = 'field_os2web_spotbox_ref_place';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['delta_offset'] = '0';
  /* Field: Content: Forfrem til */
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['id'] = 'field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['table'] = 'field_data_field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['field'] = 'field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['delta_offset'] = '0';
  /* Field: Content: KL Emneord */
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['id'] = 'field_os2web_spotbox_ref_kle';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['table'] = 'field_data_field_os2web_spotbox_ref_kle';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['field'] = 'field_os2web_spotbox_ref_kle';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['delta_offset'] = '0';
  /* Field: Content: Organisation */
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['id'] = 'field_os2web_spotbox_organizati';
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['table'] = 'field_data_field_os2web_spotbox_organizati';
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['field'] = 'field_os2web_spotbox_organizati';
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['delta_offset'] = '0';
  /* Field: Content: Politik */
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['id'] = 'field_os2web_spotbox_politics';
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['table'] = 'field_data_field_os2web_spotbox_politics';
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['field'] = 'field_os2web_spotbox_politics';
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['delta_offset'] = '0';
  /* Field: Content: Portalkategori */
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['id'] = 'field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['table'] = 'field_data_field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['field'] = 'field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['exclude'] = TRUE;
  /* Field: Content: Stikord */
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['id'] = 'field_os2web_spotbox_editor_tags';
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['table'] = 'field_data_field_os2web_spotbox_editor_tags';
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['field'] = 'field_os2web_spotbox_editor_tags';
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['term_page'] = FALSE;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'os2web_spotbox_box' => 'os2web_spotbox_box',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['nid_type'] = 'nids';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Portalkategori (field_os2web_spotbox_sitestruct) */
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['id'] = 'field_os2web_spotbox_sitestruct_tid';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['table'] = 'field_data_field_os2web_spotbox_sitestruct';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['field'] = 'field_os2web_spotbox_sitestruct_tid';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['default_argument_options']['limit'] = TRUE;
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['default_argument_options']['vocabularies'] = array(
    'os2web_base_tax_site_structure' => 'os2web_base_tax_site_structure',
  );
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['validate_options']['vocabularies'] = array(
    'os2web_base_tax_site_structure' => 'os2web_base_tax_site_structure',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'os2web_spotbox_box' => 'os2web_spotbox_box',
  );
  $handler->display->display_options['argument_input'] = array(
    'field_os2web_spotbox_sitestruct_tid' => array(
      'type' => 'none',
      'context' => 'entity:user.uid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Indhold: Portalkategori (field_os2web_spotbox_sitestruct)',
    ),
    'nid' => array(
      'type' => 'user',
      'context' => 'entity:user.uid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Indhold: Nid',
    ),
  );

  /* Display: Spotboxe portal - 2 */
  $handler = $view->new_display('panel_pane', 'Spotboxe portal - 2', 'panel_pane_7');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'spotbox spotbox-horisontal';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'spotbox-row grid-3';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['link_class'] = 'redigerlink';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['id'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['table'] = 'field_data_field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['field'] = 'field_os2web_spotbox_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_url']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Indhold */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_type'] = 'p';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  /* Field: Content: Billede */
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['id'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['table'] = 'field_data_field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['field'] = 'field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['text'] = '<a href=[field_os2web_spotbox_url] title=[title_1]><img src="[field_os2web_spotbox_lead_image]" alt="[title_1]" />
<span class="zoom-icon"></span></a>';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['alter']['link_class'] = 'overlayclass';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['empty'] = '<div class="spotbox_no_picture"><div class="spotbox_no_picture_text"><a href=[field_os2web_spotbox_url]>[body]</a></div></div>';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['settings'] = array(
    'image_style' => 'os2web_spotbox_image_right',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_os2web_spotbox_lead_image']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a href=[field_os2web_spotbox_url] title=[title]>[title]</a>';
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_os2web_spotbox_url]';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Billede (field_os2web_spotbox_lead_image:delta) */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'field_data_field_os2web_spotbox_lead_image';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
  $handler->display->display_options['fields']['delta']['label'] = '';
  $handler->display->display_options['fields']['delta']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delta']['element_label_colon'] = FALSE;
  /* Field: Content: Link tekst */
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['id'] = 'field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['table'] = 'field_data_field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['field'] = 'field_os2web_spotbox_text';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_type'] = 'h4';
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_spotbox_text']['element_default_classes'] = FALSE;
  /* Field: Content: Egenavne / Stednavne */
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['id'] = 'field_os2web_spotbox_ref_place';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['table'] = 'field_data_field_os2web_spotbox_ref_place';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['field'] = 'field_os2web_spotbox_ref_place';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_place']['delta_offset'] = '0';
  /* Field: Content: Forfrem til */
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['id'] = 'field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['table'] = 'field_data_field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['field'] = 'field_os2web_spotbox_promote_to';
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_promote_to']['delta_offset'] = '0';
  /* Field: Content: KL Emneord */
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['id'] = 'field_os2web_spotbox_ref_kle';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['table'] = 'field_data_field_os2web_spotbox_ref_kle';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['field'] = 'field_os2web_spotbox_ref_kle';
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_ref_kle']['delta_offset'] = '0';
  /* Field: Content: Organisation */
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['id'] = 'field_os2web_spotbox_organizati';
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['table'] = 'field_data_field_os2web_spotbox_organizati';
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['field'] = 'field_os2web_spotbox_organizati';
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_organizati']['delta_offset'] = '0';
  /* Field: Content: Politik */
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['id'] = 'field_os2web_spotbox_politics';
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['table'] = 'field_data_field_os2web_spotbox_politics';
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['field'] = 'field_os2web_spotbox_politics';
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_politics']['delta_offset'] = '0';
  /* Field: Content: Portalkategori */
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['id'] = 'field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['table'] = 'field_data_field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['field'] = 'field_os2web_spotbox_sitestruct';
  $handler->display->display_options['fields']['field_os2web_spotbox_sitestruct']['exclude'] = TRUE;
  /* Field: Content: Stikord */
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['id'] = 'field_os2web_spotbox_editor_tags';
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['table'] = 'field_data_field_os2web_spotbox_editor_tags';
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['field'] = 'field_os2web_spotbox_editor_tags';
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_spotbox_editor_tags']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Portalkategori (field_os2web_spotbox_sitestruct) */
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['id'] = 'field_os2web_spotbox_sitestruct_tid';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['table'] = 'field_data_field_os2web_spotbox_sitestruct';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['field'] = 'field_os2web_spotbox_sitestruct_tid';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['default_argument_options']['node'] = TRUE;
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['default_argument_options']['vocabularies'] = array(
    'os2web_base_tax_site_structure' => 'os2web_base_tax_site_structure',
  );
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_os2web_spotbox_sitestruct_tid']['validate_options']['vocabularies'] = array(
    'os2web_base_tax_site_structure' => 'os2web_base_tax_site_structure',
  );
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'os2web_spotbox_box' => 'os2web_spotbox_box',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['nid_type'] = 'nids';
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'os2web_spotbox_box' => 'os2web_spotbox_box',
  );
  /* Filter criterion: Content: Forfrem til (field_os2web_spotbox_promote_to) */
  $handler->display->display_options['filters']['field_os2web_spotbox_promote_to_tid']['id'] = 'field_os2web_spotbox_promote_to_tid';
  $handler->display->display_options['filters']['field_os2web_spotbox_promote_to_tid']['table'] = 'field_data_field_os2web_spotbox_promote_to';
  $handler->display->display_options['filters']['field_os2web_spotbox_promote_to_tid']['field'] = 'field_os2web_spotbox_promote_to_tid';
  $handler->display->display_options['filters']['field_os2web_spotbox_promote_to_tid']['value'] = array(
    5800 => '5800',
    5801 => '5801',
  );
  $handler->display->display_options['filters']['field_os2web_spotbox_promote_to_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_os2web_spotbox_promote_to_tid']['vocabulary'] = 'os2web_base_tax_promoteto';
  $handler->display->display_options['filters']['field_os2web_spotbox_promote_to_tid']['hierarchy'] = 1;
  $translatables['os2web_spotbox_view_spots'] = array(
    t('Master'),
    t('Spotboxe'),
    t('mere'),
    t('Udfør'),
    t('Gendan'),
    t('Sortér efter'),
    t('Stigende'),
    t('Faldende'),
    t('Antal elementer'),
    t('- Alle -'),
    t('Forskydning'),
    t('« første'),
    t('‹ forrige'),
    t('næste ›'),
    t('sidste »'),
    t('<img src="[field_os2web_spotbox_lead_image]" alt="[title_1]" />'),
    t('Egenavne / Stednavne'),
    t('Forfrem til'),
    t('KL Emneord'),
    t('Organisation'),
    t('Politik'),
    t('Portalkategori'),
    t('Stikord'),
    t('Alle'),
    t('Page'),
    t('more'),
    t('Spotbox på node'),
    t('<a href=[field_os2web_spotbox_url] title=[title] ><img src="[field_os2web_spotbox_lead_image]" alt="[title_1]" /></a>'),
    t('<div class="spotbox_no_picture"><div class="spotbox_no_picture_text"><a href=[field_os2web_spotbox_url]>[body]</a></div></div>'),
    t('<a href=[field_os2web_spotbox_url] title=[title]>[title]</a>'),
    t('View panes'),
    t('Spotboxe / forside - 2tv'),
    t('<a href=[field_os2web_spotbox_url] title=[title_1]>[field_os2web_spotbox_lead_image]
<span class="zoom-icon"></span></a>'),
    t('<a href=[field_os2web_spotbox_url] title=[field_os2web_spotbox_text]>[field_os2web_spotbox_text]</a>'),
    t('[title]'),
    t('Spotboxe / forside - 2th'),
    t('<a href=[field_os2web_spotbox_url] title=[title_1]><img src="[field_os2web_spotbox_lead_image]" alt="[title_1]" />
<span class="zoom-icon"></span></a>'),
    t('[title_1]'),
    t('<div class="spotbox_no_picture"><div class="spotbox_no_picture_text"><a href=[field_os2web_spotbox_url]  title=[title_1]>[body]</a></div></div>'),
    t('<a href=[field_os2web_spotbox_url] title=[title_1]>[field_os2web_spotbox_text]</a>'),
    t('Spotboxe / forside - Høj'),
    t('Spotboxe / forside - Video'),
    t('[body_1-value]'),
    t('<div class="video-text"><a href=[field_os2web_spotbox_url] title=[title_1]>[body_1]</a>
<h4><a href=[field_os2web_spotbox_url] title=[title_1]>[field_os2web_spotbox_text]</a></h4></div>'),
    t('<img src="[field_os2web_spotbox_lead_image]" alt="[title_1]" />
<span class="zoom-icon-video"></span>'),
    t('[field_os2web_spotbox_video]'),
    t('Video (field_os2web_spotbox_video:fid)'),
    t('Blok - Spotbox node'),
    t('<a href=[field_os2web_spotbox_url] title=[title_1]><img src="[field_os2web_spotbox_lead_image]" alt="[title_1]" /></a>'),
    t('<a href=[field_os2web_spotbox_url] title=[title_1]>[title]</a>'),
    t('Spotboxe subfront'),
    t('<a href=[field_os2web_spotbox_url] title=[title_1]><img src="[field_os2web_spotbox_lead_image]" alt="[title_1]" />
<div class="w80bg"><h3>[title_1]</h3>
<div class="spotbody">[body]</div>
</div>
<span class="zoom-icon"></span></a>'),
    t('Spotboxe / forside - 1'),
    t('<a href=[field_os2web_spotbox_url] title=[title_1]><img src="[field_os2web_spotbox_lead_image]" alt="[title_1]" />
<div class="spotbody">[body]</div>
<span class="zoom-icon"></span></a>'),
    t('<a href=[field_os2web_spotbox_url] title=[title_1]>[field_os2web_spotbox_big_image]
<div class="spotbody">[body]</div>
<span class="zoom-icon"></span></a>



'),
    t('Spotboxe sektion - 1'),
    t('<img src="[field_os2web_spotbox_focus_sect] " alt="[title_1]" />
<span class="zoom-icon"></span>'),
    t('Spotboxe sektion - 3'),
    t('[field_os2web_spotbox_lead_image]
<span class="zoom-icon"></span>'),
    t('.'),
    t(','),
    t('Spotboxe portal - 3'),
    t('Spotboxe portal - 2'),
  );
  $export['os2web_spotbox_view_spots'] = $view;

  return $export;
}

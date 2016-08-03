<?php
/**
 * @file
 * kidneys_misc_features.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function kidneys_misc_features_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'admin_merge_contacts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'redhen_contact';
  $view->human_name = 'Admin: merge contacts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Admin: merge contacts';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Bulk operations: Contact */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'redhen_contact';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::rules_membership_merge_contacts' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Merge Contact',
    ),
  );
  /* Field: Contact: Contact ID */
  $handler->display->display_options['fields']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['table'] = 'redhen_contact';
  $handler->display->display_options['fields']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['contact_id']['alter']['path'] = 'redhen/contact/[contact_id]';
  $handler->display->display_options['fields']['contact_id']['separator'] = '';
  /* Field: Contact: Full name */
  $handler->display->display_options['fields']['full_name']['id'] = 'full_name';
  $handler->display->display_options['fields']['full_name']['table'] = 'views_entity_redhen_contact';
  $handler->display->display_options['fields']['full_name']['field'] = 'full_name';
  $handler->display->display_options['fields']['full_name']['label'] = 'Name';
  $handler->display->display_options['fields']['full_name']['link_to_entity'] = 0;
  /* Filter criterion: Contact: Contact ID */
  $handler->display->display_options['filters']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['filters']['contact_id']['table'] = 'redhen_contact';
  $handler->display->display_options['filters']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['filters']['contact_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['contact_id']['expose']['operator_id'] = 'contact_id_op';
  $handler->display->display_options['filters']['contact_id']['expose']['label'] = 'Contact ID';
  $handler->display->display_options['filters']['contact_id']['expose']['operator'] = 'contact_id_op';
  $handler->display->display_options['filters']['contact_id']['expose']['identifier'] = 'contact_id';
  $handler->display->display_options['filters']['contact_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    9 => 0,
    7 => 0,
    8 => 0,
    11 => 0,
    14 => 0,
    13 => 0,
    15 => 0,
    10 => 0,
    16 => 0,
    17 => 0,
    20 => 0,
    12 => 0,
    19 => 0,
    18 => 0,
    21 => 0,
    22 => 0,
    28 => 0,
    23 => 0,
    24 => 0,
    25 => 0,
    26 => 0,
    27 => 0,
    30 => 0,
    29 => 0,
    31 => 0,
    32 => 0,
    33 => 0,
    34 => 0,
    35 => 0,
  );
  /* Filter criterion: Contact: First name */
  $handler->display->display_options['filters']['first_name']['id'] = 'first_name';
  $handler->display->display_options['filters']['first_name']['table'] = 'redhen_contact';
  $handler->display->display_options['filters']['first_name']['field'] = 'first_name';
  $handler->display->display_options['filters']['first_name']['operator'] = 'word';
  $handler->display->display_options['filters']['first_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['first_name']['expose']['operator_id'] = 'first_name_op';
  $handler->display->display_options['filters']['first_name']['expose']['label'] = 'First name';
  $handler->display->display_options['filters']['first_name']['expose']['operator'] = 'first_name_op';
  $handler->display->display_options['filters']['first_name']['expose']['identifier'] = 'first_name';
  $handler->display->display_options['filters']['first_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    9 => 0,
    7 => 0,
    8 => 0,
    11 => 0,
    14 => 0,
    13 => 0,
    15 => 0,
    10 => 0,
    16 => 0,
    17 => 0,
    20 => 0,
    12 => 0,
    19 => 0,
    18 => 0,
    21 => 0,
    22 => 0,
    28 => 0,
    23 => 0,
    24 => 0,
    25 => 0,
    26 => 0,
    27 => 0,
    30 => 0,
    29 => 0,
    31 => 0,
    32 => 0,
    33 => 0,
    34 => 0,
    35 => 0,
  );
  /* Filter criterion: Contact: Last name */
  $handler->display->display_options['filters']['last_name']['id'] = 'last_name';
  $handler->display->display_options['filters']['last_name']['table'] = 'redhen_contact';
  $handler->display->display_options['filters']['last_name']['field'] = 'last_name';
  $handler->display->display_options['filters']['last_name']['operator'] = 'contains';
  $handler->display->display_options['filters']['last_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['last_name']['expose']['operator_id'] = 'last_name_op';
  $handler->display->display_options['filters']['last_name']['expose']['label'] = 'Last name';
  $handler->display->display_options['filters']['last_name']['expose']['operator'] = 'last_name_op';
  $handler->display->display_options['filters']['last_name']['expose']['identifier'] = 'last_name';
  $handler->display->display_options['filters']['last_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    9 => 0,
    7 => 0,
    8 => 0,
    11 => 0,
    14 => 0,
    13 => 0,
    15 => 0,
    10 => 0,
    16 => 0,
    17 => 0,
    20 => 0,
    12 => 0,
    19 => 0,
    18 => 0,
    21 => 0,
    22 => 0,
    28 => 0,
    23 => 0,
    24 => 0,
    25 => 0,
    26 => 0,
    27 => 0,
    30 => 0,
    29 => 0,
    31 => 0,
    32 => 0,
    33 => 0,
    34 => 0,
    35 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/merge-contacts';
  $translatables['admin_merge_contacts'] = array(
    t('Master'),
    t('Admin: merge contacts'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('- Choose an operation -'),
    t('Merge Contact'),
    t('Contact ID'),
    t('.'),
    t('Name'),
    t('First name'),
    t('Last name'),
    t('Page'),
  );
  $export['admin_merge_contacts'] = $view;

  return $export;
}

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
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: User: Contact User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'redhen_contact_user';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Salesforce Mapping Object: Salesforce Mapping */
  $handler->display->display_options['relationships']['salesforce_mapping_object']['id'] = 'salesforce_mapping_object';
  $handler->display->display_options['relationships']['salesforce_mapping_object']['table'] = 'redhen_contact';
  $handler->display->display_options['relationships']['salesforce_mapping_object']['field'] = 'salesforce_mapping_object';
  /* Field: Bulk operations: Contact */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_redhen_contact';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::rules_membership_merge_contacts' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
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
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  /* Field: User: Last login */
  $handler->display->display_options['fields']['login']['id'] = 'login';
  $handler->display->display_options['fields']['login']['table'] = 'users';
  $handler->display->display_options['fields']['login']['field'] = 'login';
  $handler->display->display_options['fields']['login']['relationship'] = 'uid';
  $handler->display->display_options['fields']['login']['date_format'] = 'long';
  $handler->display->display_options['fields']['login']['second_date_format'] = 'long';
  /* Field: Contact: Dup Key */
  $handler->display->display_options['fields']['field_dup_key']['id'] = 'field_dup_key';
  $handler->display->display_options['fields']['field_dup_key']['table'] = 'field_data_field_dup_key';
  $handler->display->display_options['fields']['field_dup_key']['field'] = 'field_dup_key';
  $handler->display->display_options['fields']['field_dup_key']['element_type'] = '0';
  $handler->display->display_options['fields']['field_dup_key']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_dup_key']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_dup_key']['field_api_classes'] = TRUE;
  /* Field: Salesforce Object Mapping: Salesforce Id */
  $handler->display->display_options['fields']['salesforce_id']['id'] = 'salesforce_id';
  $handler->display->display_options['fields']['salesforce_id']['table'] = 'salesforce_mapping_object';
  $handler->display->display_options['fields']['salesforce_id']['field'] = 'salesforce_id';
  $handler->display->display_options['fields']['salesforce_id']['relationship'] = 'salesforce_mapping_object';
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
  /* Filter criterion: Contact: Email (redhen_contact_email) */
  $handler->display->display_options['filters']['redhen_contact_email_value']['id'] = 'redhen_contact_email_value';
  $handler->display->display_options['filters']['redhen_contact_email_value']['table'] = 'field_data_redhen_contact_email';
  $handler->display->display_options['filters']['redhen_contact_email_value']['field'] = 'redhen_contact_email_value';
  $handler->display->display_options['filters']['redhen_contact_email_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['redhen_contact_email_value']['expose']['operator_id'] = 'redhen_contact_email_value_op';
  $handler->display->display_options['filters']['redhen_contact_email_value']['expose']['label'] = 'Email';
  $handler->display->display_options['filters']['redhen_contact_email_value']['expose']['operator'] = 'redhen_contact_email_value_op';
  $handler->display->display_options['filters']['redhen_contact_email_value']['expose']['identifier'] = 'redhen_contact_email_value';
  $handler->display->display_options['filters']['redhen_contact_email_value']['expose']['remember_roles'] = array(
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
    t('User'),
    t('Salesforce Object'),
    t('- Choose an operation -'),
    t('Merge Contact'),
    t('Contact ID'),
    t('.'),
    t('Name'),
    t('E-mail'),
    t('Last login'),
    t('Dup Key'),
    t('Salesforce Id'),
    t('First name'),
    t('Last name'),
    t('Email'),
    t('Page'),
  );
  $export['admin_merge_contacts'] = $view;

  $view = new view();
  $view->name = 'iga_submission';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'entityform';
  $view->human_name = 'IgA Submission';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<style>
#map {
background-image:url(\'https://api.mapbox.com/styles/v1/mapbox/streets-v10/static/pin-l+000([field_base_geofield_1],[field_base_geofield])/[field_base_geofield_1],[field_base_geofield],15/1000x350@2x?access_token=pk.eyJ1IjoibmtmIiwiYSI6ImNpeXlycHIwdTAwdGozMnBvcHVyb3dsMHUifQ.Ga4ktI5QmMOipTSAG1If7g\')
}

</style>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_iga_closest_center_target_id']['id'] = 'field_iga_closest_center_target_id';
  $handler->display->display_options['relationships']['field_iga_closest_center_target_id']['table'] = 'field_data_field_iga_closest_center';
  $handler->display->display_options['relationships']['field_iga_closest_center_target_id']['field'] = 'field_iga_closest_center_target_id';
  $handler->display->display_options['relationships']['field_iga_closest_center_target_id']['label'] = 'Location';
  /* Relationship: Flags: iga_confirm */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'entityform';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'iga_confirm';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_iga_closest_center_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Address */
  $handler->display->display_options['fields']['field_base_address']['id'] = 'field_base_address';
  $handler->display->display_options['fields']['field_base_address']['table'] = 'field_data_field_base_address';
  $handler->display->display_options['fields']['field_base_address']['field'] = 'field_base_address';
  $handler->display->display_options['fields']['field_base_address']['relationship'] = 'field_iga_closest_center_target_id';
  $handler->display->display_options['fields']['field_base_address']['label'] = '';
  $handler->display->display_options['fields']['field_base_address']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_base_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_base_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_base_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Geofield */
  $handler->display->display_options['fields']['field_base_geofield']['id'] = 'field_base_geofield';
  $handler->display->display_options['fields']['field_base_geofield']['table'] = 'field_data_field_base_geofield';
  $handler->display->display_options['fields']['field_base_geofield']['field'] = 'field_base_geofield';
  $handler->display->display_options['fields']['field_base_geofield']['relationship'] = 'field_iga_closest_center_target_id';
  $handler->display->display_options['fields']['field_base_geofield']['label'] = '';
  $handler->display->display_options['fields']['field_base_geofield']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_base_geofield']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_base_geofield']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_base_geofield']['type'] = 'geofield_lat';
  $handler->display->display_options['fields']['field_base_geofield']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
  );
  /* Field: Content: Geofield */
  $handler->display->display_options['fields']['field_base_geofield_1']['id'] = 'field_base_geofield_1';
  $handler->display->display_options['fields']['field_base_geofield_1']['table'] = 'field_data_field_base_geofield';
  $handler->display->display_options['fields']['field_base_geofield_1']['field'] = 'field_base_geofield';
  $handler->display->display_options['fields']['field_base_geofield_1']['relationship'] = 'field_iga_closest_center_target_id';
  $handler->display->display_options['fields']['field_base_geofield_1']['label'] = '';
  $handler->display->display_options['fields']['field_base_geofield_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_base_geofield_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_base_geofield_1']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_base_geofield_1']['type'] = 'geofield_lon';
  $handler->display->display_options['fields']['field_base_geofield_1']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
  );
  /* Field: Field: Address */
  $handler->display->display_options['fields']['field_base_address_1']['id'] = 'field_base_address_1';
  $handler->display->display_options['fields']['field_base_address_1']['table'] = 'field_data_field_base_address';
  $handler->display->display_options['fields']['field_base_address_1']['field'] = 'field_base_address';
  $handler->display->display_options['fields']['field_base_address_1']['relationship'] = 'field_iga_closest_center_target_id';
  $handler->display->display_options['fields']['field_base_address_1']['label'] = '';
  $handler->display->display_options['fields']['field_base_address_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_base_address_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_base_address_1']['alter']['text'] = '[field_base_address_1-thoroughfare]+[field_base_address_1-locality]+[field_base_address_1-administrative_area]+[field_base_address_1-postal_code]';
  $handler->display->display_options['fields']['field_base_address_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_base_address_1']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_base_address_1']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ops']['element_class'] = 'button--orange';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops']['element_default_classes'] = FALSE;
  /* Field: center */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'center';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="margin-y--xxxl">
  <div class="bg--white max-width--xxl center padding--xl rounded">
    <h2 class="font-size--xl padding--none padding-bottom--lg">We have found the participating center closest to your home.</h2>
    <div class="sm--display--table width--100 padding-bottom--lg">
      <a class="sm--display--table-cell vertical-align--middle" href="https://www.google.com/maps/search/?api=1&amp;query=[field_base_address_1]">
        <div id="map" class="width--100 height--md sm--width--md sm--float--left sm--margin-right--md background-size--cover background-position--bottom">
        </div>
      </a>
      <div class="sm--display--table-cell vertical-align--middle">
        <div class="bold font-size--lg">[title]</div>
        [field_base_address]
      </div>
    </div>
    <p class="font-size--lg padding-bottom--lg">
      Please confirm that you are interested in participating and a clinician will contact you.
    </p>
     <p class="text-align--center">
      [ops]
    </p>
  </div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: no center */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'no center';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="margin-y--xxxl">
  <div class="bg--white max-width--xxl center padding--xl rounded">
    <h2 class="font-size--xl padding-top--none">Thank you for your interest in participating in this clinical trial.</h2>
    <p class="">
      Based on the information you provided, it does not appear that you meet the eligibility requirements for this trial.
    </p>
    <p>Would you like to be notified if an applicable trial becomes available in your area? If so, please confirm below.</p>
    <p class="text-align--center padding-top--sm">
     [ops]
   </p>
  </div>
</div>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'title';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '5';
  $handler->display->display_options['fields']['views_conditional']['then'] = '[nothing_1]';
  $handler->display->display_options['fields']['views_conditional']['or'] = '[nothing]';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  /* Contextual filter: Entityform Submission: Entityform submission ID */
  $handler->display->display_options['arguments']['entityform_id']['id'] = 'entityform_id';
  $handler->display->display_options['arguments']['entityform_id']['table'] = 'entityform';
  $handler->display->display_options['arguments']['entityform_id']['field'] = 'entityform_id';
  $handler->display->display_options['arguments']['entityform_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['entityform_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['entityform_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['entityform_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['entityform_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Entityform Submission: Entityform Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'entityform';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'iga' => 'iga',
    'iga_artemis' => 'iga_artemis',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'entityform_id' => array(
      'type' => 'user',
      'context' => 'entity:bean.field_card_action_links',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'submission ID',
    ),
    'type' => array(
      'type' => 'user',
      'context' => 'entity:bean.field-card-action-links',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'entityform_type (machine name)',
    ),
  );
  $translatables['iga_submission'] = array(
    t('Master'),
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
    t('<style>
#map {
background-image:url(\'https://api.mapbox.com/styles/v1/mapbox/streets-v10/static/pin-l+000([field_base_geofield_1],[field_base_geofield])/[field_base_geofield_1],[field_base_geofield],15/1000x350@2x?access_token=pk.eyJ1IjoibmtmIiwiYSI6ImNpeXlycHIwdTAwdGozMnBvcHVyb3dsMHUifQ.Ga4ktI5QmMOipTSAG1If7g\')
}

</style>'),
    t('Location'),
    t('flag'),
    t('[field_base_address_1-thoroughfare]+[field_base_address_1-locality]+[field_base_address_1-administrative_area]+[field_base_address_1-postal_code]'),
    t('<div class="margin-y--xxxl">
  <div class="bg--white max-width--xxl center padding--xl rounded">
    <h2 class="font-size--xl padding--none padding-bottom--lg">We have found the participating center closest to your home.</h2>
    <div class="sm--display--table width--100 padding-bottom--lg">
      <a class="sm--display--table-cell vertical-align--middle" href="https://www.google.com/maps/search/?api=1&amp;query=[field_base_address_1]">
        <div id="map" class="width--100 height--md sm--width--md sm--float--left sm--margin-right--md background-size--cover background-position--bottom">
        </div>
      </a>
      <div class="sm--display--table-cell vertical-align--middle">
        <div class="bold font-size--lg">[title]</div>
        [field_base_address]
      </div>
    </div>
    <p class="font-size--lg padding-bottom--lg">
      Please confirm that you are interested in participating and a clinician will contact you.
    </p>
     <p class="text-align--center">
      [ops]
    </p>
  </div>
</div>'),
    t('<div class="margin-y--xxxl">
  <div class="bg--white max-width--xxl center padding--xl rounded">
    <h2 class="font-size--xl padding-top--none">Thank you for your interest in participating in this clinical trial.</h2>
    <p class="">
      Based on the information you provided, it does not appear that you meet the eligibility requirements for this trial.
    </p>
    <p>Would you like to be notified if an applicable trial becomes available in your area? If so, please confirm below.</p>
    <p class="text-align--center padding-top--sm">
     [ops]
   </p>
  </div>
</div>'),
    t('All'),
    t('Content pane'),
    t('View panes'),
  );
  $export['iga_submission'] = $view;

  return $export;
}

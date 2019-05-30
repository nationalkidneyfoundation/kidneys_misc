<?php

/**
 * @file
 * kidneys_misc_features.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function kidneys_misc_features_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_base_category_index'.
  $permissions['create field_base_category_index'] = array(
    'name' => 'create field_base_category_index',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_iga_closest_center'.
  $permissions['create field_iga_closest_center'] = array(
    'name' => 'create field_iga_closest_center',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_base_category_index'.
  $permissions['edit field_base_category_index'] = array(
    'name' => 'edit field_base_category_index',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_iga_closest_center'.
  $permissions['edit field_iga_closest_center'] = array(
    'name' => 'edit field_iga_closest_center',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_base_category_index'.
  $permissions['edit own field_base_category_index'] = array(
    'name' => 'edit own field_base_category_index',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_iga_closest_center'.
  $permissions['edit own field_iga_closest_center'] = array(
    'name' => 'edit own field_iga_closest_center',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_base_category_index'.
  $permissions['view field_base_category_index'] = array(
    'name' => 'view field_base_category_index',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_iga_closest_center'.
  $permissions['view field_iga_closest_center'] = array(
    'name' => 'view field_iga_closest_center',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_base_category_index'.
  $permissions['view own field_base_category_index'] = array(
    'name' => 'view own field_base_category_index',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_iga_closest_center'.
  $permissions['view own field_iga_closest_center'] = array(
    'name' => 'view own field_iga_closest_center',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}

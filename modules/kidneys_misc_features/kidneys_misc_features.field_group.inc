<?php
/**
 * @file
 * kidneys_misc_features.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function kidneys_misc_features_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_group|node|promotion|form';
  $field_group->group_name = 'group_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'promotion';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group',
    'weight' => '1',
    'children' => array(
      0 => 'group_promo_settings',
      1 => 'group_promo_promos',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_group|node|promotion|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_promo_promos|node|promotion|form';
  $field_group->group_name = 'group_promo_promos';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'promotion';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'Promos',
    'weight' => '3',
    'children' => array(
      0 => 'field_promo_button',
      1 => 'field_promo_block',
      2 => 'field_promo_band',
      3 => 'field_promo_banner',
      4 => 'field_promo_hero',
      5 => 'field_promo_modal',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_promo_promos|node|promotion|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_promo_settings|node|promotion|form';
  $field_group->group_name = 'group_promo_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'promotion';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'Settings',
    'weight' => '2',
    'children' => array(
      0 => 'field_base_category',
      1 => 'field_base_category_index',
      2 => 'field_promo_include_paths',
      3 => 'field_base_related_entity',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_promo_settings|node|promotion|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Group');
  t('Promos');
  t('Settings');

  return $field_groups;
}

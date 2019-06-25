<?php

/**
 * @file
 * kidneys_misc_features.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function kidneys_misc_features_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['entityform_block-iga'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'iga',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'entityform_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'hyk' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'hyk',
        'weight' => 0,
      ),
      'kidneycars_bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'kidneycars_bootstrap',
        'weight' => 0,
      ),
      'kidneys' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'kidneys',
        'weight' => 0,
      ),
      'nkf_base' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nkf_base',
        'weight' => 0,
      ),
      'nkf_base_events_bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nkf_base_events_bootstrap',
        'weight' => 0,
      ),
      'nkf_cny' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nkf_cny',
        'weight' => 0,
      ),
      'nkf_florida' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nkf_florida',
        'weight' => 0,
      ),
      'nkf_indiana' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nkf_indiana',
        'weight' => 0,
      ),
      'nkf_wten' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nkf_wten',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['entityform_block-iga_artemis'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'iga_artemis',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'entityform_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'hyk' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'hyk',
        'weight' => 0,
      ),
      'kidneycars_bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'kidneycars_bootstrap',
        'weight' => 0,
      ),
      'kidneys' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'kidneys',
        'weight' => 0,
      ),
      'nkf_base' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nkf_base',
        'weight' => 0,
      ),
      'nkf_base_events_bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nkf_base_events_bootstrap',
        'weight' => 0,
      ),
      'nkf_cny' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nkf_cny',
        'weight' => 0,
      ),
      'nkf_florida' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nkf_florida',
        'weight' => 0,
      ),
      'nkf_indiana' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nkf_indiana',
        'weight' => 0,
      ),
      'nkf_wten' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nkf_wten',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}

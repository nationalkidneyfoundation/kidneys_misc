<?php

/**
 * @file
 * kidneys_misc_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kidneys_misc_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function kidneys_misc_features_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_entityform_type().
 */
function kidneys_misc_features_default_entityform_type() {
  $items = array();
  $items['iga'] = entity_import('entityform_type', '{
    "type" : "iga",
    "label" : "iga",
    "data" : {
      "draftable" : 0,
      "draft_redirect_path" : "",
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "basic" },
      "submit_button_text" : "",
      "submit_confirm_msg" : "",
      "your_submissions" : "",
      "disallow_resubmit_msg" : "",
      "delete_confirm_msg" : "",
      "page_title_view" : "",
      "preview_page" : 0,
      "submission_page_title" : "",
      "submission_text" : { "value" : "", "format" : "basic" },
      "submission_show_submitted" : 0,
      "submissions_view" : "default",
      "user_submissions_view" : "default",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : {
        "1" : "1",
        "2" : "2",
        "5" : 0,
        "9" : 0,
        "40" : 0,
        "7" : 0,
        "8" : 0,
        "11" : 0,
        "14" : 0,
        "13" : 0,
        "41" : 0,
        "15" : 0,
        "10" : 0,
        "16" : 0,
        "17" : 0,
        "20" : 0,
        "12" : 0,
        "38" : 0,
        "19" : 0,
        "37" : 0,
        "18" : 0,
        "21" : 0,
        "22" : 0,
        "39" : 0,
        "28" : 0,
        "23" : 0,
        "24" : 0,
        "25" : 0,
        "26" : 0,
        "27" : 0,
        "30" : 0,
        "29" : 0,
        "31" : 0,
        "32" : 0,
        "33" : 0,
        "34" : 0,
        "35" : 0,
        "42" : 0
      },
      "resubmit_action" : "new",
      "redirect_path" : "",
      "instruction_pre" : { "value" : "", "format" : "basic" },
      "current_type" : "iga",
      "enable_block" : 1
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : []
  }');
  $items['iga_artemis'] = entity_import('entityform_type', '{
    "type" : "iga_artemis",
    "label" : "iga_artemis",
    "data" : {
      "draftable" : 0,
      "draft_redirect_path" : "",
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "basic" },
      "submit_button_text" : "",
      "submit_confirm_msg" : "",
      "your_submissions" : "",
      "disallow_resubmit_msg" : "",
      "delete_confirm_msg" : "",
      "page_title_view" : "",
      "preview_page" : 0,
      "submission_page_title" : "",
      "submission_text" : { "value" : "", "format" : "basic" },
      "submission_show_submitted" : 0,
      "submissions_view" : "default",
      "user_submissions_view" : "default",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : {
        "1" : "1",
        "2" : "2",
        "5" : 0,
        "9" : 0,
        "40" : 0,
        "7" : 0,
        "8" : 0,
        "11" : 0,
        "14" : 0,
        "13" : 0,
        "41" : 0,
        "15" : 0,
        "10" : 0,
        "16" : 0,
        "17" : 0,
        "20" : 0,
        "12" : 0,
        "38" : 0,
        "19" : 0,
        "37" : 0,
        "18" : 0,
        "21" : 0,
        "22" : 0,
        "39" : 0,
        "28" : 0,
        "23" : 0,
        "24" : 0,
        "25" : 0,
        "26" : 0,
        "27" : 0,
        "30" : 0,
        "29" : 0,
        "31" : 0,
        "32" : 0,
        "33" : 0,
        "34" : 0,
        "35" : 0,
        "42" : 0
      },
      "resubmit_action" : "new",
      "redirect_path" : "",
      "instruction_pre" : { "value" : "", "format" : "basic" },
      "current_type" : "iga_artemis",
      "enable_block" : 1
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : { "submit" : {
        "source" : "eform\\/submit\\/iga-artemis",
        "alias" : "atoz\\/igantest",
        "language" : "und"
      }
    }
  }');
  return $items;
}

/**
 * Implements hook_flag_default_flags().
 */
function kidneys_misc_features_flag_default_flags() {
  $flags = array();
  // Exported flag: "IgA Confirm".
  $flags['iga_confirm'] = array(
    'entity_type' => 'entityform',
    'title' => 'IgA Confirm',
    'global' => 1,
    'types' => array(
      0 => 'iga',
    ),
    'flag_short' => 'Confirm',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unflag this item',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => 'Thanks!',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'email' => 0,
      'confirmation' => 0,
      'download' => 0,
      'table' => 0,
      'review' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'api_version' => 3,
    'module' => 'kidneys_misc_features',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;

}

/**
 * Implements hook_node_info().
 */
function kidneys_misc_features_node_info() {
  $items = array(
    'promotion' => array(
      'name' => t('Promotion'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

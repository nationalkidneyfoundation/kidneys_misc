<?php

/**
 * Implements hook_rules_action_info().
 */
function kidneys_misc_rules_action_info() {
  $actions = array();

  // Declare some defaults for all actions.
  $defaults = array(
    'group' => t('Redhen Contact'),
    'access callback' => 'kidneys_misc_access',
  );

  // Add an action to load contact by email address.
  $actions['kidneys_misc_fetch_by_mail'] = $defaults + array(
    'label' => t('Fetch contact by email'),
    'base' => 'kidneys_misc_rules_action_fetch_by_mail',
    'provides' => array(
      'fetched_contact' => array('type' => 'redhen_contact', 'label' => t('Fetched contact')),
    ),
  );
  $actions['kidneys_misc_fetch_by_mail']['parameter']['mail'] = array(
    'type' => 'text',
    'label' => t('Email address'),
    'description' => t('The email address to fetch by.'),
  );

  $actions['kidneys_misc_dontion_gl_code'] = array(
    'label' => t('Get GL Code for Donation'),
    'group' => t('NKF'),
    'parameter' => array(
      'office_id' => array(
        'type' => 'text',
        'label' => t('GL Office Dept Segment'),
      ),
      'gift_type' => array(
        'type' => 'text',
        'label' => t('Gift Type'),
        'optional' => TRUE
      ),
    ),
    'provides' => array(
      'gl_code' => array(
        'type' => 'text',
        'label' => t('GL Code'),
        'save' => TRUE
      ),
    ),
  );

  $actions['kidneys_misc_reassign_contact_donation_membership'] = array(
    'label' => t('Reassign contact on donations and memberships'),
    'group' => t('NKF'),
    'parameter' => array(
      'master' => array(
        'type' => 'redhen_contact',
        'label' => t('Master Contact'),
      ),
      'dupe' => array(
        'type' => 'redhen_contact',
        'label' => t('Dupe Contact'),
      ),
      'delete_dupe' => array(
        'type' => 'boolean',
        'label' => t('Delete Dupe'),
        'default value' => true
      ),
    ),
  );

  $actions['kidneys_misc_create_redirect'] = array(
    'label' => t('Create a redirect rule'),
    'group' => t('NKF'),
    'parameter' => array(
      'source' => array(
        'type' => 'text',
        'label' => t('Source'),
      ),
      'redirect' => array(
        'type' => 'text',
        'label' => t('Redirect'),
      )
    ),
  );
  $actions['kidneys_misc_generate_hash_action'] = array(
    'label' => t('Get a random hash for a url'),
    'group' => t('NKF'),
    'parameter' => array(
      'hash_length' => array(
        'type' => 'integer',
        'label' => t('Hash Length'),
      ),
    ),
    'provides' => array(
      'hash' => array(
        'type' => 'text',
        'label' => t('Hash'),
        'save' => TRUE
      ),
    ),
  );

  $actions['kidneys_misc_get_category_tid_values_rules'] = array(
    'label' => t('Get category index weighted values'),
    'group' => t('NKF'),
    'parameter' => array(
      'node' => array(
        'type' => 'node',
        'label' => t('Content'),
      )
    ),
    'provides' => array(
      'categories' => array(
        'type' => 'text',
        'label' => t('Category tid values'),
        'save' => TRUE
      ),
    ),
  );

  return $actions;
}

/**
 * Implements hook_rules_condition_info().
 */
function kidneys_misc_rules_condition_info() {
  $conditions = array();

  $conditions['kidneys_misc_exists_by_email'] = array(
    'label' => t('Contact exists by email'),
    'base' => 'kidneys_misc_rules_condition_exists_by_email',
    'group' => t('Redhen Contact'),
    'parameter' => array(
      'mail' => array(
        'type' => 'text',
        'label' => t('Email address'),
        'description' => t('The email address to check by.'),
      ),
    ),
  );

  return $conditions;
}


function kidneys_misc_get_category_tid_values_rules($node) {
  $values = kidneys_misc_get_category_tid_values($node);
  return array(
    'categories' => $values
  );
}

/**
 * Rules action: fetch contact by email address.
 */
function kidneys_misc_rules_action_fetch_by_mail($mail) {
  if(module_exists('redhen_contact')) {
    $contacts = redhen_contact_load_by_mail($mail);
    $contact = $contacts ? array_shift($contacts) : NULL;
    return array('fetched_contact' => $contact);
  }
}

/**
 * Rules action: get GL code for donation.
 */

function kidneys_misc_dontion_gl_code($office_id, $gift_type = NULL) {
  $one = '10';
  $two = $office_id;
  // Affiliates.
  if ($office_id >= 700 && $office_id < 800) {
    $three = '0000';
    // Memorial/Honor.
    if (isset($gift_type) && $gift_type != '') {
      $four = '210';
    } else {
      $four = '209';
    }
  } else {
    $three = '8000';
    // Memorial/Honor.
    if (isset($gift_type) && $gift_type != '') {
      $four = '401';
    } else {
      $four = '400';
    }
  }
  return array(
    'gl_code' => $one . '-' . $two .'-' . $three . '-' . $four
  );
}
/**
 * Rules condition: contact exists by email address.
 */
function kidneys_misc_rules_condition_exists_by_email($mail) {
  if(module_exists('redhen_contact')) {
    $contacts = redhen_contact_load_by_mail($mail);
    return is_array($contacts);
  }
}

function kidneys_misc_generate_hash_action($length = 7) {
  $hash = kidneys_misc_generate_hash($length);
  return array(
    'hash' => $hash
  );
}

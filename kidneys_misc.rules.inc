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

function kidneys_misc_dontion_gl_code($office_id, $gift_type) {
  $one = '10';
  $two = $office_id;
  $three = '8000';
  // Affiliates.
  if ($office_id >= 700) {
    // Memorial/Honor.
    if (isset($gift_type) && $gift_type != '') {
      $four = '210';
    } else {
      $four = '209';
    }
  } else {
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

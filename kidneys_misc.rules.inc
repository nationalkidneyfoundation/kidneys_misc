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
  $actions['kidneys_misc_set_line_item_type_info_recurring'] = array(
    'label' => t('Set the correct line item type and info on a recurring gift'),
    'group' => t('NKF'),
    'parameter' => array(
      'line_item' => array(
        'type' => 'commerce_line_item',
        'label' => t('Line Item'),
      )
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
  $conditions['kidneys_misc_check_for_existing_pending_orders'] = array(
    'label' => t('Recurring entity has no pending recurring orders'),
    'parameter' => array(
      'commerce_recurring' => array(
        'type' => 'commerce_recurring',
        'label' => t('Commerce recurring'),
      ),
    ),
    'group' => t('Commerce recurring'),
  );
  $conditions['kidneys_misc_check_for_recently_charged_recurring_orders'] = array(
    'label' => t('Recurring entity has no recently charged recurring order'),
    'parameter' => array(
      'commerce_recurring' => array(
        'type' => 'commerce_recurring',
        'label' => t('Commerce recurring'),
      ),
    ),
    'group' => t('Commerce recurring'),
  );
  return $conditions;
}

/*
 * See if the recurring order has any exising orders with a status of "pending recurring"
 * and if so return FALSE.
 */
function kidneys_misc_check_for_existing_pending_orders($recurring_entity) {
  $items = field_get_items('commerce_recurring', $recurring_entity, 'commerce_recurring_order');
  $order_ids = array();
  foreach ($items as $value) {
    $order_ids[] = $value['target_id'];
  }

  $orders = commerce_order_load_multiple($order_ids);

  foreach ($orders as $order) {
    if ($order->status == 'recurring_pending') {
      watchdog('kidney_misc_recurring_fail', 'Recurring entity has pending recurring order: ' . $order->order_id);
      return false;
    }
  }
  return true;
}

/*
 * See if the recurring order has any exising orders with a status of "pending recurring"
 * and if so return FALSE.
 */
function kidneys_misc_check_for_recently_charged_recurring_orders($recurring_entity) {
  $items = field_get_items('commerce_recurring', $recurring_entity, 'commerce_recurring_order');
  $order_ids = array();
  foreach ($items as $value) {
    $order_ids[] = $value['target_id'];
  }

  $interval = kidneys_misc_get_recurring_interval($recurring_entity);
  // Flip the direction of the interval so we can look back in time (wooooo).
  $interval['interval'] = $interval['interval'] * -1;
  // If we don'thave an interval then something is wrong and we shouldn't proceed.
  if (!$interval) {
    return false;
  }
  $date = new DateObject();
  interval_apply_interval($date, $interval, TRUE);

  $orders = commerce_order_load_multiple($order_ids);

  foreach ($orders as $order) {
    // TODO: Should this really only look for charged cards? What about processing, etc.?
    if ($order->status == 'cardonfile_charged' && $order->changed >= $date->getTimestamp()) {
      watchdog('kidney_misc_recurring_fail', 'Recurring entity has recently charged order: ' . $order->order_id);
      return false;
    }
  }
  return true;
}

function kidneys_misc_get_recurring_interval($recurring_entity) {
  // Get the product out of the recurring entity.
  $recurring_wrapper = entity_metadata_wrapper('commerce_recurring', $recurring_entity);
  $product_wrapper = $recurring_wrapper->commerce_recurring_ref_product;

  $product = $product_wrapper->value();
  if (!empty($product->commerce_recurring_rec_period)) {
    $recurring_interval = $product_wrapper->commerce_recurring_rec_period->value();
    if (!empty($recurring_interval)) {
      return $recurring_interval;
    } else {
      return FALSE;
    }
  }
}


function kidneys_misc_set_line_item_type_info_recurring($line_item) {
  if (!empty($line_item->data && !empty($line_item->data['recurring_entity']))) {
    // Load recurring entity
    $recurring_entity = commerce_recurring_load($line_item->data['recurring_entity']);
    // Load original order from recurring
    if (!empty($recurring_entity->commerce_recurring_order[LANGUAGE_NONE])) {
      $order_id = $recurring_entity->commerce_recurring_order[LANGUAGE_NONE][0]['target_id'];
      $order = commerce_order_load($order_id);
      // Load line item from order
      $line_item_id = $order->commerce_line_items[LANGUAGE_NONE][0]['line_item_id'];
      $original_line_item = commerce_line_item_load($line_item_id);
      // Set correct line itme type
      $line_item->type = $original_line_item->type;
      // Set all fields on line item.
      $original_line_item = (array) $original_line_item;
      foreach ($original_line_item as $key => $value) {
        if (strrpos($key, 'field_') !== FALSE) {
          $line_item->{$key} = $value;
        }
      }
      if (isset($line_item->field_sf_status)) {
        $line_item->field_sf_status[LANGUAGE_NONE][0]['value'] = 'new';
      }
    }
  }
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
  if (empty($two)) {
     $two = '920';
  }
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

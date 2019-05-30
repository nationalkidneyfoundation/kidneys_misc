<?php

/**
 * @file
 * kidneys_misc_features.features.conditional_fields.inc
 */

/**
 * Implements hook_conditional_fields_default_fields().
 */
function kidneys_misc_features_conditional_fields_default_fields() {
  $items = array();

  $items["entityform:iga_artemis:0"] = array(
    'entity' => 'entityform',
    'bundle' => 'iga_artemis',
    'dependent' => 'field_artemis_biopsy_yrs',
    'dependee' => 'field_artemis_biopsy',
    'options' => array(
      'state' => 'visible',
      'condition' => 'value',
      'grouping' => 'AND',
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => 1,
        2 => 2,
        5 => 0,
        3 => 0,
        4 => 0,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(
        1 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        2 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        5 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        9 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        40 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        7 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        8 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        11 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        14 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        13 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        41 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        15 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        10 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        16 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        17 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        20 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        12 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        38 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        19 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        37 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        18 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        21 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        22 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        39 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        28 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        23 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        24 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        25 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        26 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        27 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        30 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        29 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        31 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        32 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        33 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        34 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        35 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        42 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
      ),
      'element_edit' => array(
        1 => 1,
        3 => 0,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(
        1 => array(
          1 => 1,
          3 => 0,
        ),
        2 => array(
          1 => 1,
          3 => 0,
        ),
        5 => array(
          1 => 1,
          3 => 0,
        ),
        9 => array(
          1 => 1,
          3 => 0,
        ),
        40 => array(
          1 => 1,
          3 => 0,
        ),
        7 => array(
          1 => 1,
          3 => 0,
        ),
        8 => array(
          1 => 1,
          3 => 0,
        ),
        11 => array(
          1 => 1,
          3 => 0,
        ),
        14 => array(
          1 => 1,
          3 => 0,
        ),
        13 => array(
          1 => 1,
          3 => 0,
        ),
        41 => array(
          1 => 1,
          3 => 0,
        ),
        15 => array(
          1 => 1,
          3 => 0,
        ),
        10 => array(
          1 => 1,
          3 => 0,
        ),
        16 => array(
          1 => 1,
          3 => 0,
        ),
        17 => array(
          1 => 1,
          3 => 0,
        ),
        20 => array(
          1 => 1,
          3 => 0,
        ),
        12 => array(
          1 => 1,
          3 => 0,
        ),
        38 => array(
          1 => 1,
          3 => 0,
        ),
        19 => array(
          1 => 1,
          3 => 0,
        ),
        37 => array(
          1 => 1,
          3 => 0,
        ),
        18 => array(
          1 => 1,
          3 => 0,
        ),
        21 => array(
          1 => 1,
          3 => 0,
        ),
        22 => array(
          1 => 1,
          3 => 0,
        ),
        39 => array(
          1 => 1,
          3 => 0,
        ),
        28 => array(
          1 => 1,
          3 => 0,
        ),
        23 => array(
          1 => 1,
          3 => 0,
        ),
        24 => array(
          1 => 1,
          3 => 0,
        ),
        25 => array(
          1 => 1,
          3 => 0,
        ),
        26 => array(
          1 => 1,
          3 => 0,
        ),
        27 => array(
          1 => 1,
          3 => 0,
        ),
        30 => array(
          1 => 1,
          3 => 0,
        ),
        29 => array(
          1 => 1,
          3 => 0,
        ),
        31 => array(
          1 => 1,
          3 => 0,
        ),
        32 => array(
          1 => 1,
          3 => 0,
        ),
        33 => array(
          1 => 1,
          3 => 0,
        ),
        34 => array(
          1 => 1,
          3 => 0,
        ),
        35 => array(
          1 => 1,
          3 => 0,
        ),
        42 => array(
          1 => 1,
          3 => 0,
        ),
      ),
      'selector' => '',
      'values_set' => 1,
      'value_form' => 1,
      'value' => array(
        0 => array(
          'value' => 1,
        ),
      ),
      'values' => array(),
    ),
  );

  return $items;
}

<?php
/**
 * @file
 * kidneys_misc_features.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function kidneys_misc_features_default_rules_configuration() {
  $items = array();
  $items['rules_membership_merge_contacts'] = entity_import('rules_config', '{ "rules_membership_merge_contacts" : {
      "LABEL" : "Membership: Merge contacts",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "kidneys_misc" ],
      "USES VARIABLES" : {
        "master_contact" : { "label" : "master_contact", "type" : "redhen_contact" },
        "dupe_id" : { "label" : "dupe_id", "type" : "integer" }
      },
      "ACTION SET" : [
        { "entity_fetch" : {
            "USING" : { "type" : "redhen_contact", "id" : [ "dupe-id" ] },
            "PROVIDE" : { "entity_fetched" : { "dupe_contact" : "dupe_contact" } }
          }
        },
        { "kidneys_misc_reassign_contact_donation_membership" : {
            "master" : [ "master-contact" ],
            "dupe" : [ "dupe-contact" ],
            "delete_dupe" : "1"
          }
        }
      ]
    }
  }');
  return $items;
}

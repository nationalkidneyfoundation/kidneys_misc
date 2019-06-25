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
  $items['rules_iga_confirm_center'] = entity_import('rules_config', '{ "rules_iga_confirm_center" : {
      "LABEL" : "IgA Confirm Center",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : { "flag_flagged_iga_confirm" : [] },
      "DO" : [
        { "component_rules_iga_email_center" : { "submission" : [ "flagged-entityform" ] } },
        { "component_rules_iga_email_no_center" : { "submission" : [ "flagged-entityform" ] } }
      ]
    }
  }');
  $items['rules_iga_email_center'] = entity_import('rules_config', '{ "rules_iga_email_center" : {
      "LABEL" : "IgA Email Center",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "iga" ],
      "REQUIRES" : [ "rules", "mimemail" ],
      "USES VARIABLES" : { "submission" : { "label" : "submission", "type" : "entityform" } },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "submission" ], "field" : "field_iga_closest_center" } },
        { "NOT data_is_empty" : { "data" : [ "submission:field-iga-closest-center" ] } }
      ],
      "DO" : [
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "submission:field-iga-closest-center:nid" ] },
            "PROVIDE" : { "entity_fetched" : { "location" : "location" } }
          }
        },
        { "mimemail" : {
            "USING" : {
              "key" : "[flagged-entityform:entityform-id]",
              "to" : "[location:field-base-email]",
              "from_name" : "JANUS Study",
              "from_mail" : "janus.study@kidney.org",
              "subject" : "JANUS IgAN study participant",
              "body" : "\\u003Cp\\u003EThe following patient has been pre-screened and has agreed to be contacted by your study site for potential enrollment.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EHere is their contact info:\\u003C\\/p\\u003E\\r\\n\\u003Cstrong\\u003EFirst Name:\\u003C\\/strong\\u003E [submission:field-base-first-name]\\u003Cbr\\u003E\\r\\n\\u003Cstrong\\u003ELast Name:\\u003C\\/strong\\u003E [submission:field-base-last-name]\\u003Cbr\\u003E\\r\\n\\u003Cstrong\\u003EEmail:\\u003C\\/strong\\u003E [submission:field-base-email]\\u003Cbr\\u003E\\r\\n\\u003Cstrong\\u003EPhone:\\u003C\\/strong\\u003E [submission:field-phone]\\u003Cbr\\u003E\\r\\n\\u003Cstrong\\u003EAddress:\\u003C\\/strong\\u003E [submission:field_base_address]\\u003Cbr\\u003E\\r\\n\\u003Cstrong\\u003EPreferred Method of contact:\\u003C\\/strong\\u003E [submission:field_iga_contact_method]\\u003Cbr\\u003E\\u003Cbr\\u003E\\r\\n\\u003Cstrong\\u003EID\\u003C\\/strong\\u003E: [submission:entityform-id]\\r\\n\\u003C\\/p\\u003E",
              "plaintext" : "\\u003Cp\\u003E[submission:field-base-first-name] [submission:field-base-last-name] patient is interested in participating in the trial.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EHere\\u2019s their contact info.\\u003C\\/p\\u003E\\r\\n\\u003Cstrong\\u003EFirst Name:\\u003C\\/strong\\u003E [submission:field-base-first-name]\\u003Cbr\\u003E\\r\\n\\u003Cstrong\\u003ELast Name:\\u003C\\/strong\\u003E [submission:field-base-last-name]\\u003Cbr\\u003E\\r\\n\\u003Cstrong\\u003EEmail:\\u003C\\/strong\\u003E [submission:field-base-email]\\u003Cbr\\u003E\\r\\n\\u003Cstrong\\u003EPhone:\\u003C\\/strong\\u003E [submission:field-base-phone]\\u003Cbr\\u003E\\r\\n\\u003Cstrong\\u003EAddress:\\u003C\\/strong\\u003E [submission:field_base_address]\\u003Cbr\\u003E\\r\\n\\u003Cstrong\\u003EPreferred Method of contact:\\u003C\\/strong\\u003E [submission:field_iga_contact_method]\\r\\n\\u003C\\/p\\u003E",
              "language" : [ "" ]
            },
            "PROVIDE" : { "send_status" : { "send_status" : "Send status" } }
          }
        }
      ]
    }
  }');
  $items['rules_iga_email_no_center'] = entity_import('rules_config', '{ "rules_iga_email_no_center" : {
      "LABEL" : "IgA Email no center",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "iga" ],
      "REQUIRES" : [ "rules", "mimemail" ],
      "USES VARIABLES" : { "submission" : { "label" : "submission", "type" : "entityform" } },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "submission" ], "field" : "field_iga_closest_center" } },
        { "data_is_empty" : { "data" : [ "submission:field-iga-closest-center" ] } }
      ],
      "DO" : [
        { "mimemail" : {
            "USING" : {
              "key" : "[flagged-entityform:entityform-id]",
              "to" : "jacob.lane@kidney.org",
              "subject" : "NKF-JANUS participant",
              "body" : "\\u003Cp\\u003E[submission:field-base-first-name] [submission:field-base-last-name] patient is interested in participating in the trial. Here\\u2019s their contact info.\\u003C\\/p\\u003E\\r\\n\\u003Cstrong\\u003EFirst Name:\\u003C\\/strong\\u003E [submission:field-base-first-name]\\u003Cbr\\u003E\\r\\n\\u003Cstrong\\u003ELast Name:\\u003C\\/strong\\u003E [submission:field-base-last-name]\\u003Cbr\\u003E\\r\\n\\u003Cstrong\\u003EEmail:\\u003C\\/strong\\u003E [submission:field-base-email]\\u003Cbr\\u003E\\r\\n\\u003Cstrong\\u003EPhone:\\u003C\\/strong\\u003E [submission:field-base-phone]\\u003Cbr\\u003E\\r\\n\\u003Cstrong\\u003EAddress:\\u003C\\/strong\\u003E [submission:field_base_address]\\u003Cbr\\u003E\\r\\n\\u003Cstrong\\u003EPreferred Method of contact:\\u003C\\/strong\\u003E [submission:field_iga_contact_method]\\r\\n\\u003C\\/p\\u003E",
              "language" : [ "" ]
            },
            "PROVIDE" : { "send_status" : { "send_status" : "Send status" } }
          }
        }
      ]
    }
  }');
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
        { "entity_fetch" : {
            "USING" : { "type" : "user", "id" : [ "dupe-contact:user:uid" ] },
            "PROVIDE" : { "entity_fetched" : { "dupe_user" : "dupe_user" } }
          }
        },
        { "kidneys_misc_reassign_contact_donation_membership" : {
            "master" : [ "master-contact" ],
            "dupe" : [ "dupe-contact" ],
            "delete_dupe" : "1"
          }
        },
        { "entity_delete" : { "data" : [ "dupe-user" ] } }
      ]
    }
  }');
  return $items;
}

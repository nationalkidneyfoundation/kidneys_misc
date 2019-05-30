<?php

/**
 * @file
 * kidneys_misc_features.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function kidneys_misc_features_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'iga_trial_result';
  $page->task = 'page';
  $page->admin_title = 'iga trial result page';
  $page->admin_description = '';
  $page->path = 'iga-trial/results/%entity_id';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'entity_id' => array(
      'id' => 1,
      'identifier' => 'Entityform Submission: ID',
      'name' => 'entity_id:entityform',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_iga_trial_result__panel_context_b3c445c9-ef11-4202-878e-ac8c48950a36';
  $handler->task = 'page';
  $handler->subtask = 'iga_trial_result';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'location',
        'keyword' => 'node',
        'name' => 'entity_from_field:field_iga_closest_center-entityform-node',
        'delta' => 0,
        'context' => 'argument_entity_id:entityform_1',
        'id' => 1,
      ),
    ),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'widescreen';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main' => NULL,
      'one' => NULL,
      'two' => NULL,
      'three' => NULL,
      'four' => NULL,
      'five' => NULL,
      'six' => NULL,
      'seven' => NULL,
      'eight' => NULL,
      'nine' => NULL,
      'ten' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '545d18c6-a205-46c1-a56f-5a76aaee4061';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_iga_trial_result__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-06bfab71-d32c-4a73-90ea-59cb8b930889';
  $pane->panel = 'one';
  $pane->type = 'views_panes';
  $pane->subtype = 'iga_submission-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'entityform_id' => '%entity_id:entityform-id',
      'type' => 'iga_artemis',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'width--100 bg--gray-1',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '06bfab71-d32c-4a73-90ea-59cb8b930889';
  $display->content['new-06bfab71-d32c-4a73-90ea-59cb8b930889'] = $pane;
  $display->panels['one'][0] = 'new-06bfab71-d32c-4a73-90ea-59cb8b930889';
  $pane = new stdClass();
  $pane->pid = 'new-417f562e-90d0-40ea-9924-abed03484d9d';
  $pane->panel = 'two';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = FALSE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'entity_field_value:entityform:iga:field_iga_18',
        'settings' => array(
          'field_iga_18' => array(
            'und' => array(
              0 => array(
                'value' => '0',
              ),
            ),
          ),
          'field_iga_18_value' => array(
            0 => '0',
          ),
        ),
        'context' => 'argument_entity_id:entityform_1',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'entity_field_value:entityform:iga:field_iga_diagnosis',
        'settings' => array(
          'field_iga_diagnosis' => array(
            'und' => array(
              0 => array(
                'value' => '0',
              ),
            ),
          ),
          'field_iga_diagnosis_value' => array(
            0 => '0',
          ),
        ),
        'context' => 'argument_entity_id:entityform_1',
        'not' => FALSE,
      ),
    ),
    'logic' => 'or',
  );
  $pane->configuration = array(
    'admin_title' => 'not eligible',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<div class="container padding--xl">
<p class="font-size--lg prose">Thank you for your interest in participating in this clinical trial. Based on the information you have provided, it does not appear that you will be eligible for participation in this particular medical research study.</p>
</div>',
    'format' => 'full_html',
    'substitute' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'width--100 container padding--xl display--block',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '417f562e-90d0-40ea-9924-abed03484d9d';
  $display->content['new-417f562e-90d0-40ea-9924-abed03484d9d'] = $pane;
  $display->panels['two'][0] = 'new-417f562e-90d0-40ea-9924-abed03484d9d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['iga_trial_result'] = $page;

  return $pages;

}

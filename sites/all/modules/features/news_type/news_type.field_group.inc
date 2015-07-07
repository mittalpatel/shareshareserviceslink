<?php
/**
 * @file
 * news_type.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function news_type_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_newstags|node|news|form';
  $field_group->group_name = 'group_newstags';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'News Tags',
    'weight' => '12',
    'children' => array(
      0 => 'field_company',
      1 => 'field_company_type',
      2 => 'field_geography',
      3 => 'field_interests_and_expertise',
      4 => 'field_solution_focus',
      5 => 'field_section',
      6 => 'field_sector',
      7 => 'field_standard',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'News Tags',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_newstags|node|news|form'] = $field_group;

  return $export;
}

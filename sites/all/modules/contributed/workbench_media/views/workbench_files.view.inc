<?php

/**
 * @file
 * Default View for displaying file list.
 */

$view = new view();
$view->name = 'workbench_files';
$view->description = 'A list of all the files uploaded to the site, and nodes they appear on.';
$view->tag = 'Workbench';
$view->base_table = 'file_managed';
$view->human_name = '';
$view->core = 0;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Defaults */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->display->display_options['title'] = 'Files';
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'access workbench';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '25';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
$handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 25, 50, 100, 200';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'filemime' => 'filemime',
  'filename' => 'filename',
  'uri' => 'uri',
  'filesize' => 'filesize',
  'timestamp' => 'timestamp',
  'title' => 'title',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'filemime' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'filename' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'uri' => array(
    'sortable' => 0,
    'align' => '',
    'separator' => '',
  ),
  'filesize' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'timestamp' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'title' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
);
/* Relationship: File Usage: Content */
$handler->display->display_options['relationships']['file_to_node']['id'] = 'file_to_node';
$handler->display->display_options['relationships']['file_to_node']['table'] = 'file_usage';
$handler->display->display_options['relationships']['file_to_node']['field'] = 'file_to_node';
/* Field: File: Mime type */
$handler->display->display_options['fields']['filemime']['id'] = 'filemime';
$handler->display->display_options['fields']['filemime']['table'] = 'file_managed';
$handler->display->display_options['fields']['filemime']['field'] = 'filemime';
$handler->display->display_options['fields']['filemime']['label'] = 'Type';
$handler->display->display_options['fields']['filemime']['filemime_image'] = TRUE;
/* Field: File: Name */
$handler->display->display_options['fields']['filename']['id'] = 'filename';
$handler->display->display_options['fields']['filename']['table'] = 'file_managed';
$handler->display->display_options['fields']['filename']['field'] = 'filename';
$handler->display->display_options['fields']['filename']['link_to_file'] = TRUE;
/* Field: File: Path */
$handler->display->display_options['fields']['uri']['id'] = 'uri';
$handler->display->display_options['fields']['uri']['table'] = 'file_managed';
$handler->display->display_options['fields']['uri']['field'] = 'uri';
$handler->display->display_options['fields']['uri']['file_download_path'] = TRUE;
/* Field: File: Size */
$handler->display->display_options['fields']['filesize']['id'] = 'filesize';
$handler->display->display_options['fields']['filesize']['table'] = 'file_managed';
$handler->display->display_options['fields']['filesize']['field'] = 'filesize';
/* Field: File: Upload date */
$handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
$handler->display->display_options['fields']['timestamp']['table'] = 'file_managed';
$handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
$handler->display->display_options['fields']['timestamp']['label'] = 'Uploaded';
$handler->display->display_options['fields']['timestamp']['date_format'] = 'time ago';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'file_to_node';
$handler->display->display_options['fields']['title']['label'] = 'On Node';
$handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
/* Field: File: Path */
$handler->display->display_options['fields']['uri_1']['id'] = 'uri_1';
$handler->display->display_options['fields']['uri_1']['table'] = 'file_managed';
$handler->display->display_options['fields']['uri_1']['field'] = 'uri';
$handler->display->display_options['fields']['uri_1']['label'] = 'filepath';
/* Sort criterion: File: Upload date */
$handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
$handler->display->display_options['sorts']['timestamp']['table'] = 'file_managed';
$handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
$handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
/* Filter criterion: File: Name */
$handler->display->display_options['filters']['filename']['id'] = 'filename';
$handler->display->display_options['filters']['filename']['table'] = 'file_managed';
$handler->display->display_options['filters']['filename']['field'] = 'filename';
$handler->display->display_options['filters']['filename']['operator'] = 'contains';
$handler->display->display_options['filters']['filename']['exposed'] = TRUE;
$handler->display->display_options['filters']['filename']['expose']['label'] = 'File name';
$handler->display->display_options['filters']['filename']['expose']['identifier'] = 'filename';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page_1');
$handler->display->display_options['path'] = 'admin/workbench/files';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'File list';
$handler->display->display_options['menu']['description'] = 'List of all files uploaded to this site.';
$handler->display->display_options['menu']['weight'] = '0';
$translatables['workbench_files'] = array(
  t('Defaults'),
  t('Files'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Items per page'),
  t('- All -'),
  t('Offset'),
  t('« first'),
  t('‹ previous'),
  t('next ›'),
  t('last »'),
  t('Content'),
  t('Type'),
  t('Name'),
  t('Path'),
  t('Size'),
  t('Uploaded'),
  t('On Node'),
  t('filepath'),
  t('File name'),
  t('Page'),
);

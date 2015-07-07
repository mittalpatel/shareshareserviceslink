<?php
/**
 * @file
 * Declares our migrations.
 */
    

/**
 * Implements hook_migrate_api().
 */
function news_migrate_migrate_api() {
  $api = array(
    'api' => 2,
    'groups' => array(
      'SSL Migration' => array(
        'title' => t('SSL Migrations'),
      ),
    ),
    'migrations' => array(
      'News' => array(
        'class_name' => 'MigrateNewsMigration',
        'group_name' => 'SSL Migration',
      ),
    ),
  );
  return $api;
}
?>

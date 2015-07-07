<?php
class MigrateNewsMigration extends XMLMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    
    $this->description =
      t('Migrate news items from SSL site');
      
    $fields = array(
      'contentid' => 'External ID',
      'importid' => 'External import ID',
      'name' => 'Title',
      'introduction' => 'Summary',
      'content' => 'Body',
      'date' => 'date',
      'meta_title' => 'meta title',
      'meta_keywords' => 'meta keywords',
      'meta_description' => 'meta description',
      'meta_robots' => 'meta robots',
      'meta_display_in_sitemap' => 'meta display in sitemap',
      'canonical_url' => 'canonical url',
      'status' => 'status',
      'access_status' => 'access status',
      'display_start_date' => 'display start date',
      'display_end_date' => 'display end date',
      'display_in_search' => 'display in search',
      'created' => 'created',
      'updated' => 'updated',
      'access' => 'access',
      'url' => 'url',
      'description' => 'description',
      'image1id' => 'image id',
      'site_userid' => 'site userid',
      'tags' => 'tags',
      'company_tag' => 'company tag',
      'geography_tag' => 'geography tag',
      'section_tag' => 'section tag',
      'sector_tag' => 'sector tag',
      'erp_tag' => 'erp tag',
      'content_type_name' => 'content type name',
    );
          
    $xml_folder = DRUPAL_ROOT . '/migration/';
    $items_url = $xml_folder . 'news.xml';
    $item_xpath = '/export/item';  // relative to document
    $item_ID_xpath = 'contentid';          // relative to item_xpath
    $this->source = new MigrateSourceXML($items_url, $item_xpath, $item_ID_xpath,
      $fields);  
    
    $this->destination = new MigrateDestinationNode('news');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'contentid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
        )
      ),
      MigrateDestinationRole::getKeySchema()
    );

    $this->addFieldMapping('field_contentid', 'contentid')->xpath('contentid');
    //$this->addFieldMapping('', 'importid')->xpath('');
    $this->addFieldMapping('title', 'name')->xpath('name');
    $this->addFieldMapping('field_introduction', 'introduction')->xpath('introduction');
    $this->addFieldMapping('field_main_content', 'content')->xpath('content');
    $this->addFieldMapping('field_date', 'date')->xpath('date');
    $this->addFieldMapping('field_meta_title', 'meta_title')->xpath('meta_title');
    $this->addFieldMapping('field_meta_keywords', 'meta_keywords')->xpath('meta_keywords');
    $this->addFieldMapping('field_meta_description', 'meta_description')->xpath('meta_description');
    $this->addFieldMapping('field_meta_robots', 'meta_robots')->xpath('meta_robots');
    $this->addFieldMapping('field_meta_display_sitemap', 'meta_display_in_sitemap')->xpath('meta_display_in_sitemap');
    $this->addFieldMapping('field_canonical_url', 'canonical_url')->xpath('canonical_url');
    $this->addFieldMapping('field_status', 'status')->xpath('status');
    $this->addFieldMapping('field_access_status', 'access_status')->xpath('access_status');
    $this->addFieldMapping('field_display_start_date', 'display_start_date')->xpath('display_start_date');
    $this->addFieldMapping('field_display_end_date', 'display_end_date')->xpath('display_end_date');
    $this->addFieldMapping('field_display_search', 'display_in_search')->xpath('display_in_search');
    $this->addFieldMapping('field_created', 'created')->xpath('created');
    $this->addFieldMapping('field_updated', 'updated')->xpath('updated');
    $this->addFieldMapping('field_access', 'access')->xpath('access');
    $this->addFieldMapping('field_url', 'url')->xpath('url');
    $this->addFieldMapping('field_description', 'description')->xpath('description');
    $this->addFieldMapping('field_image_id', 'image1id')->xpath('image1id');
    $this->addFieldMapping('field_site_userid', 'site_userid')->xpath('site_userid');
    //$this->addFieldMapping('', 'tags')->xpath('');
    $this->addFieldMapping('field_company', 'company_tag')->xpath('company_tag');
    $this->addFieldMapping('field_geography', 'geography_tag')->xpath('geography_tag');
    $this->addFieldMapping('field_section', 'section_tag')->xpath('section_tag');
    $this->addFieldMapping('field_sector', 'sector_tag')->xpath('sector_tag');
    $this->addFieldMapping('field_erp', 'erp_tag')->xpath('erp_tag');
  }
  
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    //taxonomy fields map
    $tax_fields = array(
      'company_tag' => 'company',
      'geography_tag' => 'geography',
      'section_tag' => 'section',
      'sector_tag' => 'sector_',
      'erp_tag' => 'erp',
    );
    //search for the term and if it is not there add it
    foreach($tax_fields as $field => $vocabulary_name) {
      $search_term = $row->$field;
      $obj_vocabulary = taxonomy_vocabulary_machine_name_load($vocabulary_name);
      $term_list = taxonomy_get_tree($obj_vocabulary->vid);
      foreach($term_list as $term) {
        if($term->name == $search_term) break;
      }
      if($term->name != $search_term) {
        $new_term = new stdClass();
        $new_term->name = $search_term;
        $new_term->vid = $obj_vocabulary->vid;
        taxonomy_term_save($new_term);
        watchdog("migrate:taxonomy message", "added $search_term to $vocabulary_name");
      }
    }
    return TRUE;
  }
}
?>

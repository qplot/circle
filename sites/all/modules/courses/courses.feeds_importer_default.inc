<?php
/**
 * @file
 * courses.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function courses_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'advisor_importer';
  $feeds_importer->config = array(
    'name' => 'Advisor Importer',
    'description' => 'Importer for advisors',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 1,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => '|',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'STU_CAMPUS_ID',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'STU_CAMPUS_ID',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'STU_CAMPUS_ID',
            'target' => 'field_advisors_student',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'ADV_CAMPUS_ID',
            'target' => 'field_advisors_advisor_campusid',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'ADV_CAMPUS_ID',
            'target' => 'field_advisors_advisor',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'DEAN_CAMPUS_ID',
            'target' => 'field_advisors_dean_campusid',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'DEAN_CAMPUS_ID',
            'target' => 'field_advisors_dean',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'advisors',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['advisor_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'class_importer';
  $feeds_importer->config = array(
    'name' => 'Class Importer',
    'description' => 'Importer for classes',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 1,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => '|',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'CLASS_NBR',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'SUBJECT',
            'target' => 'field_class_subject',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'CATALOG_NBR',
            'target' => 'field_class_catalognbr',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'SECTION',
            'target' => 'field_class_section',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'TITLE',
            'target' => 'title',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'START_TIME',
            'target' => 'field_class_starttime',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'END_TIME',
            'target' => 'field_class_endtime',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'MON',
            'target' => 'field_class_days',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'TUES',
            'target' => 'field_class_days',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'WED',
            'target' => 'field_class_days',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'THURS',
            'target' => 'field_class_days',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'FRI',
            'target' => 'field_class_days',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'SAT',
            'target' => 'field_class_days',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'SUN',
            'target' => 'field_class_days',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'START_DT',
            'target' => 'field_class_startdate',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'END_DT',
            'target' => 'field_class_enddate',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'BLDG',
            'target' => 'field_class_building',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'ROOM',
            'target' => 'field_class_room',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'CLASS_NBR',
            'target' => 'field_class_nbr',
            'unique' => FALSE,
          ),
          19 => array(
            'source' => '1ST PRI UNIQUE',
            'target' => 'entityreference_lookup:field_class_instructorid',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'class',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['class_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'faculty_importer';
  $feeds_importer->config = array(
    'name' => 'Faculty Importer',
    'description' => 'Importer for faculty',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 1,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => '|',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUserProcessor',
      'config' => array(
        'roles' => array(
          6 => '6',
          3 => 0,
          4 => 0,
          5 => 0,
        ),
        'status' => '1',
        'defuse_mail' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'CAMPUS_ID',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'CAMPUS_ID',
            'target' => 'field_user_campusid',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'DISPLAYNAME',
            'target' => 'field_user_displayname',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'CN',
            'target' => 'field_user_commonname',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'OU',
            'target' => 'field_user_organizationalunit',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'MAIL',
            'target' => 'mail',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'EDUPERSONPRIMARYAFFILIATION',
            'target' => 'field_user_affiliation',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'TITLE',
            'target' => 'field_user_title',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'POSTALADDRESS',
            'target' => 'field_user_address',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'POSTOFFICEBOX',
            'target' => 'field_user_pobox',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'TELEPHONENUMBER',
            'target' => 'field_user_telephone',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'CAMPUS_ID',
            'target' => 'name',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'CAMPUS_ID',
            'target' => 'pass',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'PHOTO',
            'target' => 'field_user_photo:uri',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'user',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['faculty_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'housing_importer';
  $feeds_importer->config = array(
    'name' => 'Housing Importer',
    'description' => 'Importer for housing',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 1,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'CAMPUS_ID',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'CAMPUS_ID',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'CAMPUS_ID',
            'target' => 'entityreference_lookup:field_housing_student',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'location',
            'target' => 'field_housing_location',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'location',
            'target' => 'entityreference_lookup:field_housing_librarian',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'location',
            'target' => 'entityreference_lookup:field_housing_residencefaulty',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'housing',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['housing_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'librarian_importer';
  $feeds_importer->config = array(
    'name' => 'Librarian Importer',
    'description' => 'Importer for librarian',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 1,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'Unique ID',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Unique ID',
            'target' => 'entityreference_lookup:field_librarian_campusid',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Unique ID',
            'target' => 'entityreference:field_librarian_campusid',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Residence Hall',
            'target' => 'title',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Residence Hall',
            'target' => 'field_librarian_residence',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'librarian',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['librarian_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'residence_importer';
  $feeds_importer->config = array(
    'name' => 'Residence Importer',
    'description' => 'Importer for residence',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 1,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => '|',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'Unique ID',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Residence Hall',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Residence Hall',
            'target' => 'field_residence_residence',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Residence Hall Full Address',
            'target' => 'field_residence_residenceaddress',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Unique ID',
            'target' => 'field_residence_campusid',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Unique ID',
            'target' => 'entityreference_lookup:field_residence_campusid',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'residence',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['residence_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'roster_importer';
  $feeds_importer->config = array(
    'name' => 'Roster Importer',
    'description' => 'Roster Import',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 1,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => '|',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'GUID',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'NAME',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'CLASS_NBR',
            'target' => 'field_roster_classnbr',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'COURSE',
            'target' => 'entityreference:field_roster_course',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'CAMPUS_ID',
            'target' => 'entityreference_lookup:field_roster_campusid',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'roster',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['roster_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'student_importer';
  $feeds_importer->config = array(
    'name' => 'Student Importer',
    'description' => 'Importer for students',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 1,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => '|',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUserProcessor',
      'config' => array(
        'roles' => array(
          5 => '5',
          3 => 0,
          4 => 0,
          6 => 0,
        ),
        'status' => '1',
        'defuse_mail' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'CAMPUS_ID',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'NAME',
            'target' => 'field_user_displayname',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'CAMPUS_ID',
            'target' => 'field_user_campusid',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'CAMPUS_ID',
            'target' => 'name',
            'unique' => 0,
          ),
          4 => array(
            'source' => 'CAMPUS_ID',
            'target' => 'pass',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'EMAIL',
            'target' => 'mail',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'user',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['student_importer'] = $feeds_importer;

  return $export;
}

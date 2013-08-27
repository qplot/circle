<?php
/**
 * @file
 * courses.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function courses_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'advisors';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Advisors';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Advisors';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<?php
print l(\'Add Advisor for Student\', \'node/add/advisors\', array(\'query\' => array(\'destination\' => \'advisor\')));
print " | ";
print l(\'Import Advisors\' , \'import/advisor_importer\', array(\'query\' => array(\'destination\' => \'advisor\')));
print " | ";
?>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Relationship: Advisor */
  $handler->display->display_options['relationships']['field_advisors_advisor_target_id']['id'] = 'field_advisors_advisor_target_id';
  $handler->display->display_options['relationships']['field_advisors_advisor_target_id']['table'] = 'field_data_field_advisors_advisor';
  $handler->display->display_options['relationships']['field_advisors_advisor_target_id']['field'] = 'field_advisors_advisor_target_id';
  $handler->display->display_options['relationships']['field_advisors_advisor_target_id']['ui_name'] = 'Advisor';
  $handler->display->display_options['relationships']['field_advisors_advisor_target_id']['label'] = 'Advisor';
  /* Relationship: Dean */
  $handler->display->display_options['relationships']['field_advisors_dean_target_id']['id'] = 'field_advisors_dean_target_id';
  $handler->display->display_options['relationships']['field_advisors_dean_target_id']['table'] = 'field_data_field_advisors_dean';
  $handler->display->display_options['relationships']['field_advisors_dean_target_id']['field'] = 'field_advisors_dean_target_id';
  $handler->display->display_options['relationships']['field_advisors_dean_target_id']['ui_name'] = 'Dean';
  $handler->display->display_options['relationships']['field_advisors_dean_target_id']['label'] = 'Dean';
  /* Relationship: Student */
  $handler->display->display_options['relationships']['field_advisors_student_target_id']['id'] = 'field_advisors_student_target_id';
  $handler->display->display_options['relationships']['field_advisors_student_target_id']['table'] = 'field_data_field_advisors_student';
  $handler->display->display_options['relationships']['field_advisors_student_target_id']['field'] = 'field_advisors_student_target_id';
  $handler->display->display_options['relationships']['field_advisors_student_target_id']['ui_name'] = 'Student';
  $handler->display->display_options['relationships']['field_advisors_student_target_id']['label'] = 'Student';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Student ID';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: User: Display Name */
  $handler->display->display_options['fields']['field_user_displayname']['id'] = 'field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname']['table'] = 'field_data_field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname']['field'] = 'field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname']['relationship'] = 'field_advisors_student_target_id';
  $handler->display->display_options['fields']['field_user_displayname']['label'] = 'Student Name';
  /* Field: Content: Advisor Campus ID */
  $handler->display->display_options['fields']['field_advisors_advisor_campusid']['id'] = 'field_advisors_advisor_campusid';
  $handler->display->display_options['fields']['field_advisors_advisor_campusid']['table'] = 'field_data_field_advisors_advisor_campusid';
  $handler->display->display_options['fields']['field_advisors_advisor_campusid']['field'] = 'field_advisors_advisor_campusid';
  /* Field: User: Display Name */
  $handler->display->display_options['fields']['field_user_displayname_1']['id'] = 'field_user_displayname_1';
  $handler->display->display_options['fields']['field_user_displayname_1']['table'] = 'field_data_field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname_1']['field'] = 'field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname_1']['relationship'] = 'field_advisors_advisor_target_id';
  $handler->display->display_options['fields']['field_user_displayname_1']['label'] = 'Advisor Name';
  /* Field: Content: Dean Campus ID */
  $handler->display->display_options['fields']['field_advisors_dean_campusid']['id'] = 'field_advisors_dean_campusid';
  $handler->display->display_options['fields']['field_advisors_dean_campusid']['table'] = 'field_data_field_advisors_dean_campusid';
  $handler->display->display_options['fields']['field_advisors_dean_campusid']['field'] = 'field_advisors_dean_campusid';
  /* Field: User: Display Name */
  $handler->display->display_options['fields']['field_user_displayname_2']['id'] = 'field_user_displayname_2';
  $handler->display->display_options['fields']['field_user_displayname_2']['table'] = 'field_data_field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname_2']['field'] = 'field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname_2']['relationship'] = 'field_advisors_dean_target_id';
  $handler->display->display_options['fields']['field_user_displayname_2']['label'] = 'Dean Name';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_user_photo']['id'] = 'field_user_photo';
  $handler->display->display_options['fields']['field_user_photo']['table'] = 'field_data_field_user_photo';
  $handler->display->display_options['fields']['field_user_photo']['field'] = 'field_user_photo';
  $handler->display->display_options['fields']['field_user_photo']['relationship'] = 'field_advisors_advisor_target_id';
  $handler->display->display_options['fields']['field_user_photo']['exclude'] = TRUE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_user_photo_1']['id'] = 'field_user_photo_1';
  $handler->display->display_options['fields']['field_user_photo_1']['table'] = 'field_data_field_user_photo';
  $handler->display->display_options['fields']['field_user_photo_1']['field'] = 'field_user_photo';
  $handler->display->display_options['fields']['field_user_photo_1']['relationship'] = 'field_advisors_dean_target_id';
  $handler->display->display_options['fields']['field_user_photo_1']['exclude'] = TRUE;
  /* Field: User: Address */
  $handler->display->display_options['fields']['field_user_address']['id'] = 'field_user_address';
  $handler->display->display_options['fields']['field_user_address']['table'] = 'field_data_field_user_address';
  $handler->display->display_options['fields']['field_user_address']['field'] = 'field_user_address';
  $handler->display->display_options['fields']['field_user_address']['relationship'] = 'field_advisors_advisor_target_id';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'field_advisors_advisor_target_id';
  $handler->display->display_options['fields']['mail']['exclude'] = TRUE;
  /* Field: User: PO Box */
  $handler->display->display_options['fields']['field_user_pobox']['id'] = 'field_user_pobox';
  $handler->display->display_options['fields']['field_user_pobox']['table'] = 'field_data_field_user_pobox';
  $handler->display->display_options['fields']['field_user_pobox']['field'] = 'field_user_pobox';
  $handler->display->display_options['fields']['field_user_pobox']['relationship'] = 'field_advisors_advisor_target_id';
  $handler->display->display_options['fields']['field_user_pobox']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_pobox']['delta_offset'] = '0';
  /* Field: User: Telephone */
  $handler->display->display_options['fields']['field_user_telephone']['id'] = 'field_user_telephone';
  $handler->display->display_options['fields']['field_user_telephone']['table'] = 'field_data_field_user_telephone';
  $handler->display->display_options['fields']['field_user_telephone']['field'] = 'field_user_telephone';
  $handler->display->display_options['fields']['field_user_telephone']['relationship'] = 'field_advisors_advisor_target_id';
  $handler->display->display_options['fields']['field_user_telephone']['exclude'] = TRUE;
  /* Field: User: Address */
  $handler->display->display_options['fields']['field_user_address_1']['id'] = 'field_user_address_1';
  $handler->display->display_options['fields']['field_user_address_1']['table'] = 'field_data_field_user_address';
  $handler->display->display_options['fields']['field_user_address_1']['field'] = 'field_user_address';
  $handler->display->display_options['fields']['field_user_address_1']['relationship'] = 'field_advisors_advisor_target_id';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail_1']['id'] = 'mail_1';
  $handler->display->display_options['fields']['mail_1']['table'] = 'users';
  $handler->display->display_options['fields']['mail_1']['field'] = 'mail';
  $handler->display->display_options['fields']['mail_1']['relationship'] = 'field_advisors_dean_target_id';
  $handler->display->display_options['fields']['mail_1']['exclude'] = TRUE;
  /* Field: User: PO Box */
  $handler->display->display_options['fields']['field_user_pobox_1']['id'] = 'field_user_pobox_1';
  $handler->display->display_options['fields']['field_user_pobox_1']['table'] = 'field_data_field_user_pobox';
  $handler->display->display_options['fields']['field_user_pobox_1']['field'] = 'field_user_pobox';
  $handler->display->display_options['fields']['field_user_pobox_1']['relationship'] = 'field_advisors_dean_target_id';
  $handler->display->display_options['fields']['field_user_pobox_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_pobox_1']['delta_offset'] = '0';
  /* Field: User: Telephone */
  $handler->display->display_options['fields']['field_user_telephone_1']['id'] = 'field_user_telephone_1';
  $handler->display->display_options['fields']['field_user_telephone_1']['table'] = 'field_data_field_user_telephone';
  $handler->display->display_options['fields']['field_user_telephone_1']['field'] = 'field_user_telephone';
  $handler->display->display_options['fields']['field_user_telephone_1']['relationship'] = 'field_advisors_dean_target_id';
  $handler->display->display_options['fields']['field_user_telephone_1']['exclude'] = TRUE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'advisors' => 'advisors',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Campus ID';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'advisors';
  $export['advisors'] = $view;

  $view = new view();
  $view->name = 'classes';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Classes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Classes';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_class_nbr' => 'field_class_nbr',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_class_nbr' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<?php
  print l(\'Add New Class\', \'node/add/class\', array(\'query\' => array(\'destination\' => \'classes\')));
  print " | ";
  print l(\'Import Classes\', \'import/class_importer\', array(\'query\' => array(\'destination\' => \'classes\')));
  print " | ";
?>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['empty'] = TRUE;
  /* Relationship: Instructor */
  $handler->display->display_options['relationships']['field_class_instructorid_target_id']['id'] = 'field_class_instructorid_target_id';
  $handler->display->display_options['relationships']['field_class_instructorid_target_id']['table'] = 'field_data_field_class_instructorid';
  $handler->display->display_options['relationships']['field_class_instructorid_target_id']['field'] = 'field_class_instructorid_target_id';
  $handler->display->display_options['relationships']['field_class_instructorid_target_id']['ui_name'] = 'Instructor';
  $handler->display->display_options['relationships']['field_class_instructorid_target_id']['label'] = 'Instructor';
  /* Field: Content: Class NBR */
  $handler->display->display_options['fields']['field_class_nbr']['id'] = 'field_class_nbr';
  $handler->display->display_options['fields']['field_class_nbr']['table'] = 'field_data_field_class_nbr';
  $handler->display->display_options['fields']['field_class_nbr']['field'] = 'field_class_nbr';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Days */
  $handler->display->display_options['fields']['field_class_days']['id'] = 'field_class_days';
  $handler->display->display_options['fields']['field_class_days']['table'] = 'field_data_field_class_days';
  $handler->display->display_options['fields']['field_class_days']['field'] = 'field_class_days';
  $handler->display->display_options['fields']['field_class_days']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_class_days']['separator'] = ' ';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_user_full_name']['id'] = 'field_user_full_name';
  $handler->display->display_options['fields']['field_user_full_name']['table'] = 'field_data_field_user_full_name';
  $handler->display->display_options['fields']['field_user_full_name']['field'] = 'field_user_full_name';
  $handler->display->display_options['fields']['field_user_full_name']['relationship'] = 'field_class_instructorid_target_id';
  $handler->display->display_options['fields']['field_user_full_name']['exclude'] = TRUE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'class' => 'class',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Class name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Class NBR (field_class_nbr) */
  $handler->display->display_options['filters']['field_class_nbr_value']['id'] = 'field_class_nbr_value';
  $handler->display->display_options['filters']['field_class_nbr_value']['table'] = 'field_data_field_class_nbr';
  $handler->display->display_options['filters']['field_class_nbr_value']['field'] = 'field_class_nbr_value';
  $handler->display->display_options['filters']['field_class_nbr_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_class_nbr_value']['expose']['operator_id'] = 'field_class_nbr_value_op';
  $handler->display->display_options['filters']['field_class_nbr_value']['expose']['label'] = 'Class NBR';
  $handler->display->display_options['filters']['field_class_nbr_value']['expose']['operator'] = 'field_class_nbr_value_op';
  $handler->display->display_options['filters']['field_class_nbr_value']['expose']['identifier'] = 'field_class_nbr_value';
  $handler->display->display_options['filters']['field_class_nbr_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Classes */
  $handler = $view->new_display('page', 'Classes', 'classes');
  $handler->display->display_options['path'] = 'classes';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Classes';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $export['classes'] = $view;

  $view = new view();
  $view->name = 'disabled_accounts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Disabled Accounts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Disabled Accounts';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_user_campusid' => 'field_user_campusid',
    'name' => 'name',
    'php' => 'php',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_user_campusid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No disabled accounts';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Student ID';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: User: Display Name */
  $handler->display->display_options['fields']['field_user_displayname']['id'] = 'field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname']['table'] = 'field_data_field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname']['field'] = 'field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname']['label'] = 'Student Name';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Picture';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$noimg = base_path() . drupal_get_path(\'theme\', \'circle\') . "/images/placeholder.gif";
$stuimg= "public://student";
$stuimg = file_create_url($stuimg)."/";
$ID = $row->name;
$pic = $stuimg.$ID.\'.jpeg\';
?>
<img src="<?php echo $pic; ?>" width="100px" onerror="this.src=\'<?php echo $noimg; ?>\'">';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Change Status';
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'users';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = '0';
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['operator'] = 'not in';
  $handler->display->display_options['filters']['uid']['value'] = array(
    0 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'disabledaccounts';
  $export['disabled_accounts'] = $view;

  $view = new view();
  $view->name = 'housing';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Housing';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Housing';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_user_displayname' => 'field_user_displayname',
    'field_housing_location' => 'field_housing_location',
    'field_user_displayname_1' => 'field_user_displayname_1',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_displayname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_housing_location' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_displayname_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<?php
  print l(\'Add New Housing Info\', \'node/add/housing\', array(\'query\' => array(\'destination\' => \'housing\')));
  print " | ";
  print l(\'Import Housing\', \'import/housing_importer\', array(\'query\' => array(\'destination\' => \'housing\')));
  print " | ";
?>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Relationship: Student */
  $handler->display->display_options['relationships']['field_housing_student_target_id']['id'] = 'field_housing_student_target_id';
  $handler->display->display_options['relationships']['field_housing_student_target_id']['table'] = 'field_data_field_housing_student';
  $handler->display->display_options['relationships']['field_housing_student_target_id']['field'] = 'field_housing_student_target_id';
  $handler->display->display_options['relationships']['field_housing_student_target_id']['ui_name'] = 'Student';
  $handler->display->display_options['relationships']['field_housing_student_target_id']['label'] = 'Student';
  /* Relationship: Librarian */
  $handler->display->display_options['relationships']['field_housing_librarian_target_id']['id'] = 'field_housing_librarian_target_id';
  $handler->display->display_options['relationships']['field_housing_librarian_target_id']['table'] = 'field_data_field_housing_librarian';
  $handler->display->display_options['relationships']['field_housing_librarian_target_id']['field'] = 'field_housing_librarian_target_id';
  $handler->display->display_options['relationships']['field_housing_librarian_target_id']['ui_name'] = 'Librarian';
  $handler->display->display_options['relationships']['field_housing_librarian_target_id']['label'] = 'Librarian';
  /* Relationship: Librarian2 */
  $handler->display->display_options['relationships']['field_librarian_campusid_target_id']['id'] = 'field_librarian_campusid_target_id';
  $handler->display->display_options['relationships']['field_librarian_campusid_target_id']['table'] = 'field_data_field_librarian_campusid';
  $handler->display->display_options['relationships']['field_librarian_campusid_target_id']['field'] = 'field_librarian_campusid_target_id';
  $handler->display->display_options['relationships']['field_librarian_campusid_target_id']['relationship'] = 'field_housing_librarian_target_id';
  $handler->display->display_options['relationships']['field_librarian_campusid_target_id']['ui_name'] = 'Librarian2';
  $handler->display->display_options['relationships']['field_librarian_campusid_target_id']['label'] = 'Librarian2';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_housing_residencefaulty_target_id']['id'] = 'field_housing_residencefaulty_target_id';
  $handler->display->display_options['relationships']['field_housing_residencefaulty_target_id']['table'] = 'field_data_field_housing_residencefaulty';
  $handler->display->display_options['relationships']['field_housing_residencefaulty_target_id']['field'] = 'field_housing_residencefaulty_target_id';
  $handler->display->display_options['relationships']['field_housing_residencefaulty_target_id']['label'] = 'Residence';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_residence_campusid_target_id']['id'] = 'field_residence_campusid_target_id';
  $handler->display->display_options['relationships']['field_residence_campusid_target_id']['table'] = 'field_data_field_residence_campusid';
  $handler->display->display_options['relationships']['field_residence_campusid_target_id']['field'] = 'field_residence_campusid_target_id';
  $handler->display->display_options['relationships']['field_residence_campusid_target_id']['relationship'] = 'field_housing_residencefaulty_target_id';
  $handler->display->display_options['relationships']['field_residence_campusid_target_id']['label'] = 'Residence';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Student ID';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: User: Display Name */
  $handler->display->display_options['fields']['field_user_displayname']['id'] = 'field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname']['table'] = 'field_data_field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname']['field'] = 'field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname']['relationship'] = 'field_housing_student_target_id';
  $handler->display->display_options['fields']['field_user_displayname']['label'] = 'Student Name';
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_housing_location']['id'] = 'field_housing_location';
  $handler->display->display_options['fields']['field_housing_location']['table'] = 'field_data_field_housing_location';
  $handler->display->display_options['fields']['field_housing_location']['field'] = 'field_housing_location';
  /* Field: User: Display Name */
  $handler->display->display_options['fields']['field_user_displayname_1']['id'] = 'field_user_displayname_1';
  $handler->display->display_options['fields']['field_user_displayname_1']['table'] = 'field_data_field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname_1']['field'] = 'field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname_1']['relationship'] = 'field_librarian_campusid_target_id';
  $handler->display->display_options['fields']['field_user_displayname_1']['label'] = 'Librarian Name';
  /* Field: User: Campus ID */
  $handler->display->display_options['fields']['field_user_campusid']['id'] = 'field_user_campusid';
  $handler->display->display_options['fields']['field_user_campusid']['table'] = 'field_data_field_user_campusid';
  $handler->display->display_options['fields']['field_user_campusid']['field'] = 'field_user_campusid';
  $handler->display->display_options['fields']['field_user_campusid']['relationship'] = 'field_librarian_campusid_target_id';
  $handler->display->display_options['fields']['field_user_campusid']['label'] = 'Librarian ID';
  /* Field: User: Address */
  $handler->display->display_options['fields']['field_user_address']['id'] = 'field_user_address';
  $handler->display->display_options['fields']['field_user_address']['table'] = 'field_data_field_user_address';
  $handler->display->display_options['fields']['field_user_address']['field'] = 'field_user_address';
  $handler->display->display_options['fields']['field_user_address']['relationship'] = 'field_librarian_campusid_target_id';
  $handler->display->display_options['fields']['field_user_address']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_address']['delta_offset'] = '0';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'field_librarian_campusid_target_id';
  $handler->display->display_options['fields']['mail']['exclude'] = TRUE;
  /* Field: User: PO Box */
  $handler->display->display_options['fields']['field_user_pobox']['id'] = 'field_user_pobox';
  $handler->display->display_options['fields']['field_user_pobox']['table'] = 'field_data_field_user_pobox';
  $handler->display->display_options['fields']['field_user_pobox']['field'] = 'field_user_pobox';
  $handler->display->display_options['fields']['field_user_pobox']['relationship'] = 'field_librarian_campusid_target_id';
  $handler->display->display_options['fields']['field_user_pobox']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_pobox']['delta_offset'] = '0';
  /* Field: User: Telephone */
  $handler->display->display_options['fields']['field_user_telephone']['id'] = 'field_user_telephone';
  $handler->display->display_options['fields']['field_user_telephone']['table'] = 'field_data_field_user_telephone';
  $handler->display->display_options['fields']['field_user_telephone']['field'] = 'field_user_telephone';
  $handler->display->display_options['fields']['field_user_telephone']['relationship'] = 'field_librarian_campusid_target_id';
  $handler->display->display_options['fields']['field_user_telephone']['exclude'] = TRUE;
  /* Field: User: Display Name */
  $handler->display->display_options['fields']['field_user_displayname_2']['id'] = 'field_user_displayname_2';
  $handler->display->display_options['fields']['field_user_displayname_2']['table'] = 'field_data_field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname_2']['field'] = 'field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname_2']['relationship'] = 'field_residence_campusid_target_id';
  $handler->display->display_options['fields']['field_user_displayname_2']['label'] = 'Residence Name';
  /* Field: User: Address */
  $handler->display->display_options['fields']['field_user_address_1']['id'] = 'field_user_address_1';
  $handler->display->display_options['fields']['field_user_address_1']['table'] = 'field_data_field_user_address';
  $handler->display->display_options['fields']['field_user_address_1']['field'] = 'field_user_address';
  $handler->display->display_options['fields']['field_user_address_1']['relationship'] = 'field_residence_campusid_target_id';
  $handler->display->display_options['fields']['field_user_address_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_address_1']['delta_offset'] = '0';
  /* Field: User: Campus ID */
  $handler->display->display_options['fields']['field_user_campusid_1']['id'] = 'field_user_campusid_1';
  $handler->display->display_options['fields']['field_user_campusid_1']['table'] = 'field_data_field_user_campusid';
  $handler->display->display_options['fields']['field_user_campusid_1']['field'] = 'field_user_campusid';
  $handler->display->display_options['fields']['field_user_campusid_1']['relationship'] = 'field_residence_campusid_target_id';
  $handler->display->display_options['fields']['field_user_campusid_1']['label'] = 'Residence ID';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail_1']['id'] = 'mail_1';
  $handler->display->display_options['fields']['mail_1']['table'] = 'users';
  $handler->display->display_options['fields']['mail_1']['field'] = 'mail';
  $handler->display->display_options['fields']['mail_1']['relationship'] = 'field_residence_campusid_target_id';
  $handler->display->display_options['fields']['mail_1']['exclude'] = TRUE;
  /* Field: User: PO Box */
  $handler->display->display_options['fields']['field_user_pobox_1']['id'] = 'field_user_pobox_1';
  $handler->display->display_options['fields']['field_user_pobox_1']['table'] = 'field_data_field_user_pobox';
  $handler->display->display_options['fields']['field_user_pobox_1']['field'] = 'field_user_pobox';
  $handler->display->display_options['fields']['field_user_pobox_1']['relationship'] = 'field_residence_campusid_target_id';
  $handler->display->display_options['fields']['field_user_pobox_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_pobox_1']['delta_offset'] = '0';
  /* Field: User: Telephone */
  $handler->display->display_options['fields']['field_user_telephone_1']['id'] = 'field_user_telephone_1';
  $handler->display->display_options['fields']['field_user_telephone_1']['table'] = 'field_data_field_user_telephone';
  $handler->display->display_options['fields']['field_user_telephone_1']['field'] = 'field_user_telephone';
  $handler->display->display_options['fields']['field_user_telephone_1']['relationship'] = 'field_residence_campusid_target_id';
  $handler->display->display_options['fields']['field_user_telephone_1']['exclude'] = TRUE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'housing' => 'housing',
  );
  /* Filter criterion: campus_id */
  $handler->display->display_options['filters']['field_user_campusid_value']['id'] = 'field_user_campusid_value';
  $handler->display->display_options['filters']['field_user_campusid_value']['table'] = 'field_data_field_user_campusid';
  $handler->display->display_options['filters']['field_user_campusid_value']['field'] = 'field_user_campusid_value';
  $handler->display->display_options['filters']['field_user_campusid_value']['relationship'] = 'field_housing_student_target_id';
  $handler->display->display_options['filters']['field_user_campusid_value']['ui_name'] = 'campus_id';
  $handler->display->display_options['filters']['field_user_campusid_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_campusid_value']['expose']['operator_id'] = 'field_user_campusid_value_op';
  $handler->display->display_options['filters']['field_user_campusid_value']['expose']['label'] = 'Campus ID';
  $handler->display->display_options['filters']['field_user_campusid_value']['expose']['operator'] = 'field_user_campusid_value_op';
  $handler->display->display_options['filters']['field_user_campusid_value']['expose']['identifier'] = 'campus_id';
  $handler->display->display_options['filters']['field_user_campusid_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Location (field_housing_location) */
  $handler->display->display_options['filters']['field_housing_location_tid']['id'] = 'field_housing_location_tid';
  $handler->display->display_options['filters']['field_housing_location_tid']['table'] = 'field_data_field_housing_location';
  $handler->display->display_options['filters']['field_housing_location_tid']['field'] = 'field_housing_location_tid';
  $handler->display->display_options['filters']['field_housing_location_tid']['value'] = '';
  $handler->display->display_options['filters']['field_housing_location_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_housing_location_tid']['expose']['operator_id'] = 'field_housing_location_tid_op';
  $handler->display->display_options['filters']['field_housing_location_tid']['expose']['label'] = 'Location';
  $handler->display->display_options['filters']['field_housing_location_tid']['expose']['operator'] = 'field_housing_location_tid_op';
  $handler->display->display_options['filters']['field_housing_location_tid']['expose']['identifier'] = 'field_housing_location_tid';
  $handler->display->display_options['filters']['field_housing_location_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_housing_location_tid']['vocabulary'] = 'location';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'housing';
  $export['housing'] = $view;

  $view = new view();
  $view->name = 'librarian';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Librarian';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Librarian';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<?php
  print l(\'Add New Librarian\', \'node/add/librarian\', array(\'query\' => array(\'destination\' => \'librarian\')));
  print " | ";
  print l(\'Import Librarians\', \'import/librarian_importer\', array(\'query\' => array(\'destination\' => \'librarian\')));
  print " | ";
?>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Relationship: Librarian */
  $handler->display->display_options['relationships']['field_librarian_campusid_target_id']['id'] = 'field_librarian_campusid_target_id';
  $handler->display->display_options['relationships']['field_librarian_campusid_target_id']['table'] = 'field_data_field_librarian_campusid';
  $handler->display->display_options['relationships']['field_librarian_campusid_target_id']['field'] = 'field_librarian_campusid_target_id';
  $handler->display->display_options['relationships']['field_librarian_campusid_target_id']['ui_name'] = 'Librarian';
  $handler->display->display_options['relationships']['field_librarian_campusid_target_id']['label'] = 'Librarian';
  /* Field: User: Campus ID */
  $handler->display->display_options['fields']['field_user_campusid']['id'] = 'field_user_campusid';
  $handler->display->display_options['fields']['field_user_campusid']['table'] = 'field_data_field_user_campusid';
  $handler->display->display_options['fields']['field_user_campusid']['field'] = 'field_user_campusid';
  $handler->display->display_options['fields']['field_user_campusid']['relationship'] = 'field_librarian_campusid_target_id';
  $handler->display->display_options['fields']['field_user_campusid']['label'] = 'Librarian ID';
  /* Field: User: Display Name */
  $handler->display->display_options['fields']['field_user_displayname']['id'] = 'field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname']['table'] = 'field_data_field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname']['field'] = 'field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname']['relationship'] = 'field_librarian_campusid_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Residence';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Residence (field_librarian_residence) */
  $handler->display->display_options['sorts']['field_librarian_residence_tid']['id'] = 'field_librarian_residence_tid';
  $handler->display->display_options['sorts']['field_librarian_residence_tid']['table'] = 'field_data_field_librarian_residence';
  $handler->display->display_options['sorts']['field_librarian_residence_tid']['field'] = 'field_librarian_residence_tid';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'librarian' => 'librarian',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'librarian';
  $export['librarian'] = $view;

  $view = new view();
  $view->name = 'my_faculty';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'My Faculty';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My Faculty';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'users';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$insimg = "public://faculty";
$insimg = file_create_url($insimg)."/";
$ID = $row->name;
$pic = $insimg.$ID.\'.jpeg\';
?>
<img src="<?php echo $pic; ?>" width="120px">';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: User: Display Name */
  $handler->display->display_options['fields']['field_user_displayname']['id'] = 'field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname']['table'] = 'field_data_field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname']['field'] = 'field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname']['label'] = '';
  $handler->display->display_options['fields']['field_user_displayname']['element_label_colon'] = FALSE;
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Title (field_user_title) */
  $handler->display->display_options['filters']['field_user_title_value']['id'] = 'field_user_title_value';
  $handler->display->display_options['filters']['field_user_title_value']['table'] = 'field_data_field_user_title';
  $handler->display->display_options['filters']['field_user_title_value']['field'] = 'field_user_title_value';
  $handler->display->display_options['filters']['field_user_title_value']['operator'] = 'not empty';
  /* Filter criterion: User: Name (raw) */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'users';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Campus ID';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'myfaculty';
  $export['my_faculty'] = $view;

  $view = new view();
  $view->name = 'my_students';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'My Students';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My Students';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '16';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'users';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$noimg = base_path() . drupal_get_path(\'theme\', \'circle\') . "/images/placeholder.gif";
$stuimg= "public://student";
$stuimg = file_create_url($stuimg)."/";
$ID = $row->name;
$pic = $stuimg.$ID.\'.jpeg\';
?>
<img src="<?php echo $pic; ?>" width="120px" onerror="this.src=\'<?php echo $noimg; ?>\'">';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'mycircle/[name]';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: User: Display Name */
  $handler->display->display_options['fields']['field_user_displayname']['id'] = 'field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname']['table'] = 'field_data_field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname']['field'] = 'field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname']['label'] = '';
  $handler->display->display_options['fields']['field_user_displayname']['element_label_colon'] = FALSE;
  /* Field: Disable Link */
  $handler->display->display_options['fields']['cancel_node']['id'] = 'cancel_node';
  $handler->display->display_options['fields']['cancel_node']['table'] = 'users';
  $handler->display->display_options['fields']['cancel_node']['field'] = 'cancel_node';
  $handler->display->display_options['fields']['cancel_node']['ui_name'] = 'Disable Link';
  $handler->display->display_options['fields']['cancel_node']['label'] = '';
  $handler->display->display_options['fields']['cancel_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['cancel_node']['text'] = 'Disable Account';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Title (field_user_title) */
  $handler->display->display_options['filters']['field_user_title_value']['id'] = 'field_user_title_value';
  $handler->display->display_options['filters']['field_user_title_value']['table'] = 'field_data_field_user_title';
  $handler->display->display_options['filters']['field_user_title_value']['field'] = 'field_user_title_value';
  $handler->display->display_options['filters']['field_user_title_value']['operator'] = 'empty';
  /* Filter criterion: User: Campus ID (field_user_campusid) */
  $handler->display->display_options['filters']['field_user_campusid_value']['id'] = 'field_user_campusid_value';
  $handler->display->display_options['filters']['field_user_campusid_value']['table'] = 'field_data_field_user_campusid';
  $handler->display->display_options['filters']['field_user_campusid_value']['field'] = 'field_user_campusid_value';
  $handler->display->display_options['filters']['field_user_campusid_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_campusid_value']['expose']['operator_id'] = 'field_user_campusid_value_op';
  $handler->display->display_options['filters']['field_user_campusid_value']['expose']['label'] = 'Campus ID';
  $handler->display->display_options['filters']['field_user_campusid_value']['expose']['operator'] = 'field_user_campusid_value_op';
  $handler->display->display_options['filters']['field_user_campusid_value']['expose']['identifier'] = 'field_user_campusid_value';
  $handler->display->display_options['filters']['field_user_campusid_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'mystudents';
  $export['my_students'] = $view;

  $view = new view();
  $view->name = 'reference_user';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Reference User';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: User: Campus ID */
  $handler->display->display_options['fields']['field_user_campusid']['id'] = 'field_user_campusid';
  $handler->display->display_options['fields']['field_user_campusid']['table'] = 'field_data_field_user_campusid';
  $handler->display->display_options['fields']['field_user_campusid']['field'] = 'field_user_campusid';
  $handler->display->display_options['fields']['field_user_campusid']['label'] = '';
  $handler->display->display_options['fields']['field_user_campusid']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_user_full_name']['id'] = 'field_user_full_name';
  $handler->display->display_options['fields']['field_user_full_name']['table'] = 'field_data_field_user_full_name';
  $handler->display->display_options['fields']['field_user_full_name']['field'] = 'field_user_full_name';
  $handler->display->display_options['fields']['field_user_full_name']['label'] = '';
  $handler->display->display_options['fields']['field_user_full_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_full_name']['element_label_colon'] = FALSE;
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Campus ID (field_user_campusid) */
  $handler->display->display_options['filters']['field_user_campusid_value']['id'] = 'field_user_campusid_value';
  $handler->display->display_options['filters']['field_user_campusid_value']['table'] = 'field_data_field_user_campusid';
  $handler->display->display_options['filters']['field_user_campusid_value']['field'] = 'field_user_campusid_value';
  $handler->display->display_options['filters']['field_user_campusid_value']['operator'] = 'starts';
  $handler->display->display_options['filters']['field_user_campusid_value']['expose']['operator_id'] = 'field_user_campusid_value_op';
  $handler->display->display_options['filters']['field_user_campusid_value']['expose']['label'] = 'Campus ID';
  $handler->display->display_options['filters']['field_user_campusid_value']['expose']['operator'] = 'field_user_campusid_value_op';
  $handler->display->display_options['filters']['field_user_campusid_value']['expose']['identifier'] = 'campus_id';
  $handler->display->display_options['filters']['field_user_campusid_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'field_user_campusid' => 'field_user_campusid',
    'field_user_full_name' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_user_campusid' => 'field_user_campusid',
    'field_user_full_name' => 'field_user_full_name',
  );
  $handler->display->display_options['row_options']['separator'] = '';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['reference_user'] = $view;

  $view = new view();
  $view->name = 'residence';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Residence';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Residence';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<?php
  print l(\'Add New Residence\', \'node/add/residence\', array(\'query\' => array(\'destination\' => \'residence\')));
  print " | ";
  print l(\'Import Residence\', \'import/residence_importer\', array(\'query\' => array(\'destination\' => \'residence\')));
  print " | ";
?>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['empty'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_residence_campusid_target_id']['id'] = 'field_residence_campusid_target_id';
  $handler->display->display_options['relationships']['field_residence_campusid_target_id']['table'] = 'field_data_field_residence_campusid';
  $handler->display->display_options['relationships']['field_residence_campusid_target_id']['field'] = 'field_residence_campusid_target_id';
  $handler->display->display_options['relationships']['field_residence_campusid_target_id']['label'] = 'Residence';
  /* Field: User: Display Name */
  $handler->display->display_options['fields']['field_user_displayname']['id'] = 'field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname']['table'] = 'field_data_field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname']['field'] = 'field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname']['relationship'] = 'field_residence_campusid_target_id';
  /* Field: Content: Residence Hall */
  $handler->display->display_options['fields']['field_residence_residence']['id'] = 'field_residence_residence';
  $handler->display->display_options['fields']['field_residence_residence']['table'] = 'field_data_field_residence_residence';
  $handler->display->display_options['fields']['field_residence_residence']['field'] = 'field_residence_residence';
  /* Field: Content: Residence Hall Address */
  $handler->display->display_options['fields']['field_residence_residenceaddress']['id'] = 'field_residence_residenceaddress';
  $handler->display->display_options['fields']['field_residence_residenceaddress']['table'] = 'field_data_field_residence_residenceaddress';
  $handler->display->display_options['fields']['field_residence_residenceaddress']['field'] = 'field_residence_residenceaddress';
  /* Field: User: Address */
  $handler->display->display_options['fields']['field_user_address']['id'] = 'field_user_address';
  $handler->display->display_options['fields']['field_user_address']['table'] = 'field_data_field_user_address';
  $handler->display->display_options['fields']['field_user_address']['field'] = 'field_user_address';
  $handler->display->display_options['fields']['field_user_address']['relationship'] = 'field_residence_campusid_target_id';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'field_residence_campusid_target_id';
  /* Field: User: PO Box */
  $handler->display->display_options['fields']['field_user_pobox']['id'] = 'field_user_pobox';
  $handler->display->display_options['fields']['field_user_pobox']['table'] = 'field_data_field_user_pobox';
  $handler->display->display_options['fields']['field_user_pobox']['field'] = 'field_user_pobox';
  $handler->display->display_options['fields']['field_user_pobox']['relationship'] = 'field_residence_campusid_target_id';
  $handler->display->display_options['fields']['field_user_pobox']['delta_offset'] = '0';
  /* Field: User: Telephone */
  $handler->display->display_options['fields']['field_user_telephone']['id'] = 'field_user_telephone';
  $handler->display->display_options['fields']['field_user_telephone']['table'] = 'field_data_field_user_telephone';
  $handler->display->display_options['fields']['field_user_telephone']['field'] = 'field_user_telephone';
  $handler->display->display_options['fields']['field_user_telephone']['relationship'] = 'field_residence_campusid_target_id';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'residence' => 'residence',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'residence';
  $export['residence'] = $view;

  $view = new view();
  $view->name = 'roster';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Roster';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Roster';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<?php
print l(\'Enroll Student\', \'node/add/roster\', array(\'query\' => array(\'destination\' => \'roster\')));
print " | ";
print l(\'Import Roster\' , \'import/roster_importer\', array(\'query\' => array(\'destination\' => \'roster\')));
print " | ";
?>
';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['empty'] = TRUE;
  /* Relationship: Course */
  $handler->display->display_options['relationships']['field_roster_course_target_id']['id'] = 'field_roster_course_target_id';
  $handler->display->display_options['relationships']['field_roster_course_target_id']['table'] = 'field_data_field_roster_course';
  $handler->display->display_options['relationships']['field_roster_course_target_id']['field'] = 'field_roster_course_target_id';
  $handler->display->display_options['relationships']['field_roster_course_target_id']['ui_name'] = 'Course';
  $handler->display->display_options['relationships']['field_roster_course_target_id']['label'] = 'Course';
  /* Relationship: Instructor */
  $handler->display->display_options['relationships']['field_class_instructorid_target_id']['id'] = 'field_class_instructorid_target_id';
  $handler->display->display_options['relationships']['field_class_instructorid_target_id']['table'] = 'field_data_field_class_instructorid';
  $handler->display->display_options['relationships']['field_class_instructorid_target_id']['field'] = 'field_class_instructorid_target_id';
  $handler->display->display_options['relationships']['field_class_instructorid_target_id']['relationship'] = 'field_roster_course_target_id';
  $handler->display->display_options['relationships']['field_class_instructorid_target_id']['ui_name'] = 'Instructor';
  $handler->display->display_options['relationships']['field_class_instructorid_target_id']['label'] = 'Instructor';
  /* Relationship: Student */
  $handler->display->display_options['relationships']['field_roster_campusid_target_id']['id'] = 'field_roster_campusid_target_id';
  $handler->display->display_options['relationships']['field_roster_campusid_target_id']['table'] = 'field_data_field_roster_campusid';
  $handler->display->display_options['relationships']['field_roster_campusid_target_id']['field'] = 'field_roster_campusid_target_id';
  $handler->display->display_options['relationships']['field_roster_campusid_target_id']['ui_name'] = 'Student';
  $handler->display->display_options['relationships']['field_roster_campusid_target_id']['label'] = 'Student';
  /* Field: User: Campus ID */
  $handler->display->display_options['fields']['field_user_campusid']['id'] = 'field_user_campusid';
  $handler->display->display_options['fields']['field_user_campusid']['table'] = 'field_data_field_user_campusid';
  $handler->display->display_options['fields']['field_user_campusid']['field'] = 'field_user_campusid';
  $handler->display->display_options['fields']['field_user_campusid']['relationship'] = 'field_roster_campusid_target_id';
  /* Field: User: Display Name */
  $handler->display->display_options['fields']['field_user_displayname']['id'] = 'field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname']['table'] = 'field_data_field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname']['field'] = 'field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname']['relationship'] = 'field_roster_campusid_target_id';
  $handler->display->display_options['fields']['field_user_displayname']['label'] = 'Student Name';
  /* Field: Content: Class NBR */
  $handler->display->display_options['fields']['field_roster_classnbr']['id'] = 'field_roster_classnbr';
  $handler->display->display_options['fields']['field_roster_classnbr']['table'] = 'field_data_field_roster_classnbr';
  $handler->display->display_options['fields']['field_roster_classnbr']['field'] = 'field_roster_classnbr';
  $handler->display->display_options['fields']['field_roster_classnbr']['label'] = 'NBR';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_roster_course_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Course';
  /* Field: User: Display Name */
  $handler->display->display_options['fields']['field_user_displayname_1']['id'] = 'field_user_displayname_1';
  $handler->display->display_options['fields']['field_user_displayname_1']['table'] = 'field_data_field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname_1']['field'] = 'field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname_1']['relationship'] = 'field_class_instructorid_target_id';
  $handler->display->display_options['fields']['field_user_displayname_1']['label'] = 'Instructor Name';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'field_class_instructorid_target_id';
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  /* Field: Content: Days */
  $handler->display->display_options['fields']['field_class_days']['id'] = 'field_class_days';
  $handler->display->display_options['fields']['field_class_days']['table'] = 'field_data_field_class_days';
  $handler->display->display_options['fields']['field_class_days']['field'] = 'field_class_days';
  $handler->display->display_options['fields']['field_class_days']['relationship'] = 'field_roster_course_target_id';
  $handler->display->display_options['fields']['field_class_days']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_class_days']['delta_offset'] = '0';
  /* Field: Content: End Time */
  $handler->display->display_options['fields']['field_class_endtime']['id'] = 'field_class_endtime';
  $handler->display->display_options['fields']['field_class_endtime']['table'] = 'field_data_field_class_endtime';
  $handler->display->display_options['fields']['field_class_endtime']['field'] = 'field_class_endtime';
  $handler->display->display_options['fields']['field_class_endtime']['relationship'] = 'field_roster_course_target_id';
  $handler->display->display_options['fields']['field_class_endtime']['exclude'] = TRUE;
  /* Field: Content: Start Time */
  $handler->display->display_options['fields']['field_class_starttime']['id'] = 'field_class_starttime';
  $handler->display->display_options['fields']['field_class_starttime']['table'] = 'field_data_field_class_starttime';
  $handler->display->display_options['fields']['field_class_starttime']['field'] = 'field_class_starttime';
  $handler->display->display_options['fields']['field_class_starttime']['relationship'] = 'field_roster_course_target_id';
  $handler->display->display_options['fields']['field_class_starttime']['exclude'] = TRUE;
  /* Field: Content: Building */
  $handler->display->display_options['fields']['field_class_building']['id'] = 'field_class_building';
  $handler->display->display_options['fields']['field_class_building']['table'] = 'field_data_field_class_building';
  $handler->display->display_options['fields']['field_class_building']['field'] = 'field_class_building';
  $handler->display->display_options['fields']['field_class_building']['relationship'] = 'field_roster_course_target_id';
  $handler->display->display_options['fields']['field_class_building']['exclude'] = TRUE;
  /* Field: Content: Room */
  $handler->display->display_options['fields']['field_class_room']['id'] = 'field_class_room';
  $handler->display->display_options['fields']['field_class_room']['table'] = 'field_data_field_class_room';
  $handler->display->display_options['fields']['field_class_room']['field'] = 'field_class_room';
  $handler->display->display_options['fields']['field_class_room']['relationship'] = 'field_roster_course_target_id';
  $handler->display->display_options['fields']['field_class_room']['exclude'] = TRUE;
  /* Field: User: Campus ID */
  $handler->display->display_options['fields']['field_user_campusid_1']['id'] = 'field_user_campusid_1';
  $handler->display->display_options['fields']['field_user_campusid_1']['table'] = 'field_data_field_user_campusid';
  $handler->display->display_options['fields']['field_user_campusid_1']['field'] = 'field_user_campusid';
  $handler->display->display_options['fields']['field_user_campusid_1']['relationship'] = 'field_class_instructorid_target_id';
  $handler->display->display_options['fields']['field_user_campusid_1']['exclude'] = TRUE;
  /* Field: User: Address */
  $handler->display->display_options['fields']['field_user_address']['id'] = 'field_user_address';
  $handler->display->display_options['fields']['field_user_address']['table'] = 'field_data_field_user_address';
  $handler->display->display_options['fields']['field_user_address']['field'] = 'field_user_address';
  $handler->display->display_options['fields']['field_user_address']['relationship'] = 'field_class_instructorid_target_id';
  $handler->display->display_options['fields']['field_user_address']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_address']['delta_offset'] = '0';
  /* Field: User: PO Box */
  $handler->display->display_options['fields']['field_user_pobox']['id'] = 'field_user_pobox';
  $handler->display->display_options['fields']['field_user_pobox']['table'] = 'field_data_field_user_pobox';
  $handler->display->display_options['fields']['field_user_pobox']['field'] = 'field_user_pobox';
  $handler->display->display_options['fields']['field_user_pobox']['relationship'] = 'field_class_instructorid_target_id';
  $handler->display->display_options['fields']['field_user_pobox']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_pobox']['delta_offset'] = '0';
  /* Field: User: Telephone */
  $handler->display->display_options['fields']['field_user_telephone']['id'] = 'field_user_telephone';
  $handler->display->display_options['fields']['field_user_telephone']['table'] = 'field_data_field_user_telephone';
  $handler->display->display_options['fields']['field_user_telephone']['field'] = 'field_user_telephone';
  $handler->display->display_options['fields']['field_user_telephone']['relationship'] = 'field_class_instructorid_target_id';
  $handler->display->display_options['fields']['field_user_telephone']['exclude'] = TRUE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'roster' => 'roster',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Full Name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Class NBR (field_class_nbr) */
  $handler->display->display_options['filters']['field_class_nbr_value']['id'] = 'field_class_nbr_value';
  $handler->display->display_options['filters']['field_class_nbr_value']['table'] = 'field_data_field_class_nbr';
  $handler->display->display_options['filters']['field_class_nbr_value']['field'] = 'field_class_nbr_value';
  $handler->display->display_options['filters']['field_class_nbr_value']['relationship'] = 'field_roster_course_target_id';
  $handler->display->display_options['filters']['field_class_nbr_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_class_nbr_value']['expose']['operator_id'] = 'field_class_nbr_value_op';
  $handler->display->display_options['filters']['field_class_nbr_value']['expose']['label'] = 'Class NBR';
  $handler->display->display_options['filters']['field_class_nbr_value']['expose']['operator'] = 'field_class_nbr_value_op';
  $handler->display->display_options['filters']['field_class_nbr_value']['expose']['identifier'] = 'field_class_nbr_value';
  $handler->display->display_options['filters']['field_class_nbr_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title_1']['id'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['table'] = 'node';
  $handler->display->display_options['filters']['title_1']['field'] = 'title';
  $handler->display->display_options['filters']['title_1']['relationship'] = 'field_roster_course_target_id';
  $handler->display->display_options['filters']['title_1']['operator'] = 'word';
  $handler->display->display_options['filters']['title_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_1']['expose']['operator_id'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['label'] = 'Course Name';
  $handler->display->display_options['filters']['title_1']['expose']['operator'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['identifier'] = 'course_name';
  $handler->display->display_options['filters']['title_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: campus_id */
  $handler->display->display_options['filters']['field_user_campusid_value']['id'] = 'field_user_campusid_value';
  $handler->display->display_options['filters']['field_user_campusid_value']['table'] = 'field_data_field_user_campusid';
  $handler->display->display_options['filters']['field_user_campusid_value']['field'] = 'field_user_campusid_value';
  $handler->display->display_options['filters']['field_user_campusid_value']['relationship'] = 'field_roster_campusid_target_id';
  $handler->display->display_options['filters']['field_user_campusid_value']['ui_name'] = 'campus_id';
  $handler->display->display_options['filters']['field_user_campusid_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_campusid_value']['expose']['operator_id'] = 'field_user_campusid_value_op';
  $handler->display->display_options['filters']['field_user_campusid_value']['expose']['label'] = 'Campus ID';
  $handler->display->display_options['filters']['field_user_campusid_value']['expose']['operator'] = 'field_user_campusid_value_op';
  $handler->display->display_options['filters']['field_user_campusid_value']['expose']['identifier'] = 'campus_id';
  $handler->display->display_options['filters']['field_user_campusid_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Roster */
  $handler = $view->new_display('page', 'Roster', 'page');
  $handler->display->display_options['path'] = 'roster';
  $export['roster'] = $view;

  $view = new view();
  $view->name = 'users';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Users';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Users';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<?php
print l(\'Add User\', \'admin/people/create\', array(\'query\' => array(\'destination\' => \'users\')));
print " | ";
print l(\'Import Faculty\' , \'import/faculty_importer\', array(\'query\' => array(\'destination\' => \'users\')));
print " | ";
print l(\'Import Student\' , \'import/student_importer\', array(\'query\' => array(\'destination\' => \'users\')));
print " | ";
?>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['empty'] = TRUE;
  /* Field: User: Campus ID */
  $handler->display->display_options['fields']['field_user_campusid']['id'] = 'field_user_campusid';
  $handler->display->display_options['fields']['field_user_campusid']['table'] = 'field_data_field_user_campusid';
  $handler->display->display_options['fields']['field_user_campusid']['field'] = 'field_user_campusid';
  /* Field: User: Display Name */
  $handler->display->display_options['fields']['field_user_displayname']['id'] = 'field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname']['table'] = 'field_data_field_user_displayname';
  $handler->display->display_options['fields']['field_user_displayname']['field'] = 'field_user_displayname';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: campus_id */
  $handler->display->display_options['filters']['field_user_campusid_value']['id'] = 'field_user_campusid_value';
  $handler->display->display_options['filters']['field_user_campusid_value']['table'] = 'field_data_field_user_campusid';
  $handler->display->display_options['filters']['field_user_campusid_value']['field'] = 'field_user_campusid_value';
  $handler->display->display_options['filters']['field_user_campusid_value']['ui_name'] = 'campus_id';
  $handler->display->display_options['filters']['field_user_campusid_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_campusid_value']['expose']['operator_id'] = 'field_user_campusid_value_op';
  $handler->display->display_options['filters']['field_user_campusid_value']['expose']['label'] = 'Campus ID';
  $handler->display->display_options['filters']['field_user_campusid_value']['expose']['operator'] = 'field_user_campusid_value_op';
  $handler->display->display_options['filters']['field_user_campusid_value']['expose']['identifier'] = 'campus_id';
  $handler->display->display_options['filters']['field_user_campusid_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Email */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['ui_name'] = 'Email';
  $handler->display->display_options['filters']['mail']['operator'] = 'allwords';
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-mail';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'users';
  $export['users'] = $view;

  return $export;
}

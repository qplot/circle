<?php
/**
 * @file
 * courses.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function courses_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:<front>
  $menu_links['main-menu:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
  );
  // Exported menu link: main-menu:advisors
  $menu_links['main-menu:advisors'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'advisors',
    'router_path' => 'advisors',
    'link_title' => ' Advisors',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'parent_path' => 'classes',
  );
  // Exported menu link: main-menu:classes
  $menu_links['main-menu:classes'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'classes',
    'router_path' => 'classes',
    'link_title' => 'Classes',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'parent_path' => 'classes',
  );
  // Exported menu link: main-menu:comments
  $menu_links['main-menu:comments'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'comments',
    'router_path' => 'comments',
    'link_title' => 'Comments/Questions',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
  );
  // Exported menu link: main-menu:delete-content
  $menu_links['main-menu:delete-content'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'delete-content',
    'router_path' => 'delete-content',
    'link_title' => 'Delete Content',
    'options' => array(
      'attributes' => array(
        'title' => 'Delete content form',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -40,
    'parent_path' => 'import',
  );
  // Exported menu link: main-menu:for-advisors
  $menu_links['main-menu:for-advisors'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'for-advisors',
    'router_path' => 'for-advisors',
    'link_title' => 'Information for Advisors',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
  );
  // Exported menu link: main-menu:housing
  $menu_links['main-menu:housing'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'housing',
    'router_path' => 'housing',
    'link_title' => 'Residence',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'parent_path' => 'classes',
  );
  // Exported menu link: main-menu:import
  $menu_links['main-menu:import'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'import',
    'router_path' => 'import',
    'link_title' => 'Importers',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -46,
  );
  // Exported menu link: main-menu:import-content
  $menu_links['main-menu:import-content'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'import-content',
    'router_path' => 'import-content',
    'link_title' => 'Import All',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -41,
    'parent_path' => 'import',
  );
  // Exported menu link: main-menu:import/advisor_importer
  $menu_links['main-menu:import/advisor_importer'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'import/advisor_importer',
    'router_path' => 'import/%',
    'link_title' => 'Advisors',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'parent_path' => 'import',
  );
  // Exported menu link: main-menu:import/class_importer
  $menu_links['main-menu:import/class_importer'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'import/class_importer',
    'router_path' => 'import/%',
    'link_title' => 'Classes',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'parent_path' => 'import',
  );
  // Exported menu link: main-menu:import/faculty_importer
  $menu_links['main-menu:import/faculty_importer'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'import/faculty_importer',
    'router_path' => 'import/%',
    'link_title' => 'Faculty',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'parent_path' => 'import',
  );
  // Exported menu link: main-menu:import/housing_importer
  $menu_links['main-menu:import/housing_importer'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'import/housing_importer',
    'router_path' => 'import/%',
    'link_title' => 'Residence',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'parent_path' => 'import',
  );
  // Exported menu link: main-menu:import/librarian_importer
  $menu_links['main-menu:import/librarian_importer'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'import/librarian_importer',
    'router_path' => 'import/%',
    'link_title' => 'Librarian',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'parent_path' => 'import',
  );
  // Exported menu link: main-menu:import/residence_importer
  $menu_links['main-menu:import/residence_importer'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'import/residence_importer',
    'router_path' => 'import/%',
    'link_title' => 'Faculty Residence',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'parent_path' => 'import',
  );
  // Exported menu link: main-menu:import/roster_importer
  $menu_links['main-menu:import/roster_importer'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'import/roster_importer',
    'router_path' => 'import/%',
    'link_title' => 'Roster',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'parent_path' => 'import',
  );
  // Exported menu link: main-menu:import/student_importer
  $menu_links['main-menu:import/student_importer'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'import/student_importer',
    'router_path' => 'import/%',
    'link_title' => 'Student',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'parent_path' => 'import',
  );
  // Exported menu link: main-menu:import/user_importer
  $menu_links['main-menu:import/user_importer'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'import/user_importer',
    'router_path' => 'import/%',
    'link_title' => 'Users',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
    'parent_path' => 'import',
  );
  // Exported menu link: main-menu:librarian
  $menu_links['main-menu:librarian'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'librarian',
    'router_path' => 'librarian',
    'link_title' => 'Librarian',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'parent_path' => 'classes',
  );
  // Exported menu link: main-menu:mycircle
  $menu_links['main-menu:mycircle'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'mycircle',
    'router_path' => 'mycircle',
    'link_title' => 'My Network',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
  );
  // Exported menu link: main-menu:myfaculty
  $menu_links['main-menu:myfaculty'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'myfaculty',
    'router_path' => 'myfaculty',
    'link_title' => 'Faculty',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'parent_path' => 'mystudents',
  );
  // Exported menu link: main-menu:mystudents
  $menu_links['main-menu:mystudents'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'mystudents',
    'router_path' => 'mystudents',
    'link_title' => 'Students',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'parent_path' => 'mystudents',
  );
  // Exported menu link: main-menu:residence
  $menu_links['main-menu:residence'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'residence',
    'router_path' => 'residence',
    'link_title' => 'Faculty Residence',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'parent_path' => 'classes',
  );
  // Exported menu link: main-menu:roster
  $menu_links['main-menu:roster'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'roster',
    'router_path' => 'roster',
    'link_title' => 'Roster',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'parent_path' => 'classes',
  );
  // Exported menu link: main-menu:users
  $menu_links['main-menu:users'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'users',
    'router_path' => 'users',
    'link_title' => 'Users',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'parent_path' => 'classes',
  );
  // Exported menu link: user-menu:user/profile
  $menu_links['user-menu:user/profile'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/profile',
    'router_path' => 'user/%',
    'link_title' => 'My Profile',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t(' Advisors');
  t('Advisors');
  t('Classes');
  t('Comments/Questions');
  t('Delete Content');
  t('Faculty');
  t('Faculty Residence');
  t('Home');
  t('Import All');
  t('Importers');
  t('Information for Advisors');
  t('Librarian');
  t('My Network');
  t('My Profile');
  t('Residence');
  t('Roster');
  t('Student');
  t('Students');
  t('Users');


  return $menu_links;
}

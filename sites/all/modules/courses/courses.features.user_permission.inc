<?php
/**
 * @file
 * courses.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function courses_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'view all my circles'.
  $permissions['view all my circles'] = array(
    'name' => 'view all my circles',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'courses',
  );

  // Exported permission: 'view all profiles'.
  $permissions['view all profiles'] = array(
    'name' => 'view all profiles',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'courses',
  );

  // Exported permission: 'view my circle'.
  $permissions['view my circle'] = array(
    'name' => 'view my circle',
    'roles' => array(
      'student' => 'student',
    ),
    'module' => 'courses',
  );

  // Exported permission: 'view my profile'.
  $permissions['view my profile'] = array(
    'name' => 'view my profile',
    'roles' => array(
      'faculty' => 'faculty',
    ),
    'module' => 'courses',
  );

  return $permissions;
}

<?php 

function circle_preprocess_node(&$var) {
//print('123');
  //dsm('123');
  // getting campus id from third argument from URL
  $campus_id = arg(2);
  // get campus id from login user campus id field
   //dsm(arg(0)); // displays "node"
   //dsm(arg(1)); // displays node id
   //dsm(arg(2)); // displays campus id

  //dsm($campus_id);
  if(!empty($campus_id)) {
  $var['courses'] = courses_find_instructors2($campus_id);
  //dsm($var['courses']);
  //dsm('123');
  }

  else { // notices will pop up reguarding invalid arguments due to $courses not existing
    global $user;
    //dsm($user);
    if (!empty($user->uid)) {
      $u = user_load($user->uid);
      //dsm($u);
      if (!in_array("administrator", $u->roles)) {

        if (isset($u->field_user_campusid['und']['0']['value']))
          $campid = $u->field_user_campusid['und']['0']['value'];
      $var['courses'] = courses_find_instructors2($campid);
      // $role = $u->roles;
      //dsm($role);
      //dsm($campid);
      }
    }  
  }
}

function circle_preprocess_block(&$var) {

//  $var['abc'] = 1;
//  dsm($var['block']);
  // defines $url

}

function circle_preprocess_page(&$var) {
  // determine the role of the user
  // if (in_array("student", $role)) {
    // Identify the student's campus id
  // }
  $url = $_SERVER['REQUEST_URI'];
  // dsm(current_path());
  // see if URL contains strong
  if (strpos($url, 'circles/50/small')) {
    $var['theme_hook_suggestion'] = 'page__50__small';
  }
  if (strpos($url, 'circles/50/hover')) {
    $var['theme_hook_suggestion'] = 'page__50__hover';
  }
  if (strpos($url, 'circles/50/0')) {
    $var['theme_hook_suggestion'] = 'page__50__0';
  }
  if (strpos($url, 'circles/50/1')) {
    $var['theme_hook_suggestion'] = 'page__50__1';
  }
  if (strpos($url, 'circles/50/2')) {
    $var['theme_hook_suggestion'] = 'page__50__2';
  }
  if (strpos($url, 'circles/50/3')) {
    $var['theme_hook_suggestion'] = 'page__50__3';
  }
  if (strpos($url, 'circles/50/4')) {
    $var['theme_hook_suggestion'] = 'page__50__4';
  }
  if (strpos($url, 'circles/50/5')) {
    $var['theme_hook_suggestion'] = 'page__50__5';
  }
  if (strpos($url, 'circles/50/6')) {
    $var['theme_hook_suggestion'] = 'page__50__6';
  }
  if (strpos($url, 'circles/50/7')) {
    $var['theme_hook_suggestion'] = 'page__50__7';
  }
  if (strpos($url, 'circles/50/8')) {
    $var['theme_hook_suggestion'] = 'page__50__8';
  }
  if (strpos($url, 'circles/50/9')) {
    $var['theme_hook_suggestion'] = 'page__50__9';
  }
  if (strpos($url, 'circles/50/10')) {
    $var['theme_hook_suggestion'] = 'page__50__10';
  }
  if (strpos($url, 'circles/50/11')) {
    $var['theme_hook_suggestion'] = 'page__50__11';
  }
  if (strpos($url, 'circles/50/12')) {
    $var['theme_hook_suggestion'] = 'page__50__12';
  }
  if (strpos($url, 'circles/50/13')) {
    $var['theme_hook_suggestion'] = 'page__50__13';
  }
  if (strpos($url, 'circles/50/14')) {
    $var['theme_hook_suggestion'] = 'page__50__14';
  }
  if (strpos($url, 'circles/50/15')) {
    $var['theme_hook_suggestion'] = 'page__50__15';
  }
  if (strpos($url, 'circles/50/sub')) {
    $var['theme_hook_suggestion'] = 'page__50__sub';
  }

  $var['sitename'] = "My Advising Network";
}

function circle_preprocess_views_view(&$var) {
//	kpr($var);
//	print $var['display_id'];
}

function circle_menu_tree($variables) {
  return '<ul class="menu clearfix">' . $variables['tree'] . '</ul>';
}
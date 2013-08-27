<?php
function courses_mycircle_display() {
  global $user;
  //dsm($user);
  $courses = array();

}

what doesnt work
  global $user;
  //dsm($user);
  $courses = array();
  if (!empty($user->uid)) {
    $u = user_load($user->uid);
    //dsm($u);
    if (!in_array("administrator" && "instructor", $u->roles)) {
      $campid = $u->field_user_campusid['und']['0']['value'];
      if (!empty($campid)) {
        $courses = courses_find_instructors2($campid);
      } 

    } elseif (in_array("instructor", $u->roles)) {
      // what do we do if we are instructor ?
      return theme('instructor');

    } 
    elseif (empty($campid)) {
        // what do we do if campus id is missing from this user ? 
        return "Please click <a href='user/$u->uid/edit'>here</a> to register your campus ID";
      }
    else { // what to do if admin
      //drupal_goto($path = 'roster');
    }
      
  } else {
    // what do we do if someone is not logged in ? 
    return 'Please log in to access this page';
  }

  // theme this page
  return theme('circle', array('courses' => $courses));


this is my current progress
  function courses_mycircle_display() {
  global $user;
  $courses = array();
  if(!empty($user->uid)) { // check is user is logged in
    $u = user_load($user->uid);
  }

  // theme this page
  return theme('circle', array('courses' => $courses));
}

this works
function courses_mycircle_display() {
  global $user;
  $courses = array();
  if (!empty($user->uid)) {
    $u = user_load($user->uid);
    if (!in_array("administrator", $u->roles)) {
      $campid = $u->field_user_campusid['und']['0']['value'];
      if (!empty($campid)) {
        $courses = courses_find_instructors2($campid);
      } else {
        // what do we do if campus id is missing from this user ? 
      }
    } else {
      // what do we do if we are administrator ?
      // drupal_goto()
      drupal_goto($path = 'roster'); 
    }
  } else {
    // what do we do if someone is not logged in ? 
    return 'Please log in to access this page';
  }

  // theme this page
  return theme('circle', array('courses' => $courses));
}
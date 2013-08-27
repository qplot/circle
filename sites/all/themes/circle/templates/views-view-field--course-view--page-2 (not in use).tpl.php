<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */

// Variables to fields
// Use "->" when going into another stdClass
// Content -> path to field value

// $courses = array();
// foreach ($rows as $value) {
//   $course = array(
//     'title' => ''
//   );
//   $courses[] = $course;
//   # code...
// }

$vdata = &$row->_field_data['nid']['entity'];
$vtitle = $vdata->title; // The title of the course
$vbuilding = $vdata->field_building['und']['0']['value']; // Name of the building
$vcareer = $vdata->field_career['und']['0']['value']; // Career field
$vend_date = $vdata->field_end_date['und']['0']['value']; // End date of course
$vend_time = $vdata->field_end_time['und']['0']['value']; // End time of class
$venroll_cap = $vdata->field_enroll_cap['und']['0']['value']; // Maximum allowed to enroll
$venrolled = $vdata->field_enrolled['und']['0']['value']; // Amount currently enrolled
$vinstructor1 = $row->field_field_instructors['0']['raw']['entity']->title; // Name of instructor 1
$vnbr = $vdata->field_nbr['und']['0']['value']; // NBR code of course
$vroom = $vdata->field_room['und']['0']['value']; // Room number of class
$vsemester = $vdata->field_semester['und']['0']['value']; // Semester of course
$vstart_date = $vdata->field_start_date['und']['0']['value']; // Start date of course
$vstart_time = $vdata->field_start_time['und']['0']['value']; // Start time of class
$vsubject = $vdata->field_subject['und']['0']['value']; // Subject of course

// prepare instructors
$instructors = array();
foreach ($row->field_field_instructors as &$value) {
	$ins = array(
    'name' => $value['raw']['entity']->title,
    'pic_url' => $value['raw']['entity']->field_img['und'][0]['filename'],
  );
  $instructors[] = $ins;
}
// print_r($instructors);


$courses = array(
  0 => array(
    'title' => 'Civil',
    'building' => 'Carr',
    'instructors' => array(
      0 => array(
        'name' => 'Fang Jin', // instructor
        'pic_url' => '123.pic', // pic
      ),
    ),
  ),
);

?>


<!--  <?php
print "Things that have been identified with variables<br />";
print "<strong>Title: </strong>" . $vtitle . "<br />";
print "<strong>Building: </strong>" . $vbuilding . "<br />";
print "<strong>Career: </strong>" . $vcareer . "<br />";
print "<strong>End Date: </strong>" . $vend_date . "<br />";
print "<strong>End Time: </strong>" . $vend_time . "<br />";
print "<strong>Enroll Cap: </strong>" . $venroll_cap . "<br />";
print "<strong>Enrolled: </strong>" . $venrolled . "<br />";
print "<strong>Instructor 1: </strong>" . $vinstructor1 . "<br />";
print "<strong>NBR: </strong>" . $vnbr . "<br />";
print "<strong>Room: </strong>" . $vroom . "<br />";
print "<strong>Semester: </strong>" . $vsemester . "<br />";
print "<strong>Start Date: </strong>" . $vstart_date . "<br />";
print "<strong>Start Time: </strong>" . $vstart_time . "<br />";
print "<strong>Subject: </strong>" . $vsubject . "<br />";
?>

<?php 
print "<br /><br />";
print "Layout using identified variables<br /><br />";
print $vtitle . "<br />";
print $vsemester . " | " . $vcareer . " | " . $vnbr . " | " . $vsubject . "<br />";
print "Your instructor is " . $vinstructor1 . "<br />";
print "<strong>Location: </strong>" . $vbuilding . " Building<br />";
print "<strong>Time: </strong>" . $vstart_time . " - " . $vend_time . "<br />";
print "<strong>Date: </strong>" . $vstart_date . " - " . $vend_date . "<br />";
print $venrolled . "/" . $venroll_cap;


?> -->

<?php 
print "<br /><br />";
print $output; 
?>

<?php
  $path = base_path() . drupal_get_path('theme', 'circle') . "/images/";

  // courses_find_instructors2($campus_id = "0592266");
  // $view = views_get_view('roster');
  // $view->execute();
  // // dsm($view->result);

  // // post process the data into our theme format
  // // $courses = array (
  // //   'student_campus_id' => '',
  // //   'student_name',
  // //   'course_name',
  // //   'course_nbr',
  // //   'instructor_name'
  // // );
  // $courses = array();
  // foreach ($view->result as $value) {
  //   $courses[] = array(
  //     'Campus ID' => $value->field_field_roster_campusid['0']['raw']['value'],
  //     'Student Name' => $value->node_title, 
  //     'Course NBR' => $value->field_field_roster_classnbr['0']['raw']['value'],
  //     'Course Name' => $value->node_field_data_field_roster_course_title,
  //     'Instructor Name' => !empty($value->field_field_class_instructor[0]['raw']['value'])?$value->field_field_class_instructor[0]['raw']['value']:'',
  //     'Node ID' => $value->nid,
  //   );
  // }
  // dsm($courses); 
?>
<table class='coursetable'>
  <th>Campus ID</th>
  <th>Full Name</th>
  <th>NBR</th>
  <th>Course Name</th>
  <th>Instructor Name</th>
  <th>Instructor ID</th>
<?php foreach ($courses as $course) : ?>
  <?php  
    $CampusID = $course['Campus ID'];
    $studentName = $course['Student Name'];
    $CourseNBR = $course['Course NBR'];
    $CourseName = $course['Course Name'];
    $InstructorName = $course['Instructor Name'];
    $NodeID = $course['Node ID'];
    $InstructorID = $course['Instructor ID'];
  ?>
  <tr>
    <td><a href="<?=base_path();?>node/160774/<?=$CampusID?>"><?=$CampusID?></a></td>
    <td class="even"><?=$studentName?></td>
    <td><?=$CourseNBR?></td>
    <td class="even"><a href="<?=base_path();?>node/<?=$NodeID?>"><?=$CourseName?></a></td>
    <td><?=$InstructorName?></td>
    <td><?=$InstructorID?></td>
  </tr>
<?php endforeach; ?>
</table>



<?php $path = base_path() . drupal_get_path('theme', 'circle') . "/images/"; ?>
<div id="wrapper">
<div id="container">
      <div id="center">
    <a class="various" href="#student"><img src="<?=$path;?>student.png" /></a>
  </div>
    <?php foreach ($courses as $course): ?> <!-- displays circle for each instructor from array -->
      <?php // get info for each course
      $CourseName = $course['Course Name'];
      $CourseNBR = $course['Course NBR'];
      $InstructorName = $course['Instructor Name']; 
      $InstructorID = $course['Instructor ID'];
      $Descripton = NULL;
      $Office = NULL;
      $Mailing = NULL;
      $Phone = NULL;
      $Email = NULL;
      ?>
        <div class="fieldc">
         <div class="advisor-thumb"><a class="various" href="#<?php if (!empty($InstructorID)){print $InstructorID;} else {print $CourseNBR;} ?>"><!-- <img src="<?=$path?>sherwood.120.120.jpg" border="0" /> --><img src="<?=$path?>placeholder.gif" border="0" class="shrink"/></a></div>
          <div class="name"><?=$InstructorName;?></div> <!-- displays instructor name -->
          <div class="title"><?=$CourseName;?></div> <!-- displays course name -->
        </div>

      <?php if (!empty($InstructorID)): ?>

      <div id="<?=$InstructorID?>" class="profile" style="display:none;width:100%;">
        <img src="<?=$path;?>placeholder.gif" />
        <h2><?=$InstructorName?></h2>
        <h3><?=$CourseName?></h3>
        <h4></h4>
        <p>
          <?=$Descripton?>
        </p>
        <h4>Contact Information</h4>
        <ul>
          <li><strong>Office:</strong> <?$Office?></li>
          <li><strong>Mailing:</strong> <?=$Mailing?></li>
          <li><strong>Phone:</strong> <?=$Phone?></li>
          <li><strong>Email:</strong> <a href="mailto:<?$Email?>"><?=$Email?></a></li>
        </ul>
      </div>
      
      <? else: ?>
          <div id="<?=$CourseNBR?>" class="profile" style="display:none;width:100%;">
          <img src="<?=$path;?>placeholder.gif" />
          <h2><?=$InstructorName?></h2>
          <h3><?=$CourseName?></h3>
          <h4></h4>
          <p class="noins">
            This course has no instructor information to display.
          </p>
        </div>

      <?php endif; ?>

    <?php endforeach;?>    
</div>
</div>








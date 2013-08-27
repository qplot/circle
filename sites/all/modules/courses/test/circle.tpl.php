<?php
array_key_exists('first', $search_array)
// Given courses
  $path = base_path() . drupal_get_path('theme', 'circle') . "/images/";
  //dsm($courses);
  $u = user_load($user->uid);
  //dsm($u);
  $pic = $u->field_user_photo['und']['0']['uri'];
  //dsm($u->field_user_photo['und']['0']['uri']);
  $picurl = file_create_url($pic);
  $studentName = $combined['0']['Student Name'] . "</h2>";
  print "<h2>Welcome " . $studentName . "<br/>";
  dsm($combined);
?>

<?php $path = base_path() . drupal_get_path('theme', 'circle') . "/images/"; ?>
<div id="wrappercir">
  <div id="containercir">
  <div id="centersmall">
    <a class="various" href="#student"><img src="<?=$picurl?>" /></a>
  </div>
  <?php foreach ($combined as $course): ?> <!-- displays circle for each instructor from array -->
    <?php // get info for each course
      //dsm($course);
      if(count($course)>5) {
      $CourseName = $course['Course Name'];
      $CourseNBR = $course['Course NBR'];
      $InstructorName = $course['Instructor Name']; 
      $InstructorID = $course['Instructor ID'];
      $Descripton = NULL;
      $Office = NULL;
      $Mailing = NULL;
      $Phone = NULL;
      $Email = NULL;
      $Days = $course['Days'];
      $StartTime = $course['Start Time'];
      $EndTime = $course['End Time'];
      $Building = $course['Building'];
      $Room = $course['Room'];
      }
    ?>
    <?php if(count($course)>5): ?>
    <div class="fieldcir">


      <?php if (i can find a student key in this array) ?>
        <?php if (!empty($InstructorID)): ?>
          <div class="advisor-thumbsmall"><a class="various" href="#<?=$InstructorID?>"><img src="<?=$path?>placeholder.gif" border="0" class="shrink"/></a></div>
          <? else: ?>
          <div class="advisor-thumbsmall"><img src="<?=$path?>placeholder.gif" border="0" class="shrink"/></div>
        <?php endif; ?>
      <?php endif; ?>

      <?php //if (i can find a dean key in this array) ?>
      <?php //endif; ?>

      <div class="namesmall"><?=$InstructorName;?></div> <!-- displays instructor name -->
      <div class="titlesmall"><?=$CourseName;?></div> <!-- displays course name -->
    </div>
  <?php endif; ?>

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
    <div id="student" class="profile" style="display:none;width:100%;">
      <img src="<?=$picurl?>" />
      <h2><?=$studentName?></h2>
      <p><strong>Academic Dean:</strong> </p>
      <p><strong>Academic Advisor:</strong> </p>
      <h4>Course Load:</h4>
        <ul>
          <?php foreach ($combined as $course) : ?>
            <?php  
              if(count($course)>5) {
              $CampusID = $course['Campus ID'];
              $studentName = $course['Student Name'];
              $CourseNBR = $course['Course NBR'];
              $CourseName = $course['Course Name'];
              $InstructorName = $course['Instructor Name'];
              $NodeID = $course['Node ID'];
              $InstructorID = $course['Instructor ID'];
              $Days = $course['Days'];
              $StartTime = $course['Start Time'];
              $EndTime = $course['End Time'];
              $Building = $course['Building'];
              $Room = $course['Room'];
            }
            ?>
          <li>
            <strong><?=$CourseNBR?></strong> | <?=$CourseName?>
            <?php if(!empty($InstructorID)): ?>
               | <a class="various" href="#<?=$InstructorID?>"><?=$InstructorName?></a> | 
              <?php else: ?>
              | 
            <?php endif; ?>
            <?=$Days?> | <?=$StartTime?> - <?=$EndTime?> 
            <?php if(!empty($Building)||!empty($Room)) : ?>
               | <a href="#" title="link to map"><?=$Building?> <?=$Room?></a>
            <?php endif; ?>
          </li>
            <!-- <td class="even"><a href="<?=base_path();?>node/<?=$NodeID?>"><?=$CourseName?></a></td>
            <?php if(!empty($InstructorID)): ?>
              <td><a class="various" href="#<?=$InstructorID?>"><?=$InstructorName?></a></td>
              <?php else: ?>
              <td><?=$InstructorName?></td>
            <?php endif; ?> -->
            <!-- <td><?=$InstructorID?></td> -->
          </tr>
          <?php endforeach; ?>
        </ul>
      <h4>Housing:</h4>
      <ul>
        
      </ul>
    </div>
<!--       
      <? //else: ?>
          <div id="<?=$CourseNBR?>" class="profile" style="display:none;width:100%;">
          <img src="<?=$path;?>placeholder.gif" />
          <h2><?=$InstructorName?></h2>
          <h3><?=$CourseName?></h3>
          <h4></h4>
          <p class="noins">
            This course has no instructor information to display.
          </p>
        </div>
      <?php //endif; ?>
-->
    <?php endforeach;?>    
  </div>
</div>
<table class='coursetable'>
  <!-- <th>Campus ID</th> -->
  <!-- <th>Full Name</th> -->
  <th>NBR</th>
  <th>Course Name</th>
  <th>Instructor Name</th>
  <th>Start Time</th>
  <th>End Time</th>
  <th>Days</th>
  <th>Location</th>
  <!-- <th>Instructor ID</th> -->
<?php foreach ($combined as $course) : ?>
  <?php  
  if(count($course)>5) {
    $CampusID = $course['Campus ID'];
    $studentName = $course['Student Name'];
    $CourseNBR = $course['Course NBR'];
    $CourseName = $course['Course Name'];
    $InstructorName = $course['Instructor Name'];
    $NodeID = $course['Node ID'];
    $InstructorID = $course['Instructor ID'];
    $Days = $course['Days'];
    $StartTime = $course['Start Time'];
    $EndTime = $course['End Time'];
    $Building = $course['Building'];
    $Room = $course['Room'];
  }
  ?>
  <tr>
    <!-- <td><a href="<?=base_path();?>node/160774/<?=$CampusID?>"><?=$CampusID?></a></td> -->
    <!-- <td class="even"><?=$studentName?></td> -->
    <td><?=$CourseNBR?></td>
    <td class="even"><a href="<?=base_path();?>node/<?=$NodeID?>"><?=$CourseName?></a></td>
    <td><?=$InstructorName?></td>
    <td><?=$StartTime?></td>
    <td><?=$EndTime?></td>
    <td><?=$Days?></td>
    <td><?=$Building?> <?=$Room?></td>
    <!-- <td><?=$InstructorID?></td> -->
  </tr>
<?php endforeach; ?>
</table>
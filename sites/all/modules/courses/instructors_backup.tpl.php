<?php
  $all = array_merge($courses,$faculty,$housing);
  $num = count($all);
  //dsm($all); 
  // Given courses
  //dsm($courses);
  $u = user_load($user->uid);
  //dsm($u);

  $campusid = NULL;
  if(!empty($u->field_user_campusid['und']['0']['value'])) {
    $campusid = $u->field_user_campusid['und']['0']['value'];
  }

  $insimg = "public://faculty";
  $insimg = file_create_url($insimg)."/";
  $stuimg = "public://student";
  $stuimg = file_create_url($stuimg)."/".$campusid.".jpeg";
  $noimg = base_path() . drupal_get_path('theme', 'circle') . "/images/placeholder.gif";


  $studentName = NULL;
  //dsm($u->field_user_photo['und']['0']['uri']);
  if(!empty($u->field_user_displayname['und']['0']['value'])) {
    $studentName = $u->field_user_displayname['und']['0']['value'];
     print "<h2>Welcome " . $studentName . "</h2>";
  }
  //dsm($faculty);
  //dsm($courses);
  //dsm($housing);
  if(!empty($faculty['0']['0']['Advisor'])&&!empty($faculty['0']['0']['Advisor ID'])) {
    $Advisor = $faculty['0']['0']['Advisor'];
    $AdvisorID = $faculty['0']['0']['Advisor ID'];
  }
  else {
    $Advisor = NULL;
    $AdvisorID = NULL;
  }
  if(!empty($faculty['0']['1']['Dean'])&&!empty($faculty['0']['1']['Dean ID'])) {
    $Dean = $faculty['0']['1']['Dean'];
    $DeanID = $faculty['0']['1']['Dean ID'];
  } 
  else {
    $Dean = NULL;
    $DeanID = NULL;
  }
?>

<div class="show-hide-links"><a class="btn3">All</a> | <a class="btn2">Instructors</a> | <a class="btn1">Advisors</a></div>
<script type="text/javascript">
$(document).ready(function(){
  $("#All").show();
  $("#Instructors").hide();
  $("#Advisors").hide();
  $(".btn1").click(function(){
    $("#Instructors").hide();
    $("#Advisors").show();
    $("#All").hide();
  });
  $(".btn2").click(function(){
    $("#Instructors").show();
    $("#Advisors").hide();
    $("#All").hide();
  });
  $(".btn3").click(function(){
    $("#Instructors").hide();
    $("#Advisors").hide();
    $("#All").show();
  });
});
</script>




<div id="All">
  <script type="text/javascript">
  $(function(){
  var radius = "<?php echo $radius; ?>";
  var fields = $('.fieldcir'), container = $('.container1'), width = container.width(), height = container.height();
  var images = $('.advisor-thumbcir');
  var angle = 4.714, step = (2*Math.PI) / fields.length;
  fields.each(function() {
      var x = Math.round(width/2 + radius * Math.cos(angle) - $(this).width()/2);
      var y = Math.round(height/2 + radius * Math.sin(angle) - $(this).height()/2);
      if(window.console) {
          console.log($(this).text(), x, y);
      }
      $(this).css({
          left: x + 'px',
          top: y + 'px',
      });
      angle += step;
  });
  images.each(function() { // set the css for thumbnails
    $(this).css({
      width: '<?php echo $width; ?>' + 'px',
      height: '<?php echo $height; ?>' + 'px',
      border: '8px solid #ccc',
      overflow: 'hidden',
      margin: '0px auto 0px auto',
      borderRadius: 64 + 'px',
      WebkitBorderRadius:  64 + 'px',
      WebkitBorderRadius: 64 + 'px'
    });
  });
  });//]]>  
</script> 
<?php $path = base_path() . drupal_get_path('theme', 'circle') . "/images/"; ?>
<div class="wrapper1">
  <div class="container1">
  <div class="center1">
    <a class="various" href="#student"><img src="<?php echo $stuimg?>" onerror="this.src='<?php echo $noimg?>'"/></a>
  </div>
  <?php if(!empty($faculty['0'])): ?>
    <?php foreach ($faculty['0'] as $person): ?>
    <?php if(in_array('AcademicDean', $person)): ?>
      <?php //variables to use
        $Name = $person['Dean'];
        $ID = $person['Dean ID'];
        $Type = $person['Type'];
        $Descripton = NULL;
        $Office = $person['Dean Office'];
        $Mailing = $person['Dean Mailing'];
        $Phone = $person['Dean Telephone'];
        $Email = $person['Dean Email'];
        $pic = $insimg.$ID.".jpeg";
      ?>
      <div class="fieldcir">
        <?php if (!empty($ID)): ?>
          <div class="advisor-thumbsmall Faculty"><a class="various" href="#<?php echo $ID?>"><img src="<?php echo $pic?>" border="0"  onerror="this.src='<?php echo $noimg?>'"/></a></div>
          <?php else: ?>
          <div class="advisor-thumbsmall Faculty"><img src="<?php echo $noimg?>" border="0"  alt="No instructor"/></div>
        <?php endif; ?>
        <div class="namesmall"><?php echo $Name;?></div> <!-- displays instructor name -->
        <div class="titlesmall">Academic Dean</div> <!-- displays course name -->
      </div>
      <div id="<?php echo $ID?>" class="profile" style="display:none;width:100%;">
        <a onclick="$.fancybox.close()" value="CloseFB" class="backtocircle">Back to Circles</a>
        <img src="<?php echo $pic?>" onerror="this.src='<?php echo $noimg?>'"/>
        <h2 class="ch2"><?php echo $Name?></h2>
        <h3></h3>
        <p>
          <?php echo $Descripton?>
        </p>
        <h4>Contact Information</h4>
        <ul>
          <li><strong>Office:</strong> <?php echo $Office?></li>
          <li><strong>Mailing:</strong> <?php echo $Mailing?></li>
          <li><strong>Phone:</strong> <?php echo $Phone?></li>
          <li><strong>Email:</strong> <a href="mailto:<?$Email?>"><?php echo $Email?></a></li>
        </ul>
      </div>
    <?php endif; ?>
    <?php endforeach; ?>
  <?php foreach ($faculty['0'] as $person): ?>
    <?php if(in_array('AcademicAdvisor', $person)): ?>
    <?php //variables to use
      $Name = $person['Advisor'];
      $ID = $person['Advisor ID'];
      $Type = $person['Type'];
      $Descripton = NULL;
      $Office = $person['Advisor Office'];
      $Mailing = $person['Advisor Mailing'];
      $Phone = $person['Advisor Telephone'];
      $Email = $person['Advisor Email'];
      $pic = $insimg.$ID.".jpeg";
    ?>
    <div class="fieldcir">
      <?php if (!empty($ID)): ?>
        <div class="advisor-thumbsmall Faculty"><a class="various" href="#<?php echo $ID?>"><img src="<?php echo $pic?>" border="0"  onerror="this.src='<?php echo $noimg?>'"/></a></div>
        <?php else: ?>
        <div class="advisor-thumbsmall Faculty"><img src="<?php echo $noimg?>" border="0" /></div>
      <?php endif; ?>
      <div class="namesmall"><?php echo $Name;?></div> <!-- displays instructor name -->
      <div class="titlesmall">Academic Advisor</div> <!-- displays course name -->
    </div>
    <div id="<?php echo $ID?>" class="profile" style="display:none;width:100%;">
      <a onclick="$.fancybox.close()" value="CloseFB" class="backtocircle">Back to Circles</a>
      <img src="<?php echo $pic?>" onerror="this.src='<?php echo $noimg?>'"/>
      <h2><?php echo $Name?></h2>
      <h3></h3>
      <p>
        <?php echo $Descripton?>
      </p>
      <h4>Contact Information</h4>
      <ul>
        <li><strong>Office:</strong> <?php echo $Office?></li>
        <li><strong>Mailing:</strong> <?php echo $Mailing?></li>
        <li><strong>Phone:</strong> <?php echo $Phone?></li>
        <li><strong>Email:</strong> <a href="mailto:<?$Email?>"><?php echo $Email?></a></li>
      </ul>
    </div>
  <?php endif; ?>
<?php endforeach; ?>
<?php else: ?>
  <div class="fieldcir">
    <?php if (!empty($ID)): ?>
      <div class="advisor-thumbsmall Faculty"><a class="various" href="#<?php echo $ID?>"><img src="<?php echo $pic?>" border="0"  onerror="this.src='<?php echo $noimg?>'"/></a></div>
      <?php else: ?>
      <div class="advisor-thumbsmall Faculty"><img src="<?php echo $noimg?>" border="0"  alt="No instructor"/></div>
    <?php endif; ?>
    <div class="titlesmall">Academic Dean</div> <!-- displays course name -->
  </div>
<?php endif; ?>
  <?php foreach ($courses as $course): ?> <!-- displays circle for each instructor from array -->
    <?php 
      // get info for each course
        //dsm($course);
        $CourseName = $course['Course Name'];
        $InstructorName = $course['Instructor Name']; 
        $InstructorID = $course['Instructor ID'];
        $pic = $insimg.$InstructorID.".jpeg";
    ?>
    <div class="fieldcir">
      <?php if (!empty($InstructorID)): ?>
        <div class="advisor-thumbsmall Instructor"><a class="various" href="#<?php echo $InstructorID?>"><img src="<?php echo $pic?>" border="0"  onerror="this.src='<?php echo $noimg?>'"/></a></div>
        <?php else: ?>
        <div class="advisor-thumbsmall Instructor"><img src="<?php echo $noimg?>" border="0" /></div>
      <?php endif; ?>
      <div class="namesmall"><?php echo $InstructorName;?></div> <!-- displays instructor name -->
      <div class="titlesmall"><?php echo $CourseName;?></div> <!-- displays course name -->
    </div>
  <?php endforeach; ?>

  <?php foreach ($courses as $course): 
        $CourseName = $course['Course Name'];
        $InstructorName = $course['Instructor Name']; 
        $InstructorID = $course['Instructor ID'];
        $Descripton = NULL;
        $Office = $course['Office'];
        $Mailing = $course['Mailing'];
        $Phone = $course['Telephone'];
        $Email = $course['Email'];
        $Room = $course['Room'];
        $pic = $insimg.$InstructorID.".jpeg";
        ?>
    <div id="<?php echo $InstructorID?>" class="profile" style="display:none;width:100%;">
      <a onclick="$.fancybox.close()" value="CloseFB" class="backtocircle">Back to Circles</a>
      <img src="<?php echo $pic?>" onerror="this.src='<?php echo $noimg?>'"/>
      <h2><?php echo $InstructorName?></h2>
      <h3><?php echo $CourseName?></h3>
      <h4></h4>
      <p>
        <?php echo $Descripton?>
      </p>
      <h4>Contact Information</h4>
      <ul>
        <li><strong>Office:</strong> <?php echo $Office?></li>
        <li><strong>Mailing:</strong> <?php echo $Mailing?></li>
        <li><strong>Phone:</strong> <?php echo $Phone?></li>
        <li><strong>Email:</strong> <a href="mailto:<?$Email?>"><?php echo $Email?></a></li>
      </ul>
    </div>
  <?php endforeach; ?>
  <?php if(!empty($housing['0'])): ?>
    <?php foreach ($housing['0'] as $staff): ?>
      <?php if(in_array('Librarian', $staff)): ?>
        <?php //variables to use
          $Name = $staff['Librarian'];
          $ID = $staff['Librarian ID'];
          $Type = $staff['Type'];
          $Descripton = NULL;
          $Office = $staff['Librarian Office'];
          $Mailing = $staff['Librarian Mailing'];
          $Phone = $staff['Librarian Telephone'];
          $Email = $staff['Librarian Email'];
          $pic = $insimg.$ID.".jpeg";
        ?>
        <div class="fieldcir">
          <?php if (!empty($ID)): ?>
            <div class="advisor-thumbsmall Faculty"><a class="various" href="#<?php echo $ID?>"><img src="<?php echo $pic?>" border="0" onerror="this.src='<?php echo $noimg?>'"/></a></div>
            <?php else: ?>
            <div class="advisor-thumbsmall Faculty"><img src="<?php echo $noimg?>" border="0" /></div>
          <?php endif; ?>
          <div class="namesmall"><?php echo $Name;?></div> <!-- displays instructor name -->
          <div class="titlesmall"><?php echo $Type;?></div> <!-- displays course name -->
        </div>
        <div id="<?php echo $ID?>" class="profile" style="display:none;width:100%;">
          <a onclick="$.fancybox.close()" value="CloseFB" class="backtocircle">Back to Circles</a>
          <img src="<?php echo $pic?>" onerror="this.src='<?php echo $noimg?>'"/>
          <h2><?php echo $Name?></h2>
          <h3></h3>
          <p>
            <?php echo $Descripton?>
          </p>
          <h4>Contact Information</h4>
          <ul>
            <li><strong>Office:</strong> <?php echo $Office?></li>
            <li><strong>Mailing:</strong> <?php echo $Mailing?></li>
            <li><strong>Phone:</strong> <?php echo $Phone?></li>
            <li><strong>Email:</strong> <a href="mailto:<?$Email?>"><?php echo $Email?></a></li>
          </ul>
        </div>
      <?php endif; ?>
      <?php if(in_array('Faculty in Residence', $staff)): ?>
        <?php //variables to use
          $Name = $staff['Residence'];
          $ID = $staff['Residence ID'];
          $Type = $staff['Type'];
          $Descripton = NULL;
          $Office = $staff['Residence Office'];
          $Mailing = $staff['Residence Mailing'];
          $Phone = $staff['Residence Telephone'];
          $Email = $staff['Residence Email'];
          $pic = $insimg.$ID.".jpeg";
        ?>
        <div class="fieldcir">
          <?php if (!empty($ID)): ?>
            <div class="advisor-thumbsmall Faculty"><a class="various" href="#<?php echo $ID?>"><img src="<?php echo $pic?>" border="0"  onerror="this.src='<?php echo $noimg?>'"/></a></div>
            <?php else: ?>
            <div class="advisor-thumbsmall Faculty"><img src="<?php echo $noimg?>" border="0" /></div>
          <?php endif; ?>
          <div class="namesmall"><?php echo $Name;?></div> <!-- displays instructor name -->
          <div class="titlesmall"><?php echo $Type;?></div> <!-- displays course name -->
        </div>
        <div id="<?php echo $ID?>" class="profile" style="display:none;width:100%;">
          <a onclick="$.fancybox.close()" value="CloseFB" class="backtocircle">Back to Circles</a>
          <img src="<?php echo $pic?>" onerror="this.src='<?php echo $noimg?>'"/>
          <h2><?php echo $Name?></h2>
          <h3></h3>
          <p>
            <?php echo $Descripton?>
          </p>
          <h4>Contact Information</h4>
          <ul>
            <li><strong>Office:</strong> <?php echo $Office?></li>
            <li><strong>Mailing:</strong> <?php echo $Mailing?></li>
            <li><strong>Phone:</strong> <?php echo $Phone?></li>
            <li><strong>Email:</strong> <a href="mailto:<?$Email?>"><?php echo $Email?></a></li>
          </ul>
        </div>
      <?php endif; ?>
    <?php endforeach; ?>
  <?php endif; ?>
    <div id="student" class="profile" style="display:none;width:100%;">
      <a onclick="$.fancybox.close()" value="CloseFB" class="backtocircle">Back to Circles</a>
      <img src="<?php echo $stuimg?>" onerror="this.src='<?php echo $noimg?>'"/>
      <h2><?php echo $studentName?></h2>
      <p><strong>Academic Dean:</strong> <a class="various" href="#<?php echo $DeanID?>"><?php echo $Dean?></a></p>
      <p><strong>Academic Advisor:</strong> <a class="various" href="#<?php echo $AdvisorID?>"><?php echo $Advisor?></a></p>
      <h4>Course Load:</h4>
        <ul>
          <?php foreach ($courses as $course) : ?>
            <?php  
              $CourseNBR = $course['Course NBR'];
              $CourseName = $course['Course Name'];
              $InstructorName = $course['Instructor Name'];
              $InstructorID = $course['Instructor ID'];
              $Days = $course['Days'];
              $StartTime = $course['Start Time'];
              $EndTime = $course['End Time'];
              $Building = $course['Building'];
              $Room = $course['Room'];
            ?>
          <li>
            <strong><?php echo $CourseNBR?></strong> | <?php echo $CourseName?>
            <?php if(!empty($InstructorID)): ?>
               | <a class="various" href="#<?php echo $InstructorID?>"><?php echo $InstructorName?></a> | 
              <?php else: ?>
              | 
            <?php endif; ?>
            <?php echo $Days?> | <?php echo $StartTime?> - <?php echo $EndTime?> 
            <?php if(!empty($Building)||!empty($Room)) : ?>
               | <a href="#" title="link to map"><?php echo $Building?> <?php echo $Room?></a>
            <?php endif; ?>
          </li>
          </tr>
          <?php endforeach; ?>
        </ul>
      <h4>Housing:</h4>
      <ul>
        <?php if(!empty($housing['0'])): ?>
          <?php foreach ($housing['0'] as $staff): ?>
            <?php if(array_key_exists('Librarian', $staff)): ?>
              <?php $Librarian = $staff['Librarian']; $LibrarianID = $staff['Librarian ID']; ?>
              <li>Librarian: <a class="various" href="#<?php echo $LibrarianID?>"><?php echo $Librarian?></a></li>
            <?php endif; ?>
          <?php endforeach; ?>
        <?php endif; ?>
      </ul>
    </div> 
  </div>
</div>
</div>









<div id="Instructors">
  <script type="text/javascript">
    $(function(){
    var radius = "<?php echo $radius; ?>";
    var fields = $('.field1'), container = $('.container1'), width = container.width(), height = container.height();
    var images = $('.advisor-thumbsmall');
    var angle = 4.714, step = (2*Math.PI) / fields.length;
    fields.each(function() {
        var x = Math.round(width/2 + radius * Math.cos(angle) - $(this).width()/2);
        var y = Math.round(height/2 + radius * Math.sin(angle) - $(this).height()/2);
        if(window.console) {
            console.log($(this).text(), x, y);
        }
        $(this).css({
            left: x + 'px',
            top: y + 'px',
        });
        angle += step;
    });
    images.each(function() { // set the css for thumbnails
      $(this).css({
        width: '<?php echo $width; ?>' + 'px',
        height: '<?php echo $height; ?>' + 'px',
        border: '8px solid #ccc',
        overflow: 'hidden',
        margin: '0px auto 0px auto',
        borderRadius: 64 + 'px',
        WebkitBorderRadius:  64 + 'px',
        WebkitBorderRadius: 64 + 'px'
      });
    });
    });//]]>  
  </script> 
  <div class="wrapper1">
<div class="container1">
  <div class="center1">
    <a class="various" href="#student"><img src="<?php echo $stuimg?>" onerror="this.src='<?php echo $noimg?>'"/></a>
  </div>
<?php foreach ($courses as $course): ?> <!-- displays circle for each instructor from array -->
    <?php 
      // get info for each course
      //dsm($course);
        $CourseName = $course['Course Name'];
        $InstructorName = $course['Instructor Name']; 
        $InstructorID = $course['Instructor ID'];
        $pic = $insimg.$InstructorID.".jpeg";
    ?>
    <div class="field1">
      <?php if (!empty($InstructorID)): ?>
        <div class="advisor-thumbsmall Instructor"><a class="various" href="#<?php echo $InstructorID?>"><img src="<?php echo $pic?>" border="0"  onerror="this.src='<?php echo $noimg?>'"/></a></div>
        <?php else: ?>
        <div class="advisor-thumbsmall Instructor"><img src="<?php echo $noimg?>" border="0" /></div>
      <?php endif; ?>
      <div class="namesmall"><?php echo $InstructorName;?></div> <!-- displays instructor name -->
      <div class="titlesmall"><?php echo $CourseName;?></div> <!-- displays course name -->
    </div>
  <?php endforeach; ?>

  <?php foreach ($courses as $course): 
        $CourseName = $course['Course Name'];
        $InstructorName = $course['Instructor Name']; 
        $InstructorID = $course['Instructor ID'];
        $Descripton = NULL;
        $Office = NULL;
        $Mailing = NULL;
        $Phone = NULL;
        $Email = NULL;
        $Room = $course['Room'];
        $pic = $insimg.$InstructorID.".jpeg";
        ?>
    <div id="<?php echo $InstructorID?>" class="profile" style="display:none;width:100%;">
      <a onclick="$.fancybox.close()" value="CloseFB" class="backtocircle">Back to Circles</a>
      <img src="<?php echo $pic?>" onerror="this.src='<?php echo $noimg?>'"/>
      <h2><?php echo $InstructorName?></h2>
      <h3><?php echo $CourseName?></h3>
      <h4></h4>
      <p>
        <?php echo $Descripton?>
      </p>
      <h4>Contact Information</h4>
      <ul>
        <li><strong>Office:</strong> <?$Office?></li>
        <li><strong>Mailing:</strong> <?php echo $Mailing?></li>
        <li><strong>Phone:</strong> <?php echo $Phone?></li>
        <li><strong>Email:</strong> <a href="mailto:<?$Email?>"><?php echo $Email?></a></li>
      </ul>
    </div>
  <?php endforeach; ?>

    <div id="student" class="profile" style="display:none;width:100%;">
      <a onclick="$.fancybox.close()" value="CloseFB" class="backtocircle">Back to Circles</a>
      <img src="<?php echo $stuimg?>" onerror="this.src='<?php echo $noimg?>'"/>
      <h2><?php echo $studentName?></h2>
      <p><strong>Academic Dean:</strong> <a class="various" href="#<?php echo $DeanID?>"><?php echo $Dean?></a></p>
      <p><strong>Academic Advisor:</strong> <a class="various" href="#<?php echo $AdvisorID?>"><?php echo $Advisor?></a></p>
      <h4>Course Load:</h4>
        <ul>
          <?php foreach ($courses as $course) : ?>
            <?php  
              $CourseNBR = $course['Course NBR'];
              $CourseName = $course['Course Name'];
              $InstructorName = $course['Instructor Name'];
              $InstructorID = $course['Instructor ID'];
              $Days = $course['Days'];
              $StartTime = $course['Start Time'];
              $EndTime = $course['End Time'];
              $Building = $course['Building'];
              $Room = $course['Room'];
            ?>
          <li>
            <strong><?php echo $CourseNBR?></strong> | <?php echo $CourseName?>
            <?php if(!empty($InstructorID)): ?>
               | <a class="various" href="#<?php echo $InstructorID?>"><?php echo $InstructorName?></a> | 
              <?php else: ?>
              | 
            <?php endif; ?>
            <?php echo $Days?> | <?php echo $StartTime?> - <?php echo $EndTime?> 
            <?php if(!empty($Building)||!empty($Room)) : ?>
               | <a href="#" title="link to map"><?php echo $Building?> <?php echo $Room?></a>
            <?php endif; ?>
          </li>
          </tr>
          <?php endforeach; ?>
        </ul>
      <h4>Housing:</h4>
      <ul>
        <?php if(!empty($housing['0'])): ?>
          <?php foreach ($housing['0'] as $staff): ?>
            <?php if(array_key_exists('Librarian', $staff)): ?>
              <?php $Librarian = $staff['Librarian'] ?>
              <li>Librarian: <?php echo $Librarian?></li>
            <?php endif; ?>
          <?php endforeach; ?>
        <?php endif; ?>
      </ul>
    </div> 
  </div>
</div>
<br><br>
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
<?php foreach ($courses as $course) : ?>
  <?php  
    $CampusID = $course['Campus ID'];
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
  ?>
  <tr>
    <!-- <td><a href="<?php //echo base_path();?>node/160774/<?php //echo $CampusID?>"><?php //echo $CampusID?></a></td> -->
    <!-- <td class="even"><?php //echo $studentName?></td> -->
    <td><?php echo $CourseNBR?></td>
    <td class="even"><a href="<?php echo base_path();?>node/<?php echo $NodeID?>"><?php echo $CourseName?></a></td>
    <td><?php echo $InstructorName?></td>
    <td><?php echo $StartTime?></td>
    <td><?php echo $EndTime?></td>
    <td><?php echo $Days?></td>
    <td><?php echo $Building?> <?php echo $Room?></td>
    <!-- <td><?php //echo $InstructorID?></td> -->
  </tr>
<?php endforeach; ?>
</table>
</div>








<div id="Advisors">
  <script type="text/javascript">
    $(function(){
    var radius = 200;
    var fields = $('.field2'), container = $('.container1'), width = container.width(), height = container.height();
    var images = $('.advisor-thumbsmall');
    var angle = 4.714, step = (2*Math.PI) / fields.length;
    fields.each(function() {
        var x = Math.round(width/2 + radius * Math.cos(angle) - $(this).width()/2);
        var y = Math.round(height/2 + radius * Math.sin(angle) - $(this).height()/2);
        if(window.console) {
            console.log($(this).text(), x, y);
        }
        $(this).css({
            left: x + 'px',
            top: y + 'px',
        });
        angle += step;
    });
    images.each(function() { // set the css for thumbnails
      $(this).css({
        width: '<?php echo $width; ?>' + 'px',
        height: '<?php echo $height; ?>' + 'px',
        border: '8px solid #ccc',
        overflow: 'hidden',
        margin: '0px auto 0px auto',
        borderRadius: 64 + 'px',
        WebkitBorderRadius:  64 + 'px',
        WebkitBorderRadius: 64 + 'px'
      });
    });
    });//]]>  
  </script> 
<div class="wrapper1">
<div class="container1">
   <div class="center1">
    <a class="various" href="#student"><img src="<?php echo $stuimg?>" onerror="this.src='<?php echo $noimg?>'"/></a>
  </div>
<?php if(!empty($faculty['0'])): ?>
    <?php foreach ($faculty['0'] as $person): ?>
    <?php if(in_array('AcademicDean', $person)): ?>
      <?php //variables to use
        $Name = $person['Dean'];
        $ID = $person['Dean ID'];
        $Type = $person['Type'];
        $Descripton = NULL;
        $Office = $person['Dean Office'];
        $Mailing = $person['Dean Mailing'];
        $Phone = $person['Dean Telephone'];
        $Email = $person['Dean Email'];
        $pic = $insimg.$ID.".jpeg";
      ?>
      <div class="field2">
        <?php if (!empty($ID)): ?>
          <div class="advisor-thumbsmall Faculty"><a class="various" href="#<?php echo $ID?>"><img src="<?php echo $pic?>" border="0" onerror="this.src='<?php echo $noimg?>'"/></a></div>
          <?php else: ?>
          <div class="advisor-thumbsmall Faculty"><img src="<?php echo $noimg?>" border="0" alt="No instructor"/></div>
        <?php endif; ?>
        <div class="namesmall"><?php echo $Name;?></div> <!-- displays instructor name -->
        <div class="titlesmall">Academic Dean</div> <!-- displays course name -->
      </div>
      <div id="<?php echo $ID?>" class="profile" style="display:none;width:100%;">
        <a onclick="$.fancybox.close()" value="CloseFB" class="backtocircle">Back to Circles</a>
        <img src="<?php echo $pic?>" onerror="this.src='<?php echo $noimg?>'"/>
        <h2 class="ch2"><?php echo $Name?></h2>
        <h3></h3>
        <p>
          <?php echo $Descripton?>
        </p>
        <h4>Contact Information</h4>
        <ul>
          <li><strong>Office:</strong> <?php echo $Office?></li>
          <li><strong>Mailing:</strong> <?php echo $Mailing?></li>
          <li><strong>Phone:</strong> <?php echo $Phone?></li>
          <li><strong>Email:</strong> <a href="mailto:<?$Email?>"><?php echo $Email?></a></li>
        </ul>
      </div>
    <?php endif; ?>
    <?php endforeach; ?>
  <?php foreach ($faculty['0'] as $person): ?>
    <?php if(in_array('AcademicAdvisor', $person)): ?>
    <?php //variables to use
      $Name = $person['Advisor'];
      $ID = $person['Advisor ID'];
      $Type = $person['Type'];
      $Descripton = NULL;
      $Office = $person['Advisor Office'];
      $Mailing = $person['Advisor Mailing'];
      $Phone = $person['Advisor Telephone'];
      $Email = $person['Advisor Email'];
      $pic = $insimg.$ID.".jpeg";
    ?>
    <div class="field2">
      <?php if (!empty($ID)): ?>
        <div class="advisor-thumbsmall Faculty"><a class="various" href="#<?php echo $ID?>"><img src="<?php echo $pic?>" border="0"  onerror="this.src='<?php echo $noimg?>'"/></a></div>
        <?php else: ?>
        <div class="advisor-thumbsmall Faculty"><img src="<?php echo $noimg?>" border="0" /></div>
      <?php endif; ?>
      <div class="namesmall"><?php echo $Name;?></div> <!-- displays instructor name -->
      <div class="titlesmall">Academic Advisor</div> <!-- displays course name -->
    </div>
    <div id="<?php echo $ID?>" class="profile" style="display:none;width:100%;">
      <a onclick="$.fancybox.close()" value="CloseFB" class="backtocircle">Back to Circles</a>
      <img src="<?php echo $pic?>" onerror="this.src='<?php echo $noimg?>'"/>
      <h2><?php echo $Name?></h2>
      <h3></h3>
      <p>
        <?php echo $Descripton?>
      </p>
      <h4>Contact Information</h4>
      <ul>
        <li><strong>Office:</strong> <?php echo $Office?></li>
        <li><strong>Mailing:</strong> <?php echo $Mailing?></li>
        <li><strong>Phone:</strong> <?php echo $Phone?></li>
        <li><strong>Email:</strong> <a href="mailto:<?$Email?>"><?php echo $Email?></a></li>
      </ul>
    </div>
  <?php endif; ?>
<?php endforeach; ?>
<?php else: ?>
  <div class="field2">
    <?php if (!empty($ID)): ?>
      <div class="advisor-thumbsmall Faculty"><a class="various" href="#<?php echo $ID?>"><img src="<?php echo $pic?>" border="0"  onerror="this.src='<?php echo $noimg?>'"/></a></div>
      <?php else: ?>
      <div class="advisor-thumbsmall Faculty"><img src="<?php echo $noimg?>" border="0"  alt="No instructor"/></div>
    <?php endif; ?>
    <div class="titlesmall">Academic Dean</div> <!-- displays course name -->
  </div>
<?php endif; ?>
<?php if(!empty($housing['0'])): ?>
    <?php foreach ($housing['0'] as $staff): ?>
      <?php if(in_array('Librarian', $staff)): ?>
        <?php //variables to use
          $Name = $staff['Librarian'];
          $ID = $staff['Librarian ID'];
          $Type = $staff['Type'];
          $Descripton = NULL;
          $Office = $staff['Librarian Office'];
          $Mailing = $staff['Librarian Mailing'];
          $Phone = $staff['Librarian Telephone'];
          $Email = $staff['Librarian Email'];
          $pic = $insimg.$ID.".jpeg";
        ?>
        <div class="field2">
          <?php if (!empty($ID)): ?>
            <div class="advisor-thumbsmall Faculty"><a class="various" href="#<?php echo $ID?>"><img src="<?php echo $pic?>" border="0"  onerror="this.src='<?php echo $noimg?>'"/></a></div>
            <?php else: ?>
            <div class="advisor-thumbsmall Faculty"><img src="<?php echo $noimg?>" border="0" /></div>
          <?php endif; ?>
          <div class="namesmall"><?php echo $Name;?></div> <!-- displays instructor name -->
          <div class="titlesmall"><?php echo $Type;?></div> <!-- displays course name -->
        </div>
        <div id="<?php echo $ID?>" class="profile" style="display:none;width:100%;">
          <a onclick="$.fancybox.close()" value="CloseFB" class="backtocircle">Back to Circles</a>
          <img src="<?php echo $pic?>" onerror="this.src='<?php echo $noimg?>'"/>
          <h2><?php echo $Name?></h2>
          <h3></h3>
          <p>
            <?php echo $Descripton?>
          </p>
          <h4>Contact Information</h4>
          <ul>
            <li><strong>Office:</strong> <?php echo $Office?></li>
            <li><strong>Mailing:</strong> <?php echo $Mailing?></li>
            <li><strong>Phone:</strong> <?php echo $Phone?></li>
            <li><strong>Email:</strong> <a href="mailto:<?$Email?>"><?php echo $Email?></a></li>
          </ul>
        </div>
      <?php endif; ?>
      <?php if(in_array('Faculty in Residence', $staff)): ?>
        <?php //variables to use
          $Name = $staff['Residence'];
          $ID = $staff['Residence ID'];
          $Type = $staff['Type'];
          $Descripton = NULL;
          $Office = $staff['Residence Office'];
          $Mailing = $staff['Residence Mailing'];
          $Phone = $staff['Residence Telephone'];
          $Email = $staff['Residence Email'];
          $pic = $insimg.$ID.".jpeg";
        ?>
        <div class="field2">
          <?php if (!empty($ID)): ?>
            <div class="advisor-thumbsmall Faculty"><a class="various" href="#<?php echo $ID?>"><img src="<?php echo $pic?>" border="0"  onerror="this.src='<?php echo $noimg?>'"/></a></div>
            <?php else: ?>
            <div class="advisor-thumbsmall Faculty"><img src="<?php echo $noimg?>" border="0" /></div>
          <?php endif; ?>
          <div class="namesmall"><?php echo $Name;?></div> <!-- displays instructor name -->
          <div class="titlesmall"><?php echo $Type;?></div> <!-- displays course name -->
        </div>
        <div id="<?php echo $ID?>" class="profile" style="display:none;width:100%;">
          <a onclick="$.fancybox.close()" value="CloseFB" class="backtocircle">Back to Circles</a>
          <img src="<?php echo $pic?>" onerror="this.src='<?php echo $noimg?>'"/>
          <h2><?php echo $Name?></h2>
          <h3></h3>
          <p>
            <?php echo $Descripton?>
          </p>
          <h4>Contact Information</h4>
          <ul>
            <li><strong>Office:</strong> <?php echo $Office?></li>
            <li><strong>Mailing:</strong> <?php echo $Mailing?></li>
            <li><strong>Phone:</strong> <?php echo $Phone?></li>
            <li><strong>Email:</strong> <a href="mailto:<?$Email?>"><?php echo $Email?></a></li>
          </ul>
        </div>
      <?php endif; ?>
    <?php endforeach; ?>
  <?php endif; ?>
  </div>
</div>
</div>
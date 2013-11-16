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


  //dsm($u->field_user_photo['und']['0']['uri']);
  $studentName = NULL;
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

<script type="text/javascript">
$(function(){
var radius = "<?php echo $radius; ?>";
var fields = $('.fieldcir'), container = $('#containercir'), width = container.width(), height = container.height();
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

<br><br>

<div id="wrappercir">
  <div id="containercir">
  <div id="centercir">
    <a class="various" href="#student"><img src="<?php echo $stuimg?>" onerror="this.src='<?php echo $noimg?>'"/></a>
  </div>
  <?php if(!empty($faculty['0'])): ?>

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
      // $pic = $course['Advisor Photo'];
      // $pic = file_create_url($pic);
      $pic = $insimg.$ID.".jpeg";
    ?>
    <div class="fieldcir">
      <?php if (!empty($ID)): ?>
        <div class="advisor-thumbcir Faculty"><a class="various" href="#<?php echo $ID?>"><img src="<?php echo $pic?>" border="0" class="shrink" onerror="this.src='<?php echo $noimg?>'"/></a></div>
        <?php else: ?>
        <div class="advisor-thumbcir Faculty"><img src="<?php echo $noimg?>" border="0" class="shrink"/></div>
      <?php endif; ?>
      <div class="namecir"><?php echo $Name;?></div> <!-- displays instructor name -->
      <div class="titlecir">Academic Advisor</div> <!-- displays course name -->
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
        // $pic = $course['Dean Photo'];
        // $pic = file_create_url($pic);
        $pic = $insimg.$ID.".jpeg";
      ?>
      <div class="fieldcir">
        <?php if (!empty($ID)): ?>
          <div class="advisor-thumbcir Faculty"><a class="various" href="#<?php echo $ID?>"><img src="<?php echo $pic?>" border="0" class="shrink" onerror="this.src='<?php echo $noimg?>'"/></a></div>
          <?php else: ?>
          <div class="advisor-thumbcir Faculty"><img src="<?php echo $noimg?>" border="0" class="shrink" alt="No instructor"/></div>
        <?php endif; ?>
        <div class="namecir"><?php echo $Name;?></div> <!-- displays instructor name -->
        <div class="titlecir">Academic Dean</div> <!-- displays course name -->
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

<?php else: ?>
  <div class="fieldcir">
    <?php if (!empty($ID)): ?>
      <div class="advisor-thumbcir Faculty"><a class="various" href="#<?php echo $ID?>"><img src="<?php echo $pic?>" border="0" class="shrink" onerror="this.src='<?php echo $noimg?>'"/></a></div>
      <?php else: ?>
      <div class="advisor-thumbcir Faculty"><img src="<?php echo $noimg?>" border="0" class="shrink" alt="No instructor"/></div>
    <?php endif; ?>
    <div class="titlecir">Academic Dean</div> <!-- displays course name -->
  </div>
<?php endif; ?>

  <?php foreach ($courses as $course): ?> <!-- displays circle for each instructor from array -->
    <?php 
      // get info for each course
      //dsm($course);
        $CourseName = $course['Course Name'];
        $InstructorName = $course['Instructor Name']; 
        $InstructorID = $course['Instructor ID'];
        $pic = $course['Photo Path'];
        // $pic = $course['Instructor Pic'];
        // $pic = file_create_url($pic);
        //$pic = $insimg.$InstructorID.".jpeg";
    ?>
    <div class="fieldcir">
      <?php if (!empty($InstructorID)): ?>
        <div class="advisor-thumbcir Instructor"><a class="various" href="#<?php echo $InstructorID?>"><img src="<?php echo $pic?>" border="0" class="shrink" onerror="this.src='<?php echo $noimg?>'"/></a></div>
        <?php else: ?>
        <div class="advisor-thumbcir Instructor"><img src="<?php echo $noimg?>" border="0" class="shrink"/></div>
      <?php endif; ?>
      <div class="namecir"><?php echo $InstructorName;?></div> <!-- displays instructor name -->
      <div class="titlecir"><?php echo $CourseName;?></div> <!-- displays course name -->
      <div class="titlecir"><?php echo $InstructorID;?></div> <!-- displays Instructor ID -->
    </div>
  <?php endforeach; ?>

  <?php foreach ($courses as $course):
  //dsm($course);
        $CourseName = $course['Course Name'];
        $InstructorName = $course['Instructor Name']; 
        $InstructorID = $course['Instructor ID'];
        $Descripton = NULL;
        $Office = $course['Office'];
        $Mailing = $course['Mailing'];
        $Phone = $course['Telephone'];
        $Email = $course['Email'];
        $Room = $course['Room'];
        // $pic = $course['Instructor Pic'];
        // $pic = file_create_url($pic);
        $pic = $insimg.$InstructorID.".jpeg";
        ?>
    <div id="<?php echo $InstructorID?>" class="profile" style="display:none;width:100%;">
      <a onclick="$.fancybox.close()" value="CloseFB" class="backtocircle">Back to Circles</a>
      <img src="<?php echo $pic;?>" onerror="this.src='<?php echo $noimg?>'"/>
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
          // $pic = $staff['Librarian Photo'];
          // $pic = file_create_url($pic);
          $pic = $insimg.$ID.".jpeg";
        ?>
        <div class="fieldcir">
          <?php if (!empty($ID)): ?>
            <div class="advisor-thumbcir Faculty"><a class="various" href="#<?php echo $ID?>"><img src="<?php echo $pic?>" border="0" class="shrink" onerror="this.src='<?php echo $noimg?>'"/></a></div>
            <?php else: ?>
            <div class="advisor-thumbcir Faculty"><img src="<?php echo $noimg?>" border="0" class="shrink"/></div>
          <?php endif; ?>
          <div class="namecir"><?php echo $Name;?></div> <!-- displays instructor name -->
          <div class="titlecir"><?php echo $Type;?></div> <!-- displays course name -->
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
          // $pic = $staff['Residence Photo'];
          // $pic = file_create_url($pic);
          $pic = $insimg.$ID.".jpeg";
        ?>
        <div class="fieldcir">
          <?php if (!empty($ID)): ?>
            <div class="advisor-thumbcir Faculty"><a class="various" href="#<?php echo $ID?>"><img src="<?php echo $pic?>" border="0" class="shrink" onerror="this.src='<?php echo $noimg?>'"/></a></div>
            <?php else: ?>
            <div class="advisor-thumbcir Faculty"><img src="<?php echo $noimg?>" border="0" class="shrink"/></div>
          <?php endif; ?>
          <div class="namecir"><?php echo $Name;?></div> <!-- displays instructor name -->
          <div class="titlecir"><?php echo $Type;?></div> <!-- displays course name -->
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
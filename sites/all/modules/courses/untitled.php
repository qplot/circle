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
    <a class="various" href="#student"><img src="<?=$picurl?>" /></a>
  </div>
<?php foreach ($courses as $course): ?> <!-- displays circle for each instructor from array -->
    <?php 
      // get info for each course
      //dsm($course);
        $CourseName = $course['Course Name'];
        $InstructorName = $course['Instructor Name']; 
        $InstructorID = $course['Instructor ID'];
    ?>
    <div class="field1">
      <?php if (!empty($InstructorID)): ?>
        <div class="advisor-thumbsmall"><a class="various" href="#<?=$InstructorID?>"><img src="<?=$path?>placeholder.gif" border="0" class="shrink"/></a></div>
        <? else: ?>
        <div class="advisor-thumbsmall"><img src="<?=$path?>placeholder.gif" border="0" class="shrink"/></div>
      <?php endif; ?>
      <div class="namesmall"><?=$InstructorName;?></div> <!-- displays instructor name -->
      <div class="titlesmall"><?=$CourseName;?></div> <!-- displays course name -->
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
        ?>
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
  <?php endforeach; ?>

    <div id="student" class="profile" style="display:none;width:100%;">
      <img src="<?=$picurl?>" />
      <h2><?=$studentName?></h2>
      <p><strong>Academic Dean:</strong> <a class="various" href="#<?=$DeanID?>"><?=$Dean?></a></p>
      <p><strong>Academic Advisor:</strong> <a class="various" href="#<?=$AdvisorID?>"><?=$Advisor?></a></p>
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
          </tr>
          <?php endforeach; ?>
        </ul>
      <h4>Housing:</h4>
      <ul>
        <?php foreach ($housing['0'] as $staff): ?>
          <?php if(array_key_exists('Librarian', $staff)): ?>
            <?php $Librarian = $staff['Librarian'] ?>
            <li>Librarian: <?=$Librarian?></li>
          <?php endif; ?>
        <?php endforeach; ?>
      </ul>
    </div> 
  </div>
</div>

<br><br><br>
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
    <a class="various" href="#student"><img src="<?=$picurl?>" /></a>
  </div>
<?php if($faculty['0']): ?>
    <?php foreach ($faculty['0'] as $person): ?>

      <?php if(in_array('Academic Advisor', $person)): ?>
      <?php //variables to use
        $Name = $person['Advisor'];
        $ID = $person['Advisor ID'];
        $Type = $person['Type'];
        $Descripton = NULL;
        $Office = NULL;
        $Mailing = NULL;
        $Phone = NULL;
        $Email = NULL;
      ?>
      <div class="field2">
        <?php if (!empty($ID)): ?>
          <div class="advisor-thumbsmall"><a class="various" href="#<?=$ID?>"><img src="<?=$path?>placeholder.gif" border="0" class="shrink"/></a></div>
          <? else: ?>
          <div class="advisor-thumbsmall"><img src="<?=$path?>placeholder.gif" border="0" class="shrink"/></div>
        <?php endif; ?>
        <div class="namesmall"><?=$Name;?></div> <!-- displays instructor name -->
        <div class="titlesmall"><?=$Type;?></div> <!-- displays course name -->
      </div>
      <div id="<?=$ID?>" class="profile" style="display:none;width:100%;">
        <img src="<?=$path;?>placeholder.gif" />
        <h2><?=$Name?></h2>
        <h3></h3>
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
    <?php endif; ?>
    <?php if(in_array('Academic Dean', $person)): ?>
      <?php //variables to use
        $Name = $person['Dean'];
        $ID = $person['Dean ID'];
        $Type = $person['Type'];
        $Descripton = NULL;
        $Office = NULL;
        $Mailing = NULL;
        $Phone = NULL;
        $Email = NULL;
      ?>
      <div class="field2">
        <?php if (!empty($ID)): ?>
          <div class="advisor-thumbsmall"><a class="various" href="#<?=$ID?>"><img src="<?=$path?>placeholder.gif" border="0" class="shrink"/></a></div>
          <? else: ?>
          <div class="advisor-thumbsmall"><img src="<?=$path?>placeholder.gif" border="0" class="shrink"/></div>
        <?php endif; ?>
        <div class="namesmall"><?=$Name;?></div> <!-- displays instructor name -->
        <div class="titlesmall"><?=$Type;?></div> <!-- displays course name -->
      </div>
      <div id="<?=$ID?>" class="profile" style="display:none;width:100%;">
        <img src="<?=$path;?>placeholder.gif" />
        <h2><?=$Name?></h2>
        <h3></h3>
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
    <?php endif; ?>
    <?php endforeach; ?>
  <?php foreach ($housing['0'] as $hstaff): ?>
    <?php if(in_array('Librarian', $hstaff)): ?>
      <?php //variables to use
        $Name = $hstaff['Librarian'];
        $ID = $hstaff['Librarian ID'];
        $Type = $hstaff['Type'];
        $Descripton = NULL;
        $Office = NULL;
        $Mailing = NULL;
        $Phone = NULL;
        $Email = NULL;
      ?>
      <div class="field2">
        <?php if (!empty($ID)): ?>
          <div class="advisor-thumbsmall"><a class="various" href="#<?=$ID?>"><img src="<?=$path?>placeholder.gif" border="0" class="shrink"/></a></div>
          <? else: ?>
          <div class="advisor-thumbsmall"><img src="<?=$path?>placeholder.gif" border="0" class="shrink"/></div>
        <?php endif; ?>
        <div class="namesmall"><?=$Name;?></div> <!-- displays instructor name -->
        <div class="titlesmall"><?=$Type;?></div> <!-- displays course name -->
      </div>
      <div id="<?=$ID?>" class="profile" style="display:none;width:100%;">
        <img src="<?=$path;?>placeholder.gif" />
        <h2><?=$Name?></h2>
        <h3></h3>
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
    <?php endif; ?>
  <?php endforeach; ?>
  <?php endif; ?>
  </div>
</div>
</div>
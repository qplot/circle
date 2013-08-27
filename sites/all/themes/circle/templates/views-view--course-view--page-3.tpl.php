<?php
/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
?>
<div class="<?php print $classes; ?>">
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <?php print $title; ?>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($header): ?>
    <div class="view-header">
      <?php print $header; ?>
    </div>
  <?php endif; ?>

  <?php if ($exposed): ?>
    <div class="view-filters">
      <?php print $exposed; ?>
    </div>
  <?php endif; ?>

  <?php if ($attachment_before): ?>
    <div class="attachment attachment-before">
      <?php print $attachment_before; ?>
    </div>
  <?php endif; ?>

  <?php if ($rows): ?>
    <div class="view-content">
      <?php print "Circles (Edited version)"; ?>

      <?php 
        $courses = array(
          0 => array(
            'title' => 'Academic Dean',
            'building' => '',
            'instructors' => array(
              0 => array(
                'name' => 'Lee Baker', // instructor
                'pic_url' => 'lee-baker.120.150.jpg', // pic
                'class' => 'ciradmin',
             ),
            ),
          ),
          1 => array(
            'title' => 'Academic Advisor',
            'building' => '',
            'instructors' => array(
              0 => array(
                'name' => 'Susan Alberts', // instructor
                'pic_url' => 'susan-alberts.120.120.jpg', // pic
                'class' => 'ciradmin',
             ),
            ),
          ),
          2 => array(
            'title' => 'Math I',
            'building' => 'Math Hall',
            'instructors' => array(
              0 => array(
                'name' => 'David McClay, PhD', // instructor
                'pic_url' => 'david-mcclay.120.120.jpg', // pic
                'class' => 'cirins',
             ),
            ),
          ),
          3 => array(
            'title' => 'Biology 101',
            'building' => 'Science Hall',
            'instructors' => array(
              0 => array(
                'name' => 'Guo Juin Hong, PhD', // instructor
                'pic_url' => 'guo-juin-hong.120.120.jpg', // pic
                'class' => 'cirins',
             ),
            ),
          ),
          4 => array(
            'title' => 'English 101',
            'building' => 'English Hall',
            'instructors' => array(
              0 => array(
                'name' => 'Michael Moses, PhD', // instructor
                'pic_url' => 'michael-moses.120.120.jpg', // pic
                'class' => 'cirins',
             ),
            ),
          ),
          5 => array(
            'title' => 'Calculus 101',
            'building' => 'Math Hall',
            'instructors' => array(
              0 => array(
                'name' => 'David McClay, PhD', // instructor
                'pic_url' => 'david-mcclay.120.120.jpg', // pic
                'class' => 'cirins',
             ),
            ),
          ),
          6 => array(
            'title' => 'US History',
            'building' => 'Carr Building',
            'instructors' => array(
              0 => array(
                'name' => 'Huntington Willard, PhD', // instructor
                'pic_url' => 'huntington-willard.120.120.jpg', // pic
                'class' => 'cirins',
             ),
            ),
          ),
          /*7 => array(
             'title' => 'Chemisty I',
             'building' => 'Science Hall',
             'instructors' => array(
               0 => array(
                 'name' => 'Guo Juin Hong, PhD', // instructor
                 'pic_url' => 'guo-juin-hong.120.120.jpg', // pic
                 'class' => 'cirins',
              ),
             ),
           ),
           8 => array(
             'title' => 'Calculus 101',
             'building' => 'Math Hall',
             'instructors' => array(
               0 => array(
                 'name' => 'David McClay, PhD', // instructor
                 'pic_url' => 'david-mcclay.120.120.jpg', // pic
                 'class' => 'cirins',
              ),
             ),
           ),
           9 => array(
             'title' => 'English 101',
             'building' => 'English Hall',
             'instructors' => array(
               0 => array(
                 'name' => 'Michael Moses, PhD', // instructor
                 'pic_url' => 'michael-moses.120.120.jpg', // pic
                 'class' => 'cirins',
              ),
             ),
           ),
           10 => array(
             'title' => 'Biology 101',
             'building' => 'Science Hall',
             'instructors' => array(
               0 => array(
                 'name' => 'Guo Juin Hong, PhD', // instructor
                 'pic_url' => 'guo-juin-hong.120.120.jpg', // pic
                 'class' => 'cirins',
              ),
             ),
           ),
           11 => array(
             'title' => 'US History',
             'building' => 'Carr Building',
             'instructors' => array(
               0 => array(
                 'name' => 'Fang Jin, PhD', // instructor
                 'pic_url' => 'fang-jin.120.120.jpg', // pic
                 'class' => 'cirins',
              ),
             ),
           ),
           12 => array(
             'title' => 'Chemisty I',
             'building' => 'Science Hall',
             'instructors' => array(
               0 => array(
                 'name' => 'Guo Juin Hong, PhD', // instructor
                 'pic_url' => 'guo-juin-hong.120.120.jpg', // pic
                 'class' => 'cirins',
              ),
             ),
           ),
           13 => array(
             'title' => 'Math II',
             'building' => 'Math Hall',
             'instructors' => array(
               0 => array(
                 'name' => 'David McClay, PhD', // instructor
                 'pic_url' => 'david-mcclay.120.120.jpg', // pic
                 'class' => 'cirins',
              ),
             ),
           ),
           14 => array(
             'title' => 'Calculus 101',
             'building' => 'Math Hall',
             'instructors' => array(
               0 => array(
                 'name' => 'David McClay, PhD', // instructor
                 'pic_url' => 'david-mcclay.120.120.jpg', // pic
                 'class' => 'cirins',
              ),
             ),
           ), */
           15 => array(
            'title' => 'Pegram Hall Resident Assistant',
            'building' => '',
            'instructors' => array(
              0 => array(
                'name' => 'Audrey Kang', // instructor
                'pic_url' => 'audrey-kang.120.120.png', // pic
                'class' => 'ciradmin',
             ),
            ),
          ),


        );
        // $abc = "0";
        // $ctitle = $courses[$abc]['title'];
        // $cins = $courses[$abc]['instructors']['0']['name'];
        // $cinsimg = $courses[$abc]['instructors']['0']['pic_url'];
// dpm($courses);

      ?>
    <?php 

       // foreach ($courses as $value) {
       //   # code...
       //  $ctitle = $value['title'];
       //  $cins = $value['instructors']['0']['name'];
       //  $cinsimg = $value['instructors']['0']['pic_url'];
       //  dsm($ctitle);
       //  dsm($cins);
       //  dsm($cinsimg);
       // }
      $path = base_path() . drupal_get_path('theme', 'circle') . "/images/";

    ?>
<div id="wrappercir">
<div id="containercir">
      <div id="centercir">
    <a class="various" href="#student"><img src="<?=$path;?>student.png" /></a>
  </div>
    <?php foreach ($courses as $course): ?> <!-- displays circle for each instructor from array -->
      <?php $instructor = &$course['instructors'][0]; //path through array ?>

      <div class="fieldcir">
        <div class="<?=$instructor['class'];?> advisor-thumbcir"><a class="various" href="#"><img src="<?=$path;?><?=$instructor['pic_url'];?>" border="0" /></a></div>
        <div class="namecir"><?=$instructor['name'];?></div> <!-- displays instructor name -->
        <div class="titlecir"><?=$course['title'];?></div> <!-- displays course name -->
      </div>

    <?php endforeach; ?>
</div>
</div>

    </div>
  <?php elseif ($empty): ?>
    <div class="view-empty">
      <?php print $empty; ?>
    </div>
  <?php endif; ?>

  <?php if ($pager): ?>
    <?php print $pager; ?>
  <?php endif; ?>

  <?php if ($attachment_after): ?>
    <div class="attachment attachment-after">
      <?php print $attachment_after; ?>
    </div>
  <?php endif; ?>

  <?php if ($more): ?>
    <?php print $more; ?>
  <?php endif; ?>

  <?php if ($footer): ?>
    <div class="view-footer">
      <?php print $footer; ?>
    </div>
  <?php endif; ?>

  <?php if ($feed_icon): ?>
    <div class="feed-icon">
      <?php print $feed_icon; ?>
    </div>
  <?php endif; ?>

</div><?php /* class view */ ?>

<!-- <script type='text/javascript'>//<![CDATA[ 
$(function(){
var radius = 240;
var fields = $('.field'), container = $('#container'), width = container.width(), height = container.height();
var angle = 4.714, step = (2*Math.PI) / fields.length;
fields.each(function() {
    var x = Math.round(width/2 + radius * Math.cos(angle) - $(this).width()/2);
    var y = Math.round(height/2 + radius * Math.sin(angle) - $(this).height()/2);
    if(window.console) {
        console.log($(this).text(), x, y);
    }
    $(this).css({
        left: x + 'px',
        top: y + 'px'
    });
    angle += step;
});
});//]]>  
</script>
<script type="text/javascript" src="js/jquery.fancybox.js"></script>
<link rel="stylesheet" type="text/css" href="css/jquery.fancybox.css" media="screen" />
<link rel="stylesheet" type="text/css" href="css/style.css" media="screen" />
[if lt IE 9]
<link rel="stylesheet" type="text/css" href="css/ie.css" media="screen" />
[endif]
</head> -->

<div id="wrapper">
<h1>Advising Circle for Jane Q. Student</h1>
<?php 
	$path = "../" . drupal_get_path('theme', 'circle');
 ?>
<div id="container">
    <div id="center">
		<a class="various" href="#student"><img src="<?=$path?>/images/student.png" /></a>
	</div>
    <div class="fieldc">
		<div class="advisor-thumb"><a class="various" href="#profile01"><img src="<?=$path?>/images/lee-baker.120.150.jpg" border="0" /></a></div>
		<div class="name">Lee Baker, PhD</div>
		<div class="title">Academic Dean</div>
	</div>
    <div class="fieldc">
		<div class="advisor-thumb"><a class="various" href="#profile02"><img src="<?=$path?>/images/susan_alberts.120.120.jpg" border="0" /></a></div>
		<div class="name">Susan Alberts, PhD</div>
		<div class="title">Academic Advisor</div>
	</div>
    <div class="fieldc">
		<div class="advisor-thumb"><a class="various" href="#profile03"><img src="<?=$path?>/images/david_mcclay.120.120.jpg" border="0" /></a></div>
		<div class="name">David McClay, PhD</div>
		<div class="title">Instructor, BIOLOGY 119.02D</div>
	</div>
    <div class="fieldc">
		<div class="advisor-thumb"><a class="various" href="#profile04"><img src="<?=$path?>/images/hargrove.120.120.jpg" border="0" /></a></div>
		<div class="name">Amanda Hargrove, PhD</div>
		<div class="title">Instructor, CHEM 166.01</div>
	</div>
    <div class="fieldc">
		<div class="advisor-thumb"><a class="various" href="#profile05"><img src="<?=$path?>/images/michael-moses.120.120.jpg" border="0" /></a></div>
		<div class="name">Michael Moses, PhD</div>
		<div class="title">Instructor, ENGLISH 103S.01</div>
	</div>
    <div class="fieldc">
		<div class="advisor-thumb"><a class="various" href="#profile06"><img src="<?=$path?>/images/guo-juin-hong.120.120.jpg" border="0" /></a></div>
		<div class="name">Guo-Juin Hong, PhD</div>
		<div class="title">Instructor, AMES 89S.03</div>
	</div>
	<div class="fieldc">
		<div class="advisor-thumb"><a class="various" href="#profile07"><img src="<?=$path?>/images/audrey-kang.120.120.png" border="0" /></a></div>
		<div class="name">Audrey Kang</div>
		<div class="title">Pegram Hall Resident Assistant</div>
	</div>
</div>

<!-- inline elements -->
<div id="student" class="profile" style="display:none;width:100%;">
	<img src="<?=$path?>/images/student.png" />
	<h2>Jane Q. Student</h2>
	<h3>Freshman</h3>
	<p><strong>Academic Dean:</strong> Lee Baker, PhD</p>
	<p><strong>Academic Advisor:</strong> Susan Alberts, PhD</p>
	<h4>Fall 2013 Course Load:</h4>
	<ul>
	  <li>BIOLOGY 119.02D <em>CELL &amp; DEVELOPMENTAL BIOLOGY</em> - David McClay, PhD<br />
	  TuTh 4:40PM - 5:55PM, Friedl Bdg 216</li>
	  <li>CHEM 166.01 <em>PHYSICAL CHEMISTRY</em> - Amy Bejsovec, PhD<br />
	  MW 8:30AM - 9:45AM, French Science 2231</li>
	  <li>ENGLISH 103S.01 <em>INTRO TO WRITING SHORT STORIES</em> - Michael Valdez Moses, PhD<br />
	  Tu 10:05AM - 12:35PM, Social Sciences 107</li>
	  <li>AMES 89S.03 <em>FIRST-YEAR SEMINAR (TOP)</em> - Guo-Juin Hong, PhD<br />
	  W 1:40PM - 4:10PM, Nasher 119</li>
	</ul>
	<h4>Fall 2013 Housing:</h4>
	<ul>
	  <li>Pegram Residence Hall (Neighborhood 1)</li>
	  <li>Audrey Kang, Resident Assistant</li>
	</ul>
</div>

<div id="profile01" class="profile" style="display:none;width:100%;">
	<img src="<?=$path?>/images/lee-baker.240.351.jpg" />
	<h2>Lee Baker, PhD</h2>
	<h3>Academic Advisor</h3>
	<h4>Professor of Cultural Anthropology</h4>
	<p>
		Lee D. Baker is Dean of Academic Affairs of Trinity College of Arts and Sciences, Associate Vice Provost for Undergraduate Education, and Professor of Cultural Anthropology, Sociology, and African and African American Studies at Duke University. He received his B.S. from Portland State University and doctorate in anthropology from Temple University. He has been a resident fellow at Harvard's W.E.B. Du Bois Institute, the Smithsonian's National Museum of American History, Johns Hopkins's Institute for Global Studies, The University of Ghana-Legon, the American Philosophical Society, and the National Humanities Center. His books include From Savage to Negro: Anthropology and the Construction of Race (<a href="https://scholars-staging.oit.duke.edu/display/per8194252">more...</a>)
	</p>
	<h4>Contact Information</h4>
	<ul>
		<li><strong>Office:</strong> 114 Allen, Durham, NC 27708-0042</li>
		<li><strong>Mailing:</strong> Box 90042, Durham, NC 27708-0042</li>
		<li><strong>Phone:</strong> (919) 684-3465</li>
		<li><strong>Email:</strong> <a href="mailto:ldbaker@duke.edu">ldbaker@duke.edu</a></li>
	</ul>
</div>

<div id="profile02" class="profile" style="display:none;width:100%;">
	<img src="<?=$path?>/images/susan_alberts.260.260.jpg" />
	<h2>Susan Alberts, PhD</h2>
	<h3>Academic Advisor</h3>
	<h4>Professor of Biology</h4>
	<p>
		
	</p>
	<h4>Contact Information</h4>
	<ul>
		<li><strong>Office:</strong> 130 Science Drive, Rm 137, Duke Box 90338, Durham, NC 27708</li>
		<li><strong>Mailing:</strong> Box 90338, Durham, NC 27708-0338</li>
		<li><strong>Phone:</strong> (919) 660-7272</li>
		<li><strong>Email:</strong> <a href="mailto:alberts@duke.edu">alberts@duke.edu</a></li>
	</ul>
</div>

<div id="profile03" class="profile" style="display:none;width:100%;">
	<img src="<?=$path?>/images/david_mcclay.260.260.jpg" />
	<h2>David McClay, PhD</h2>
	<h3>Instructor, BIOLOGY 119.02D</h3>
	<h4>Arthur S. Pearse Professor of Biology in Trinity College of Arts and Sciences</h4>
	<p>
		We ask how the embryo works. Prior to morphogenesis the embryo specifies each cell through transcriptional regulation and signaling. Our research builds gene regulatory networks to understand how that early specification works. We then ask how this specification programs cells for their morphogenetic movements at gastrulation, and how the cells deploy patterning information. Current projects examine 1) novel signal transduction mechanisms that establish and maintain embryonic boundaries mold the embryo at gastrulation; 2) specification of primary mesenchyme cells in such a way that they are prepared to execute an epithelial-mesenchymal transition, and then study mechanistically the regulation of that transition (<a href="https://scholars-staging.oit.duke.edu/display/per0577042">more...</a>)
	</p>
	<h4>Contact Information</h4>
	<ul>
		<li><strong>Office:</strong> 4102 French Science Center, Science Dr., Durham, NC 27708</li>
		<li><strong>Mailing:</strong> Box 90338, Department of Biology, Durham, NC 27708-1000</li>
		<li><strong>Phone:</strong> (919) 613-8188</li>
		<li><strong>Email:</strong> <a href="mailto:dmcclay@duke.edu">dmcclay@duke.edu</a></li>
	</ul>
</div>

<div id="profile04" class="profile" style="display:none;width:100%;">
	<img src="<?=$path?>/images/hargrove.jpg" />
	<h2>Amanda Hargrove, PhD</h2>
	<h3>Instructor, CHEM 166.01</h3>
	<h4>Scholar in Residence</h4>
	<!--<p>
		The Hargrove lab will harness the unique properties of small organic molecules to study the structure, function and therapeutic potential of long noncoding RNAs (lncRNAs). The discovery of these fascinating biomolecules has caused a paradigm shift in molecular biology and speculation as to their role as the master drivers of diseases such as cancer. At the same time very little is known about their structure and function, leading some to call the field a veritable “wild West.” Small molecules are the perfect tools for such exploration, and the Hargrove lab will work at the interface of chemistry and biology, employing (<a href="https://scholars-staging.oit.duke.edu/">more...</a>)
	</p>
	<h4>Contact Information</h4>
	<ul>
		<li><strong>Office:</strong> Rm. 4312 Ffsc, Dept. of Biology, Durham, NC 27708</li>
		<li><strong>Mailing:</strong> Box 90338, Dept. of Biology, Durham, NC 27708-0338</li>
		<li><strong>Phone:</strong> (919) 613-8162</li>
		<li><strong>Email:</strong> <a href="mailto:bejsovec@duke.edu">bejsovec@duke.edu</a></li>
	</ul>-->
</div>

<div id="profile05" class="profile" style="display:none;width:100%;">
	<img src="<?=$path?>/images/michael-moses.jpg" />
	<h2>Michael Moses, PhD</h2>
	<h3>Instructor, ENGLISH 103S.01</h3>
	<h4>Associate Professor with Tenure</h4>
	<p>
		Michael Valdez Moses grew up in Los Angeles and was educated at Harvard, New College, Oxford, and the University of Virginia. He is the author of <i>The Novel and the Globalization of Culture</i> (Oxford UP, 1995), and has edited several collections of critical essays including <i>The Writings of J. M. Coetzee</i> (Duke UP, 1994), <i>Modernism and Colonialism:  British and Irish Literature, 1900-1939</i> (Duke UP, 2007), and <i>Modernism and Cinema,</i> (Edinburgh UP, 2010).  His articles and reviews have appeared in <i>Modernism/Modernity</I>, <i>Kenyon Review</i>, <i> Modernist Cultures</I>, <i>Latin American Literary Review</i>, <i>South Atlantic Quarterly</i>, <i>Modern Fiction Studies</i>, <i>Literary Imagination</i>, <i>Journal of Literary Studies</i> (<a href="https://scholars-staging.oit.duke.edu/display/per5145252">more...</a>)
	</p>
	<h4>Contact Information</h4>
	<ul>
		<li><strong>Office:</strong> 319 Allen Bldg, Durham, NC 27708</li>
		<li><strong>Mailing:</strong> Box 90015, Durham, NC 27708-0015</li>
		<li><strong>Phone:</strong> (919) 684-8880</li>
		<li><strong>Email:</strong> <a href="mailto:mmoses@duke.edu">mmoses@duke.edu</a></li>
	</ul>
</div>

<div id="profile06" class="profile" style="display:none;width:100%;">
	<img src="<?=$path?>/images/guo-juin-hong.jpg" />
	<h2>Guo-Juin Hong, PhD</h2>
	<h3>Instructor, AMES 89S.01</h3>
	<h4>Associate Professor of Asian and Middle Eastern Studies</h4>
	<p>
		Film historiography, film theory, postcolonial theory and theories of culture and globalization; film and other media of Taiwan, Hong Kong and China
	</p>
	<h4>Contact Information</h4>
	<ul>
		<li><strong>Office:</strong> 2204 Erwin Road, Room 220, Durham, NC 27708</li>
		<li><strong>Mailing:</strong> Box 90414, Durham, NC 27708-0414</li>
		<li><strong>Phone:</strong> (919) 660-4396</li>
		<li><strong>Email:</strong> <a href="mailto:jghong@duke.edu">jghong@duke.edu</a></li>
	</ul>
</div>

<div id="profile07" class="profile" style="display:none;width:100%;">
	<img src="<?=$path?>/images/audrey-kang.260.260.jpg" />
	<h2>Audrey Kang</h2>
	<h3>Pegram Hall Resident Assistant</h3>
	<p>
		
	</p>
	<h4>Contact Information</h4>
	<ul>
		<li><strong>Mailing:</strong> Box 90414, Durham, NC 27708-0414</li>
		<li><strong>Phone:</strong> (919) 660-4396</li>
		<li><strong>Email:</strong> <a href="mailto:jghong@duke.edu">jghong@duke.edu</a></li>
	</ul>
</div>
</div>
<?php


?>
<div id="<?php print $id; ?>" class="rate-container">
  <div class="question">
    <span class="bold"><?php print $question; ?> </span>
    <a class="js--return-false"
       data-track="event"
       data-category="<?php print $category; ?>"
       data-action="<?php print $action; ?>"
       data-label="yes"
       data-value="<?php print $value; ?>"
       data-toggle="class"
       data-target="<?php print $id; ?> > div"
       data-class="hide"
       href="#"><?php print $yes_label; ?></a>
    <a class="js--return-false"
       data-track="event"
       data-category="<?php print $category; ?>"
       data-action="<?php print $action; ?>"
       data-label="no"
       data-value="<?php print $value; ?>"
       data-toggle="class"
       data-target="<?php print $id; ?> > div"
       data-class="hide"
       href="#"><?php print $no_label; ?></a>
   </div>
   <div class="thanks">
     <?php print $thanks;?>
   </div>
</div>

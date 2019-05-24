<?php


?>
<div id="rating-<?php print $id; ?>" class="rate-container">
  <div class="question bg--gray-1 padding-x--xxs display--inline-block">
    <span class=""><?php print $question; ?> </span>
    <a class="js--return-false padding-left--xxs"
       data-track="event"
       data-category="<?php print $category; ?>"
       data-action="<?php print $action; ?>"
       data-label="yes"
       data-value="<?php print $value; ?>"
       data-toggle="class"
       data-target="#rating-<?php print $id; ?> > div"
       data-class="hide"
       href="#"><?php print $yes_label; ?></a>
    <a class="js--return-false padding-left--xxs"
       data-track="event"
       data-category="<?php print $category; ?>"
       data-action="<?php print $action; ?>"
       data-label="no"
       data-value="<?php print $value; ?>"
       data-toggle="class"
       data-target="#rating-<?php print $id; ?> > div"
       data-class="hide"
       href="#"><?php print $no_label; ?></a>
   </div>
   <div class="hide thanks bg--gray-1 padding-x--xxs display--inline-block">
     <?php print $thanks;?>
   </div>
</div>

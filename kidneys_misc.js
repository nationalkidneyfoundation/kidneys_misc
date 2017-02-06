(function ($, Drupal) {
  Drupal.behaviors.nkf_misc = {
    attach: function(context, settings) {
      jQuery("#promotion--block").load("/nkf-promotion/block/test");
      jQuery("#promotion--button").load("/nkf-promotion/button/test");
    }
  }
})(jQuery, Drupal);

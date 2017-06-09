(function ($, Drupal) {
  Drupal.behaviors.nkf_misc_pardot = {
    attach: function(context, settings) {
      $(window).on("message", function(e) {
        var data = e.originalEvent.data;
        if (data.submitted) {
          console.log(data);
          if (data.email) {
            var iFrame = '<iframe src="https://go.pardot.com/l/219342/2017-06-02/q74n?email=' + data.email + '" width="100%" height="500" type="text/html" frameborder="0" allowTransparency="true" style="border: 0"></iframe>'
            $('#pardot-progressive').append(iFrame);
            $.magnificPopup.open({
              items: {
                src: '#pardot-progressive',
                type: 'inline'
              }
            });
          } else {
            //$.magnificPopup.close();
          }
        }
      });
    }
  }
})(jQuery, Drupal);

(function ($, Drupal) {
  Drupal.kidneys_misc = Drupal.kidneys_misc || {};
  Drupal.kidneys_misc.getCategories = function(stringify) {
    stringify = stringify || false;
    var c = $.cookie('categories') || '{}';
    c = JSON.parse(c);
    if (c[undefined]) {
      delete c[undefined];
    }
    return stringify ? JSON.stringify(c) : c;
  }
  Drupal.kidneys_misc.addCategory = function(c, w) {
    var cs = Drupal.kidneys_misc.getCategories(false);
    if (c) { {
      cs[c] = +cs[c] ? cs[c] + (w / cs[c]) : w || 1;
    }}
    $.cookie('categories', JSON.stringify(cs), { path: '/' });
  }
  Drupal.kidneys_misc.addCategories = function(newCs) {
    if (typeof newCs === 'string') {
      newCs = JSON.parse(newCs);
    }
    $.each(newCs, function(i,v){
      Drupal.kidneys_misc.addCategory(i,v);
    });
  }
  Drupal.behaviors.nkf_misc = {
    attach: function(context, settings) {
      if (Drupal.settings.kidneys_categories && !Drupal.settings.kidneys_categories_processed) {
        Drupal.kidneys_misc.addCategories(Drupal.settings.kidneys_categories);
        Drupal.settings.kidneys_categories_processed = true;
      }
      var query = Drupal.kidneys_misc.getCategories(true);
      $(".promotion").each(function() {
        $(this).once(function() {
          var base = $(this).attr('id');
          var element_settings = {
            url: settings.basePath + settings.pathPrefix + 'nkf-promotion?display=' + $(this).data('promo') + '&query=' + query + '&calling_q=' + Drupal.settings.calling_q,
            event: 'fetch',
            progress: {
              type: 'none'
            }
          };
          Drupal.ajax[base] = new Drupal.ajax(base, this, element_settings);
          $(this).trigger('fetch');
        });
        $(this).once().click(function(){
          var obj = {
            hitType: 'event',
            eventCategory: 'promo',
            eventAction: $(this).data('promo') ? $(this).data('promo') : '',
            eventLabel: $('>div',this).data('promo-name') ? $('>div',this).data('promo-name') : '',
            eventValue: $('>div',this).data('id') ? $('>div', this).data('id') : '',
            transport: 'beacon'
          };
          try {
            ga('send', obj);
          } catch (e) {}
        });
      });
    }
  }


})(jQuery, Drupal);

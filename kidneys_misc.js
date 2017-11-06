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

  Drupal.kidneys_misc.sticky_nav = function() {
    var o = {
      hasScrolled: false,
      hasResized: false,
      nav: $('.sticky-nav'),
      nav_sections: $('.nav-section'),
      onScroll: function() { o.hasScrolled = true; },
      onResize: function() { o.hasResized = true; },
      checkScroll: function() {
        if (o.hasScrolled) {
          o.hasScrolled = false;
          o.orientNav();
        }
      },
      checkResize: function() {
        if (o.hasResized) {
          o.hasResized = false;
          o.orientNav();
        }
      },
      orientNav: function() {
        var window_top = $(window).scrollTop();
        o.setNavPosition(window_top);
        o.setNavActiveItem(window_top);
      },
      setNavPosition: function(window_top) {
        if (window_top > o.nav_top) {
          if(!o.nav.hasClass('position--fixed')) {
            o.nav.addClass('position--fixed');
            o.nav.removeClass('position--relative');
            $('.nav-sub').removeClass('hide');
            $('.label', o.nav).addClass('bg--white--o40');
          }
        } else {
          if(o.nav.hasClass('position--fixed')) {
            o.nav.removeClass('position--fixed');
            o.nav.addClass('position--relative');
            $('.nav-sub').addClass('hide');
            $('.label', o.nav).removeClass('bg--white--o40');
          }
        }
      },
      setNavActiveItem: function(window_top) {
        o.nav_sections.each(function(i,v) {
          var s = $(v);
          var t = s.offset().top;
          var b = t + $(v).outerHeight();
          var j;
          if (window_top > (t - 50) && window_top < b) {
            $('a', o.nav).removeClass('bold');
            j = $('.nav-anchor', v).attr('id');
            o.nav.find('a[href="#' + j + '"]').addClass('bold');
          }
        });
      },
      init: function() {
        console.log('initing');
        if (o.nav.length > 0) {
          o.nav_top = o.nav.offset().top;
          $(window).scroll(o.onScroll);
          $(window).resize(o.onResize);
          window.setInterval(o.checkScroll, 50);
          window.setInterval(o.checkResize, 50);
        }
      }
    }
    return o;
  }

  Drupal.behaviors.nkf_misc = {
    attach: function(context, settings) {
      $('body').once(Drupal.kidneys_misc.sticky_nav().init());
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

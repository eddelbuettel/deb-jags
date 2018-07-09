## Process this file with automake to produce Makefile.in

SUBDIRS = src plugins

install-data-local:
	@$(NORMAL_INSTALL)
	if test -d src/pixmaps; then \
	  $(mkinstalldirs) $(DESTDIR)$(pkgdatadir)/pixmaps; \
	  for pixmap in src/pixmaps/*; do \
	    if test -f $$pixmap; then \
	      $(INSTALL_DATA) $$pixmap $(DESTDIR)$(pkgdatadir)/pixmaps; \
	    fi \
	  done \
	fi 
	if test -d plugins; then \
	  $(mkinstalldirs) $(DESTDIR)$(pkgdatadir)/plugins; \
	  for plugin in plugins/*.plugin; do \
            $(mkinstalldirs) $(DESTDIR)$(pkgdatadir)/$$plugin; \
	      for i in $$plugin/*; do \
                 if test -f $$i; then \
                   $(INSTALL_DATA) $$i $(DESTDIR)$(pkgdatadir)/$$plugin; \
                 fi \
               done \
	  done \
	fi 
	if test -f src/jags.conf.sample; then \
	  cp src/jags.conf.sample $(DESTDIR)$(pkgdatadir)/jags.conf.sample;	\
	  echo "";\
	  echo "************************************************";\
	  echo "* NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE *";\
	  echo "************************************************";\
	  echo "";\
	  echo "Jags successfully installed.";\
	  echo "";\
	  echo "If you're upgrading from a previous version of Jags: ";\
	  echo "Please run ./upgrade as your regular user to make ";\
	  echo "sure that your config-files will be updated.";\
	  echo "";\
	  echo "";\
	fi
#	echo "If you're upgrading from a previous version of Jags: ";\
#	echo "Please run ./upgrade as you regular user to make ";\
#	echo "sure that your config-files will be updated.";
# 	      for i in src/plugins/$$plugin/*; do 
#                 if test -f $$i; then 
#                   $(INSTALL_DATA) $$i $(DESTDIR)$(pkgdatadir)/plugins/$$plugin; 
#                 fi 
#               done 
# 	    if test -d $$plugin; then \
#               $(mkinstalldirs) $(DESTDIR)$(pkgdatadir)/plugins/$$plugin; \
# 	    fi \

# dist-hook:
# 	if test -d pixmaps; then \
# 	  mkdir $(distdir)/pixmaps; \
# 	  for pixmap in pixmaps/*; do \
# 	    if test -f $$pixmap; then \
# 	      cp -p $$pixmap $(distdir)/pixmaps; \
# 	    fi \
# 	  done \
# 	fi


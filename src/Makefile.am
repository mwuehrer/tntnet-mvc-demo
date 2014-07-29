AUTOMAKE_OPTIONS = subdir-objects

bin_PROGRAMS = demo

ecppSources = \
    view/index.ecpp \
    view/fibonacci.ecpp \
    view/sort_int.ecpp \
    frame.ecpp

#Static sources which should be compiled into the binary
staticResources = \
	resources/static_resource.htm \
	resources/favicon.ico \
	resources/style.css \
	resources/test.js

staticComprResources = $(staticResources:=.gz)

#Static sources which should be located outside the binary
staticFiles = \
	www/tux.svg \
	www/jquery/jquery-ui.css \
	www/jquery/jquery-ui.js \
	www/jquery/external/jquery/jquery.js 

staticComprFiles = $(staticFiles:=.gz)

demo_SOURCES = \
	controller/index.cpp \
	controller/fibonacci.cpp \
	controller/sort_int.cpp \
	main.cpp \
	$(ecppSources)

nodist_demo_SOURCES = \
	resources.cpp

AM_INCLUDES = -I$(top_srcdir)/src

#start of dynamic linked libraries:
demo_LDFLAGS = -lboost_program_options -lboost_filesystem -lboost_system
demo_LDFLAGS += -lcxxtools -ltntnet 
#end of dynamic linked libraries

CLEANFILES = $(ecppSources:.ecpp=.cpp) $(ecppSources:.ecpp=.deps) resources.cpp $(staticComprFiles) $(staticComprResources)

#
# Rules for tntnet applications
#

resources.cpp: $(staticResources) $(staticComprResources) $(staticComprFiles) Makefile.am
	$(ECPPC) -bb -n resources -p -o resources.cpp -I$(srcdir) $(staticResources) $(staticComprResources)

SUFFIXES=.ecpp .ico .ico.gz .htm .htm.gz .cpp .css .css.gz .js .js.gz .svg .svg.gz
.css.css.gz: 
	$(GZIP) < $< > $@
.js.js.gz: 
	$(GZIP) < $< > $@
.svg.svg.gz:
	$(GZIP) < $< > $@
.ico.ico.gz:
	$(GZIP) < $< > $@
.htm.htm.gz:
	$(GZIP) < $< > $@
.ecpp.cpp:
	$(ECPPC) -I $(top_srcdir)/src -n `echo "$<" | $(SED) 's/\(.*\)\.ecpp/\1/'` -o $@ $<
.ecpp.deps:
	$(ECPPC) -M -n $* -I $(srcdir) -I $(srcdir)/include $< | $(SED) '1s/\(.*\).cpp:/\1.cpp \1.deps:/' > $@
.ico.cpp:
	$(ECPPC) -b -m image/x-icon -o $@ $<

-include $(ecppSources:.ecpp=.deps)

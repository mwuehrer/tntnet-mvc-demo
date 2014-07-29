AC_INIT([TNTNET MVC Demo],[0.0.1],[bugs@wuehrer.biz],[tntnet-mvc-demo],[https://github.com/mwuehrer/tntnet-mvc-demo])
AM_INIT_AUTOMAKE([-Wall -Werror foreign]) #TODO: remove foreign

AC_PROG_CXX
AC_LANG(C++)
AX_CXX_COMPILE_STDCXX_11([noext],[mandatory])

AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([src/config.h])


AC_CHECK_HEADER([cxxtools/mutex.h], , AC_MSG_ERROR([cxxtools headers not found]))
AC_CHECK_HEADER([tnt/tntnet.h], , AC_MSG_ERROR([tntnet headers not found]))
AC_CHECK_PROGS(ECPPC, [ecppc])
AC_CHECK_PROGS(GZIP, [gzip])
AC_PROG_SED
AX_CHECK_COMPILE_FLAG([-Wall], [CPPFLAGS="$CPPFLAGS -Wall"])
AX_CHECK_COMPILE_FLAG([-pedantic], [CPPFLAGS="$CPPFLAGS -pedantic"])
AX_CHECK_COMPILE_FLAG([-Wextra], [CPPFLAGS="$CPPFLAGS -Wextra"])
AX_CHECK_COMPILE_FLAG([-Werror], [CPPFLAGS="$CPPFLAGS -Werror"])
AX_BOOST_BASE([1.54],, [AC_MSG_ERROR([boost is needed, but it was not found in your system])])
AX_BOOST_SYSTEM
AX_BOOST_FILESYSTEM
AX_BOOST_PROGRAM_OPTIONS

#TODO: try to patch tntnet, that this lines are not needed anymore
AX_CHECK_COMPILE_FLAG([-Wno-unused-parameter], [CPPFLAGS="$CPPFLAGS -Wno-unused-parameter"])
AX_CHECK_COMPILE_FLAG([-Wno-unused-local-typedefs], [CPPFLAGS="$CPPFLAGS -Wno-unused-local-typedefs"])

#TODO: after patching and before final deployment uncomment the following line
# AX_CHECK_COMPILE_FLAG([-Weffc++], [CPPFLAGS="$CPPFLAGS -Weffc++"])

AC_OUTPUT([Makefile
        src/Makefile
    ])

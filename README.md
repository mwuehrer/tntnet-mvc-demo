MVC-Demo
========

Description
-----------

This repository contains a mvc-demo-app with tntnet.
It also contains a php version of this application, to compare the speed against the c++ variant.


Prerequisites
-------------

To use this demo-app, the git-version of TNTNET is needed (the latest stable
(version 2.2) doesn't have mvc-support.)


Build
-----

    * autoreconf -i
    * ./configure
    * make

    To generate debug-mode, execute the following:
    alias configuredebug='CPPFLAGS=-DDEBUG CFLAGS="-ggdb -O0" CXXFLAGS="-ggdb -O0" ./configure'

    * autoreconf -i
    * configuredebug
    * make

    After building, you can start the webserver by typing:

    cd src; ./demo


Folders:
--------

    In the folder src/ there are the sources of the tntnet-application.
    In the folder cmp/ there are the sources of the php-application.

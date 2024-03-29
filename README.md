Service Manager
===============

A cross-platform programming and scripting language-agnostic solution to system service development.

Features
--------

* Statically compiled targets.
* Has a liberal open source license.  MIT or LGPL, your choice.

Building Service Manager
------------------------

There is no ./configure && make here.  Just good old-fashioned shell scripts.

Windows (VC++ command-line):  build.bat

Mac (gcc):  build_mac.sh

Linux and many variants (gcc):  build_nix.sh

You may need to chmod +x or something to get the script to run, but you already knew that.

There is a test PHP-based service that handles 'notify.stop' and 'notify.reload' commands.  It also supports - via the Service Manager PHP SDK - a couple of command-line options to make installation and removal easy:

````
php test_service.php install
php test_service.php uninstall
php test_service.php configdump
````

You can, of course, write a test service in whatever language you want though.  It's simple and straightforward.

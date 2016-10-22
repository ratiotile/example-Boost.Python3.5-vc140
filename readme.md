
This example uses boost v1.55 because later versions appear to have problems building boost.python on windows.

Download boost and build boost.python. You may have to play with the options to get the right filename to be generated.
`G:\Libraries\boost\boost_1_55_0>b2 -j4 --with-python variant=debug address-model=32 link=shared,static runtime-debugging=on  toolset=msvc-14.0 -a`

In this case we are looking for `boost_python3-vc140-mt-gd-1_55.lib` which is actually an import library and not a static library, and `boost_python3-vc140-mt-gd-1_55.dll`.

decoding boost names
--------------------
vc140 - compiler

mt - multithreading

gd - runtime debugging and debug symbols

Common Problems
===============

'2to3' is not recognized
------------------------
running tests with bjam seems to fail with '2to3' is not recognized as a internal or external command...

You should have python.exe in C:\Python35 and 2to3.py in C:\Python35\Tools\Scripts.

Create a batch file called 2to3.bat in C:\Python35 and put this line in the batch file

    python %~dp0Tools\Scripts\2to3.py %*

VS wants to use vc120 instead of vc140
--------------------------------------
get the error `LNK1104: cannot open file 'boost-python-vc120-mt-1_55.lib'` in visual studio 2015 (vc140), and the project compiler is set to v140?

Boost 1.55 is too old to know about v140, so you need to edit `boost/config/auto_link.hpp`:

    #  elif defined(BOOST_MSVC) && (BOOST_MSVC < 1900)
    #    define BOOST_LIB_TOOLSET "vc120"

    #  elif defined(BOOST_MSVC)
    #    define BOOST_LIB_TOOLSET "vc140"

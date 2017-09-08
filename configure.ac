#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([FULL-PACKAGE-NAME], [VERSION], [BUG-REPORT-ADDRESS])
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE(Gameee,1.0)

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([SDL2],[SDL_Init],[],[
	      echo "Error! the SDL2 library has not been found!"
	      exit -1
])

AC_CHECK_LIB([SDL2_image],[IMG_Load],[],[
	      echo "Error! the SDL2_image library has not been found!"
	      exit -1
])

# Checks for header files.
AC_CHECK_HEADER([SDL.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 src/interface/Makefile])
AC_OUTPUT

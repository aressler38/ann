AC_INIT([anne], [1.0])
AM_INIT_AUTOMAKE([subdir-objects])

AC_PROG_RANLIB
AC_PROG_CXX
AC_LANG([C++])

OPENCL_DIST_DIR="/cygdrive/e/Intel/OpenCL/sdk"
OPENCL_CFLAGS="-I${OPENCL_DIST_DIR}/include"
OPENCL_LDFLAGS="-L${OPENCL_DIST_DIR}/lib/x64 -lOpenCL"
AM_CXXFLAGS="--pedantic -Wall -std=c++14 -O2"

AC_SUBST([AM_CXXFLAGS])
AC_SUBST([OPENCL_CFLAGS])
AC_SUBST([OPENCL_LDFLAGS])

AC_CONFIG_FILES([
                 Makefile
                 src/Makefile
                 ])
AC_OUTPUT

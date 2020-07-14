cmake_minimum_required(VERSION "3.17")

project("anne")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_VERBOSE_MAKEFILE ON)

# The way to hook up boost is to install it on your system and then
# set these two environment variables: BOOST_ROOT and BOOST_LIBRARYDIR.
# Cmake has a findBoost module that reads those and hooks it up.
# Example:
# BOOST_ROOT=/path/to/boost_1_73_0
# BOOST_LIBRARYDIR=/path/to/boost_1_73_0/lib64-msvc-14.1
if(WIN32)
message(STATUS "Using BOOST_ROOT: '$ENV{BOOST_ROOT}'")
message(STATUS "Using BOOST_LIBRARYDIR: '$ENV{BOOST_LIBRARYDIR}'")
endif()

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS system filesystem unit_test_framework  REQUIRED)

add_subdirectory(src) 

enable_testing()
add_subdirectory(test) 

#install(TARGETS "${PROJECT_NAME}" DESTINATION bin)


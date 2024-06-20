cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION True)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

project(
    ChangeMe
    DESCRIPTION "ChangeMe"
    HOMEPAGE_URL https://github.com/hugsy/ChangeMe
)

set(PROJECT_AUTHOR hugsy)
set(PROJECT_LICENSE MIT)

set(CXX_STANDARD 23)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

option(DEBUG                       "Enable Debug"                                             ON)
option(BUILD_EXAMPLES              "Compile the examples"                                     ON)
option(BUILD_TESTING               "Compile the test suite"                                   ON)

set(PROJECT_ROOT_DIR ${CMAKE_CURRENT_LIST_DIR})


#
# Build main part
#
add_subdirectory(src)


#
# Build unit tests
#
if(BUILD_TESTING)
    include(CTest)
    add_subdirectory(tests)
endif()


#
# Build toolkit
#
if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

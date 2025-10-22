project(ChangeMe
        LANGUAGES CXX
        VERSION 0.1.0)

set(PROJECT_LIB_SRC_DIR ${PROJECT_ROOT_DIR}/src CACHE INTERNAL "PROJECT_LIB_SRC_DIR")

#
# Create the constants.hpp macro file
#
configure_file(
    "${PROJECT_LIB_SRC_DIR}/constants.hpp.in"
    "${PROJECT_LIB_SRC_DIR}/constants.hpp"
    NEWLINE_STYLE WIN32
)

#
# Print out cmake compile info
#
message(STATUS "CMAKE_MODULE_PATH:                 ${CMAKE_MODULE_PATH}")
message(STATUS "CMAKE_SYSTEM_PROCESSOR:            ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "CMAKE_SYSTEM_NAME:                 ${CMAKE_SYSTEM_NAME}")

add_library(${PROJECT_NAME} STATIC lib.cpp)

set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
    CXX_STANDARD 23
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)

install(TARGETS ${PROJECT_NAME} DESTINATION ${PROJECT_NAME}/Library)

#
# Unit tests
#
project(ProjectTests)

set(PROJECT_TEST_DIR ${PROJECT_ROOT_DIR}/tests CACHE INTERNAL "PROJECT_TEST_DIR")

enable_testing()

set(COMMON_TEST_DIR ${PROJECT_TEST_DIR})

set(
    SOURCE_FILES

    ${COMMON_TEST_DIR}/main.cpp
    ${COMMON_TEST_DIR}/pwn_utils.cpp
    ${COMMON_TEST_DIR}/pwn_crypto.cpp
    ${COMMON_TEST_DIR}/pwn_assm_disasm.cpp
)


if(MSVC)
    set(TEST_DIR ${COMMON_TEST_DIR}/win32)
    set(
        SOURCE_FILES

        ${SOURCE_FILES}

    )

    add_compile_definitions(_UNICODE UNICODE)
else()
    set(TEST_DIR ${COMMON_TEST_DIR}/linux)
    set(
        SOURCE_FILES

        ${SOURCE_FILES}

    )

    add_compile_definitions(_GNU_SOURCE=1)
endif(MSVC)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
add_dependencies(${PROJECT_NAME} ${CMAKE_PROJECT_NAME})

#
# Prepare the test command
#
add_test(
    NAME ${PROJECT_NAME}
    COMMAND $<TARGET_FILE:${PROJECT_NAME}>
)

set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
    CXX_STANDARD 23
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)
target_include_directories(${PROJECT_NAME} PUBLIC ${TEST_DIR} $<TARGET_PROPERTY:${CMAKE_PROJECT_NAME},INCLUDE_DIRECTORIES>)
target_link_libraries(${PROJECT_NAME} PRIVATE $<TARGET_LINKER_FILE:${CMAKE_PROJECT_NAME}>)

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:${CMAKE_PROJECT_NAME}> $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

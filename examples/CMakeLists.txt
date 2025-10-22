project(Examples)

set(PROJECT_EXAMPLES_DIR ${PROJECT_ROOT_DIR}/examples CACHE INTERNAL "PROJECT_EXAMPLES_DIR")

set(
    EXAMPLES_DIRS

    # Populate here
)

foreach(EXAMPLE ${EXAMPLES_DIRS})
    file(GLOB SOURCE_FILES ${PROJECT_EXAMPLES_DIR}/${EXAMPLE}/*.cpp ${PROJECT_EXAMPLES_DIR}/${EXAMPLE}/*.asm)
    add_executable(${EXAMPLE} WIN32 ${SOURCE_FILES})
    add_dependencies(${EXAMPLE} ${CMAKE_PROJECT_NAME})
    set_target_properties(${EXAMPLE} PROPERTIES  CXX_STANDARD 23)
    target_compile_features(${EXAMPLE} PRIVATE cxx_std_23)
    target_include_directories(${EXAMPLE} PUBLIC ${TEST_DIR} $<TARGET_PROPERTY:${CMAKE_PROJECT_NAME},INCLUDE_DIRECTORIES>)
    target_link_libraries(${PROJECT_NAME} PRIVATE $<TARGET_LINKER_FILE:${CMAKE_PROJECT_NAME}>)
    if(MSVC)
        target_link_options(${EXAMPLE} PRIVATE "/Subsystem:Console")
    endif(MSVC)
    install(TARGETS ${EXAMPLE} DESTINATION Examples)
    install(FILES $<TARGET_PDB_FILE:${EXAMPLE}> DESTINATION Examples/Debug OPTIONAL)
endforeach()

# Tests CMakeLists
enable_testing()
add_subdirectory(${PROJECT_SOURCE_DIR}/third_party/googletest ${CMAKE_BINARY_DIR}/googletest)

file(GLOB TEST_SOURCES *.cpp)

add_executable(run_tests ${TEST_SOURCES})

target_include_directories(run_tests PRIVATE ${PROJECT_SOURCE_DIR}/includes)

target_link_libraries(run_tests
    gtest_main
    diagnostics_lib
)

include(GoogleTest)
gtest_discover_tests(run_tests)

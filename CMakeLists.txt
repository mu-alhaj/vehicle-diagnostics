#   from root: VDS
#   run to config cmake:
#       cmake -S . -B build -DBUILD_TESTING=ON
#   run to build applications:
#       cmake --build build
#   run to run tests:
#       ctest --test-dir build/tests

cmake_minimum_required(VERSION 3.10)
project(VehicleDiagnostics)

set(CMAKE_CXX_STANDARD 17)

# Define include directories for headers
include_directories(
    ${PROJECT_SOURCE_DIR}/includes
)

# Grab all cpp files in src/
file(GLOB_RECURSE SOURCES src/*.cpp)

# Remove main.cpp , in order to make lib for testing.
list(REMOVE_ITEM ALL_SOURCES src/main.cpp)

# add_subdirectory for tests
option(BUILD_TESTING "Build unit tests" ON)
if(BUILD_TESTING)
    # make library of the source code.
    add_library(diagnostics_lib ${SOURCES} )
    target_include_directories(diagnostics_lib PUBLIC ${PROJECT_SOURCE_DIR}/includes)
    
    
    add_subdirectory(tests)
endif()

# here we append main.cpp to the SOURCES before making executable
list(APPEND SOURCES src/main.cpp)

add_executable(diagnostics_app ${SOURCES})

# Link libraries if needed (e.g., pthread, etc.)
# target_link_libraries(diagnostics_app pthread)
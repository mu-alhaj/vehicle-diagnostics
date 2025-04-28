cmake_minimum_required(VERSION 3.10)
project(VehicleDiagnostics)

set(CMAKE_CXX_STANDARD 17)

# Define include directories for headers
include_directories(
    ${PROJECT_SOURCE_DIR}/includes
)

# Define source files
set(SOURCES
    src/main.cpp

    # Sensors
    src/sensor.cpp
    src/tempSensor.cpp
    src/rpmSensor.cpp
    src/voltageSensor.cpp
    src/display.cpp

    # Managers
    src/sensorManager.cpp
    src/safetyManager.cpp

    # Data Provider
    src/dataProvider.cpp
)

add_executable(diagnostics_app ${SOURCES})

# Link libraries if needed (e.g., pthread, etc.)
# target_link_libraries(diagnostics_app pthread)
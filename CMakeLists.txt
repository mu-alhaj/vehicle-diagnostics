cmake_minimum_required(VERSION 3.10)
project(VehicleDiagnostics)

set(CMAKE_CXX_STANDARD 17)

# Define include directories for headers
include_directories(
    ${PROJECT_SOURCE_DIR}/sensors
    ${PROJECT_SOURCE_DIR}/managers
    ${PROJECT_SOURCE_DIR}/dataProvider
)

# Define source files
set(SOURCES
    src/main.cpp

    # Sensors
    src/sensors/sensor.cpp
    src/sensors/tempSensor.cpp
    src/sensors/rpmSensor.cpp
    src/sensors/voltageSensor.cpp

    # Managers
    src/managers/sensorManager.cpp
    src/managers/safetyManager.cpp

    # Data Provider
    src/dataProvider/dataProvider.cpp
)

add_executable(diagnostics_app ${SOURCES})

# Link libraries if needed (e.g., pthread, etc.)
# target_link_libraries(diagnostics_app pthread)
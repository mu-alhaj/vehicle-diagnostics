cmake_minimum_required(VERSION 3.10)
project(VehicleDiagnostics)

set(CMAKE_CXX_STANDARD 17)

add_executable(diagnostics_app
    main.cpp
    sensor.cpp
    sensorManager.cpp
    safetyManager.cpp
    tempSensor.cpp
    rpmSensor.cpp
    voltageSensor.cpp
    )
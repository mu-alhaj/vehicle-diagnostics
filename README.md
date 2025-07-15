# Vehicle Diagnostics System (VDS)

A modular C++ simulation of a vehicle diagnostics system designed to demonstrate modern object-oriented principles, smart pointers, and clean architecture in a Linux-based C++ project. Sensors read from a simulated engine, data is distributed through a central provider, and safety checks and visual outputs are handled via independent components.

## Features

- Simulated engine generating dynamic values (temperature, RPM, voltage, etc.)
- Modular sensor classes using polymorphism
- Central `DataProvider` to distribute data using observer pattern
- `SafetyManager` to detect overheat, overvoltage, etc.
- `Display` module to show real-time readings
- Clean folder structure and CMake integration
- Designed with real-world software architecture principles in mind (like AUTOSAR)

## Build and Run

This project uses `CMake`. You’ll need a C++17 compiler and make.

### Steps:

```bash
cd path/to/vds
mkdir build && cd build
cmake ..
make
./diagnostics_app

## Concepts Demonstrated

- Object-Oriented Programming (Inheritance, Abstraction, Encapsulation)
- Polymorphism with abstract base class `Sensor`
- Smart pointers (`std::shared_ptr`)
- Observer pattern (listeners in `DataProvider`)
- Separation of concerns and clean code design

## Future Enhancements

- Add logging module
- Remote diagnostics over network
- Apply digital filtering to noisy sensor data
- Implement real-time plotting or GUI output

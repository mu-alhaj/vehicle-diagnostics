#pragma once

struct SensorData {
    double voltage;
    double rpm;
    double temp;
    double load;
    double oilPressure;
    double fuelConsumption;
};

enum struct Warning {
    WARNING_VOLTAGE,
    WARNING_RPM,
    WARNING_TEMPERATURE,
    WARNING_COUNT       // ADD WARNINGS BEFORE THIS LINE
};
#pragma once

struct SensorData {
    double voltage;
    double rpm;
    double temp;
};

enum struct Warning {
    WARNING_VOLTAGE,
    WARNING_RPM,
    WARNING_TEMPERATURE,
    WARNING_COUNT       // ADD WARNINGS BEFORE THIS LINE
};
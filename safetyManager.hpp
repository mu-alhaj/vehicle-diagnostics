#pragma once

class SafetyManager {
    double voltage  = 0.0;
    double rpm      = 0.0;
    double temp     = 0.0;

public:
    void updateReadings( double voltage, double rpm, double temp );
    void checkSafety();
};
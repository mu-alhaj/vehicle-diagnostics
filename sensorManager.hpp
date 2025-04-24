#pragma once

#include <vector>
#include <memory>
#include "sensor.hpp"

using namespace std;

class SensorManager {
    vector<shared_ptr<Sensor>> sensors;
    double voltage  = 0.0;
    double rpm      = 0.0;
    double temp     = 0.0;
public:
    void addSensor( shared_ptr< Sensor > sensor );
    void readAll();
    double getVoltage() const;
    double getRpm() const;
    double getTemp() const;
};
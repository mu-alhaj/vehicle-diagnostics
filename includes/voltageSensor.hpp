#pragma once 

#include "sensor.hpp"

using namespace std;

class VoltageSensor : public Sensor {
public:
    VoltageSensor( std::shared_ptr<Engine> engine );
    SensorId getId() const override;
    double readValue() const override;
};
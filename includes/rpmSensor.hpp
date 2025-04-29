#pragma once

#include "sensor.hpp"

using namespace std;

class RpmSensor : public Sensor {
public:
    RpmSensor( std::shared_ptr<Engine> engine );
    SensorId getId() const override;
    double readValue() const override;
};
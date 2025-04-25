#pragma once

#include "sensor.hpp"

using namespace std;

class RpmSensor : public Sensor {
public:
    string getName() const override;
    double readValue() const override;
};
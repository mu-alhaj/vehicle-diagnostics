#pragma once

#include "sensor.hpp"

using namespace std;

class TemperatureSensor : public Sensor {
public:
    string getName() const override;
    double readValue() const override;

};
#pragma once 

#include "sensor.hpp"

using namespace std;

class VoltageSensor : public Sensor {
public:
    string getName() const override;
    double readValue() const override;
};
#include "voltageSensor.hpp"
#include <cstdlib>


string VoltageSensor::getName() const {
    return "Voltage";
}

double VoltageSensor::readValue() const {
    return 12.0 + ( rand() %300 ) / 100.0;
}
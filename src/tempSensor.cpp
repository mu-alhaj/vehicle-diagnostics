#include "tempSensor.hpp"
#include <cstdlib>

string TemperatureSensor::getName() const{
    return "Temperature";
}

double TemperatureSensor::readValue() const{
    return 75.0 + ( rand() % 1000 ) / 10.0;
}
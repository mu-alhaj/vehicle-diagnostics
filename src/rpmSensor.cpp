#include "rpmSensor.hpp"
#include <cstdlib>

using namespace std;

string RpmSensor::getName() const {
    return "RPM";
}

double RpmSensor::readValue() const {
    return 800 + ( rand() % 2000 );
}
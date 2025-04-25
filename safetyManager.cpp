#include "safetyManager.hpp"
#include <iostream>

using namespace std;

const double threshold_voltage     = 30;
const double threshold_rpm         = 6000;
const double threshold_temp        = 100;

void SafetyManager::updateReadings( double voltage, double rpm, double temp ){
    this->voltage = voltage;
    this->rpm = rpm;
    this->temp = temp;
}

void SafetyManager::checkSafety(){
    if ( voltage > threshold_voltage )
        cout << "warning - over voltage " << voltage << endl;
    if ( rpm > threshold_rpm )
        cout << "warning - over rpm " <<  rpm << endl;
    if ( temp > threshold_temp )
        cout << "warning - over temp " << temp << endl;
}
// test
#pragma once

#include "sensorManager.hpp"

/*
    dataProvider: should be able to collect data from sensor manager, filter and process it if needed. And be ready to 
    deliver it for concerned classes like safety manager, display etc.
*/

class DataProvider {
    double voltage  = 0.0;
    double rpm      = 0.0;
    double temp     = 0.0;

public:
void updateData( SensorManager sm );
};
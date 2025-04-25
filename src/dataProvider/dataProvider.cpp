#include "dataProvider.hpp"
#include <iostream>


void DataProvider::updateData( SensorManager sm ){
    voltage = sm.getVoltage();
    rpm     = sm.getRpm();
    voltage = sm.getTemp();
    cout << "form the data provider" << endl;
}
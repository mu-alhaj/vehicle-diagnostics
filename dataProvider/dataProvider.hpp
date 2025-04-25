#pragma once

/*
    dataProvider: should be able to collect data from sensor manager, filter and process it if needed. And be ready to 
    deliver it.
*/

class DataProvider {
    double voltage  = 0.0;
    double rpm      = 0.0;
    double temp     = 0.0;

public:
    void updateReadings( double voltage, double rpm, double temp );
    void checkSafety();
};
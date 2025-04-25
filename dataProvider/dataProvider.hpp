#pragma once

#include <functional>

/*
    dataProvider: should be able to collect data from sensor manager, filter and process it if needed. And be ready to 
    deliver it for concerned classes like safety manager, display etc.
*/

class DataProvider {

using DataReadyCallback = std::function<void(int voltage, int rpm, int temp)>;

private:
    double voltage  = 0.0;
    double rpm      = 0.0;
    double temp     = 0.0;


public:
    void addListner( DataReadyCallback cb );
    void updateData( double v, double r, double t );
    std::vector<DataReadyCallback> listners;
};
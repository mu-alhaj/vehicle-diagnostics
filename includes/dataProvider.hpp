#pragma once

#include <functional>
#include "commonTypes.hpp"

/*
    dataProvider: should be able to collect data from sensor manager, filter and process it if needed. And be ready to 
    deliver it for concerned classes like safety manager, display etc.
*/

class DataProvider {

using DataReadyCallback = std::function<void( SensorData data )>;

private:
    SensorData m_collectedData;


public:
    void addListner( DataReadyCallback cb );
    void updateData( SensorData data );
    std::vector<DataReadyCallback> listners;
};
#include "dataProvider.hpp"
#include <iostream>

using namespace std;

void DataProvider::addListner( DataReadyCallback cb ){
    listners.push_back( cb );
}

void DataProvider::updateData( SensorData data ){
    // m_collectedData.voltage = data.voltage;
    // m_collectedData.rpm     = data.rpm;
    // m_collectedData.temp    = data.temp;

    m_collectedData = data;

    // when data is received, filtered and processed. publish it to listners:
    for ( auto& cb : listners )
    {
        cb( m_collectedData );
    }
    

}
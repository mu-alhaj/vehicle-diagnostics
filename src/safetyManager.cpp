#include "safetyManager.hpp"
#include <iostream>

using namespace std;

const double threshold_voltage     = 30;
const double threshold_rpm         = 6000;
const double threshold_temp        = 100;

void SafetyManager::addListner( NotifyWarningsCallback cb ){
    listners.push_back( cb );
}

void SafetyManager::updateSensorData( SensorData data ){
    m_data.voltage  = data.voltage;
    m_data.rpm      = data.rpm;
    m_data.temp     = data.temp;
}

void SafetyManager::checkSafety() const{
    if ( m_data.voltage > threshold_voltage ){
        notifyListners( Warning::WARNING_VOLTAGE );
    }
    if ( m_data.rpm > threshold_rpm ){
        notifyListners( Warning::WARNING_RPM );
    }
    if ( m_data.temp > threshold_temp ){
        notifyListners( Warning::WARNING_TEMPERATURE );
    }
}

void SafetyManager::notifyListners( Warning w ) const{
    for ( auto& cb : listners )
    {
        cb( w );
    }
}
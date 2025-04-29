#include "sensorManager.hpp"
#include "sensorId.hpp"
#include <iostream>

using namespace std;


void SensorManager::addSensor( shared_ptr< Sensor > sensor ){
    m_sensors.push_back( sensor );
}

void SensorManager::readAll() {
    for ( const auto& sensor : m_sensors ){
        SensorId id = sensor->getId();
        double value = sensor->readValue();

        // should find a way to collect data without needing to add data to this switch case!
        switch ( id )
        {
        case SensorId::FUEL_CONSUMPTION:
            m_sensorData.fuelConsumption = value;
            break;
        case SensorId::LOAD :
            m_sensorData.load = value;
            break;
        case SensorId::OIL_PRESSURE:
            m_sensorData.oilPressure = value;
            break;
        case SensorId::RPM:
            m_sensorData.rpm = value;
            break;
        case SensorId::TEMPERATURE:
            m_sensorData.temp = value;
            break;
        case SensorId::VOLTAGE:
            m_sensorData.voltage = value;
            break;
        default:
            cout << "[ warning ] sensor id : " << static_cast<int>( id ) << "was not read by sensor manager." << endl;
            break;
        }
    }
    // when all sensors are read, update the data provider.
    m_dataProviderUpdate_cb( m_sensorData );
}

double SensorManager::getVoltage() const {
    return m_sensorData.voltage;
}

double SensorManager::getRpm() const {
    return m_sensorData.rpm;
}

double SensorManager::getTemp() const {
    return m_sensorData.temp;
}

void SensorManager::registerCallback( UpdateCallback cb ){
    m_dataProviderUpdate_cb = cb;
}
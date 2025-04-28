#include "sensorManager.hpp"
#include <iostream>

using namespace std;


void SensorManager::addSensor( shared_ptr< Sensor > sensor ){
    sensors.push_back( sensor );
}

void SensorManager::readAll() {
    for ( const auto& sensor : sensors ){
        string name = sensor->getName();
        double value = sensor->readValue();

        // here we can use a map to update readings.
        if ( name == "Temperature" ){
            sensorData.temp = value;
        }
        if ( name == "RPM" ){
            sensorData.rpm = value;
        }
        if ( name == "Voltage" ){
            sensorData.voltage = value;
        }
    }

    cout << __FILE__ << " : " << __func__ << endl;
    // when all sensors are read, update the data provider.
    dataProviderUpdate_cb( sensorData );
}

double SensorManager::getVoltage() const {
    return sensorData.voltage;
}

double SensorManager::getRpm() const {
    return sensorData.rpm;
}

double SensorManager::getTemp() const {
    return sensorData.temp;
}

void SensorManager::registerCallback( UpdateCallback cb ){
    dataProviderUpdate_cb = cb;
}
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
            this->temp = value;
        }
        if ( name == "RPM" ){
            this->rpm = value;
        }
        if ( name == "Voltage" ){
            this->voltage = value;
        }
        cout << name << " : " << value << endl;
    }

    // when all sensors are read, update the data provider.
    callback( *this );
}

double SensorManager::getVoltage() const {
    return this->voltage;
}

double SensorManager::getRpm() const {
    return this->rpm;
}

double SensorManager::getTemp() const {
    return this->temp;
}

void SensorManager::registerCallback( UpdateCallback cb ){
    callback = cb;
}
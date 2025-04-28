#pragma once

/*
    sensor manager should be able to start/restart, calibrate sensors. As well as collecting raw data from sensors.
*/

#include <vector>
#include <memory>
#include "sensor.hpp"
#include <functional>
#include "commonTypes.hpp"

class SensorManager {

using UpdateCallback = std::function<void( SensorData data )>;

public:
    void    addSensor( shared_ptr< Sensor > sensor );
    void    readAll();
    double  getVoltage() const;
    double  getRpm() const;
    double  getTemp() const;
    void    registerCallback( UpdateCallback cb );

private:
    vector<shared_ptr<Sensor>> sensors;
    UpdateCallback dataProviderUpdate_cb;
    SensorData sensorData;

};
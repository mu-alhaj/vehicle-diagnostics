#pragma once

#include "sensor.hpp"


class LoadSensor : public Sensor {
public:
    LoadSensor( std::shared_ptr<Engine> engine );
    SensorId getId() const override;
    double readValue() const override;

};
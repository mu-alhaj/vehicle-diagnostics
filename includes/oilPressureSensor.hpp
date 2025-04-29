#pragma once

#include "sensor.hpp"


class OilPressureSensor : public Sensor {
public:
    OilPressureSensor( std::shared_ptr<Engine> engine );
    SensorId getId() const override;
    double readValue() const override;

};
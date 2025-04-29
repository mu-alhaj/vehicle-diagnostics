#pragma once

#include "sensor.hpp"


class FuelConsumptionSensor : public Sensor {
public:
    FuelConsumptionSensor( std::shared_ptr<Engine> engine );
    SensorId getId() const override;
    double readValue() const override;

};
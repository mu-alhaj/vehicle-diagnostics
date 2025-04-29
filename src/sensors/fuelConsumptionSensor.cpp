#include "fuelConsumptionSensor.hpp"

FuelConsumptionSensor::FuelConsumptionSensor( std::shared_ptr<Engine> engine ) : Sensor( engine ) {
    m_id = SensorId::FUEL_CONSUMPTION;
}
SensorId FuelConsumptionSensor::getId() const {
    return m_id;
}

double FuelConsumptionSensor::readValue() const {
    return m_engine->getFuelConsumption();
}
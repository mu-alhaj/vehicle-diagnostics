#include "voltageSensor.hpp"

VoltageSensor::VoltageSensor( std::shared_ptr<Engine> engine ) : Sensor( engine ) {
    m_id = SensorId::VOLTAGE;
}

SensorId VoltageSensor::getId() const {
    return m_id;
}

double VoltageSensor::readValue() const {
    return m_engine->getVoltage();
}
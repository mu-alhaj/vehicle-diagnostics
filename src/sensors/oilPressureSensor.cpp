#include "oilPressureSensor.hpp"

OilPressureSensor::OilPressureSensor( std::shared_ptr<Engine> engine ) : Sensor( engine ) {
    m_id = SensorId::OIL_PRESSURE;
}

SensorId OilPressureSensor::getId() const {
    return m_id;
}

double OilPressureSensor::readValue() const {
    return m_engine->getOilPressure();
}
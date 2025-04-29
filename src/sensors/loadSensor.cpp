#include "loadSensor.hpp"

LoadSensor::LoadSensor( std::shared_ptr<Engine> engine ) : Sensor( engine ) {
    m_id = SensorId::LOAD;
}

SensorId LoadSensor::getId() const {
    return m_id;
}

double LoadSensor::readValue() const {
    return m_engine->getLoad();
}
#include "rpmSensor.hpp"

RpmSensor::RpmSensor( std::shared_ptr<Engine> engine ) : Sensor( engine ) {
    m_id = SensorId::RPM;
}

SensorId RpmSensor::getId() const {
    return m_id;
}

double RpmSensor::readValue() const {
    return m_engine->getRpm();
}
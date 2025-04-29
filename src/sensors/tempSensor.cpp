#include "tempSensor.hpp"

TemperatureSensor::TemperatureSensor( std::shared_ptr<Engine> engine ) : Sensor( engine ) {
    m_id = SensorId::TEMPERATURE;
}

SensorId TemperatureSensor::getId() const{
    return m_id;
}

double TemperatureSensor::readValue() const{
    return m_engine->getTemperature();
}
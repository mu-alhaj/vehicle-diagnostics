#pragma once 

#include <memory>
#include "engine.hpp"
#include "sensorId.hpp"

// for debug
#include <iostream>


using namespace std;

class Sensor{
protected:
    std::shared_ptr<Engine> m_engine;
    SensorId m_id;
public:
    Sensor( std::shared_ptr<Engine> engine ) : m_engine( engine ) {}
    virtual SensorId getId() const = 0;
    virtual double readValue() const = 0;
    virtual ~Sensor() = default;
};
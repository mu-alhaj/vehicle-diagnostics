#include "engine.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>


using namespace std;

double base_load        = 0.5;
double base_rpm         = 1000;
double base_pressure    = 10;
double base_voltage     = 12;

double cooling_rate     = 0.4;
double ambient_temp     = 20.0;

double getRand(double min, double max) {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed the random number generator
    return min + static_cast<double>(std::rand()) / RAND_MAX * (max - min); // Scale to [min, max]
}

void Engine::start(){
    m_load          = base_load;
    m_voltage       = base_voltage;
    m_temperature   = ambient_temp;
}
void Engine::setSenario(){}

void Engine::update(){

    m_load +=  getRand( -0.02 , 0.02 );
    m_rpm   = base_rpm + m_load * 5000;
    
    double heatingFactor = m_rpm * m_load / 1000.0;
    double coolingFactor = m_rpm * cooling_rate / 1000.0;
    m_temperature += heatingFactor - coolingFactor;
    if ( m_temperature < ambient_temp ){
        m_temperature = ambient_temp;
    }

    m_oilPressure = base_pressure + m_rpm/1000 - (m_temperature - 90 )* 0.01;
    m_fuelConsumption = ( m_rpm/1000 ) * ( 0.5 + m_load );
    m_voltage -= ( m_load < 0.8 )? 0 : 0.1;
}

double Engine::getRpm() const{
    return m_rpm;
}
double Engine::getTemperature() const{
    return m_temperature;
}
double Engine::getVoltage() const{
    return m_voltage;
}

double Engine::getLoad() const{
    return m_load;
}

double Engine::getFuelConsumption() const{
    return m_fuelConsumption;
}

double Engine::getOilPressure() const{
    return m_oilPressure;
}
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
    
    return min + static_cast<double>(std::rand()) / RAND_MAX * (max - min); // Scale to [min, max]
}

double checkBoundary( double value, double min, double max ){
    if ( value < min ) return min;
    if ( value > max ) return max;
    return value;
}

void Engine::start(){
    
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed the random number generator

    m_load          = base_load;
    m_voltage       = base_voltage;
    m_temperature   = ambient_temp;
}
void Engine::setSenario(){}

void Engine::update(){

    // Random load.
    m_load +=  getRand( -0.02 , 0.02 );

    m_load = checkBoundary( m_load, 0.0, 1.0 );
    
    // RPM.
    m_rpm   = base_rpm + m_load * 5000;
    
    // Temp.
    double heating = m_rpm * m_load / 1000.0;
    double cooling = m_rpm * cooling_rate * ( (m_temperature - 90) > 1 ? (m_temperature - 90): 1 ) / 1000.0;

    m_temperature += heating - cooling;
    m_temperature = checkBoundary( m_temperature, ambient_temp, 110.0 );

    // Oil Pressure.
    m_oilPressure = base_pressure + m_rpm/1000 - (m_temperature - 90 )* 0.01;
    
    // Fuel consumption.
    m_fuelConsumption = ( m_rpm/1000 ) * ( 0.5 + m_load );

    // Voltage.
    double v_charge     = m_rpm/100000.0;  
    double v_disCharge  = m_rpm/120000.0;
    m_voltage += v_charge - v_disCharge;

    m_voltage = checkBoundary( m_voltage, 10.0, 14.0 );
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
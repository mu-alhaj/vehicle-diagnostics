#pragma once



class Engine
{
private:
    double m_rpm                = 0;
    double m_temperature        = 0;
    double m_voltage            = 0;
    double m_load               = 0;
    double m_oilPressure        = 0;
    double m_fuelConsumption    = 0;

public:
    void start();
    void setSenario();
    void update();

    double getRpm() const;
    double getTemperature() const;
    double getVoltage() const;
    double getLoad() const;
    double getFuelConsumption() const;
    double getOilPressure() const;
};
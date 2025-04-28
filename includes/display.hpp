#pragma once

#include "commonTypes.hpp"

class Display
{
private:
    SensorData  m_data;
    bool        m_warningsToDisplay[static_cast<int>(Warning::WARNING_COUNT)] = {0};
public:
    void updateSensorData( SensorData data );
    void updateWarnings( Warning w );
    void show();
};

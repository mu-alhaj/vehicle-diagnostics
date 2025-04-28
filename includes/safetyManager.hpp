#pragma once

#include <functional>
#include "commonTypes.hpp"

/*
    safety mangaer should be able to receive sensor data processes and ready to be used. and determine any info, warnings or errors.
*/

class SafetyManager {

using NotifyWarningsCallback = std::function< void( Warning warning ) >;

private:
    SensorData  m_data;
    std::vector<NotifyWarningsCallback> listners;

    void notifyListners( Warning w ) const;

public:
    void addListner( NotifyWarningsCallback cb );
    void updateSensorData( SensorData data );
    void checkSafety() const;
};
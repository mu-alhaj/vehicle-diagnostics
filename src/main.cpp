#include <iostream>
#include <memory>
#include <thread>
#include <chrono>

#include "sensorManager.hpp"
#include "safetyManager.hpp"
#include "dataProvider.hpp"
#include "tempSensor.hpp"
#include "rpmSensor.hpp"
#include "voltageSensor.hpp"
#include "commonTypes.hpp"
#include "display.hpp"



int main() {
    SensorManager sensorManager;
    SafetyManager safetyManager;
    DataProvider dataProvider;
    Display display;

    sensorManager.registerCallback( 
        [&dataProvider]( SensorData data ){
            dataProvider.updateData( data );
        }
     );
    sensorManager.addSensor( std::make_shared<TemperatureSensor>() );
    sensorManager.addSensor( std::make_shared<RpmSensor>() );
    sensorManager.addSensor( std::make_shared<VoltageSensor>() );

    dataProvider.addListner(
        [&safetyManager]( SensorData data ){
            safetyManager.updateSensorData( data );
        }
     );

     dataProvider.addListner(
        [&display]( SensorData data ){
            display.updateSensorData( data );
        }
     );

     safetyManager.addListner(
        [&display]( Warning w ){
            display.updateWarnings( w );
        }
     );

    while (true) {
        sensorManager.readAll();
        safetyManager.checkSafety();
        display.show();
        std::this_thread::sleep_for( std::chrono::seconds( 2 ) );
    }

    return 0;
}

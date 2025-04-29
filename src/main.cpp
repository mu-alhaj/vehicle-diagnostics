#include <iostream>
#include <memory>
#include <thread>
#include <chrono>


#include "commonTypes.hpp"

#include "engine.hpp"

#include "tempSensor.hpp"
#include "rpmSensor.hpp"
#include "voltageSensor.hpp"
#include "fuelConsumptionSensor.hpp"
#include "loadSensor.hpp"
#include "oilPressureSensor.hpp"

#include "sensorManager.hpp"
#include "safetyManager.hpp"
#include "dataProvider.hpp"

#include "display.hpp"


using namespace std;

int main() {

    // declare entities.
    SensorManager sensorManager;
    SafetyManager safetyManager;
    DataProvider dataProvider;
    Display display;

    auto p_engine = make_shared<Engine>();



    // initialize entities.
    sensorManager.registerCallback( 
        [&dataProvider]( SensorData data ){
            dataProvider.updateData( data );
        }
     );
    sensorManager.addSensor( make_shared<TemperatureSensor>( p_engine ) );
    sensorManager.addSensor( make_shared<RpmSensor>( p_engine ) );
    sensorManager.addSensor( make_shared<VoltageSensor>( p_engine ) );
    sensorManager.addSensor( make_shared<FuelConsumptionSensor>( p_engine ) );
    sensorManager.addSensor( make_shared<OilPressureSensor>( p_engine ) );
    sensorManager.addSensor( make_shared<LoadSensor>( p_engine ) );

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

     // start.

     p_engine->start();


    while (true) {
        p_engine->update();
        sensorManager.readAll();
        safetyManager.checkSafety();
        display.show();
        std::this_thread::sleep_for( std::chrono::seconds( 1 ) );
    }

    return 0;
}

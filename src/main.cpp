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



int main() {
    SensorManager sensorManager;
    SafetyManager safetyManager;
    DataProvider dataProvider;

    sensorManager.registerCallback( 
        [&dataProvider]( double voltage, double rpm, double temp ){
            dataProvider.updateData( voltage, rpm, temp );
        }
     );
    sensorManager.addSensor( std::make_shared<TemperatureSensor>() );
    sensorManager.addSensor( std::make_shared<RpmSensor>() );
    sensorManager.addSensor( std::make_shared<VoltageSensor>() );

    dataProvider.addListner(
        [&safetyManager]( double voltage, double rpm, double temp ){
            safetyManager.updateReadings( voltage, rpm, temp );
        }
     );

    while (true) {
        system("clear"); // or "cls" on Windows
        std::cout << "\nVehicle Diagnostics:\n";
        sensorManager.readAll();
        // todo: these values should be retreived form data provider instead.
        // safetyManager.updateReadings( sensorManager.getVoltage(), sensorManager.getRpm(), sensorManager.getTemp() );
        // safetyManager.checkSafety();
        std::this_thread::sleep_for( std::chrono::seconds( 2 ) );
    }

    return 0;
}

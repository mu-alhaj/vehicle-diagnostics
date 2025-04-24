#include <iostream>
#include <memory>
#include <thread>
#include <chrono>

#include "sensorManager.hpp"
#include "safetyManager.hpp"
#include "tempSensor.hpp"
#include "rpmSensor.hpp"
#include "voltageSensor.hpp"



int main() {
    SensorManager sensorManager;
    SafetyManager safetyManager;
    sensorManager.addSensor(std::make_shared<TemperatureSensor>());
    sensorManager.addSensor(std::make_shared<RpmSensor>());
    sensorManager.addSensor(std::make_shared<VoltageSensor>());

    while (true) {
        system("clear"); // or "cls" on Windows
        std::cout << "\nVehicle Diagnostics:\n";
        sensorManager.readAll();
        safetyManager.updateReadings( sensorManager.getVoltage(), sensorManager.getRpm(), sensorManager.getTemp() );
        safetyManager.checkSafety();
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    return 0;
}

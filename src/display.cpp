#include "display.hpp"
#include "iostream"

using namespace std;


void Display::updateSensorData( SensorData data ){
    m_data.voltage  = data.voltage;
    m_data.rpm      = data.rpm;
    m_data.temp     = data.temp;
}

void Display::updateWarnings( Warning w ){
    m_warningsToDisplay[static_cast<int>( w )] = true;
}

void Display::show(){
    system("clear"); // or "cls" on Windows
    // Display Banner
    cout << "===========================================" << endl;
    cout << "           VEHICLE DIAGNOSTICS            " << endl;
    cout << "===========================================" << endl;

    // Display Sensor Data
    cout << "\nSensor Data:" << endl;
    cout << "--------------------------" << endl;
    cout << "Voltage:       " << m_data.voltage << " V" << endl;
    cout << "RPM:           " << m_data.rpm << " RPM" << endl;
    cout << "Temperature:   " << m_data.temp << " C" << endl;

    // Display Active Warnings
    cout << "\nActive Warnings:" << endl;
    cout << "------------------------" << endl;

    bool hasWarnings = false;
    for ( size_t i = 0; i < static_cast<int>( Warning::WARNING_COUNT ); ++i ) {
        if ( m_warningsToDisplay[i] ) {
            hasWarnings = true;
            // Display warning based on enum value
            switch ( static_cast<Warning>( i ) ) {
                case Warning::WARNING_VOLTAGE:
                    cout << "[WARNING] Voltage is outside acceptable range!" << endl;
                    break;
                case Warning::WARNING_RPM:
                    cout << "[WARNING] RPM is too high!" << endl;
                    break;
                case Warning::WARNING_TEMPERATURE:
                    cout << "[WARNING] Temperature is too high!" << endl;
                    break;
                default:
                    break;
            }
            // display warning only one time
            m_warningsToDisplay[i] = false;        // maybe not the best practice to let show() set these off, but works for now.
        }
    }

    // If no warnings are active
    if (!hasWarnings) {
        cout << "No active warnings." << endl;
    }

    cout << "===========================================" << endl;
}


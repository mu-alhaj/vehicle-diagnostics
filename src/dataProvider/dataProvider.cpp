#include "dataProvider.hpp"
#include <iostream>

using namespace std;

void DataProvider::addListner( DataReadyCallback cb ){
    listners.push_back( cb );
}

void DataProvider::updateData( double v, double r, double t ){
    voltage = v;
    rpm     = r;
    temp    = t;
    cout << __FILE__ << " : " << __func__ << endl;

    cout << "voltage : " << voltage << endl;
    cout << "rpm     : " << rpm << endl;
    cout << "temp    : " << temp << endl;

    // when data is received, filtered and processed. publish it to listners:
    for ( auto& cb : listners )
    {
        cb( voltage, rpm, temp );
    }
    

}
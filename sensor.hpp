#pragma once 

#include <string>

using namespace std;

class Sensor{
    public:
    virtual string getName() const = 0;
    virtual double readValue() const = 0;
    virtual ~Sensor() = default;
};
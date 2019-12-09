#include "circuit.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


// COMPONENT
Component::Component(string const _name, Connection* const _left, Connection* const _right)
    : name{_name}, left{_left}, right{_right} {
    }

// Virtual functions
void Component::Update(double const _timeStep){};
double Component::getCurrent(){};


double Component::getVoltage(){

}

Component::~Component() {

}


// BATTERY
Battery::Battery(string const _name, Connection* const _left. Connection* const _right, double const _voltage)
    : Component(_name, _left, _right), voltage{_voltage} {
    }

void Battery::Update(double const _timeStep) {
    left->charge = voltage;
    right->charge = 0;
}

double Battery::getCurrent() {
    return 0
}

Battery::~() {
}


// RESISTOR
Resistor::Resistor(string const _name, Connection* const _left. Connection* const _right, double const _voltage)
    : Component(_name, _left, _right), resistance{_resistance} {
    }

void Resistor::Update(double const _timeStep) {
    double potential{left->charge - right->charge};
    double change{potential / resistance * _timeStep};
    left->charge += change;
    right->charge -= change;
}

double Resistor::getCurrent() {
    return (getVoltage() / 2);
}

Resistor::~Resistor() {
}


// CAPACITOR
Capacitor::Capacitor(string const _name, Connection* const _left. Connection* const _right,  double const _storage, double storedATM)
    : Component(_name, _left, _right), storage{_storage}, storedATM{storedATM} {
    }

void Capacitor::Update(double const _timeStep) {
    
}

double Capacitor::getCurrent() {
    return 
}

Capacitor::~Capacitor() {
}
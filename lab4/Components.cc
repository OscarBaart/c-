#include "Circuit.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


// COMPONENT
Component::Component(string const _name, Connection* const _in, Connection* const _out)
    : name{_name}, in{_in}, out{_out} {
    }

// Virtual functions
void Component::update(double const _timeStep){};
double Component::getCurrent(){};

double Component::getVoltage(){
    if(in->charge > out->charge) {
        volt = (in->charge - out->charge);
    }
    return volt;
}

Component::~Component() {
}


// BATTERY
Battery::Battery(string const _name, Connection* const _in, Connection* const _out, double const _voltage)
    : Component(_name, _in, _out), voltage{_voltage} {
    }

void Battery::update(double const _timeStep) {
    in->charge = voltage;
    out->charge = 0;
}

double Battery::getCurrent() {
    return 0;
}

Battery::~Battery() {
}


// RESISTOR
Resistor::Resistor(string const _name, Connection* const _in, Connection* const _out, double const _resistance)
    : Component(_name, _in, _out), resistance{_resistance} {
    }

void Resistor::update(double const _timeStep) {
    if(in->charge > out->charge) {
        double potential{in->charge - out->charge};
        double change{(potential / resistance) * _timeStep};
        in->charge -= change;
        out->charge += change;
    } else {
        double potential{out->charge - in->charge};
        double change{(potential / resistance) * _timeStep};
        out->charge -= change;
        in->charge += change;
    }
}

double Resistor::getCurrent() {
    return (getVoltage() / resistance);
}

Resistor::~Resistor() {
}


// CAPACITOR
Capacitor::Capacitor(string const _name, Connection* const _in, Connection* const _out,  double const _storage, double _storedATM)
    : Component(_name, _in, _out), storage{_storage}, storedATM{_storedATM} {
    }

void Capacitor::update(double const _timeStep) {
    if(in->charge > out->charge) {
        double potential{in->charge - out->charge};
        double change{storage * (potential - storedATM) * _timeStep};
        in->charge -= change;
        out->charge += change;
        storedATM += change;
    } else {
        double potential{out->charge - in->charge};
        double change{storage * (potential - storedATM) * _timeStep};
        out->charge -= change;
        in->charge += change;
        storedATM += change;
    }
}

double Capacitor::getCurrent() {
    return storage*(getVoltage()-storedATM);
}

Capacitor::~Capacitor() {
}
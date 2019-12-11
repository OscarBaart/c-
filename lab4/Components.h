#ifndef COMPONENTS_H
#define COMPONENTS_H
#include <string>
#include "Connection.h"





class Component
{
protected:
    std::string name;
    Connection* in;
    Connection* out;

public:
    Component(std::string const _name, Connection *const _in, Connection *const _out);
    virtual void update(double const _timeStep);
    virtual double getCurrent();
    double getVoltage();
    ~Component();
};
class Battery : public Component
{
private:
    double const voltage;

    public:
    Battery(std::string const _name, Connection* const _in, Connection* const _out, double const _voltage);
    void update(double const _timeStep);
    double getCurrent();
    ~Battery();
};

class Resistor : public Component
{
private:
    double const resistance;

    public:
    Resistor(std::string const _name, Connection* const _in, Connection* const _out, double const _resistance);
    void update(double const _timeStep);
    double getCurrent();
    ~Resistor();
};

class Capacitor : public Component
{
private:
    double const storage;
    double storedATM;

    public:
    Capacitor(std::string const _name, Connection* const _in, Connection* const _out, double const _storage, double _storedATM );
    void update(double const _timeStep);
    double getCurrent();
    ~Capacitor();
};
#endif
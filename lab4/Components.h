#ifndef COMPONENTS_H
#define COMPONENTS_H
#include <string>
#include "Connection.h"
/*
Base class should have virtual destructor.


Functions that doesn't have a implementation should be pure-virtual. (Empty functions are not ok)

6-4. Use the “virtual” keyword only in your base class. Use “override” in your subclass to shadow a 
definition in your base class


It doesn't compile for me so I wont check any other stuff before you fix that.
*/

class Component
{
protected:
    Connection* in;
    Connection* out;
    double volt;

public:
    std::string name;
    Component(std::string const _name, Connection *const _in, Connection *const _out);
    virtual void update(double const _timeStep);
    virtual double getCurrent();
    double getVoltage();
    virtual ~Component();
};
class Battery : public Component
{
private:
    double const voltage;

    public:
    Battery(std::string const _name, Connection* const _in, Connection* const _out, double const _voltage);
    void update(double const _timeStep) override;
    double getCurrent() override;
    ~Battery() override;
};

class Resistor : public Component
{
private:
    double const resistance;

    public:
    Resistor(std::string const _name, Connection* const _in, Connection* const _out, double const _resistance);
    void update(double const _timeStep) override;
    double getCurrent() override;
    ~Resistor() override;
};

class Capacitor : public Component
{
private:
    double const storage;
    double storedATM;

    public:
    Capacitor(std::string const _name, Connection* const _in, Connection* const _out, double const _storage, double _storedATM );
    void update(double const _timeStep) override;
    double getCurrent() override;
    ~Capacitor() override;
};
#endif
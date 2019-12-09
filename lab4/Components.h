#include <string>
#include "Connection.h"
using namespace std;


class Component
{
protected:
    string name;
    Connection* left;
    Connection* right;

public:
    Component(string const _name, Connection *const _left, Connection *const _right);
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
    Battery(string const _name, Connection* const _left, Connection* const _right, double const _voltage);
    void update(double const _timeStep);
    double getCurrent();
    ~Battery();
};

class Resistor : public Component
{
private:
    double const resistance;

    public:
    Resistor(string const _name, Connection* const _left, Connection* const _right, double const _resistance);
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
    Capacitor(string const _name, Connection* const _left, Connection* const _right, double const _storage, double storedATM );
    void update(double const _timeStep);
    double getCurrent();
    ~Capacitor();
};
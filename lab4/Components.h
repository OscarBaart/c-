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
    Component(String const _name, Connection *const _left, Connection *const _right);
    virtual void Update(double const _timeStep);
    virtual void getCurrent();
    ~Component();
};
class Battery : public Component
{
private:
    double const voltage;

    public:
    Battery(string const _name, Connection* const _left. Connection* const _right, double const _voltage);
    void Update(double const _timeStep);
    void getCurrent();
    ~Battery();
};

class Resistor : public Component
{
private:
    double const resistance;

    public:
    Resistor(string const _name, Connection* const _left. Connection* const _right, double const _resistance);
    void Update(double const _timeStep);
    void getCurrent();
    ~Resistor();
};

class Capacitor : public Component
{
private:
    double const storage;
    double storedATM;

    public:
    Capacitor(string const _name, Connection* const _left. Connection* const _right, double const _storage, double storedATM );
    void Update(double const _timeStep);
    void getCurrent();
    ~Capacitor();
};
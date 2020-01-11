#include <string>
#include "Connection.h"
using namespace std;
/*
Base class should have virtual destructor.


Functions that doesn't have a implementation should be pure-virtual. (Empty functions are not ok)

6-4. Use the “virtual” keyword only in your base class. Use “override” in your subclass to shadow a definition in your base class


It doesn't compile for me so I wont check any other stuff before you fix that.
*/

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

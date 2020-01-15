#ifndef COMPONENTS_H
#define COMPONENTS_H
#include <string>
#include "Connection.h"
/*


TODO:
--Functions that doesn't have a implementation should be pure-virtual. (Empty functions are not ok) ###DONE

--Output doesnt match example ##DONE

--You got memory leaks ###DONE

--Functions that doesnt modify the object should be const.

--Name should be in private or const

Comment:
--Should not have override on the deconstructors
*/

class Component
{
protected:
    Connection* in;
    Connection* out;
    double volt;

public:
    std::string const name;
    Component(std::string const _name, Connection *const _in, Connection *const _out);
    virtual void update(double const _timeStep) = 0;
    virtual double getCurrent() const = 0;
    virtual double getVoltage() const;
    virtual ~Component() = default;
};
class Battery : public Component
{
private:
    double const voltage;

    public:
    Battery(std::string const _name, Connection* const _in, Connection* const _out, double const _voltage);
    void update(double const _timeStep) override;
    double getCurrent() const override;
    double getVoltage() const override;
    ~Battery() = default;
};

class Resistor : public Component
{
private:
    double const resistance;

    public:
    Resistor(std::string const _name, Connection* const _in, Connection* const _out, double const _resistance);
    void update(double const _timeStep) override;
    double getCurrent() const override;
    ~Resistor() = default;
};

class Capacitor : public Component
{
private:
    double const storage;
    double storedATM;

    public:
    Capacitor(std::string const _name, Connection* const _in, Connection* const _out, double const _storage, double _storedATM );
    void update(double const _timeStep) override;
    double getCurrent() const override;
    ~Capacitor() = default;
};
#endif

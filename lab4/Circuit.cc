#include "Circuit.h"

Circuit::Circuit()
    : circuitComponents{} {
        
    }

void Circuit::add(Component* const comp)
{
    circuitComponents.push_back(comp);
}

void Circuit::stepSimulation(double const _timestep)
{
    for (Component* c : circuitComponents){
        c->update(_timestep);
    }
}

void Circuit::printLine() 
{

    for (Component* c : circuitComponents){
        cout << fixed << setprecision(2) << setw(6) << c->getVoltage();
        cout << setprecision(2) << setw(6) << c->getCurrent();
    }
    cout << endl;
}

void Circuit::simulate(int const iteration, int const lines, double const _timestep)
{
    printFirst();
    for(int i = 1; i <= iteration; ++i) {
        stepSimulation(_timestep);
        if(i % ((iteration)/(lines))==0) {
            printLine();
            //count += count;
        }
    }
}

void Circuit::printFirst()
{
    for (Component* c : circuitComponents){
        cout << setw(12) << c->name;
    }
    cout << endl;
    for (Component* c : circuitComponents){
        cout << setw(6) << "Volt";
        cout << setw(6) << "Curr";
    }
    cout << endl;
}

Circuit::~Circuit() {
}

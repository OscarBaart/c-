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
        cout << setprecision(2) << setw(6) << c->getVoltage() << " ";
        cout << setprecision(2) << setw(6) << c->getCurrent() << " ";
    }
    cout << endl;
}

void Circuit::simulate(int const iteration, int const lines, double const _timestep)
{
    int count = iteration / lines;
    for(int i = 1; i <= iteration; ++i) {
        stepSimulation(_timestep);
        if(i == count || i == 1) {
            printLine();
            count += count;
        }
    }
}

Circuit::~Circuit() {
}

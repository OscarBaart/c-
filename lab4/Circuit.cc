#include Circuit.h

Circuit::Cercuit()
    : circuitComponents{} {
        
    }

void simulate(int const iteration, int const lines, double const _timestep)
{
    for(int i = 1; i <= iteration, ++i) {
        stepSimulation(_timestep);
    }
}

void stepSimulation(double const _timestep)
{
    for (circuitComponents* c : component){
        c->update(_timestep)
    }
}
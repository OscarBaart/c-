#ifndef CIRCUIT_H
#define CIRCUIT_H
#include <iomanip>
#include <iostream>
#include <vector>
#include "Components.h"

using namespace std;

class Circuit {
    private:
    vector<Component*> circuitComponents; 

    public:
    Circuit();
    void add(Component* const);
    void stepSimulation(double const);
    void printLine();
    void simulate(int const, int const, double const);
    ~Circuit();
};
#endif
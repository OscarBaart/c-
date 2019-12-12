#ifndef CIRCUIT_H
#define CIRCUIT_H
#include <iomanip>
#include <iostream>
#include <vector>
#include "Components.h"



class Circuit {
    private:
    std::vector<Component*> circuitComponents; 

    public:
    Circuit();
    void printFirst();
    void add(Component* const);
    void stepSimulation(double const);
    void printLine();
    void simulate(int const, int const, double const);
    ~Circuit();
};
#endif
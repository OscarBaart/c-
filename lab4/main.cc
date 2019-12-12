#include "Components.h"
#include "Connection.h"
#include "Circuit.h"
#include <vector>

void circuit1()
{
    Connection a, b, c, d;
    Circuit circ{};
    circ.add(new Battery("Bat", &a, &d, 24.0));
    circ.add(new Resistor("R1", &a, &b, 6.0));
    circ.add(new Resistor("R2", &b, &c, 4.0));
    circ.add(new Resistor("R3", &c, &d, 8.0));
    circ.add(new Resistor("R4", &b, &d, 12.0));
    circ.simulate(20000, 10, 0.01);
}

void circuit2()
{
    Connection a, b, c, d;
    Circuit circ{};
    circ.add(new Battery("Bat", &a, &d, 24.0));
    circ.add(new Resistor("R1", &a, &b, 150.0));
    circ.add(new Resistor("R2", &a, &c, 50.0));
    circ.add(new Resistor("R3", &b, &c, 100.0));
    circ.add(new Resistor("R4", &b, &d, 300.0));
    circ.add(new Resistor("R5", &c, &d, 250.0));
    circ.simulate(20000, 10, 0.01);
}

int main(int argc, char** argv) {
    circuit1();
    //circuit2();
    return 0;
}
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
    circ.add(new Resistor("R2", &b, &c, 6.0));
    circ.add(new Resistor("R3", &c, &d, 6.0));
    circ.add(new Resistor("R4", &b, &d, 6.0));
    circ.simulate(20000, 10, 0.01);
}

int main(int argc, char** argv) {
    circuit1();
    return 0;
}
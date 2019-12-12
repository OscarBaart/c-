#include "Components.h"
#include "Connection.h"
#include "Circuit.h"
#include <vector>
using namespace std;



void circuit1(int const _iterations, int const _lines, double const _step, double const _batVoltage)
{
    Connection a, b, c, d;
    Circuit circ{};
    circ.add(new Battery("Bat", &a, &d, _batVoltage));
    circ.add(new Resistor("R1", &a, &b, 6.0));
    circ.add(new Resistor("R2", &b, &c, 4.0));
    circ.add(new Resistor("R3", &c, &d, 8.0));
    circ.add(new Resistor("R4", &b, &d, 12.0));
    circ.simulate(_iterations, _lines, _step);
}

void circuit2(int const _iterations, int const _lines, double const _step, double const _batVoltage)
{
    Connection a, b, c, d;
    Circuit circ{};
    circ.add(new Battery("Bat", &a, &d, _batVoltage));
    circ.add(new Resistor("R1", &a, &b, 150.0));
    circ.add(new Resistor("R2", &a, &c, 50.0));
    circ.add(new Resistor("R3", &b, &c, 100.0));
    circ.add(new Resistor("R4", &b, &d, 300.0));
    circ.add(new Resistor("R5", &c, &d, 250.0));
    circ.simulate(_iterations, _lines, _step);
}

void circuit3(int const _iterations, int const _lines, double const _step, double const _batVoltage)
{
    Connection a, b, c, d;
    Circuit circ{};
    circ.add(new Battery("Bat", &a, &d, _batVoltage));
    circ.add(new Resistor("R1", &a, &b, 150.0));
    circ.add(new Resistor("R2", &a, &c, 50.0));
    circ.add(new Capacitor("C3", &b, &c, 1.0, 0));
    circ.add(new Resistor("R4", &b, &d, 300.0));
    circ.add(new Capacitor("C5", &c, &d, 0.75, 0));
    circ.simulate(_iterations, _lines, _step);
}
void help(int error)
{
    cout << endl << "<==================== CIRCUIT SIMILUATOR HELP ====================>" << endl;
    if (error == 1){
        cout << "When starting the similuator you should together with './a.out'" << endl;
        cout << "also input 'iterations', 'line', 'timestep' and 'batteryVoltage'" <<endl;
    }else if (error == 2){
        cout << "Valid values: iterations > 1, line > 1, step > 0, batteryVoltage >= 0 " << endl;
    }
    cout << "<=================================================================>" << endl;
    cout << endl;
}

int main(int argc, char** argv) {
    
    int iterations;
    int line;
    double step = 0.01;
    double batVoltage = 24;
    

   
   try{
    int iterations{stoi(argv[1])};
    int line{stoi(argv[2])};
    double step{stod(argv[3])};
    double batVoltage{stod(argv[4])};
    if (iterations < 1 || line < 1 || step <= 0 || batVoltage < 0){
        help(2);
        exit(2);
    }
    circuit1(iterations, line, step, batVoltage);
    cout << endl;
    circuit2(iterations, line, step, batVoltage);
    cout << endl;
    circuit3(iterations, line, step, batVoltage);
    
    
    }catch (exception){    
  
    if (argc != 5){
        help(1);
    exit(1);
    }
    }
}
#include "Components.h"
#include "Connection.h"
#include "Circuit.h"
#include <vector>
using namespace std;



void circuit1(int const _iterations, int const _lines, double const _step, double const _batVoltage)
{

    Circuit circ{};
    Connection P, N, R124, R223;

    Battery* bat = new Battery("Bat", &N, &P, _batVoltage);
    Resistor* R1 = new Resistor("R1", &P, &R124, 6.0);
    Resistor* R2 = new Resistor("R2", &R124, &R223, 4.0);
    Resistor* R3 = new Resistor("R3", &R223, &N, 8.0);
    Resistor* R4 = new Resistor("R4", &R124, &N, 12.0);
    
    circ.add(bat);
    circ.add(R1);
    circ.add(R2);
    circ.add(R3);
    circ.add(R4);
    circ.simulate(_iterations, _lines, _step);       
    
    delete bat;
    delete R1;
    delete R2;
    delete R3;
    delete R4;

    
}

void circuit2(int const _iterations, int const _lines, double const _step, double const _batVoltage)
{
    Circuit circ{};

    Connection p, n, L, R;

    Battery* bat = new Battery("Bat", &n, &p, _batVoltage);
    Resistor* R1 = new Resistor("R1", &p, &L, 150.0);
    Resistor* R2 = new Resistor("R2", &p, &R, 50.0);
    Resistor* R3 = new Resistor("R3", &L, &R, 100.0);
    Resistor* R4 = new Resistor("R4", &L, &n, 300.0);
    Resistor* R5 = new Resistor("R5", &R, &n, 250.0);

    circ.add(bat);
    circ.add(R1);
    circ.add(R2);
    circ.add(R3);
    circ.add(R4);
    circ.add(R5);

    circ.simulate(_iterations, _lines, _step);

    delete bat;
    delete R1;
    delete R2;
    delete R3;
    delete R4;
    delete R5;
}

void circuit3(int const _iterations, int const _lines, double const _step, double const _batVoltage)
{
    Circuit circ{};
    Connection p, n, L, R;
    Battery* bat = new Battery("Bat", &n, &p, _batVoltage);
    Resistor* R1 = new Resistor("R1", &p, &L, 150.0);
    Resistor* R2 = new Resistor("R2", &p, &R, 50.0);
    Capacitor* C3 = new Capacitor("C3", &L, &R, 1.0, 0);
    Resistor* R4 = new Resistor("R4", &L, &n, 300.0);
    Capacitor* C5 = new Capacitor("C5", &R, &n, 0.75, 0);

    circ.add(bat);
    circ.add(R1);
    circ.add(R2);
    circ.add(C3);
    circ.add(R4);
    circ.add(C5);

    circ.simulate(_iterations, _lines, _step);

    delete bat;
    delete R1;
    delete R2;
    delete C3;
    delete R4;
    delete C5;
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
    double step;
    double batVoltage;
    

   
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
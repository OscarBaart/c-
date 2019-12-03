#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{   
    cout << "INPUT PART" << endl << setfill('=') << setw(10) << "=" << endl;

    double fp{};
    cout << "Enter first price: ";
    cin >> fp;
    while (fp < 0)
    {
        cerr << "ERROR: First price must be at least 0 (zero) SEK" << endl;
        cout << "Enter first price: ";
        cin >> fp;
    }

    double lp{};
    cout << "Enter last price: ";
    cin >> lp;
    while (lp < fp)
    {
        cerr << "ERROR: Last price must be higher than first price" << endl;
        cout << "Enter last price: ";
        cin >> lp;
    }

    double stride{};
    cout << "Enter stride: ";
    cin >> stride;
    while (stride <= 0.01)
    {
        cerr << "ERROR: Stride must be at least 0.01" << endl;
        cout << "Enter stride: ";
        cin >> stride;
    }
    
    double tp{};
    cout << "Enter tax percent: ";
    cin >> tp;
    while (tp < 0 || tp > 100)
    {
        cerr << "ERROR: Tax percentage needs to be between 0 and 100" << endl;
        cout << "Enter tax percent: ";
        cin >> tp;
    }
    tp = tp/100;

    cout << endl << "INPUT PART" << endl<< setw(10) << "=" << endl;
    cout << setw(13) << setfill(' ') << "Price" << setw(20) << "Tax" << setw(20) << "Price with tax" << endl;
    cout << setfill('-') << setw(53) << '-' << setfill(' ') << endl;

    cout << std::fixed << std::setprecision(2);
    while (fp <= lp)
    {
            cout << setw(13) << fp << setw(20) << tp * fp << setw(20) 
            << fp + (tp * fp) << endl;
         
        fp = fp + stride;
        
    }
    
    
}
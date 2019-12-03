#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{   
    int int1{};
    string str{};
    char c{};
    double real{};

    cout << "Enter one integer: ";
    cin >> int1;
    cout << "You entered the number: " << int1 << endl;
    cin.ignore(1000, '\n');
    cout << endl;

    cout << "Enter four integers: ";
    cin >> int1;
    cout << "You entered the numbers: " << int1;
    cin >> int1;
    cout << " " << int1;
    cin >> int1;
    cout << " " << int1;
    cin >> int1;
    cout << " " << int1 << endl; 
    cin.ignore(1000, '\n');
    cout << endl;
    
    cout << "Enter one integer and one real number: ";
    cin >> int1 >> real;
    cout << "the real is: " << std::fixed << std::setprecision(3) << right << setw(10) << real << endl;
    cout << "The integer is: " << setw(7) << int1 << endl;
    cin.ignore(1000, '\n');
    cout << endl;
    
    cout << "Enter one real and one integer number: ";
    cin >> real >> int1;
    cout << "the real is: " << setfill('.') << setw(11) << real << endl;
    cout << "The integer is: " << setw(8) << int1 << endl;
    cin.ignore(1000, '\n');
    cout << endl;

    cout << "Enter a character: ";
    cin >> c;
    cout << "You entered: " << c << endl;
    cin.ignore(1000, '\n');
    cout << endl;
    
    cout << "Enter a word: ";
    cin >> str;
    cout << "The word " << str << " has " << str.size() << " Characters." << endl;
    cin.ignore(1000, '\n');
    cout << endl;
    
    cout << "Enter an integer and a word: ";
    cin >> int1 >> str;
    cout << "You entered '" << int1 << "' and '" << str << "'." << endl;
    cin.ignore(1000, '\n');
    cout << endl;
    
    cout << "Enter an character and a word: ";
    cin >> c >> str;
    cout << "You entered the string \"" << str << "\" and the character '" << c << "'." << endl;
    cin.ignore(1000, '\n');
    cout << endl;
    
    cout << "Enter a word and a real number: ";
    cin >> str >> real;
    cout << "You entered: \"" << str << "\" and \"" << std::fixed << std::setprecision(3) << real << "\"." << endl; 
    cin.ignore(1000, '\n');   
    cout << endl;
    //
    cout << "Enter a text-line: ";
    getline(cin, str);
    cout << "You entered: \"" << str << "\"" << endl;
    cout << endl;

    cout << "Enter a second line of text: ";
    getline(cin, str);
    cout << "You entered: '" << str << "\"" << endl;
    cout << endl;

    cout << "Enter three words: ";
    cin >> str;
    cout << "You entered: '" << str << " ";
    cin >> str;
    cout << str << " ";
    cin >> str;
    cout << str << "'";   
}
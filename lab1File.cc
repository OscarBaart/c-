#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

int main ()
{
    ifstream ifs {"data.txt"};
    string s{};
    string longest{};
    string shortest{};
    double count = 0;
    double chars{};

    while (ifs >> s)
    {
        if (count == 0)
        {
            shortest = s;
        }

        if (s.size() > longest.size())
        {
        longest = s;
        }

        if (s.size() < shortest.size())
        {
        shortest = s;
        }

        ++count;
        chars += s.size();
    }

    if (count < 1 )
    {
        cout << "ERROR. The file is empty." << endl;
    } else 
    {
        cout << "There are " << count << " words in the file." << endl;
        cout << "The shortest word was " << '"' << shortest << '"' << " with " 
            << shortest.size() << " charachter(s)." << endl;
        cout << "The longest word was " << '"' << longest << '"' <<" with " 
            << longest.size() << " charcter(s)." << endl;
        cout << "The averge length was " << std::fixed << std::setprecision(2)
            << chars/count << " charachter(s)." << endl;
    }
}
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
#include "Clean.h"
using namespace std;

int main(int argc, char** argv) {
    Cleaner Cleaner{};

    string fileName{};
    string output{};
    fileName = argv[1];
    output = argv[2];
    
    ifstream file{fileName};

    vector<string> stringList;

    istream_iterator<string> fin_it(file);
    istream_iterator<string> eos; 

    copy(fin_it, eos, back_inserter(stringList));

    auto print = [](const string& word){cout << ' ' << word;};
    for_each (stringList.begin(), stringList.end(), print);
    cout << endl;

    Cleaner.listCleaner(stringList);

    Cleaner.printCleanList(output);

   
}
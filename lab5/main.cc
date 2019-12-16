#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm> 
using namespace std;

int main(int argc, char** argv) {
    ifstream file("example.html.url");

    vector<string> stringList;

    istream_iterator<string> fin_it(file);
    istream_iterator<string> eos; 

    copy(fin_it, eos, back_inserter(stringList));

    cout << "hello world";
    }
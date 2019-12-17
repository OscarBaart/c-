#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
#include "Clean.h"
using namespace std;

void error (string const errorInfo){
    cerr << endl<< "ERRROR!! " << errorInfo << " ERROR!!" << endl;
    cerr << "Valid input: ./a.out *filename* [-a] [-f] [-o N]" << endl << endl; 
}

int main(int argc, char** argv) {
    if(argc < 3){
        error("Not enough arguments");
        exit(1);
    } 

    Cleaner Cleaner{};

    string fileName{};
    string output{};
    int limit{};

    try {
        fileName = argv[1];
        output = argv[2];
        if((output == "-o") && (argc == 4)){
            limit=stoi(argv[3]);
            if (limit < 4){
                error("Words are larger than 3");
                exit(1);
            }
        }else if((output == "-o") && (argc < 4) ) {
                error("Must set limit when using '-o'");
                exit(1); 
    
        }else if((argc > 3) && (output != "-o")){
            error("Limit is only used with argument '-o'");
            exit(1); 
        } 
         
     }catch(exception& e) {
        
        error("Incorrect use of arguments"); 
        exit(1);  
    }
    
    ifstream file{fileName};

    vector<string> dirtyList;
    istream_iterator<string> fin_it(file);
    istream_iterator<string> eos; 
    copy(fin_it, eos, back_inserter(dirtyList));
    

    Cleaner.listCleaner(dirtyList);
    switch (output[1]){
        case 'a':
            Cleaner.printAlfa();
            break;
        case 'f':
            Cleaner.printFrequency();
            break;
        case 'o':
            Cleaner.printLimit(limit);
            break;
        default:
            error("Incorrect argument");
            break;
            exit(1);
    }
    

   
}
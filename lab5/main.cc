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
    cerr << "ERRROR!! " << errorInfo << " ERROR!!" << endl;
    cerr << "Valid input: ./a.out *filename* [-a] [-f] [-o N]" << endl; 
}

int main(int argc, char** argv) {
    Cleaner Cleaner{};

    string fileName{};
    string output{};
    int limit;

    try {
        string fileName = argv[1];
        string output = argv[2];
        int limit{stoi(argv[3])};

        if(argc < 3){
            error("Not enough arguments");
           return -1; 
        // }else if ((output !="-a")||(output != "-f")||(output != "-o")){
        //     error("Nonvalid argument");
        //     return -1; 
        }else if((output=="-o") && (limit < 3)){
                error("Limit must be higher than 3");
                return -1; 
        }else if((limit) && (output != "-o")){
            error("Limit is only used with argument '-o'");
            return -1; 
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
            cout << "bababababa";
            break;
        default:
            error("Incorrect argument HALUUUU");
            //cout << endl << output << endl;
            break;
    }
         
     }catch(exception) {
        
        error("Incorrect use of arguments"); 
        return -1;  
    }
  

   
}
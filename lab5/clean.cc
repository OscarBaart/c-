#include "Clean.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <set>
#include <functional>
using namespace std;

void Cleaner::listCleaner (vector<string> &dirtyList){
    for_each (dirtyList.begin(), dirtyList.end(), [this](string &cleanWord){ wordCleaner(cleanWord);});
    for_each (cleanList.begin(), cleanList.end(), [&] (string cleanWord) {cleanMap[cleanWord]++;});
}

void Cleaner::wordCleaner (string cleanWord){
    cleanWord.erase(0, cleanWord.find_first_not_of("\n\t\v\f\r"));
    cleanWord.erase(0, cleanWord.find_first_not_of("\"\'("));
    cleanWord.erase(cleanWord.find_last_not_of("\n\v\f\r\t") + 1);
    cleanWord.erase(cleanWord.find_last_not_of(",;.:?!\"\')") + 1);
    if (cleanWord.size() < 3)
        return;
    if (cleanWord.at(0) == '-' || cleanWord.at(cleanWord.size() - 1) == '-')
        return;
    if (cleanWord.find("--")!= std::string::npos)
        return;
    if (cleanWord.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-")!= std::string::npos)
        return;

    std::transform(cleanWord.begin(), cleanWord.end(), cleanWord.begin(), ::tolower);

    cleanList.push_back(cleanWord);
}

void Cleaner::printAlfa(){
     auto print = [](const pair<string, int> w){
           cout << setw(8) << w.first << ' ' << w.second << endl;
        };
        for_each (cleanMap.begin(), cleanMap.end(), print);
}
void Cleaner::printFrequency() {
        typedef function<bool(pair<string, int>, pair<string, int>)> Comparator;
        Comparator compFunctor = 
                [](pair<string, int> elem1, pair<string, int> elem2)
                {
                    return elem1.second >= elem2.second;
                };
                
        set<pair<string, int>, Comparator> setOfWords(
            cleanMap.begin(), cleanMap.end(), compFunctor);

        for_each (setOfWords.begin(), setOfWords.end(), [&] (const pair<string, int> &w) {
            cout << w.first << ' ' << w.second << endl;
        });


}

void Cleaner::printLimit(int const limit){
    int currSize{};
    auto wordPrint =[&currSize, &limit] (string cleanWord){ 
    if((currSize+cleanWord.size()) < limit){
        currSize += cleanWord.size() +1;
        cout << cleanWord << " ";
    } else {
        currSize = cleanWord.size() +1;
        cout << endl;
        cout << cleanWord << " ";
    }
    };
    for_each(cleanList.begin(), cleanList.end(), wordPrint);
    
}



Cleaner::~Cleaner() {}
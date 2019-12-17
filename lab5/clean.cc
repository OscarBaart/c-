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
    
    // auto cleanWord = [](const string& dirtyWord) {
    //     wordCleaner(dirtyWord);
    // };
    
  
    for_each (dirtyList.begin(), dirtyList.end(), [this](string &dirtyWord){ wordCleaner(dirtyWord);});
    for_each (cleanList.begin(), cleanList.end(), [&] (string dirtyWord) {cleanMap[dirtyWord]++;});
}

void Cleaner::wordCleaner (string dirtyWord){
    dirtyWord.erase(0, dirtyWord.find_first_not_of("\n\t\v\f\r"));
    dirtyWord.erase(0, dirtyWord.find_first_not_of("\"\'("));
    dirtyWord.erase(dirtyWord.find_last_not_of("\n\v\f\r\t") + 1);
    dirtyWord.erase(dirtyWord.find_last_not_of(",;.:?!\"\')") + 1);
    if (dirtyWord.size() < 3)
        return;
    if (dirtyWord.at(0) == '-' || dirtyWord.at(dirtyWord.size() - 1) == '-')
        return;
    if (dirtyWord.find("--")!= std::string::npos)
        return;
    if (dirtyWord.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-")!= std::string::npos)
        return;

    std::transform(dirtyWord.begin(), dirtyWord.end(), dirtyWord.begin(), ::tolower);

    cleanList.push_back(dirtyWord);
}


void Cleaner::printCleanList(string port) {
        
    if (port == "-a"){
        auto print = [](const pair<string, int> w){
           cout << setw(8) << w.first << ' ' << w.second << endl;
        };
        for_each (cleanMap.begin(), cleanMap.end(), print);
    }else if (port == "-f"){
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
    } else {

    }
}

Cleaner::~Cleaner() {}
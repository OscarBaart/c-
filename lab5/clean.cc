#include "Clean.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

void Cleaner::listCleaner (vector<string> &dirtyList){
    
    // auto cleanWord = [](const string& dirtyWord) {
    //     wordCleaner(dirtyWord);
    // };
    
  
    for_each (dirtyList.begin(), dirtyList.end(), [this](string &dirtyWord){ wordCleaner(dirtyWord);});

   
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


    // if (dirtyWord.size() > largestWordSize) {
    //    largestWordSize = dirtyWord.size();
    // }
    //for_each(cleanList.begin(), cleanList.end(), check)
    checkWord(dirtyWord);
    //cleanList.push_back(make_pair(dirtyWord, 1);
}

void Cleaner::checkWord(string currWord){
    auto sortList = [this](string currWord) {
        if(count(cleanList.begin(), cleanList.end(), currWord) > 0) {
            cleanList[&currWord] = cleanList[&currWord] + 1;
        } else 
            cleanList.push_back(make_pair(currWord, 1);
    }

    for_each(cleanList.begin(), cleanList.end(), sortList)
}

void Cleaner::printCleanList(string port) {
    if (port == "-a"){
        std::sort(cleanList.begin(), cleanList.end());
    }
    else if (port == "-f"){
        std::sort(cleanList.begin(), cleanList.end());
    }
    auto print = [](const string& word){
        cout << word << ' ' << endl;
    };
    for_each (cleanList.begin(), cleanList.end(), print);
    cout << endl;
}


Cleaner::~Cleaner() {}
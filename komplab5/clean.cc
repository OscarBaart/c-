#include "Clean.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <set>
#include <functional>
#include <cctype>

using namespace std;

//TODO: Complementary work needed, do not use for_each if you want to modify the container in any way.
//Hint: use transform. ###DONE

//TODO: Complementary work needed, do not use [&] if you dont want to actually take everything in
//scope into the lambda function. This is overall a bad practise since it doesn't show what you're
//intending to change in the lambda. ###DONE

//TODO: Complementary work needed, comparing with the entire alphabet each iteration is far too
//inefficient. Hint: use the library cctype. ###DONE

void Cleaner::listCleaner (vector<string> &dirtyList){
    transform (dirtyList.begin(), dirtyList.end(), dirtyList.begin(),[this] (string word){ return wordCleaner(word);});
    for_each (cleanList.begin(), cleanList.end(), [this] (string cleanWord) {cleanMap[cleanWord]++;});
}

string Cleaner::wordCleaner (string cleanWord){
    cleanWord.erase(0, cleanWord.find_first_not_of("\n\t\v\f\r"));
    cleanWord.erase(0, cleanWord.find_first_not_of("\"\'("));
    cleanWord.erase(cleanWord.find_last_not_of("\n\v\f\r\t") + 1);
    cleanWord.erase(cleanWord.find_last_not_of(",;.:?!\"\')") + 1);
    if (cleanWord.size() < 3)
        return cleanWord;
    if (cleanWord.at(0) == '-' || cleanWord.at(cleanWord.size() - 1) == '-')
        return cleanWord;
    if (cleanWord.find("--")!= string::npos)
        return cleanWord;
    if (find_if(cleanWord.begin(), cleanWord.end(),
                   [](char c) { return !isalpha(c); }) != cleanWord.end())
        return cleanWord;

    transform(cleanWord.begin(), cleanWord.end(), cleanWord.begin(), ::tolower);

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

        for_each (setOfWords.begin(), setOfWords.end(), [this] (const pair<string, int> &w) {
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
    cout << endl;
}



Cleaner::~Cleaner() {}

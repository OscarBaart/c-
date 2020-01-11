#ifndef _CLEAN_H_
#define _CLEAN_H_

#include <vector>
#include <iomanip>
#include <iostream>
#include <map>


class Cleaner {
    public:
    void listCleaner(std::vector<std::string> &);
    void printCleanList(std::string);
    void printLimit(int const );
    void printAlfa();
    void printFrequency();
    ~Cleaner();

    private:
    std::string wordCleaner(std::string);
    void checkWord(std::string);
    std::vector<std::string> cleanList;
    std::map<std::string, int> cleanMap;
    std::string dirtyWord;
    std::string cleanWord;
    int largestWordSize;
    
};

#endif
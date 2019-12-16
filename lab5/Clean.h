#ifndef _CLEAN_H_
#define _CLEAN_H_

#include <vector>
#include <iomanip>
#include <iostream>

class Cleaner {
    public:
    void listCleaner(std::vector<std::string> &);
    void printCleanList(std::string);
    ~Cleaner();

    private:
    void wordCleaner(std::string);
    void checkWord(std::string);
    std::vector<std::pair <std::string, int> > cleanList;
    std::string dirtyWord;
    std::string cleanWord;
    int largestWordSize;
    
};

#endif
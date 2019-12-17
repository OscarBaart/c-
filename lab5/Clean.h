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
    ~Cleaner();

    private:
    void wordCleaner(std::string);
    void checkWord(std::string);
    std::vector<std::pair<std::string, int>> listForPrint;
    std::vector<std::string> cleanList;
    std::map<std::string, int> cleanMap;
    std::unordered_map<std::string, std::int> cleanUnorderedMap;
    std::string dirtyWord;
    std::string cleanWord;
    int largestWordSize;
    
};

#endif
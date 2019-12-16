#include <list>
#include <iomanip>
#include <iostream>

class Cleaner {
    public:
    std::list<std::string> potential;
    std::list<std::string> cleaned;
    void readFile(std::ifstream&);

    private:
    bool isValid(std::string);
    void cleanList();
};
#ifndef MY_STRUCT_H
#define MY_STRUCT_H
#include <string>
#include <iostream>
#include <sstream>

struct Time{
    int h{};
    int m{};
    int s{};
};

/*TODO:
 x = y + z shouldn't change y or z. Test this for your operator + and -

 
 ++(++t) should work (same for --)

Postfix doesn't work as intended.

should test +/- for an hour or a day.

 */
std::string to_string(Time , bool ap=false);

Time& operator ++ (Time &);

Time operator ++ (Time &, int);

Time operator + (Time &, int );

Time& operator -- (Time &);

Time operator -- (Time &, int);

Time operator - (Time &, int );

bool operator == (Time const &, Time const &);

bool operator !=(Time const&, Time const&);

bool operator >(Time const&, Time const&);

bool operator <(Time const &, Time const&);

bool operator >=(Time const&, Time const&);

bool operator <=(Time const&, Time const&);

std::ostream& operator <<(std::ostream&, Time const &);

std::istream& operator >>(std::istream& , Time &);

bool checkValue(Time const&);

#endif 

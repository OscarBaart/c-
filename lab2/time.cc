#include "catch.hpp"
#include <iomanip>
#include "my_struct.h"
using namespace std;

string to_string(Time t, bool ap)
{
    string str{};
    string tod{};
    if (ap)
    {
        if (t.h > 12)
        {
            tod = " pm";
            t.h = t.h - 12;
        }
        else
        {
            tod = " am";
        }
    }
    if (t.h < 10)
    {
        str += "0";
    }
    str += std::to_string(t.h);
    str += ":";
    if (t.m < 10)
    {
        str += "0";
    }
    str += std::to_string(t.m);
    str += ":";
    if (t.s < 10)
    {
        str += "0";
    }
    str += std::to_string(t.s);
    str += tod;
    return str;
}

Time& operator++(Time &t)
{
    ++t.s;
    if (t.s > 59)
    {
        ++t.m;
        t.s = 0;
        if (t.m > 59)
        {
            ++t.h;
            t.m = 0;
            if (t.h > 23)
            {
                t.h = 0;
            }
        }
    }
    return t;
}

Time operator++(Time &t, int)
{
    Time temp = t;
    ++t;
    return temp;
}

Time operator+(Time &t, int inc)
{
    Time temp = t;
    for (int i = 0; i < inc; ++i)
    {
        ++temp;
    }
    return temp;
}

Time& operator--(Time &t)
{
    --t.s;
    if (t.s < 0)
    {
        --t.m;
        t.s = 59;
        if (t.m < 0)
        {
            --t.h;
            t.m = 59;
            if (t.h < 0)
            {
                t.h = 23;
            }
        }
    }
    return t;
}

Time operator--(Time &t, int)
{
    Time temp = t;
    --t;
    return temp;
}

Time operator-(Time &t, int inc)
{
    Time temp = t;
    for (int i = 0; i < inc; ++i)
    {
        --temp;
    }
    return temp;
}

bool operator==(Time const &t1, Time const &t2)
{
    //Comment: could just return (t1 > t2 || t2 > t1)
    if (t1 > t2 || t2 > t1)
    {
        return false;
    }
    return true;
}

bool operator!=(Time const &t1, Time const &t2)
{
    if (t1 > t2 || t2 > t1)
    {
        return true;
    }
    return false;
}

bool operator>(Time const &t1, Time const &t2)
{
    if (t1.h > t2.h)
    {
        return true;
    }
    else if (t1.h == t2.h && t1.m > t2.m)
    {
        return true;
    }
    else if (t1.h == t2.h && t1.m == t2.m && t1.s > t2.s)
    {
        return true;
    }
    return false;
}

bool operator<(Time const &t1, Time const &t2)
{
    if (t2 > t1)
    {
        return true;
    }
    return false;
}

bool operator >=(Time const &t1, Time const &t2)
{
    if (t1 > t2 || t2 == t1)
    {
        return true;
    }
    return false;
}

bool operator <=(Time const &t1, Time const &t2)
{
    if (t2 > t1 || t2 == t1)
    {
        return true;
    }
    return false;
}

ostream &operator<<(ostream &os, Time const&t)
{
    os << to_string(t, false);
    return os;
}

istream &operator>>(istream &in, Time &t)
{
    char c{};
    in >> t.h >> c >> t.m >> c >> t.s;
    if (!checkValue(t))
    {   
        in.setstate(std::ios::failbit);
    }
    return in;
}

bool checkValue(Time const&t)
{
    if (t.h < 0 || t.h > 23)
    {
        return false;
    }
    else if (t.m < 0 || t.m > 59)
    {
        return false;
    }
    else if (t.s < 0 || t.s > 59)
    {
        return false;
    }
    return true;
}

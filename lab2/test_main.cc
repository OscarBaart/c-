#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "my_struct.h"
using namespace std;


TEST_CASE ("testing H (00-23) and M/S (00-59)")
{
Time t1{23, 59, 59};
Time t2{34, 56, 00};
Time t3{11, -12, 59};
CHECK(checkValue(t1));
CHECK_FALSE(checkValue(t3));
CHECK_FALSE(checkValue(t2));
}

TEST_CASE ("Testing printed time")
{
Time t1{23, 59, 59};
Time t2{14, 56, 00};
Time t3{11, 12, 59};
Time t4{};
CHECK(to_string(t1) == "23:59:59");
CHECK(to_string(t2, true) == "02:56:00 pm");
CHECK_FALSE(to_string(t2, true) == "14:56:00");
CHECK(to_string(t3, true) == "11:12:59 am");
CHECK(to_string(t4) == "00:00:00");
}

TEST_CASE ("Testing + & - operator")
{
Time t1{23, 59, 59};
Time t2{14, 56, 00};
Time t3{11, 12, 59};
Time t4{0,0,0};
Time t5{0,0,05};
Time t6{0,0,10};
CHECK(to_string(t1++) == "23:59:59"); //This should still print 23:59:59 (The old value of t1)
CHECK(to_string(t1) == "00:00:00");
CHECK(to_string(t2 + 65) == "14:57:05");
CHECK(to_string(t1 + 10, true) == "00:00:10 am");
CHECK(to_string(t4--) == "00:00:00");
CHECK(to_string(t4) == "23:59:59");
CHECK(to_string(t4 - 5) == "23:59:54");
t4 = t5 + 1000;
CHECK(to_string(t5) == "00:00:05");
t4 = t5 - 1000;
CHECK(to_string(t5) == "00:00:05");
CHECK(to_string(t5 + 86400) == "00:00:05");
CHECK(to_string(++(++t6)) == "00:00:12");
}

TEST_CASE("Compare operator")
{
    Time t1{13, 13, 13};
    Time t2{13, 13, 13};
    Time t3{10, 30, 30};
    CHECK(t1 > t3);
    CHECK(t3 < t2);
    CHECK(t1 == t2);
    CHECK(t1 != t3);
    CHECK_FALSE(t1 < t3);
    CHECK(t1 >= t2);
    CHECK(t3 <= t2);
}


TEST_CASE("Input & Output")
{
    Time t1{13, 13, 13};
    Time t2{13, 13, 59};
    Time t3{10, 30, 30};
    ostringstream oss{};
    istringstream iss{"12:12:12"};
    istringstream issW{"18:123:01"};
    oss << t1;
    CHECK(oss.str() == to_string(t1));
    iss >> t2;
    CHECK(iss.str() == "12:12:12");
    issW >> t3;
    CHECK_FALSE(issW.str() == "18:123:01");
    CHECK(issW.fail());
}

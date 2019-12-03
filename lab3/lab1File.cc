// This test program uses a test framework supporting TDD and BDD.
// You are not required to use the framework, but encouraged to.
// Code:
// https://github.com/philsquared/Catch.git
// Documentation:
// https://github.com/philsquared/Catch/blob/master/docs/tutorial.md

// You ARE however required to implement all test cases outlined here,
// even if you do it by way of your own function for each case.  You
// are recommended to solve the cases in order, and rerun all tests
// after you modify your code.

// This define lets Catch create the main test program
// (Must be in only one place!)
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Sorted_List.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include <random>

//=======================================================================
// Test cases
//=======================================================================

TEST_CASE( "Create an empty list" ) {
  Sorted_List l{};

  REQUIRE( l.is_empty() == true );
  REQUIRE( l.size() == 0 );
}

TEST_CASE( "Insert sorted vaules" ) {
  Sorted_List l {};
  l.insert(10);
  l.insert(15);
  l.insert(5);
  l.insert(12);
  l.insert(1);
  l.insert(20);
  l.print();
  cout << endl;
}

TEST_CASE( " Printing sorted list " ) {
  Sorted_List l {};
  l.insert(10);
  l.insert(15);
  l.insert(5);
  l.insert(12);
  l.insert(1);
  l.insert(20);
  l.print();
  cout << endl;
}

TEST_CASE( " Removing value from list " ) {
  Sorted_List l {};
  l.insert(10);
  l.insert(15);
  l.insert(5);
  l.insert(12);
  l.insert(1);
  l.insert(20);
  l.print();
  cout << endl;
  l.remove_value(12);
  l.print();
  cout << endl;
  l.remove_value(1);
  l.remove_value(20);
  l.print();
  cout << endl;
}

TEST_CASE( " Removing all value from list " ) {
  Sorted_List l {};
  l.insert(10);
  l.insert(15);
  l.insert(5);
  l.insert(12);
  l.insert(1);
  l.insert(20);
  l.print();
  cout << endl;
  l.~Sorted_List();
  REQUIRE(l.is_empty());
  l.print();
  cout << endl;
}

TEST_CASE( " Copy Operator ") {
  Sorted_List l2 {};
  l2.insert(2);
  l2.insert(6);
  l2.insert(10);
  l2.print();
  cout << endl;
  Sorted_List l1 = l2;
  l2.insert(10);
  REQUIRE(!l1.is_empty());
  l2.print();
  l1.print();
  cout << endl;
}

TEST_CASE( " Copy Cosntructor") {
  Sorted_List l2 {};
  l2.insert(2);
  l2.insert(6);
  l2.insert(10);
  cout << endl;
  Sorted_List l1{l2};
  REQUIRE(!l1.is_empty());
  l1.print();
  l2.insert(16);
  l1.print();
  l2.print();
  cout << endl;
}

TEST_CASE( " Move Constructor ") {
  Sorted_List l1{};
  l1.insert(3);
  l1.insert(7);
  l1.insert(12);
  Sorted_List l2(std::move(l1));
  REQUIRE(l1.is_empty());
  l2.print();
  cout << endl;
}

TEST_CASE( " Move Operator ") {
  Sorted_List l1{};
  l1.insert(5);
  l1.insert(6);
  l1.insert(7);
  Sorted_List l2{};
  l2=std::move(l1);
  REQUIRE(l1.is_empty());
  l2.print();
  cout << endl;
}

// It is your job to create new test cases and fully test your Sorted_List class

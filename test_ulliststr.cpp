#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cassert>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

void testPushBack(){
  ULListStr ballaList;
  ballaList.push_back("Maciej");
  ballaList.push_back("Wiktor");
  ballaList.push_back("Bownik");
  assert(ballaList.size() == 3);
  assert(ballaList.back() == "Bownik");
  assert(ballaList.front() == "Maciej");
  cout << "push back test passed!" << endl;
}

void testPushFront(){
  ULListStr ballaList;
  ballaList.push_front("Bownik");
  ballaList.push_front("Wiktor");
  ballaList.push_front("Maciej");
  
  assert(ballaList.size() == 3);
  assert(ballaList.back() == "Bownik");
  assert(ballaList.front() == "Maciej");
  cout << "push front test passed!" << endl;
}

void testPopBack(){
  ULListStr ballaList;
  ballaList.push_back("Maciej");
  ballaList.push_back("Wiktor");
  ballaList.push_back("Bownik");
  ballaList.pop_back();
  assert(ballaList.size() == 2);
  assert(ballaList.back() == "Wiktor");
  cout << "pop back test passed!" << endl;
}

void testPopFront(){
  ULListStr ballaList;
  ballaList.push_back("Maciej;");
  ballaList.push_back("Wiktor");
  ballaList.push_back("Bownik");
  ballaList.pop_front();
  assert(ballaList.size() == 2);
  assert(ballaList.front() == "Wiktor");
  cout << "pop front test passed!" << endl;
}

int main(int argc, char* argv[])
{
  testPushBack();
  testPushFront();
  testPopBack();
  testPopFront();

}

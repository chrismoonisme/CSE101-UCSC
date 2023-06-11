//-----------------------------------------------------------------------------
// DictionaryClient.cpp
// A test client for the Dictionary ADT
//-----------------------------------------------------------------------------
#include<iostream>
#include<string>
#include<stdexcept>
#include"Dictionary.h"

using namespace std;

int main(){

  Dictionary A;
  
  A.setValue("a", 1);
  A.setValue("b", 5);
  A.setValue("e", 3214);
  
  cout << "A = " << A << endl;
  
  A.end();
  A.prev();
  
  cout << "current val is " << A.currentVal() << endl;
  
  A.prev();
  A.prev();
  
  
  cout << "has current? " << A.hasCurrent() << endl;
  
  A.remove("b");
  
  cout << "A = " << A << endl;
  
  
  A.setValue("a", 3);
  
  cout << "A = " << A << endl;
  
  
  Dictionary B = A;
  
  cout << "B = " << B << endl;

  
  
  return 0;

}


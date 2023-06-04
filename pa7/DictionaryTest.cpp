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
  
  A.setValue("plaices", 1);
  
  A.setValue("ambusher", 2);
  
  A.setValue("crosby", 3);
  
  A.setValue("wattles", 4);
  
  A.setValue("pardoner", 5);
  
  A.setValue("pythons", 6);
  
  A.setValue("second", 7);
  
  A.setValue("forms", 8);
  
  A.setValue("impales", 9);
  
  A.setValue("pic", 10);
  
  A.setValue("verticals", 5);
  
  A.setValue("recriminator", 5);
  
  A.setValue("cul", 5);
  
  A.setValue("potables", 5);
  
  A.setValue("norm", 5);
  
  A.setValue("reinsurer", 5);
  
  A.setValue("recoining", 5);
  
  A.setValue("dissocialised", 5);
  
  A.setValue("cohabit", 5);
  
  A.setValue("hemiolia", 5);
  
  A.setValue("cantling", 5);
  
  A.setValue("glamorized", 5);
  
  A.setValue("millesimal", 5);
  A.setValue("glagolitic", 5);
  
  A.setValue("vesturers", 5);
  
  A.setValue("ulnaria", 5);
  
  A.setValue("effectuates", 5);
  A.setValue("mimer", 5);

  
  
  
  
  string s = A.pre_string();
  
  cout << "A = \n" << A << endl;
  
  cout << "A = \n" << s << endl;
  

  return 0;


}


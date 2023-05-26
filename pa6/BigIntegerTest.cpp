//-----------------------------------------------------------------------------
//  BigIntegerClient.cpp 
//  A test client for the BigInteger ADT
//-----------------------------------------------------------------------------
#include<iostream>
#include<string>
#include<stdexcept>
#include"BigInteger.h"

using namespace std;

int main(){

  string s1 = "+00006523485630758234007488392857982374523487612398700554";
  string s2 = "-330293847502398475";
  
  long x = -330293847502398475;
  
  BigInteger N = BigInteger();  
  
  BigInteger A = BigInteger(s1);
  
  BigInteger B = BigInteger(s2);
  
  BigInteger C = BigInteger(x);
  
  cout << endl;
  

  cout << "A = " << A << endl;
  
  cout << "B = " << B << endl;
  
  cout << "C = " << C << endl;
   
  cout << "N = " << N << endl;
  
  A.makeZero();
  
  cout << "A zeroed out = " << A << endl;
  
  C.negate();
  
  cout << "A negated = " << C << endl;

  return 0;


}


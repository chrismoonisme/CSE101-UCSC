//pa6
//ckmoon

#include<iostream>
#include<string>

#include<fstream>

#include"List.h"
#include "BigInteger.h"

using namespace std;

int main(int argc, char* argv[]){

  
  ifstream in;
  
  ofstream out;
  
  string line;
  
  // check command line for correct number of arguments
   if( argc != 3 ){
      cerr << "Usage: " << argv[0] << " <input file> <output file>" << endl;
      return(EXIT_FAILURE);
   }
   
   // open files for reading and writing 
   in.open(argv[1]);
   if( !in.is_open() ){
      cerr << "Unable to open file " << argv[1] << " for reading" << endl;
      return(EXIT_FAILURE);
   }

   out.open(argv[2]);
   if( !out.is_open() ){
      cerr << "Unable to open file " << argv[2] << " for writing" << endl;
      return(EXIT_FAILURE);
   }
   
   
   
   getline(in, line);
   
   BigInteger A = BigInteger(line);
   
   getline(in, line);
   
   getline(in, line);
   
   BigInteger B = BigInteger(line);
   
   
   
   out << A << endl;
   
   out << endl;
   
   
   
   out << B << endl;
   
   out << endl;
   
   
   
   BigInteger C = A + B;
   
   out << C << endl;
   
   out << endl;
   
   
   
   C = A -B;
   
   out << C << endl;
   
   out << endl;
   
   
   
   out << "0" << endl;
   
   out << endl;
   
   
   
   BigInteger D = BigInteger(3);
   
   BigInteger F = BigInteger(2);
   
   D*=A;
   
   //out << D << endl;
   
   F*=B;
   
   //out << F << endl;
   
   C = D-F;
   
   out << C << endl;
   
   out << endl;
   
   
   C = A*B;
   
   out << C << endl;
   
   out << endl;
   
   
   C = A*A;
   
   out << C << endl;
   
   out << endl;
   
   C = B*B;
   
   out << C << endl;
   
   out << endl;
   
   
   
   BigInteger nine = BigInteger(9);
   
   BigInteger sixteen = BigInteger(16);
   
   D = A*A*A*A*nine;
   
   
   C= B*B*B*B*B*sixteen;
   
   F= D+C;
   out << F << endl;
   

   in.close();
   out.close();


    return 0;



}


//pa7
//ckmoon

#include<iostream>
#include<string>

#include<fstream>

#include"Dictionary.h"

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
   
   //line number
   int linenum = 0;
   
   //dictionary
   Dictionary D;
   
   //loop througn lines in file
   while(getline(in, line) ){
    
    linenum++;
    
    D.setValue(line, linenum);
  
    
   }
   
    string s = D.pre_string();
  
    out << D << endl;
  
    out << s << endl;
   
   in.close();
   out.close();
   
  
  return 0;
  
}


//pa8
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
  
  //string tokenBuffer;
  
  string token;
  
  size_t len, begin, end;
  
  //int token_count;
  
  string delim = " \t\\\"\',<.>/?;:[{]}|`~!@#$%^&*()-_=+0123456789";
  
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
   
   
   Dictionary D;
   
   while(getline(in, line)){
   
    len = line.length();
    
    //tokenBuffer = "";
    
    begin = min(line.find_first_not_of(delim, 0), len);
    
    end   = min(line.find_first_of(delim, begin), len);
   
    token = line.substr(begin, end-begin);
    
    while( token!="" ){
    
    
      for(size_t i = 0; i < token.length(); i++){
      
        token[i] = tolower(token[i]);
      
      }
    
      if(D.contains(token) == 0){
      
        D.setValue(token.c_str(), 1);
      
      }else{
      
        D.setValue(token.c_str(), D.getValue(token.c_str()) + 1);
      
      }
      
      begin = min(line.find_first_not_of(delim, end+1), len);
      end   = min(line.find_first_of(delim, begin), len);
      token = line.substr(begin, end-begin);
    
    }
   
   
   }
   
   
   out << D << endl;
   
   
  in.close();
  out.close();
   
   return 0;
   
   

}

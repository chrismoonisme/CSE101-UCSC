//pa6
//ckmoon

#include<iostream>
#include<string>
#include<stdexcept>
#include "List.h"
#include "BigInteger.h"

#define BASE 1000000000
#define POWER 9

// Class Constructors & Destructors -------------------------------------------

//empty constructor
BigInteger::BigInteger(){
    
  //sign and list
  signum = 0;
   
  //digits = new List();
   
}

//long constructor
BigInteger::BigInteger(long x){

  std::string s = std::to_string(x);
  
  //this = BigInteger(s);
//check if string is emptry
  if(s.empty() == true){
  
     throw std::invalid_argument("BigInteger: Constructor: non-numeric string");
  
  }
  
  //check for non ints
  std::size_t invalid = s.find_first_not_of("+-0123456789");
  
  if(invalid != std::string::npos){
  
    throw std::invalid_argument("BigInteger: Constructor: empty string");
  
  }
  
  //digits = List();
  
  //get sign
  if(s.at(0) == '-'){
  
    signum = -1;
  
  }else {
  
    signum = 1;
  
  }
  
  //get index of the first actual number
  int index = 0;

  while(s.at(index) == '+' || s.at(index) == '-' || s.at(index) == '0'){
  
    index++;
  
  }
  
  //printf("first number occurs at %d\n", index);
  
  //get length of number
  int length = s.size() - (index);
  
  //printf("length of number is %d\n", length);
  
  //nodes needed
  int nodes = ((length-1)/POWER) +1;
  
  //printf("need %d nodes\n", nodes);
  
  //leading zeros needed
  int zeros = (POWER*nodes)-(length);
  
  //printf("need %d leading zeros\n", zeros);
  
  //store temp values
  std::string temp;
  
  //loop for each node
  for(int i = 0; i < nodes; i++){
    
    //9 values per node
    for (int j = 0; j < POWER; j++) {
      
      //if leading zeros are still needed, append a 0
      if(zeros != 0){

        temp+= '0';
        
        zeros--;
      
      //else append from the string
      }else{
      
        temp+= s[index];
        
        index++;
      
      }
    
    }
    
    long l = atol(temp.c_str());
    
    
    temp.clear();
    
    //printf("add value %ld\n", l);
    
    digits.insertBefore(l);
  
  }


}


//string constructor
BigInteger::BigInteger(std::string s){
  
  //check if string is emptry
  if(s.empty() == true){
  
     throw std::invalid_argument("BigInteger: Constructor: non-numeric string");
  
  }
  
  //check for non ints
  std::size_t invalid = s.find_first_not_of("+-0123456789");
  
  if(invalid != std::string::npos){
  
    throw std::invalid_argument("BigInteger: Constructor: empty string");
  
  }
  
  //digits = List();
  
  //get sign
  if(s.at(0) == '-'){
  
    signum = -1;
  
  }else {
  
    signum = 1;
  
  }
  
  //get index of the first actual number
  int index = 0;

  while(s.at(index) == '+' || s.at(index) == '-' || s.at(index) == '0'){
  
    index++;
  
  }
  
  //printf("first number occurs at %d\n", index);
  
  //get length of number
  int length = s.size() - (index);
  
  //printf("length of number is %d\n", length);
  
  //nodes needed
  int nodes = ((length-1)/POWER) +1;
  
  //printf("need %d nodes\n", nodes);
  
  //leading zeros needed
  int zeros = (POWER*nodes)-(length);
  
  //printf("need %d leading zeros\n", zeros);
  
  //store temp values
  std::string temp;
  
  //loop for each node
  for(int i = 0; i < nodes; i++){
    
    //9 values per node
    for (int j = 0; j < POWER; j++) {
      
      //if leading zeros are still needed, append a 0
      if(zeros != 0){

        temp+= '0';
        
        zeros--;
      
      //else append from the string
      }else{
      
        temp+= s[index];
        
        index++;
      
      }
    
    }
    
    long l = atol(temp.c_str());
    
    
    temp.clear();
    
    //printf("add value %ld\n", l);
    
    digits.insertBefore(l);
  
  }
  
  //printf("constructed\n");
  //printf("length of list is %d\n", digits.length());

}
  
  
  
  
  
  
  






//copy constructor
BigInteger::BigInteger(const BigInteger& N){

  this->signum = N.sign();
  
  this->digits = List(N.digits); 
  
  
}

// Access Functions -----------------------------------------------------

//return sign
int BigInteger::sign() const{

  return signum;

}

//compare
/*
int BigInteger::compare(const BigInteger& N) const{

  int result = 0;
  
  if(this->sign() > N.sign()){
    
    //og has a greater sign than n
    return 1;
  
  }else if(this->sign() < N.sign()){
    
    //n has a greater sign than og
    return -1;
  
  }else if(this->digits.length() > N.digits.length() ){
    
    //og has more digits than n
    return 1;
  
  }else if(this->digits.length() < N.digits.length() ){
  
    //og has less digits than n
    return -1;
  
  }else{
    
    //compare node by node
    (this->digits).moveFront();
    
    N.digits.moveFront();
    
    for(int i = 0; i < this->digits.length(); i++){
      
      //get values
      long og = this->digits.peekNext();
      
      long n = N.digits.peekNext();
      
      //if positive and og is greater than n
      if(og > n && this->sign() == 1){
      
        return 1;
      
      //negative and og is greater than n
      }else if(og > n && this->sign() == -1){
      
        return -1;
        
      //positive and og is less than n
      }else if(og < n && this->sign() == 1){
      
        return -1;
      
      //negative and og is less than n
      }else if(og > n && this->sign() == -1){
      
        return 1;
      
      }
      
      //next
      this->digits.moveNext();
      
      N.digits.moveNext();
    
    }
  
  }
  
  return result;

}
*/

// Manipulation procedures -------------------------------------------------

//make zero
void BigInteger::makeZero(){

  digits.clear();
  
  signum = 0;

}

//negate
void BigInteger::negate(){

  if(signum != 0){
  
    signum *= -1;
  
  }

}

// BigInteger Arithmetic operations ----------------------------------------




// Print -------------------------------------------------------------------

//print
std::string BigInteger::to_string() {
  
  //printf("start printing\n");
  //printf("length of list is %d\n", digits.length());
  
  if(digits.length() == 0){
    
    //printf("nothing to print\n");
    return "0";
  
  }

  std::string s = "";
  
  if(signum == (-1) ){
  
    s+= '-';
  
  }
  
  digits.moveFront();
  
  for(int i =0; i < digits.length(); i++){
  
    if(i != 0){
    
      std::string e = std::to_string(digits.peekNext());
      
      //printf("length is %ld\n", e.size());
    
      for( size_t j = 0; j < POWER - e.size(); j++){
      
        s +='0';
      
      }
      
      //e.clear();
    
    }
    
    s += std::to_string(digits.peekNext());
    
    digits.moveNext();
  
  }
  //printf("finish print\n");
  return s;



}

// Overriden Operators -----------------------------------------------------

std::ostream& operator<<( std::ostream& stream, BigInteger N ) {
  //printf("length is %d\n", N.digits.length());

   return stream << N.to_string();
   
}
















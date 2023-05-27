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

int BigInteger::compare(const BigInteger& N) const{

  int result = 0;
  
  List L1 = this->digits;
  List L2 = N.digits;
  
  //printf("digits in A is %d\n", L1.length());
    
  //printf("digits in B is %d\n", L2.length());
  
  if(this->sign() > N.sign()){
    
    //og has a greater sign than n
    return 1;
  
  }else if(this->sign() < N.sign()){
    
    //n has a greater sign than og
    return -1;
  
  }else if(L1.length() > L2.length() ){
    
    if(N.sign() == -1){
    //og has more digits than n
      return -1;
    }
    return 1;
  
  }else if(L1.length() < L2.length() ){
  
    //og has less digits than n
    if(N.sign() == -1){
    //og has more digits than n
      return 1;
    }
    
    //printf("og has less digits, and is therefore smaller\n");
    return -1;
  
  }else{
    
    //compare node by node
    (L1).moveFront();
    
    L2.moveFront();
    
    //printf("value of A pos is %d\n", L1.position());
    //printf("value of B pos is %d\n", L2.position());
    
    //printf("value of A length is %d\n", L1.length());
    
    for(int i = 0; i < this->digits.length(); i++){
      
      //get values
      long og = L1.peekNext();
      //printf("value of A node is %ld\n", og);
      
      long n = L2.peekNext();
      //printf("value of B node is %ld\n", n);
      
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
      L1.moveNext();
      
      L2.moveNext();
    
    }
  
  }
  
  return result;

}


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


//normalize
int normalize(List& L){

  //find sign
  int sign = 1;
  
  L.moveFront();
  
  if(L.peekNext() < 0){
  
    sign = -1;
    
    while(L.position() != L.length()){
    
      L.setAfter(L.peekNext() * -1);
      
      L.moveNext();
    
    }
  
  }else if(L.length() == 0){
  
    sign = 0;
  
  }
  
  
  //move to end of list
  L.moveBack();
  
  long curr = 0;
  
  long carry = 0;
  
  while(L.position() != 0 ){
  
    curr = L.peekPrev();
    //printf("loop, current is %ld\n", curr);
    
    //if i need to carry from before, add 1 to the value
    
    if(carry == 1){
    
      //printf("need to append and make %ld\n", L.peekPrev() + 1);
      
      L.setBefore(L.peekPrev() + 1);
      curr = L.peekPrev();
      
      carry = 0;
      //printf("set carry to 0\n");
    
    }
    
    if(carry == -1){
    
      //printf("need to delete and make %ld\n", L.peekPrev() + 1);
      
      L.setBefore(L.peekPrev() - 1);
      curr = L.peekPrev();
      
      carry = 0;
      //printf("set carry to 0\n");
    
    }
    
    //if the current value is too large
    if(curr >= BASE){
      //printf("digit is too big, setting carry to 1\n");
      L.setBefore(curr - BASE);
      
      //mark for carry next time
      carry = 1;
    
    }
    
    //too small
    if(curr < 0){
    
      //printf("digit is too small, setting carry to -1\n");
      L.setBefore(curr + BASE);
      
      carry = -1;
    
    }
    
    L.movePrev();
  
  }
  
  
  //printf("exit while\n");
  //printf("carry = %ld\n", carry);
  
  if(carry == 1){
    
    L.insertBefore(1);
  
  }
  
  return sign;

}

//sum list WORKS
void sumList(List& S, List A, List B, int sgna, int sgnb){

  S.clear();
  
  A.moveFront();
  
  B.moveFront();
  
  while(A.position() != A.length() && B.position() != B.length()){
    
    printf("add up %ld and %ld\n", (sgna*A.peekNext()), (sgnb*B.peekNext()));
    
    printf("value is %ld\n", ((sgna*A.peekNext()) + (sgnb*B.peekNext()) ));
    
    if( (sgna*A.peekNext()) + (sgnb*B.peekNext()) < 0){
    
      S.insertBefore(  ((sgna*A.peekNext()) + (sgnb*B.peekNext()) ));
    
    }else{
    
      S.insertBefore( (sgna*A.peekNext()) + (sgnb*B.peekNext()) );
    
    }
    
    A.moveNext();
    
    //if(A != B){
    
    B.moveNext();
    
    //}
  
  }
  
  //printf("exiting while \n");
  
  //flush
  if(A.position() != A.length()){
  
    while(A.position() != A.length()){
    
      S.insertBefore( (sgna*A.peekNext()) );
      A.moveNext();
    
    }
  
  }
  
  //printf("flushed a \n");
  
  //flush
  if(B.position() != B.length()){
  
    while(B.position() != B.length()){
    
      S.insertBefore( (sgnb*B.peekNext()) );
      B.moveNext();
    
    }
  
  }
  
  S.moveFront();
  
  //printf("flushed b \n");
  //S.signum = normalize(S);
  
}

//add
BigInteger BigInteger::add(const BigInteger &N) const{
  
  BigInteger sum = BigInteger();
  
  BigInteger n = BigInteger(N);
  
  n.negate();
  
  if(this->compare(n) == 0){
  
    return sum;
  
  }
  
  List a = this->digits;
  List b = N.digits;
  
  sumList(sum.digits, a, b, this->sign(), N.sign());
  
  sum.signum = normalize(sum.digits);
  
  //printf("finished sumlist \n");
  
  //normalize(sum.digits);
  
  return sum;

}

//subtract
BigInteger BigInteger::sub(const BigInteger &N) const{
  
  BigInteger N2 = BigInteger(N);
  
  N2.negate();
  
 
  
  return this->add(N2);

}

//mult
BigInteger BigInteger::mult(const BigInteger &N) const{
  
  BigInteger x = BigInteger(N);
  
  return x;

}
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
  
    if(i != 0 && digits.peekNext() - BASE <= 0){
    
      std::string e = std::to_string(digits.peekNext());
      
      //printf("length is %ld\n", e.size());
    
      for( size_t j = 0; j < POWER - e.size(); j++){
      
        s +='0';
      
      }
      //printf("exit for loop\n");
      //e.clear();
    
    }
    
    //printf("digit is %ld\n", digits.peekNext());
    
    s += std::to_string(digits.peekNext())+' ';
    
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

bool operator==(const BigInteger& A, const BigInteger& B){

  if(A.compare(B) == 0){
  
    return true;
  
  }
  
  return false;

}

bool operator<(const BigInteger& A, const BigInteger& B){

  if(A.compare(B) == -1){
  
    return true;
  
  }
  
  return false;

}

bool operator<=(const BigInteger& A, const BigInteger& B){

  if(A.compare(B) == -1 || A.compare(B) == 0){
  
    return true;
  
  }
  
  return false;

}

bool operator>(const BigInteger& A, const BigInteger& B){

  if(A.compare(B) == 1){
  
    return true;
  
  }
  
  return false;

}

bool operator>=(const BigInteger& A, const BigInteger& B){

  if(A.compare(B) == 1 || A.compare(B) == 0){
  
    return true;
  
  }
  
  return false;

}

BigInteger operator+(const BigInteger& A, const BigInteger& B){

  return A.add(B);

}

BigInteger operator-(const BigInteger& A, const BigInteger& B){

  return A.sub(B);

}

BigInteger operator+=( BigInteger& A, const BigInteger& B){

  A = A+B;
  
  return A;

}

BigInteger operator-=( BigInteger& A, const BigInteger& B){

  A = A-B;
  
  return A;

}

BigInteger operator*(const BigInteger& A, const BigInteger& B){

  return A.mult(B);

}

BigInteger operator*=( BigInteger& A, const BigInteger& B){

  A = A*B;
  
  return A;

}















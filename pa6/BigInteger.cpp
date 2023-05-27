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
    
    //printf("value of A length is %d\n", L1.length());BigInteger C
    
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
      }else if(og < n && this->sign() == -1){
      
        return 1;
      
      }
      
      //next
      L1.moveNext();
      
      L2.moveNext();
    
    }
  
  }
  
  //printf("same value \n");
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

  
  }
  
  
  //move to end of list
  L.moveBack();
  
  //declare current and carry
  long curr = 0;
  
  long carry = 0;
  
  //loop through list
  while(L.position() != 0 ){
    
    //set cursor 
    curr = L.peekPrev();
    
    if(carry != 0){
      
      //printf("add carry (%ld) to curr (%ld)\n", carry, curr);
      
      L.setBefore(curr+=carry);
    
    }
    
    //reset carry
    carry = 0;
    
    
    //if curr >= BASE
    
    if(curr >= BASE){
    
      //printf("too large\n");
    
      carry = 1* ((curr - (curr%BASE)) / BASE);
      
      L.setBefore(curr%BASE);
      
      //curr = L.peekPrev();
    
    
    }
    
    if(curr < 0 ){
    
      //printf("too small\n");
    
      int tracker = 0;
    
      while(curr < 0){
      
        curr+=BASE;
        
        tracker++;
      
      }
      
      //printf("new curr = %ld\n", curr);
      
      L.setBefore(curr);
      
      carry = -1*tracker;
      
      //printf("carry over = %ld\n", carry);
      
    }
    
    L.movePrev();
    
  }
  
  L.moveFront();
  if(carry != 0){
  
    L.insertBefore(carry);
  
  }
  
  //printf("sign is %d\n", sign);
  return sign;

}

//sum list WORKS
void sumList(List& S, List A, List B, int sign){

  S.clear();
  
  A.moveBack();
  
  B.moveBack();
  
  
  while(A.position() != 0 && B.position() != 0){
    
    //printf("add up %ld and %ld\n", (A.peekPrev()), (sign*B.peekPrev()));
    
    //printf("value is %ld\n", ((A.peekPrev()) + (sign*B.peekPrev()) ));
    
    
    
    S.insertAfter(  ((A.peekPrev()) + (sign*B.peekPrev()) ));
    
    A.movePrev();
    
    B.movePrev();
    
  }
  
  //printf("exiting while \n");
  
  //flush
  if(A.position() != 0){
  
    while(A.position() != 0){
    
      S.insertAfter( (A.peekPrev()) );
      A.movePrev();
    
    }
  
  }
  
  //printf("flushed a \n");
  
  //flush
  if(B.position() != 0){
  
    while(B.position() != 0){
    
      S.insertAfter( (sign*B.peekPrev()) );
      B.movePrev();
    
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
    
  
    
    //A is negative B is positive
    if(this->sign() == -1 && N.sign() == 1){
    
      sumList(sum.digits, N.digits, this->digits, -1 );
      
      sum.signum = normalize(sum.digits);
    
    }
    
    //both negative
    if(this->sign() == -1 && N.sign() == -1){
    
      sumList(sum.digits, N.digits, this->digits, 1 );
      
      sum.signum = normalize(sum.digits);
      
      sum.signum = -1;
    
    }
    
    //A positive B negative
    if(this->sign() == 1 && N.sign() == -1){
    
      sumList(sum.digits, this->digits, N.digits, -1 );
      
      sum.signum = normalize(sum.digits);
    
    }
    
    //both positive
    if(this->sign() == 1 && N.sign() == 1){
    
      sumList(sum.digits, this->digits, N.digits, 1 );
      
      sum.signum = normalize(sum.digits);
    
    }
    
    
    return sum;
  

}

//subtract
BigInteger BigInteger::sub(const BigInteger &N) const{
  
    BigInteger N2 = BigInteger(N);
  
    N2.negate();
  
 
  
    return this->add(N2);


}

//scalar mult
void scalarMultList(List& L, ListElement m){

  L.moveBack();
  
  while(L.position() != 0){
  
    //printf("%ld x %ld\n", L.peekPrev(), m);
  
    L.setBefore(L.peekPrev() * m);
    
    L.movePrev();
  
  }
  
  //printf("finished scalar mult\n");
  //normalize(L);
  //printf("normalized\n");
  

}

void shiftList(List& L, int p){

  std::string s = "";
  
  for(int i = 0; i < POWER; i++){
  
    s += '0';
    
  }
  
  long l = atol(s.c_str());
  
  L.moveBack();
  
  
  for(int j = 0; j< p; j++){
  
    L.insertBefore(l);
  
  }
  
}

//mult
BigInteger BigInteger::mult(const BigInteger &N) const{
  
  BigInteger X = BigInteger();
  
  int sign = 1;
  
  List a = this->digits;
  
  List b = N.digits;
  
  if(a.length() ==0 || b.length() ==0){
  
    return X;
  
  }
  
  
  //loop through b list
  b.moveBack();
  
  int shift = 0;
  
  while(b.position() != 0){
  
    List add = this->digits;
    
    //set a to the scalar
    scalarMultList(add, b.peekPrev());
    
    //shift necessary amount
    if(shift != 0){
    
      shiftList(add, shift);
      //printf("shifted\n");
    
    }
    
    shift++;
    
    //printf("SCALAR MULT\n");
    
    //add.moveFront();
    
    //for(int i = 0; i<add.length(); i++){
    
      //printf("%ld ", add.peekNext());
      //add.moveNext();
    
    //}
    
    //printf("\n");
    
    
    //printf("ADD\n");
    
    //add onto total
    sumList(X.digits, X.digits, add, sign);
    
    //List c = X.digits;
    
    //c.moveFront();
    
    //for(int i = 0; i<c.length(); i++){
    
      //printf("%ld ", c.peekNext());
      //c.moveNext();
    
    //}
    
    //c.clear();
    
    //printf("\n");

    //printf("NORMALIZE\n");
    
    normalize(X.digits);
    
    //c = X.digits;
    
    //c.moveFront();
    
    //for(int i = 0; i<c.length(); i++){
    
      //printf("%ld ", c.peekNext());
      //c.moveNext();
    
    //}
    
    //printf("\n\n");
    
    //c.clear();
    
    
    add.clear();
    
    //move cursor
    b.movePrev();
    
    
  }
  
  if(this->sign() != N.sign()){
  
    
  
    //printf("diff sign %d vs %d\n", this->sign(), N.sign());
    X.signum = -1;
  
  }else{
    
    //printf("same sign\n");
    
    X.signum = 1;
  
  }
  
  return X;

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















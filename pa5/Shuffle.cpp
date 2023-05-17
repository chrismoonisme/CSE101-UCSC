//ckmoon
//pa4

#include<iostream>
#include<string>
#include<stdexcept>
#include"List.h"

using namespace std;

void shuffle(List &D){

    List A, B;
    
    D.moveFront();
    //cout << "D moves front" << A << endl;
    //cout << "halfway mark = " << D.length()/2 << endl;
  
    //cout << "length is " << D.length() << endl;
  
    for(int i =0; i< D.length(); i++){
  
      int a = D.moveNext();
      
      //cout << "a is " << a << endl;
      
      //cout << "position is " << D.position() << endl;
      
      if(D.position() <= D.length()/2){
        //cout << "A pos" << A.position()<<endl;
        A.insertBefore(a);
        //cout << "insert into A" << endl;
    
      }else{
        //cout << "B pos" << B.position()<<endl;
        B.insertBefore(a);
        //cout << "insert into B" << endl;
    
      }
      
    }
    
    
    cout << "A = " << A << endl;
  
    cout << "B = " << B << endl;
  
    //A.moveFront();
    //B.moveFront();
  
    //while(A.position() != A.length()){
  
     /// int x = A.moveNext();
    
      //B.moveNext();
    
      //B.insertAfter(x);
    
     // B.moveNext();
  
    //}
    
    
    //D.clear();
    A.moveFront();
    B.moveFront();
    A.clear();
    
    B.clear();
    
    /*
    for(int i =0; i < A.length()+B.length(); i++){
      
      if((i+1) %2 ==0){
      
        int a = A.moveNext();
        D.insertBefore(a);
      
      }else{
        int b = B.moveNext();
        D.insertBefore(b);
      
      }
      
      
    }
    
    */
    
  
  
    cout << "B = " << B << endl;
    
    
    
   



}



int main(int argc, char** argv){

  
  if(argc != 2){
  
    printf("2 arguments not given\n");
    
    exit(1);
    
  }
  
  cout << "deck size       shuffle count" << endl;
  cout << "------------------------------" << endl;
  
  
  List D;
  
  for(int i = 1; i<atoi(argv[1])+1; i++){
  
    D.insertBefore(i);
  
  }
  
  cout << "D = " << D << endl;
  

  
  shuffle(D);
  
  cout << "D = " << D << endl;
  
  shuffle(D);
  
  cout << "D = " << D << endl;
  
  
  
  

  
  return 0;



}

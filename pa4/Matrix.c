//Christopher Moon
//ckmoon
//pa4

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "Matrix.h"
#include "List.h"

typedef struct EntryObj{
  
  //value of the int
  int column;
  
  double value;
  
}EntryObj;

typedef EntryObj* Entry; 

Entry entry_create(int x, double y){

  //allocate mem
  Entry e = malloc( sizeof(EntryObj) );
  
  if(e){  
  
    e->column = x;
    
    e->value = y;
    
  }else{
  
    free(e);
    
    e= NULL;
  
  }
  
  return e;

}

void entry_delete(Entry* n){
  
  //free and null node
  if( n!=NULL && *n!=NULL ){
  
      free(*n);
      
      *n = NULL;
      
   }

}

//matrix ADT def
typedef struct MatrixObj{

  List *grid;
  
  int order;

}MatrixObj;

//matrix constructor
Matrix newMatrix(int n){

  Matrix m = malloc( sizeof(MatrixObj) );

  if(m){
    
    //allocate for array of lists
    m->grid = malloc(sizeof(List*) * (n));
    
    //allocate for each list inside the array
    for(int i = 0; i < n; i++){
      
      //allocate for each list inside the array
      m->grid[i] = newList();
    
    }
    
    //store order
    m->order = n;
  
  }else{
    
    free(m);
    
    m = NULL;
  
  }
  
  return m;

}

//matrix delete
void freeMatrix(Matrix* pM){

  for(int i = 0; i < (*pM)->order; i++){
  
    freeList( &(*pM)->grid[i]);
  
  }
  
  free(pM);
  pM = NULL;

}

//return matrix size
int size(Matrix M){

  return M->order;

}

int NNZ(Matrix M){

  int elements;
  
  //loop through array of lists
  for(int i =0; i <M->order; i++){
  
    //get length of each list and add length to number of non zero elements
    elements += length(M->grid[i]);
  
  }
  
  return elements;

}

int equals(Matrix A, Matrix B){
  
  //if the orders are different, automatically not equal
  if(A->order != B->order){
    
    return 0;
  
  }
  
  //loop through each List in the grids for each matrix, and compare list values
  for(int i = 0; i < A->order; i++){
    
    //if the lists at i are of different length, matrices are not equal
    if( length(A->grid[i]) != length(B->grid[i])  ){
      
      return 0;
    
    }
    
    //else check through each list element by element
    moveFront(A->grid[i]);
    moveFront(B->grid[i]);
    
    while(index(A->grid[i]) >= 0){
    
      Entry a = *(Entry*)get(A->grid[i]);
      Entry b = *(Entry*)get(B->grid[i]);
      
      if(a->value != b->value ){
      
        return 0;
      
      }
      
      moveNext(A->grid[i]);
      moveNext(B->grid[i]);
      
      entry_delete(&a);
      entry_delete(&b);
    
    }

  }
  
  return 1;
}

//reset to 0
void makeZero(Matrix M){

  //for each list inside the array
  for(int i = 0; i < size(M); i++){
      
    //delete og list
    freeList(&(M->grid[i]));
    
    //make a new empty list to replace og list
    M->grid[i] = newList();
    
  }

}

//change entry
void changeEntry(Matrix M, int i, int j, double x){

  if( (1 <= i && i <=size(M)) && (1<=j && j <= size(M)) ){
  
   //loop through list i
   
   moveFront(M->grid[i-1]);
   
   while(index(M->grid[i-1]) >= 0){
   
    Entry e = *(Entry*)get(M->grid[i-1]);
    
    //if column matches j, change value
    if(e->column == j){
    
      e->value = x;
    
    }
    
    moveNext(M->grid[i-1]);
   
    entry_delete(&e);
   
   }
  
  }else{
    
    printf("bad bounds for change entry \n");
    exit(1);
    
  }

}

//copy
Matrix copy(Matrix A){
  
  //allocate mem for copy, B
  Matrix B = newMatrix(size(A));
  
  //loop through array of lists in B (Lists should all be empty at first)
  for(int i = 0; i < size(B); i++){
    
    //loop though As list i
    moveFront(A->grid[i]);
    
    while(index(B->grid[i]) >= 0){
      
      //get corresponding A entry 
      Entry e = *(Entry*)get(A->grid[i]);
      
      //append A entry to B's list
      append(B->grid[i], e);
      
      //move next in As list
      moveNext(A->grid[i]);
   
      entry_delete(&e);
    
    }
    
  }
  
  return B;

}

//transpose
Matrix transpose(Matrix A){

  //allocate for new matrix B
  Matrix B = newMatrix(size(A));
  
  //loop through array of lists in B (Lists should all be empty at first)
  for(int i = 0; i < size(B); i++){
    
    //loop though empty list i
    moveFront(A->grid[i]);
    
    while(index(B->grid[i]) >= 0){
    
    
      //EX
      // row 2: (3, 1)
      // would become
      // row 3: (2, 1);
      
      //get corresponding A entry
      // row 2: (3, 1)
      Entry e = *(Entry*)get(A->grid[i]);
      
      //transpose entry
      // (2, 1);
      Entry t = *(Entry*)get(A->grid[i]);
      
      t->column = i;
      
      //append TRANSPOSE into B
      // row 3: (2, 1);
      append(B->grid[e->column], t);
      
      //move next in Bs list
      moveNext(A->grid[i]);
   
      entry_delete(&e);
      entry_delete(&t);
    
    }
    
  }
  
  return B;

}

//print
void printMatrix(FILE* out, Matrix M){
  
  //loop through array of lists
  for(int i = 0; i < size(M); i++){
  
    //print row, if not zero
    if(length(M->grid[i]) != 0){
    
      fprintf(out, "%d:", i);
    
    }
    
    //loop though list i
    moveFront(M->grid[i]);
    
    while(index(M->grid[i]) >= 0){
    
      Entry e = *(Entry*)get(M->grid[i-1]);
      
      fprintf(out, " (%d, %f)", e->column, e->value);
      
      moveNext(M->grid[i]);
   
      entry_delete(&e);
    
    }
    
    //newline
    fprintf(out, "\n");
    
  }

}






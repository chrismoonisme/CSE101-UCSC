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
  
  free(*pM);
  *pM = NULL;

}

//return matrix size
int size(Matrix M){

  return M->order;

}

int NNZ(Matrix M){

  int elements = 0;
  
  //loop through array of lists
  for(int i =0; i < M->order; i++){
    
    //printf("list\n");
    //get length of each list and add length to number of non zero elements
    elements += length(M->grid[i]);
  
  }
  
  return elements;

}

//equals
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
    
      Entry a = (Entry)get(A->grid[i]);
      Entry b = (Entry)get(B->grid[i]);
      
      if(a->value != b->value ){
      
        return 0;
      
      }
      
      moveNext(A->grid[i]);
      moveNext(B->grid[i]);
      
      //entry_delete(&a);
      //entry_delete(&b);
    
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
  
  //printf("change entry run\n");
  
  if( (1 <= i && i <=size(M)) && (1<=j && j <= size(M)) ){
  
    //track whether the entry exists
    bool exist = false;
    
    //if list isnt 0
    if(length(M->grid[i-1]) > 0){
      
      //printf("list is nonzero in length\n");
      
      //loop through list
      moveFront(M->grid[i-1]);
      
      //printf("moving to front, index is %d\n", index(M->grid[i-1]));
      
    
      while(index(M->grid[i-1]) >= 0 ){
      
        //printf("running while loop\n");
      
        Entry temp = (Entry)get(M->grid[i-1]);
        
        //printf("grabbing element, value %d, %f\n", temp->column, temp->value);
        
        
        //if an entry exists in the list with the same column
        if(temp->column == j){
          
          exist = true;
          
          //printf("an element already exists in list, changing value\n");
          
          //if x is zero, delete the entry
          if(x == 0.0){
          
            //printf("set to 0 means delete\n");
            //entry_delete(&temp);
            delete(M->grid[i-1]);
            
            break;
          
          //else change the value of the entry to x
          }else{
          
            //printf("change\n");
            temp->value = x;
          
          }
        
        }
        
        
        moveNext(M->grid[i-1]);
        
        //entry_delete(&temp);
      
      }
      
      //entry_delete(&temp);
    
    }
    
    //if an element does not exist at all
    if(exist == false){
      
      //printf("an element does not exist in the list yet, appending element to list\n");
      
      if(x != 0){
      
        Entry e = entry_create(j, x);
      
        if(length(M->grid[i-1]) == 0){
        
          //printf("appending\n");
          append(M->grid[i-1], e);
        
        }else{
        
          moveFront(M->grid[i-1]);
          
          while(index(M->grid[i-1]) > -1 && ((Entry)get(M->grid[i-1]))->column < j){
          
            moveNext(M->grid[i-1]);
          
          }
          
          if(index(M->grid[i-1]) != -1){
          
            insertBefore(M->grid[i-1], e);
          
          }else{
          
            //printf("appending\n");
            append(M->grid[i-1], e);
          
          }
        
        }
        
      }
      
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
    
      while(index(A->grid[i]) >= 0){
      
        //get corresponding A entry 
        Entry e = (Entry)get(A->grid[i]);
      
        //append A entry to B's list
        append(B->grid[i], e);
      
        //move next in As list
        moveNext(A->grid[i]);
   
        //entry_delete(&e);
    
      }
    
    }
  
  return B;

}

//transpose
Matrix transpose(Matrix A){

  //allocate for new matrix B
  Matrix B = newMatrix(size(A));
  
  //loop through array of lists in B (Lists should all be empty at first)
  for(int i = 0; i < size(A); i++){
    
    //loop though empty list i
    moveFront(A->grid[i]);
    
    while(index(A->grid[i]) >= 0){
    
    
      //EX
      // row 2: (3, 1)
      // would become
      // row 3: (2, 1);
      
      //get corresponding A entry
      // row 2: (3, 1)
      Entry e = (Entry)get(A->grid[i]);
      
      //create transpose entry
      // (2, 1);
      //printf("i value is %d\n", i);
      //printf("e value is %lf\n", e->value);
      //printf("e column is %d\n", e->column);
      
      Entry t = entry_create(i+1, e->value);
      
      
      //append TRANSPOSE into B
      // row 3: (2, 1);
      append(B->grid[e->column-1], t);
      
      //changeEntry(B, e->column + 1, i+1, e->value);
      
      //move next in Bs list
      moveNext(A->grid[i]);
   
      //entry_delete(&e);
      //entry_delete(&t);
    
    }
    
  }
  
  return B;

}

//print
void printMatrix(FILE* out, Matrix M){
  
  //loop through array of lists
  for(int i = 0; i < size(M); i++){
    
    //printf("printing row %d\n", i+1);
    
    //print row, if not zero
    if(length(M->grid[i]) != 0){
    
      fprintf(out, "%d:", i+1);
      
      //loop though list i
      moveFront(M->grid[i]);
      //printf("moved front\n");
    
      while(index(M->grid[i]) >= 0){
    
        Entry e = (Entry)get(M->grid[i]);
        
        //printf("run\n");
      
        fprintf(out, " (%d, %.1lf)", e->column, e->value);
      
        moveNext(M->grid[i]);
   
        //entry_delete(&e);
    
      }
    
      //newline
      fprintf(out, "\n");
      
    }
    
  }

}

//scalar mult
Matrix scalarMult(double x, Matrix A){

  Matrix B = newMatrix(size(A));
  
  //loop through array of lists
  for(int i = 0; i < size(A); i++){
  
    moveFront(A->grid[i]);
    
    while(index(A->grid[i]) >= 0){
      
      //get value
      Entry e = (Entry)get(A->grid[i]);
      
      //make new entry to insert into B
      Entry e2 = entry_create(e->column, e->value*x);
      
      append(B->grid[i], e2);
    
      moveNext(A->grid[i]);
      
    }
  
  }
  
  return B;

}

//sum
Matrix sum(Matrix A, Matrix B){

  if(size(A) != size(B)){
    
    printf("matrices should not be different sizes to add\n");
    exit(1);
    
  }
  
  if(equals(A, B) ){
  
    return scalarMult(2, A);
  
  }
  
  Matrix S = newMatrix(size(A));
  
   //loop through array of lists
  for(int i = 0; i < size(A); i++){
  
    moveFront(A->grid[i]);
    moveFront(B->grid[i]);
    
    while(index(A->grid[i]) >= 0 && index(B->grid[i]) >= 0){
      
      //get values
      Entry a = (Entry)get(A->grid[i]);
      
      Entry b = (Entry)get(B->grid[i]);
      
      //printf("column a = %d\n", a->column);
      //printf("column b = %d\n", b->column);
      
      //cases
      if(a->column > b->column){
      
        Entry e = entry_create(b->column, b->value);
        
        append(S->grid[i], e);
        
        moveNext(B->grid[i]);
      
      }else if(a->column < b->column){
        
        Entry e = entry_create(a->column, a->value);
        
        append(S->grid[i], e);
        
        moveNext(A->grid[i]);
      
      }else {
      
        if(a->value + b->value != 0){
      
          Entry e = entry_create(b->column, a->value + b->value);
        
          append(S->grid[i], e);
        
        }
        
        moveNext(B->grid[i]);
        
        moveNext(A->grid[i]);
      
      }
      
    }
    
    //flush
    if(index(A->grid[i]) >= 0){
      
      while(index(A->grid[i]) >= 0){
      
        Entry a = (Entry)get(A->grid[i]);
      
        Entry e = entry_create(a->column, a->value);
        
        append(S->grid[i], e);
        
        moveNext(A->grid[i]);
      
      }
    
    }
    
    if(index(B->grid[i]) >= 0){
      
      while(index(B->grid[i]) >= 0){
      
        Entry a = (Entry)get(B->grid[i]);
      
        Entry e = entry_create(a->column, a->value);
        
        append(S->grid[i], e);
        
        moveNext(B->grid[i]);
      
      }
    
    }
  
  }
  
  return S;

}

//diff
Matrix diff(Matrix A, Matrix B){

  if(size(A) != size(B)){
    
    printf("matrices should not be different sizes to subtract\n");
    exit(1);
    
  }
  
  if(equals(A, B) ){
  
    return newMatrix(size(A));
  
  }
  
  if( NNZ(A) == 0 ){
  
    return scalarMult(-1, B);
  
  }
  
  Matrix S = newMatrix(size(A));
  
   //loop through array of lists
  for(int i = 0; i < size(A); i++){
  
    moveFront(A->grid[i]);
    moveFront(B->grid[i]);
    
    while(index(A->grid[i]) >= 0 && index(B->grid[i]) >= 0){
      
      //get values
      Entry a = (Entry)get(A->grid[i]);
      
      Entry b = (Entry)get(B->grid[i]);
      
      //printf("column a = %d\n", a->column);
      //printf("column b = %d\n", b->column);
      
      //cases
      if(a->column > b->column){
      
        Entry e = entry_create(b->column, b->value);
        
        append(S->grid[i], e);
        
        e->value *= -1;
        
        moveNext(B->grid[i]);
      
      }else if(a->column < b->column){
        
        Entry e = entry_create(a->column, a->value);
        
       
        
        append(S->grid[i], e);
        
        moveNext(A->grid[i]);
      
      }else {
      
        if(a->value - b->value != 0){
      
          Entry e = entry_create(b->column, a->value - b->value);
           //e->value *= -1;
          append(S->grid[i], e);
        
        }
        
        moveNext(B->grid[i]);
        
        moveNext(A->grid[i]);
      
      }
      
    }
    
    //flush
    if(index(A->grid[i]) >= 0){
      
      while(index(A->grid[i]) >= 0){
      
        Entry a = (Entry)get(A->grid[i]);
      
        Entry e = entry_create(a->column, a->value);
        
       
        e->value *= -1;
    
        
        
        append(S->grid[i], e);
        
        moveNext(A->grid[i]);
      
      }
    
    }
    
    if(index(B->grid[i]) >= 0){
      
      while(index(B->grid[i]) >= 0){
      
        Entry a = (Entry)get(B->grid[i]);
      
        Entry e = entry_create(a->column, a->value);
        
         e->value *= -1;
        
        append(S->grid[i], e);
        
        moveNext(B->grid[i]);
      
      }
    
    }
  
  }
  
  return S;

}

double vectorDot(List P, List Q){

  double dp = 0;

  moveFront(P);
  
  moveFront(Q);
  
  while(index(P) >= 0 && index(Q) >= 0){
  
    Entry a = (Entry)get(P);
    
    Entry b = (Entry)get(Q);
    
    if(a->column > b->column){
    
      moveNext(Q);
    
    }else if(a->column < b->column){
    
      moveNext(P);
    
    }else{
    
      dp+= a->value * b->value;
      moveNext(Q);
      moveNext(P);
    
    }
    
  }
  
  return dp;

}


//Matrix product(Matrix A, Matrix B){
  
  //return A;

//}


//product
Matrix product(Matrix A, Matrix B){


  if(size(A) != size(B)){
    
    printf("matrices should not be different sizes to multiply\n");
    exit(1);
    
  }
  

  Matrix S = newMatrix(size(A));
  
  //printf("created new matrix\n");
  
  Matrix T = transpose(B);
  
  //printf("setup transpose\n");
  
  //loop through each element in the matrix
  
  //array of lists
  for(int i = 0; i < size(A); i++){
    
    List a = A->grid[i];
    
    if(length(a) != 0){
    
      for(int j = 0; j < size(A); j++){
    
        List b = T->grid[j];
        
        if(length(b) != 0){
      
          double dp = vectorDot(a, b);
      
          //printf("j value is %d\n", j);
      
          //changeEntry(S, i+1, j, dp);
          if(dp != 0){
            
            Entry x = entry_create(j+1, dp);
          
            append(S->grid[i], x);
            
            
          }
          
        }
  
      }
    
    }
  
  }
  
  //printf("reached end of product\n");
  
  freeMatrix(&T);
  
  return S;
  
}










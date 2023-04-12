//Christopher Moon
//ckmoon
//pa1

#include <stdlib.h>
#include <stdio.h>
#include "list.h"


//node 
typedef struct NodeObj{
  
  //value of the int
  int value;
  
  //pointer to next node in the list
  struct Node* prev;
  
  //pointer to previous node
  struct Node* next;
  
} NodeObj;

typedef NodeObj* Node; 

//node constructor
Node node_create(int value){

  //allocate mem
  Node *n = (Node *)malloc( sizeof(Node) );
  
  if(n){  
  
    n->prev = NULL;
    
    n->next = NULL;
    
    n->value = value;
  
  }else{
  
    free(n);
    
    n = NULL:
  
  }
  
  return n;

}

//node delete
void node_delete(Node* n){
  
  //free and null node pointers
  free(n->next);
  n->next = NULL;
  free(n->prev);
  n->prev = NULL;
  
  //free and null node
  free(n);
  
  n = NULL;

}

//linked list
typedef struct ListObj{

  Node front;
  
  Node back;
  
  Node cursor; 
  
  int length;
  
  int index;

} ListObj;

//list constructor
List newList(void){

  List *l = (List *)malloc( sizeof(List) );
  
  if(l){
  
    l->front = NULL;
    
    l->back = NULL;
    
    l->cursor = NULL;
    
    l->length = 0;
    
    l->index = -1; 
  
  }else{
  
    free(l);
    
    l= NULL;
  
  }
  
  return l;
  
}

//deconstructor
void freeList(List *pl){
  
  while (pl->front != NULL) {
  
    // temp set to next after front
    Node *temp  = pl->front->next;
  
    // front cleared
    node_delete(pl->front);
  
    // new front is temp
    pl->front = temp;
  
  }
  
  free(pl);
  
  pl = NULL;

}

//return length
int length(List L){
  
  return L->length;

}

//return index
int index(List L){
  
  return L->index;

}

//return front
int front(List L){
  
  if(L->length != 0 && L->index >= 0){
    
    return L->front->value;
  
  }
  
  exit(1);
  
}

//return back
int back(List L){
  
  if(L->length != 0){
    
    return L->back->value;
  
  }
  
  exit(1);

  
}

//return cursor node value
int get(List L){
  
  if(L->length != 0){
    
    return L->cursor->value;
  
  }
  
  exit(1);
  
}

//checks if two lists are equal
bool equals(List A, List B){
  
  //if not same length, automatically false
  if(A->length != B->length){
  
    return false;
  
  }
  
  //temp nodes for comparison, set as beginning nodes of both lists
  Node *a  = A->front
  
  Node *b  = A->front
  
  while(a != NULL){
    
    //if the equivalent nodes dont have the same numerical value, false
    if(a->value != b->value){
    
      return false;
    
    }
    
    //update nodes
    a = a->next;
    b = b->next;
    
  }
  
  return true;
  
}
  
  


//pa5
//ckmoon

#include<iostream>
#include<string>
#include<stdexcept>
#include"List.h"

// Private Constructor --------------------------------------------------------

//Node constructor
List::Node::Node(ListElement x){

   data = x;
   
   next = nullptr;
   
   prev = nullptr;
   
}

// Class Constructors & Destructors -------------------------------------------

// Creates a new List in the empty state.
List::List(){
  
  //create sentinel nodes
  frontDummy = new Node(0);
   
  backDummy = new Node(0);
  
  //have sentinel nodes point to each other
  frontDummy->next = backDummy;
  
  backDummy->prev = frontDummy;
  
  //cursor pointers
  beforeCursor = frontDummy;
   
  afterCursor = backDummy;
   
  //cursor cant be undef
  pos_cursor = 0;
   
  num_elements = 0;
   
}


//copy constructor
List::List(const List& L){

  //make empty list
  frontDummy = new Node(0);
   
  backDummy = new Node(0);
  
  frontDummy->next = backDummy;
  
  backDummy->prev = frontDummy;
   
  beforeCursor = frontDummy;
   
  afterCursor = backDummy;
  
  pos_cursor = 0;
   
  num_elements = 0;
  
  //load elements of L into the new empty list

  
    Node *n = L.frontDummy->next;
  
    while(n!=L.backDummy){
  
      this->insertBefore(n->data);
    
      n = n->next;
  
    }
    
  
  
}


// Destructor

List::~List(){

   clear();
   
   delete frontDummy;
   delete backDummy; 
   
}


// Access functions -----------------------------------------------------------

//return num of elements in list
int List::length() const{

   return(num_elements);
   
}

//returns front element VALUE of list
ListElement List::front() const{
  
  //if list is 0, exit
  if(num_elements ==0){
    
    throw std::length_error("List: front(): empty list");
    
  }
  
  //else return front node
  return(frontDummy->next->data);

}

//returns back element VALUE of list
ListElement List::back() const{
  
  //if list is 0, exit
  if(num_elements ==0){
    
    throw std::length_error("List: back(): empty list");

  
  }
  
  //else return front node
  return(backDummy->prev->data);

}

//return pos of cursor list
int List::position() const{
  
  if(0 <= pos_cursor && pos_cursor <= num_elements){
    
    return(pos_cursor);
  
  }else{
    printf("error with position\n");
    exit(1);
  
  }
   
}

//return value of the node after cursor
ListElement List::peekNext() const{
  
  
  if(pos_cursor >= num_elements){
  
    throw std::range_error("out of range for peekNext"); 
  
  }
  
  return(afterCursor->data);

}

//return value of the node after cursor
ListElement List::peekPrev() const{
  
  
  if(pos_cursor <= 0){
  
    throw std::range_error("out of range for peekPrev"); 
  
  }
  
  return(beforeCursor->data);

}

// Manipulation procedures -------------------------------------------------

//reset a list
void List::clear(){

  //reset all stats
  pos_cursor = 0;
  
  num_elements = 0;
  
  moveBack();
  
  Node *N =nullptr;
  
  for(N=frontDummy->next; N!=nullptr; N=N->next){
  
    if(N != backDummy){
    
      delete N->prev;
    
    }
  
  
  }
  
  
  //reset sentinels
  frontDummy->next = backDummy;
  
  backDummy->prev = frontDummy;
  
  moveFront();

}

//move cursor to front
void List::moveFront(){
  
  //set index to 0
  pos_cursor = 0;
  
  //change pointers
  beforeCursor = frontDummy;
  
  afterCursor = frontDummy->next;

}

//move cursor to back
void List::moveBack(){
  
  //set index to length
  pos_cursor = num_elements;
  
  //change pointers
  beforeCursor = backDummy->prev;
  
  afterCursor = backDummy;

}

//move cursor over 1, return value of node passed over
ListElement List::moveNext(){
  
  if(pos_cursor >= num_elements){
  
    throw std::range_error("out of range for moveNext"); 
  
  }
  //increase pos cursor
  pos_cursor++;
  
  //change pointers
  beforeCursor = afterCursor;
  
  afterCursor = afterCursor->next;
  
  return beforeCursor->data;

}

//move cursor over -1, return value of node passed over
ListElement List::movePrev(){
  
  if(pos_cursor > 0){
  
    //increase pos cursor
    pos_cursor--;
  
    //change pointers
    afterCursor = beforeCursor;
  
    beforeCursor = beforeCursor->prev;
  
    return afterCursor->data;
  
  
  }else{
    
    throw std::range_error("out of range for movePrev"); 
  
  
  }
  

}

//insert new node val x after cursor
void List::insertAfter(ListElement x){
  
  //printf("beforeCursor is now %d\n", beforeCursor->data); 
  //printf("afterCursor is now %d\n", afterCursor->data); 
  
  //make a new node
  Node *n = new Node(x);
  
  //insert
  
  //set ns pointers
  n->prev = beforeCursor;
  n->next = afterCursor;
  
  //change pointers for existing nodes
  beforeCursor->next = n;
  afterCursor->prev = n;
  
  //change cursor
  afterCursor = n;
  
  //increment elements
  num_elements++;

}

//insert new node val x before cursor
void List::insertBefore(ListElement x){

  //make a new node
  Node *n = new Node(x);
  //printf("made new node\n");
  
  
  //insert
  
  //set ns pointers
  n->prev = beforeCursor;
  n->next = afterCursor;
  
  //change pointers for existing nodes
  beforeCursor->next = n;
  afterCursor->prev = n;
  
  //change cursor
  beforeCursor = n;
  
  //increment elements
  num_elements++;
  
  pos_cursor++;

}

//set afterCursor val
void List::setAfter(ListElement x){
  
  if(pos_cursor < num_elements){
  
    afterCursor->data = x;
  
  }else{
  
    throw std::range_error("out of range for setBefore"); 
  
  }

}

//set afterCursor val
void List::setBefore(ListElement x){
  
  if(pos_cursor > 0){
  
    beforeCursor->data = x;
  
  }else{
  
    throw std::range_error("out of range for setBefore"); 
  
  }

}

//delete afterCursor
void List::eraseAfter(){

  if(pos_cursor < num_elements){
  
    num_elements--;
    
    Node *x = afterCursor;
    
    afterCursor->next->prev = beforeCursor;
    
    beforeCursor->next = afterCursor->next;
    
    afterCursor = afterCursor->next;
    
    //printf("deleting %d\n",x->data); 
    
    //printf("beforeCursor is now %d\n", beforeCursor->data); 
    //printf("afterCursor is now %d\n", afterCursor->data); 
    
    delete x;
  
  }else{
    
    throw std::range_error("out of range for eraseAfter");
  
  }
  
}

//delete beforeCursor
void List::eraseBefore(){

  if(pos_cursor > 0){
  
    num_elements--;
    
    pos_cursor--;
    
    //temp val
    Node *x = beforeCursor;
    
    beforeCursor->prev->next = afterCursor;
    
    afterCursor->prev = beforeCursor->prev;
    
    beforeCursor = beforeCursor->prev;
    
    //printf("deleting %d\n",x->data); 
    //printf("beforeCursor is now %d\n", beforeCursor->data); 
    
    //printf("beforeCursor next is now %d\n", beforeCursor->next->data); 
    //printf("afterCursor is now %d\n", afterCursor->data); 
    //printf("afterCursor prev is now %d\n", afterCursor->prev->data); 
    
    delete x;
  
  }else{
  
    throw std::range_error("out of range for eraseBefore");
  
  }
  
}

// Other Functions ---------------------------------------------------------

//start searching at cursor for x
ListElement List::findNext(ListElement x) {

  int val = -100;
  
  bool found = false;
 
  while(val != x && pos_cursor != num_elements){
 
    val = moveNext();
    
    if(val == x){
    
      found = true;
    
    }
  
  }
  
  if(found){
  
    return pos_cursor;
  
  }
  
  return -1;

}

//start searching at cursor for x, going DOWN
ListElement List::findPrev(ListElement x) {

  int val = -100;
  
  bool found = false;
 
  while(val != x && pos_cursor != 0){
 
    val = movePrev();
    
    if(val == x){
    
      found = true;
    
    }
  
  }
  
  if(found){
  
    return pos_cursor;
  
  }
  
  return -1;

}

//cleanup
void List::cleanup(){

  Node* N = nullptr;
  
  for(N=frontDummy->next; N!=backDummy; N=N->next){
  
    Node* x = nullptr;
    
    for(x = N->next; x!=backDummy; x=x->next){
    
      if(x->data == N->data){ 
      
        x->data = -1;
      
      }
      
    }
  
  }
  
  Node* S = nullptr;
  
  int a = 0;
  
  int z = 0;
  
  for(S=frontDummy->next; S!=backDummy; S=S->next){
    //printf("cursor is %d\n", pos_cursor);
    if(S->data == -1){
      //printf("a is %d\n", a);
      num_elements--;
      
      if(a <= pos_cursor){
        
        z++;
      
      }
    
    }
    
    
    a++;
  
  }
  
  pos_cursor -= z;

  

}

//concat
List List::concat(const List& L) const{

  List J;
  
  Node* N = this->frontDummy->next;
  
  Node* M = L.frontDummy->next;
  
  if(L.num_elements != 0){
  
    while( N!=this->backDummy ){
    
      J.insertBefore(N->data);
      
      N = N->next;
      
    }
  
  }
  
  if(this->num_elements!= 0){
  
    while( M!=L.backDummy ){
    
      J.insertBefore(M->data);
      
      M = M->next;
      
    }
  
  }
  
  J.moveFront();
  return J;

}

//print
std::string List::to_string() const{

  Node* N = nullptr;
  
   std::string s = "";

   for(N=frontDummy; N!=nullptr; N=N->next){
   
      if(N == frontDummy){
      
        s += "(";
        
      }else if(N == backDummy){
      
        s += ")";
        
      }else{
        
        if(N == backDummy->prev){
        
          s += std::to_string(N->data);
        
        }else{
        
          s += std::to_string(N->data)+", ";
        
        }
      
      }
      
   }
   
   return s;

}

//equals
bool List::equals(const List& Q) const{
  
  if(Q.num_elements != this->num_elements){
  
    return false;
  
  }
  
  bool eq = false;
   Node* N = nullptr;
   Node* M = nullptr;

   eq = ( this->num_elements == Q.num_elements );
   
   N = this->frontDummy;
   M = Q.frontDummy;
   
   while( eq && N!=nullptr){
   
      eq = (N->data == M->data);
      
      N = N->next;
      M = M->next;
   }
   
   return eq;

}

// Overriden Operators -----------------------------------------------------

std::ostream& operator<<( std::ostream& stream,  const List& L ) {
   return stream << L.to_string();
}


bool operator==(const List& A, const List& B){
   return A.equals(B);
}


List& List::operator=( const List& Q ) {
   if( this != &Q ){ // not self assignment
      // make a copy of Q
      List temp = Q;

      // then swap the copy's fields with fields of this
      std::swap(frontDummy, temp.frontDummy);
      std::swap(backDummy, temp.backDummy);
      std::swap(num_elements, temp.num_elements);
   }

   // return this with the new data installed
   return *this;

   // the copy, if there is one, is deleted upon return
}


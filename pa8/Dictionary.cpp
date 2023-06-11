//pa8
//ckmoon

#include<iostream>
#include<string>
#include<stdexcept>
#include"Dictionary.h"

//private contructor

//Node constructor
Dictionary::Node::Node(keyType k, valType v){

   key = k;
   
   val = v;
   
   parent = nullptr;
   
   left = nullptr;
   
   right = nullptr;
   
   color = 0;
   
}

//transplant
//void Dictionary::transplant(Node* u, Node* v){

  //if(u->parent == nullptr){
  
    //root = v;
  
  //}else if(u == u->parent->left){
  
    //u->parent->left = v;
  
  //}else{
  
    //u->parent->right = v;
  
  //}
  
  //if(v != nullptr){
  
    //v->parent = u->parent;
  
  //}

//}

//in order print
void Dictionary::inOrderString(std::string& s, Node* R) const{

  if(R != nil){

    //left in order
    inOrderString(s, R->left);
    
    //convert val to string
    std::string v = std::to_string(R->val);
    
    //print
    s+= R->key + " : " + v + "\n";
    
    //right in order
    inOrderString(s, R->right);
  }

}

//pre order print
void Dictionary::preOrderString(std::string& s, Node* R) const{

  if(R != nil){
  
    //print
    s+= R->key;
    
    if(R->color == 1){
    
      s+= " (RED)";
    
    
    }
    
    s+="\n";
    
    //left
    preOrderString(s, R->left);
    
    //right
    preOrderString(s, R->right);
  
  }

}

//copy
void Dictionary::preOrderCopy(Node *R){

  if(R != nil && R->key != "nil"){
    
    printf("copy in key %s\n", R->key.c_str());
    
    setValue(R->key, R->val);
    
    preOrderCopy(R->left);
  
    preOrderCopy(R->right);
    
  }

}

//delete in post order
void Dictionary::postOrderDelete(Node* R){

  if(R != nil){
  
    postOrderDelete(R->left);
    
    postOrderDelete(R->right);
    
    delete R; 
  
  }
  
}

//search for a key
Dictionary::Node* Dictionary::search(Node* R, keyType k) const{

  

  if(R == nil || k == R->key){
  
    return R;
    
  }else if(k < R->key){
  
    return search(R->left, k);
  
  }else{
  
    return search(R->right, k); 
  
  }
  
 

}

//find min
Dictionary::Node* Dictionary::findMin(Node* R){
  
  
  
  //else, search for min
  while(R->left != nil){
  
    R = R->left;
  
  }
  
  return R;

}

//find max
Dictionary::Node* Dictionary::findMax(Node* R){

  
  //else search for max
  while(R->right != nil){
  
    R = R->right;
  
  }
  
  return R;

}

//find next in order
Dictionary::Node* Dictionary::findNext(Node* N){
  
  if(N->right != nil){
  
    return findMin(N->right);
  
  }
  
  Node *y = N->parent;
  
  while(y != nil && N == y->right){
  
    N = y;
    
    y = y->parent;
  
  }
  
  return y;
  
}

//find prev in order
Dictionary::Node* Dictionary::findPrev(Node* N){
  
  if(N->left != nil){
  
    return findMax(N->left);
  
  }
  
  Node *y = N->parent;
  
  while(y != nil && N == y->left){
  
    N = y;
    
    y = y->parent;
  
  }
  
  return y;
  
}

// RBT Helper Functions (Optional) -----------------------------------------

//left rotate
void Dictionary::LeftRotate(Node *N){

  //set y
  Node *y = N->right;
  
  //y left subtree into N right subtree
  N->right = y->left;
  
  if(y->left != nil ){
  
    y->left->parent = N;
  
  }

  //link y parent to N
  y->parent = N->parent;
  
  if(N->parent == nil){
    
    root = y;
  
  }else if(N == N->parent->left){
  
    N->parent->left = y;
  
  }else{
  
    N->parent->right = y;
  
  }
  
  y->left = N;
  
  N->parent = y;

}

//right rotate
void Dictionary::RightRotate(Node *N){

  Node *y = N->left;
  
  N->left = y->right;
  
  if(y->right != nil){
  
    y->right->parent = N;
  
  }
  
  y->parent = N->parent ;
  
  if(N->parent == nil){
  
      root = y;
      
  }else if( N == N->parent->right){
  
      N->parent->right = y;
      
  }else{
  
      N->parent->left = y;
  
  }
  
  y->right = N;
  
  N->parent = y;

}

//insert fix
void Dictionary::RB_InsertFixUp(Node* N){

  //printf("entered insert fix up\n");
  
  //RED == 1
  //BLACK == 0
  
  
  
  while( N->parent->color == 1 ){
  
    //printf("entered while \n");
  
    if(N->parent == N->parent->parent->left){
    
      //printf("n parent = n parent parent left \n");
    
      Node *y = N->parent->parent->right;
      
      //printf("created node y \n");
      
      if(y->color == 1){
      
        //printf("y color is red \n");
      
        N->parent->color = 0;     
        
        y->color = 0;       
        
        N->parent->parent->color = 1;    
        
        N = N->parent->parent; 

      }else{
      
        //printf("y color is black \n");
      
        if(N == N->parent->right){
        
          //printf("need to rotate \n");
        
          N = N->parent;
          
          LeftRotate(N);
          
          //printf("left rotated\n");
        
        }
        
        N->parent->color = 0;
        
        N->parent->parent->color = 1;
        
        RightRotate(N->parent->parent);
        
        //printf("right rotated\n");
      
      }
      
    }else{
    
      //printf("big else\n");
      
        Node*y = N->parent->parent->left;
        
        //printf("created node y\n");
        
        if(y->color == 1){
        
          //printf("y is red\n");
        
          N->parent->color = 0;
          
          y->color = 0;
          
          N->parent->parent->color = 1;
          
          N = N->parent->parent;
        
        
      
        }else{
        
          //printf("y is black\n");
      
          if(N == N->parent->left){
        
            N = N->parent;
          
            RightRotate(N);
            
            //printf("rightrotate \n");
        
          }
        
          N->parent->color = 0;
        
          N->parent->parent->color = 1;
        
          LeftRotate(N->parent->parent);
          
          //printf("leftrotate \n");
      
        }
      
      }
  
    }
    
    //printf("exit while \n");
    

    root->color = 0;
    
}

//transplant
void Dictionary::RB_Transplant(Node* u, Node* v){

  if(u->parent == nil){
  
    root = v;
  
  }else if(u == u->parent->left){
  
    u->parent->left = v;
  
  }else{
  
    u->parent->right = v;
  
  }

  v->parent = u->parent;

}

void Dictionary::RB_DeleteFixUp(Node* N){

  while(N != root && N->color == 0){
  
    if(N == N->parent->left){
    
      Node *w = N->parent->right;
      
      if(w->color == 1){
      
        w->color = 0;
        
        N->parent->color = 1;
        
        LeftRotate(N->parent);
        
        w = N->parent->right;
      
      }
      
      if(w->left->color == 0 && w->right->color == 0){
      
        w->color = 1;
        
        N =  N->parent;
      
      }else{
      
        if(w->right->color == 0){
        
          w->left->color = 0;
          
          w->color = 1;
          
          RightRotate(w);
          
          w = N->parent->right;
        
        }
        
        w->color = N->parent->color;
        
        N->parent->color = 0;
        
        w->right->color = 0;
        
        LeftRotate(N->parent);
        
        N = root;
      
      }
      
    }else{
    
      Node *w = N->parent->left;
      
      if(w->color == 1){
        
        w->color =0;
        
        N->parent->color =1;
        
        RightRotate(N->parent);
        
        w = N->parent->left;
      
      }
      
      if(w->right->color == 0 && w->left->color == 0){
      
        w->color = 1;
        
        N = N->parent;
      
      }else{
      
        if(w->left->color == 0){
        
          w->right->color = 0;
          
          w->color = 1;
          
          LeftRotate(w);
          
          w = N->parent->left;
        
        }
        
        w->color = N->parent->color;
        
        N->parent->color = 0;
        
        w->left->color = 0;
        
        RightRotate(N->parent);
        
        N = root;
      
      }
    
    }
  
  }
  
  N->color = 0;

}

//delete
void Dictionary::RB_Delete(Node* N){

  Node* y = N;
  
  Node *x;
  
  int ycolor = y->color;
  
  if(N->left == nil){
  
    x = N->right;
    
    RB_Transplant(N, N->right);
  
  }else if(N->right == nil){
  
    x = N->left;
    
    RB_Transplant(N, N->left);
  
  }else{
  
    y = findMin(N->right);
    
    ycolor = y->color;
    
    x = y->right;
    
    if(y->parent == N){
    
      x->parent = y;
    
    }else{
    
      RB_Transplant(y, y->right);
      
      y->right = N->right;
      
      y->right->parent = y;
    
    }
    
    RB_Transplant(N, y);
    
    y->left = N->left;
    
    y->left->parent = y;
    
    y->color = N->color;
  
  
  }
  
  if(ycolor == 0){
  
    RB_DeleteFixUp(x);
  
  }


}


// Class Constructors & Destructors -------------------------------------------

// Creates a new dict in the empty state.
Dictionary::Dictionary(){

  nil = new Node("nil", -1);;

  root = nil;
  
  current = root; 
  
  num_pairs = 0;

}

//copy
Dictionary::Dictionary(const Dictionary& D){
  
  this->nil = new Node("nil", -1);
  
  this->root = nil;
  
  this->num_pairs = 0;
  
  this->current = this->root;
  
  //printf("started copy\n");
  
  
  this->preOrderCopy(D.root);

}


//delete
Dictionary::~Dictionary(){

  if(num_pairs != 0){
  
    postOrderDelete(root);
    
  }
  
  delete nil;

}

// Class Functions -------------------------------------------

//size
int Dictionary::size() const{

  return num_pairs;

}

//if exists
bool Dictionary::contains(keyType k) const{

  if(search(root, k) == nil){
  
    return false;
  
  }
  
  return true;

}

//get reference of val of k
valType& Dictionary::getValue(keyType k) const{

  Node *n = search(root, k);
  
  return n->val;

}

//check if current is defined
bool Dictionary::hasCurrent() const{
  
  if(current != nil){
  
    return true;
  
  }
  
  return false;

}

//returns reference to current val
valType& Dictionary::currentVal() const{

  if(hasCurrent() == false){
  
    throw std::logic_error("no valid current");
  
  }
  
  return current->val;
  
}

//return current key
keyType Dictionary::currentKey() const{

  if(hasCurrent() == false){
  
    throw std::logic_error("no valid current");
  
  }

  return current->key;

}

//clear
void Dictionary::clear(){

  postOrderDelete(root);
  
  num_pairs = 0;
  
  root = nil;
  
  current = root;
  
}

//insert or override 
void Dictionary::setValue(keyType k, valType v){

    
    //search if K already exists in tree
    Node *n = search(root, k);
    
    //printf("searched \n");
  
    //if k exists, override
    if(n != nil){
    
      //printf("need to override \n");
  
      n->key = k;
    
      n->val = v;
      
    //else insert
    }else{
    
      //printf("need to insert \n");
      
      //create node to insert
      Node *z = new Node(k , v);
      
      //printf("created node \n");
      
      //increment stats
      //printf("k = %s\n", k.c_str());
      //printf("adding a pair to current pairs, %d\n", num_pairs);
      num_pairs++;
      
      Node *y = nil;
      
      Node *x = root;
      
      while(x != nil){
      
        y = x;
        
        if(k < x->key){
        
          x = x->left;
        
        }else{
        
          x = x->right;
        
        }
      
      }
      
      //printf("while completed \n");
      
      z->parent = y;
      
      if(y == nil){
      
        //printf("this is the root \n");
      
        root = z;
      
      }else if(z->key < y->key){
      
        y->left = z;
      
      }else{
      
        y->right = z;
      
      }
      
      //printf("children and root figured out \n");
      
      z->left = nil;
    
      z->right = nil;
    
      z->color = 1;
    
     
      
      
      RB_InsertFixUp(z);
      //printf("insertfixup \n");
      
      
      
      
      
      //printf("insertfixup \n");
  
    
    }
    
  
  //}

}

void Dictionary::remove(keyType k ){

  num_pairs--;

  Node *z = search(root, k);
  //printf("searched\n");
  
  if(z == current){
    
    //printf("current deleted\n");
    current = nil;
  
  }
  
  RB_Delete(z);
  
  delete z;
  
  
}

//set beginning
void Dictionary::begin(){

  if(num_pairs!=0){

    current = findMin(root);
    
  }

}

//set beginning
void Dictionary::end(){

  if(num_pairs!=0){
  
    current = findMax(root);
  
  }

}

//move current next
void Dictionary::next(){

  if(hasCurrent() == false){
  
    throw std::logic_error("no valid current");
  
  }

  current = findNext(current);

}

//move current prev
void Dictionary::prev(){

  if(hasCurrent() == false){
  
    throw std::logic_error("no valid current");
  
  }

  current = findPrev(current);

}

std::string Dictionary::to_string() const{

  std::string s = "";
  
  inOrderString(s, root);
  
  return s;

}

std::string Dictionary::pre_string() const{

  std::string s = "";
  
  preOrderString(s, root);
  
  return s;

}

bool Dictionary::equals(const Dictionary& D) const{

  std::string s = "";

  this->inOrderString(s, this->root); 
  
  std::string s2 = "";
  
  D.inOrderString(s2, D.root); 
  
  return s2 == s;

}

std::ostream& operator<<( std::ostream& stream,  Dictionary& D ) {

   return stream << D.to_string();
   
}

bool operator==(const Dictionary& A, const Dictionary& B ){
   return A.equals(B);
}

Dictionary& Dictionary::operator=( const Dictionary& D ){


  this->clear();
  
  this->preOrderCopy(D.root);
  
  return *this;


}





//pa7
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
   
}

//transplant
void Dictionary::transplant(Node* u, Node* v){

  if(u->parent == nullptr){
  
    root = v;
  
  }else if(u == u->parent->left){
  
    u->parent->left = v;
  
  }else{
  
    u->parent->right = v;
  
  }
  
  if(v != nullptr){
  
    v->parent = u->parent;
  
  }

}

//in order print
void Dictionary::inOrderString(std::string& s, Node* R) const{

  if(R != nullptr){

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

  if(R != nullptr){
  
    //print
    s+= R->key + "\n";
    
    //left
    preOrderString(s, R->left);
    
    //right
    preOrderString(s, R->right);
  
  }

}

//copy
void Dictionary::preOrderCopy(Node *R){

  if(R!= nullptr ){
    
    //printf("copy in key %s\n", R->key.c_str());
    setValue(R->key, R->val);
    
    preOrderCopy(R->left);
  
    preOrderCopy(R->right);
    
  }

}

//delete in post order
void Dictionary::postOrderDelete(Node* R){

  if(R != nullptr){
  
    postOrderDelete(R->left);
    
    postOrderDelete(R->right);
    
    delete R; 
  
  }
  
}

//search for a key
Dictionary::Node* Dictionary::search(Node* R, keyType k) const{

  //if(R == nullptr){
  
    //return nullptr;
  
  //}

  if(R == nullptr || k == R->key){
  
    return R;
    
  }else if(k < R->key){
  
    return search(R->left, k);
  
  }else{
  
    return search(R->right, k); 
  
  }
  
  //return nullptr;

}

//find min
Dictionary::Node* Dictionary::findMin(Node* R){
  
  //if tree rooted at R is empty, return nil
  //if(R->left == nullptr && R->right == nullptr){
  
    //return nullptr;
  
  //}
  
  //else, search for min
  while(R->left != nullptr){
  
    R = R->left;
  
  }
  
  return R;

}

//find max
Dictionary::Node* Dictionary::findMax(Node* R){

  //if tree rooted at R is empty, return nil
  //if(R->left == nullptr && R->right == nullptr){
  
    //return nullptr;
  
  //}
  
  //else search for max
  while(R->right != nullptr){
  
    R = R->right;
  
  }
  
  return R;

}

//find next in order
Dictionary::Node* Dictionary::findNext(Node* N){
  
  if(N->right != nullptr){
  
    return findMin(N->right);
  
  }
  
  Node *y = N->parent;
  
  while(y != nullptr && N == y->right){
  
    N = y;
    
    y = y->parent;
  
  }
  
  return y;
  
}

//find prev in order
Dictionary::Node* Dictionary::findPrev(Node* N){
  
  if(N->left != nullptr){
  
    return findMax(N->left);
  
  }
  
  Node *y = N->parent;
  
  while(y != nullptr && N == y->left){
  
    N = y;
    
    y = y->parent;
  
  }
  
  return y;
  
}


// Class Constructors & Destructors -------------------------------------------

// Creates a new dict in the empty state.
Dictionary::Dictionary(){

  nil = nullptr;

  root = nil;
  
  current = root; 
  
  num_pairs = 0;

}

//copy
Dictionary::Dictionary(const Dictionary& D){
  
  this->nil = nullptr;
  
  this->root = nil;
  
  this->num_pairs = 0;
  
  this->current = this->root;
  
  //printf("started copy\n");
  
  
  preOrderCopy(D.root);

}


//delete
Dictionary::~Dictionary(){

  if(num_pairs != 0){
  
    postOrderDelete(root);
    
  }

}

// Class Functions -------------------------------------------

//size
int Dictionary::size() const{

  return num_pairs;

}

//if exists
bool Dictionary::contains(keyType k) const{

  if(search(root, k) == nullptr){
  
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
  
  if(current != nullptr){
  
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
  
  root = nullptr;
  
  current = root;
  
}

//insert or override 
void Dictionary::setValue(keyType k, valType v){

  //if nothing in tree, insert root
  //if(root == nullptr){
  
    //root = new Node(k, v);
    
    //num_pairs++;
  
  //if the tree isnt empty
  //}else{
    
    //search if K already exists in tree
    Node *n = search(root, k);
  
    //if k exists, override
    if(n != nullptr){
  
      n->key = k;
    
      n->val = v;
      
    //else insert
    }else{
      
      //create node to insert
      Node *z = new Node(k , v);
      
      //increment stats
      //printf("k = %s\n", k.c_str());
      //printf("adding a pair to current pairs, %d\n", num_pairs);
      num_pairs++;
      
      Node *y = nullptr;
      
      Node *x = root;
      
      while(x != nullptr){
      
        y = x;
        
        if(k < x->key){
        
          x = x->left;
        
        }else{
        
          x = x->right;
        
        }
      
      }
      
      z->parent = y;
      
      if(y == nullptr){
      
        root = z;
      
      }else if(z->key < y->key){
      
        y->left = z;
      
      }else{
      
        y->right = z;
      
      }
    
    }
  
  //}

}

void Dictionary::remove(keyType k ){

  num_pairs--;

  Node *z = search(root, k);
  //printf("searched\n");
  
  if(z == current){
    
    //printf("current deleted\n");
    current = nullptr;
  
  }
  
  if(z->left == nullptr){
    
    //printf("left\n");
    transplant(z, z->right);

    delete z;
  
  }else if(z->right == nullptr){
    //printf("right\n");
    transplant(z, z->left);

    delete z;
  
  }else{

    Node *y = findMin(z->right);

    //printf("min key is %s\n", y->key.c_str() );
    
    //printf("transplanted\n");
    
    if(y->parent != z){
    
      printf("if\n");
      
      transplant(y, y->right);

      y->right = z->right;
      
      y->right->parent = y;
    
    }
    //printf("after if\n");

    transplant(z, y);

    y->left = z->left;
    
    y->left->parent = y;
    
    delete z;

  }

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





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

  if(R == nullptr){
  
    return nullptr;
  
  }

  if(k == R->key){
  
    return R;
    
  }else if(k < R->key){
  
    return search(R->left, k);
  
  }else{
  
    return search(R->left, k); 
  
  }
  
  return nullptr;

}

//find min
Dictionary::Node* Dictionary::findMin(Node* R){
  
  //if tree rooted at R is empty, return nil
  if(R->left == nullptr && R->right == nullptr){
  
    return nullptr;
  
  }
  
  //else, search for min
  while(R->left != nullptr){
  
    R = R->left;
  
  }
  
  return R;

}

//find max
Dictionary::Node* Dictionary::findMax(Node* R){

  //if tree rooted at R is empty, return nil
  if(R->left == nullptr && R->right == nullptr){
  
    return nullptr;
  
  }
  
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


// Class Constructors & Destructors -------------------------------------------

// Creates a new dict in the empty state.
Dictionary::Dictionary(){

  nil = nullptr;

  root = nil;
  
  current = root; 
  
  num_pairs = 0;

}

//delete
Dictionary::~Dictionary(){

  if(num_pairs != 0){
  
    postOrderDelete(root);
    
  }

}

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


//insert or override 
void Dictionary::setValue(keyType k, valType v){

  //if nothing in tree, insert root
  if(root == nullptr){
  
    root = new Node(k, v);
  
  //if the tree isnt empty
  }else{
    
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
  
  }

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

std::ostream& operator<<( std::ostream& stream,  Dictionary& D ) {

   return stream << D.to_string();
   
}




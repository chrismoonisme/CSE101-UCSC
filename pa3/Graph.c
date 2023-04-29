//Christopher Moon
//ckmoon
//pa3

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "List.h"
#include "Graph.h"

//def graph
typedef struct GraphObj{
  
  //adj lists
  List *neighbors;
  
  //vertex attributes
  int *color;
  
  int *parents;
  
  //int *distance;
  
  int *discover;
  
  int *finish;

  //graph stats
  int order;
  
  int edges;
  
  //int vertex;
  

}GraphObj;

//constructor
Graph newGraph(int n){
  
  //allocate for graph
  Graph g = malloc( sizeof(GraphObj) );
  
  if(g){
    
    //allocate for array of lists
    g->neighbors = malloc(sizeof(List*) * (n+1));
    
    for(int i = 0; i < n+1; i++){
      
      //allocate for each list inside the array
      g->neighbors[i] = newList();
    
    }
    
    //allocate for array of colors
    g->color = malloc(sizeof(int*) * (n+1));
    
    //allocate for array of parents
    g->parents = malloc(sizeof(int*) * (n+1));
    
    for(int i = 0; i < n+1; i++){
    
      g->parents[i] = NIL;
    
    }
    
    //allocate for array of distances
    //g->distance = malloc(sizeof(int*) * (n+1));
    
    //for(int i = 0; i < n+1; i++){
    
      //g->distance[i] = INF;
    
    //}
    
    //allocate for array of discovery times
    g->discover = malloc(sizeof(int*) * (n+1));
    
    for(int i = 0; i < n+1; i++){
    
      g->discover[i] = UNDEF;
    
    }
    
    //allocate for array of finishing times
    g->finish = malloc(sizeof(int*) * (n+1));
    
    for(int i = 0; i < n+1; i++){
    
      g->finish[i] = UNDEF;
    
    }
    
    
    //initialize stats
    g->order = n;
    
    g->edges = 0;
    
    //g->vertex = NIL;
    
  
  }else{
  
    free(g);
    
    g = NULL;
  
  }
  
  return g;

}

//delete graph
void freeGraph(Graph *pG){
  
  //free array of lists
  for(int i = 0; i < (*pG)->order+1; i++){
      
      //allocate for each list inside the array
      freeList( &(*pG)->neighbors[i] );
    
  }
  
  free((*pG)->neighbors);
  
  (*pG)->neighbors = NULL;
  
  //free int arrays
  free((*pG)->color);
  
  (*pG)->color = NULL;
  
  free((*pG)->parents);
  
  (*pG)->parents = NULL;
  
  //free((*pG)->distance);
  
  //(*pG)->distance = NULL;
  
  free((*pG)->discover);
  
  (*pG)->discover = NULL;
  
  free((*pG)->finish);
  
  (*pG)->finish = NULL;
  
  //free entire struct
  free(*pG);
  
  *pG=NULL;

}

//get order
int getOrder(Graph G){

  if( G==NULL ){
  
      printf("error calling on NULL graph reference\n");
      
      exit(1);
  }
  
  return G->order;

}

//get edges
int getSize(Graph G){

  if( G==NULL ){
  
      printf("error calling on NULL graph reference\n");
      
      exit(1);
  }
  
  return G->edges;

}

//get vertex
//int getSource(Graph G){

  //if( G==NULL ){
  
      //printf("error calling on NULL graph reference\n");
      
      //exit(1);
  //}
  
  //return G->vertex;

//}

//get parent of u
int getParent(Graph G, int u){

  if( G==NULL ){
  
      printf("error calling on NULL graph reference\n");
      
      exit(1);
  }
  
  if( 1 <= u && u <= getOrder(G)){
  
    return G->parents[u];
  
  }else{
    
    printf("prereq failure\n");  
    exit(1);
  
  }

}

int getDiscover(Graph G, int u){

  if( G==NULL ){
  
      printf("error calling on NULL graph reference\n");
      
      exit(1);
  }
  
  if( 1 <= u && u <= getOrder(G)){
  
    return G->discover[u];
  
  }else{
  
    exit(1);
  
  }

}

int getFinish(Graph G, int u){

  if( G==NULL ){
  
      printf("error calling on NULL graph reference\n");
      
      exit(1);
  }
  
  if( 1 <= u && u <= getOrder(G)){
  
    return G->finish[u];
  
  }else{
  
    exit(1);
  
  }

}

//get distance 
//int getDist(Graph G, int u){

  //if( G==NULL ){
  
      //printf("error calling on NULL graph reference\n");
      
      //exit(1);
  //}
  
  //if( 1 <= u && u <= getOrder(G)){
  
    //return G->distance[u];
  
  //}else{
    
    //printf("getdist bounds failure\n");
    //exit(1);
  
  //}

//}

//bfs
//void BFS(Graph G, int s){

  //for(int x = 0; x < getOrder(G)+1; x++){
      
    //if(x != s){
    
      //1 = white
      //G->color[x] = 1;
      
      //G->distance[x] = INF;
      
      //G->parents[x] = NIL;
    
    //}
    
  //}
  
  //2 = gray
  //G->color[s] = 2;
  
  //G->distance[s] = 0;
  
  //G->parents[s] = NIL;
  
  //create empty list
  //List l = newList();
  
  //append s to the list
  //append(l, s);
  
  //int x;
  
  //int y;
  
  //while list isnt empty
  //while(length(l) > 0){
    
    //get value of front node
    //x = front(l);
    
    //delete the front node
    //deleteFront(l);
    
    
    //set cursor of vertex x's adjacency list to the first node
    //moveFront(G->neighbors[x]);
    
    //loop through nodes in x's list
    //for(int i = 0; i < length(G->neighbors[x]); i++){
      
      //get value of y
      //y = get(G->neighbors[x]);
      
      //if white
      //if(G->color[y] == 1){
      
        //G->color[y] = 2;
        
        //G->distance[y] = G->distance[x]+1;
        
        //G->parents[y] = x;
        
        //append(l, y);
      
      //}
      
      //move cursor over one
      //moveNext(G->neighbors[x]);
    
    //}
    
    //G->color[x] = 3;
  
  //}
  //G->vertex = s;
  //freeList(&l);
//}

//add edge
void addEdge(Graph G, int u, int v){
  
  addArc(G, u, v);
  
  addArc(G, v, u);
  
  G->edges--;

}

//add arc
void addArc(Graph G, int u, int v){

  if( G==NULL ){
  
      printf("error calling on NULL graph reference\n");
      
      exit(1);
  }
  
  //u and v must fall in the required range
  if( (1 <= u && u <= getOrder(G)) && (1 <= v && v <= getOrder(G)) ){
    
    //increase edges by 1
    G->edges++;
    
    //add v to the adjacency list of u
    //if u has nothing in its list, append v
    if(length(G->neighbors[u]) == 0){
      
      append(G->neighbors[u], v);
    
    //else, check if if v is the front element in the list, if so dont do anything cause its already in the list
    }else if(inList(G->neighbors[u], v) == false){
      
        moveFront(G->neighbors[u]);
      
        
        while(index(G->neighbors[u]) > -1 &&  get(G->neighbors[u]) < v ){
        
          moveNext(G->neighbors[u]);
          
          
        }
        
        if(index(G->neighbors[u]) != -1){
        
          insertBefore(G->neighbors[u], v);
        
        }else{
        
          append(G->neighbors[u], v);
        
        }
      
    }else{
    
      G->edges--;
    
    }
  
  }else{
    
    printf("add arc terminates due to bad u or v value\n");
    exit(1);
  
  }
  
}

//void getPath(List L, Graph G, int u){

  //if(getSource(G) == NIL){
    
    //printf("run BFS before running this function\n");
    //exit(1);
  
  //}
  
  //if( 1 <= u && u <= getOrder(G)){
  
    //if(u == getSource(G)){
    
      //append(L, getSource(G));
    
    
    //}else if(G->parents[u] == NIL){
    
      //append(L, NIL);
    
    
    //}else{
      
      //getPath(L, G, G->parents[u] );
      //append(L, u);
      
    //}
  
  //}else{
  
    //exit(1);
  
  //}
  
//}

//print a graph
void printGraph(FILE* out, Graph G){
  
  int val;
  
  for(int i = 1; i < getOrder(G)+1; i++){
    
    moveFront(G->neighbors[i]);
    fprintf(out, "%d: ", i);
    
    for(int j = 0; j< length(G->neighbors[i]); j++){
      
      val = get(G->neighbors[i]);
      
      fprintf(out, "%d ", val);
      
      moveNext(G->neighbors[i]);
    
    }
    
    //newline
    if(i != getOrder(G)){
    
      fprintf(out, "\n");
    
    }
  
  }

}

//void makeNull(Graph G){
  
  //int n = getOrder(G);
  
  //freeGraph(&G);
  
  //G = newGraph(n);

//}

Graph copyGraph(Graph G){

  //make new empty graph with same order as original 
  Graph g2 = newGraph(getOrder(G));
  
  //copy edges
  g2->edges = getSize(G);
  
  printf("edges duped\n");  
  
  //copy up adjacency lists
  for(int i = 0; i < getOrder(G)+1; i++){
  
    g2->neighbors[i] = copyList(G->neighbors[i]);
  
  }
  
  printf("adjs duped\n");  
  
  //copy parents
  for(int i = 1; i < getOrder(G)+1; i++){
  
    g2->parents[i] = getParent(G, i);
  
  }
  
  printf("parents duped\n");  
  
  //copy colors
  for(int i = 1; i < getOrder(G)+1; i++){
  
    g2->color[i] = G->color[i]; 
  
  }
  
  //copy discover time
  for(int i = 1; i < getOrder(G)+1; i++){
  
    g2->discover[i] = getDiscover(G, i);
  
  }
  
  //copy finish time
  for(int i = 1; i < getOrder(G)+1; i++){
  
    g2->finish[i] = getFinish(G, i);
  
  }
  
  return g2;
  
}

//return same order graph with adj lists reversed
Graph transpose(Graph G){
  
  //make new empty graph with same order as original 
  Graph g2 = newGraph(getOrder(G));
  
  //loop through adj lists
  for(int i =0; i<getOrder(G)+1; i++){
    
    //move to front of adj list of i
    moveFront(G->neighbors[i]);
    
    //if x is in y, then add y to x
    for(int j =0; j<length(G->neighbors[i]); j++){
      
      //x = get(G->parents[i])
      //y = G->parents[i] or i
      
      //(u,v) adds v to u
      addArc(g2, get(G->neighbors[i]), i);
      
      moveNext(G->neighbors[i]);
    
    }
  
  }

  return g2;

}

int visit(Graph G, int x, int t, List S){

  int time = t;
  
  time++;
  
  //printf("vertex %d discovered at time %d\n", x, time);
  
  
  //discover = time++;
  G->discover[x] = time;
  
  //color = gray
  G->color[x] = 2;
  
  //for all vertices in x's adj list
  moveFront(G->neighbors[x]);
  
  for(int y  = 0; y < length(G->neighbors[x]); y++){
  
    //printf("vertex adjacent to %d\n", get(G->neighbors[x]) );
    
    if(G->color[get(G->neighbors[x])] == 1){
    
      G->parents[get(G->neighbors[x])] = x;
      
      //printf("vertex has undiscovered child %d\n", y);
      
      time = visit(G, get(G->neighbors[x]), time, S);
    
    }
    
    moveNext(G->neighbors[x]);
  
  }
  
  G->color[x] = 3;
  
  time++;
  
  //printf("vertex %d finished at time %d\n", x, time);
  
  G->finish[x] = time;
  
  //update stack
  prepend(S, x);
  deleteBack(S);
  //moveNext(S);
  
  return time;


}


void DFS(Graph G, List S){
  
  //copy stack
  List temp = copyList(S);
  
  //printList(stdout, temp);
  
  //if stack doesnt contain the right number of vertices, terminate
  if(length(S) != getOrder(G) ){
  
    exit(1);
    
  }
  
  //for all vertices, in order of the stack
  moveFront(S);

  for(int x = 0;  x<length(S); x++){
    
    //set to white
    //white = 1
    G->color[get(S)] = 1;
    
    //parent set to nil
    G->parents[get(S)] = NIL;
    
    moveNext(S);

  }
  
  //set time to 0;
  int time = 0;
  
  //for all vertices, in order of stack
  moveFront(temp);
  
  moveFront(S);
  
  for(int x = 0; x<length(temp); x++){
    
    //if white
    if(G->color[get(temp)] == 1){
      
      //visit y
      time = visit(G, get(temp), time, S);
    
    
    }
    
    moveNext(temp);
    
  
  }


}

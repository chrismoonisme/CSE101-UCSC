//Christopher Moon
//ckmoon
//pa3

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#include"List.h"
#include"Graph.h"


int main(int argc, char** argv){

  //files
  FILE *infile; 
  FILE *outfile; 
  
  //make sure 2 args
  if(argc != 3){
  
    printf("2 arguments not given\n");
    
    exit(1);
    
  }
  
  //open files
  infile = fopen(argv[1], "r");
  
  outfile = fopen(argv[2], "w");
  
  //check if files are valid
  if(infile==NULL || outfile==NULL){
  
    printf("bad files\n");
    
    exit(1);
    
  }
  
  //get order value, n
  int n;
  
  fscanf(infile, "%d", &n);
  
  //make graph and stack
  Graph g = newGraph(n);
  
  List s = newList();

  //loop through rest of stuff
  int v1;
  
  int v2;
  
  
  while(fscanf(infile, "%d %d", &v1, &v2) != EOF){
    
    if( (v1 != 0 && v2 != 0) ){
    
      addArc(g, v1, v2);

    
    }
    
  }
  
  //set up stack
  for(int i = 1; i <n+1; i++){
  
    append(s,i);
  
  }
  
  //printList(outfile, s);
  
  fprintf(outfile, "Adjacency list representation of G:\n");
  
  printGraph(outfile, g);
  
  //get transpose
  Graph t = transpose(g);
  
  //run dfs on g
  DFS(g, s);
  
  //printList(outfile, s);
  
  //run dfs on t
  DFS(t, s);
  
  //find scc
  
  //component toggle
  int toggle = 0;
  
  //component tracker
  int c = 0;
  
  //create temp list to hold current components
  List temp = newList();
  
  //loop through stack
  moveFront(s);
  
  for(int i = 0; i < length(s); i++){
  
    //printf("checking %d\n", get(s));
  
    //terminate a current component
    if(toggle == 1 && getParent(t, get(s)) == NIL){
    
      toggle = 0;
      
      append(temp, 0);
      
    }
    
    //start component if not in a component already
    if(toggle == 0 && getParent(t, get(s)) == NIL){
      
      //printf("%d is the start of a new component\n", get(s));
      toggle = 1;
      c++;
    
    }
    
    //if in a component, append vertex to temp list
    if(toggle == 1){
    
      append(temp, get(s));
      
    }
    
    moveNext(s);
  
  }
  
  //flush remaining vertices 
  append(temp, 0);
  
  //print components
  List p = newList();
  fprintf(outfile, "\n\n");
  fprintf(outfile, "G contains %d strongly connected components:\n", c);
  
  toggle = 0;
  int j = 0;
  moveBack(temp);
  
  for(int i = 0; i < length(temp); i++){
    
    if(toggle == 1 && get(temp) == 0){
      
      fprintf(outfile, "Component %d: ", j);
      printList(outfile, p);
      
      fprintf(outfile, "\n");
      
      clear(p);
      
      toggle = 0;
    
    }
  
    
    if(toggle == 0 && get(temp) == 0){
    
      toggle = 1;
      j++;
    
    }
    
    if(toggle == 1 && get(temp) != 0){
    
      prepend(p, get(temp) );
    
    }
    movePrev(temp);
  
  
  }
  
  //fprintf(outfile, "\n");
  fprintf(outfile, "Component %d: ", j);    
  printList(outfile, p);
  
  
  
  
  
  freeList(&s);
  freeList(&p);
  freeList(&temp);
  freeGraph(&g);
  freeGraph(&t);
  fclose(infile);
  fclose(outfile);

  


  return 0;

}

//Christopher Moon
//ckmoon
//pa1

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#include"List.h"
#define MAX_LEN 300

int main(int argc, char** argv){

  //file pointers
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

  //count lines of infile
  
  char buf[300];
  
  int n = 0;
  
  while(fgets(buf, 300, infile) != NULL){
      	
    n++;
  
  }
  
  //printf("number of lines is %d\n", n);
  
  //create string array of length n
  char **arr = malloc( sizeof(char *) * n);
  
  
  //infile reset
  fclose(infile);
  infile = fopen(argv[1], "r");

  //read in lines of infile into string array
  int lines = 0;
  
  while(fgets(buf, 300, infile) != NULL){
    
    //printf("buf value is %s\n", buf);
    
    arr[lines] = (char*)malloc(strlen(buf) +1);
    
    strcpy(arr[lines], buf);
    
    //buf = buf[300];
    lines++;
    
  }
  
  //printf("string array is %s\n", arr[0]);
  
  //printf("string array is %s\n", arr[1]);
  
  //printf("string array is %s\n", arr[2]);
  
  //printf("string array is %s\n", arr[3]);
  
  //create list
  List l = newList();

  //sort?
  for (int i = 0; i < n; i++){
  
    moveBack(l);
    
    while(index(l) >-1 && strcmp(arr[i], arr[get(l)]) < 0){
      
      movePrev(l);
      
    }
    
    if(index(l) > -1){
    
      insertAfter(l, i);
      
    }else{
    
      prepend(l, i);
      
    }
    
  }

  //output
  
  moveFront(l);
  
  while (index(l) > -1){
  
    fprintf(outfile, "%s", arr[get(l)]);
    
    moveNext(l);
    
  }
  
  //free arr
  for(int i=0; i<n; i++){
  
    free(arr[i]);
    
    arr[i] = NULL;
  
  }
  
  
  free(arr);
  arr=NULL;

  // free list
  freeList(&l);

  // close files
  fclose(infile);
  
  fclose(outfile);

  return 0;

}

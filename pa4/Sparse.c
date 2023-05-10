//Christopher Moon
//ckmoon
//pa4

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#include"List.h"
#include"Matrix.h"


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
  
  //get lines
  int a;
  
  int b;
  
  fscanf(infile, "%d %d %d", &n, &a, &b);
  
  int row;
  
  int col;
  
  double val;
  
  //make empty matrix a
  Matrix A = newMatrix(n);
  
  //collect values for a
  for(int i = 0; i < a; i++){
  
    fscanf(infile, "%d %d %lf", &row, &col, &val);
    
    changeEntry(A, row, col, val);
    
  }
  
  
  //make empty matrix b
  Matrix B = newMatrix(n);
  
  //collect values for a
  for(int i = 0; i < b; i++){
  
    fscanf(infile, "%d %d %lf", &row, &col, &val);
    
    changeEntry(B, row, col, val);
    
  }
  
  fprintf(outfile, "A has %d non-zero entries:\n", NNZ(A));
  
  printMatrix(outfile, A);
  
  fprintf(outfile, "\n");
  
  fprintf(outfile, "B has %d non-zero entries:\n", NNZ(B));
  
  printMatrix(outfile, B);
  
  fprintf(outfile, "\n");
  
  
  fprintf(outfile, "(1.5)*A =\n");
  
  Matrix scalar = scalarMult(1.5, A);
  
  printMatrix(outfile, scalar);
  
  fprintf(outfile, "\n");
  
  
  fprintf(outfile, "A+B =\n");
  
  Matrix add = sum(A, B);
  
  printMatrix(outfile, add);
  
  fprintf(outfile, "\n");
  
  
  fprintf(outfile, "A+A =\n");
  
  Matrix add2 = sum(A, A);
  
  printMatrix(outfile, add2);
  
  fprintf(outfile, "\n");
  
  fprintf(outfile, "B-A =\n");
  
  Matrix sub = diff(B, A);
  
  printMatrix(outfile, sub);
  
  fprintf(outfile, "\n");
  
  fprintf(outfile, "A-A =\n");
  
  fprintf(outfile, "\n");
  
  
  fprintf(outfile, "Transpose(A) =\n");
  
  Matrix t = transpose(A);
  
  printMatrix(outfile, t);
  
  fprintf(outfile, "\n");
  
  
  fprintf(outfile, "A*B =\n");
  
  Matrix mul = product(A, B);
  
  printMatrix(outfile, mul);
  
  fprintf(outfile, "\n");
  
  
  fprintf(outfile, "B*B =\n");
  
  Matrix mul2 = product(B, B);
  
  printMatrix(outfile, mul2);
  
  fprintf(outfile, "\n");
  
  
  
  freeMatrix(&A);
  
  freeMatrix(&B);
  freeMatrix(&scalar);
  freeMatrix(&add);
  freeMatrix(&add2);
  freeMatrix(&sub);
  freeMatrix(&t);
  freeMatrix(&mul);
  freeMatrix(&mul2);
  
  fclose(infile);
  fclose(outfile);

  return 0;
  


}


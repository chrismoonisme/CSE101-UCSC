//-----------------------------------------------------------------------------
//  MatrixClient.c 
//  A test client for the Matrix ADT
//-----------------------------------------------------------------------------
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include"Matrix.h"
     
int main(){

  //printf("start\n");

   //int n=100000;
   int n=10;
   
   Matrix A = newMatrix(n);
   Matrix B = newMatrix(n);
   
   Matrix X = newMatrix(n);
   //Matrix C, D, E, F, G, H;
   
   Matrix H, F, C, D, D2, x2, E, a2, G;
   
   changeEntry(A, 3,3,9); changeEntry(B, 3,3,1);

   changeEntry(A, 1,1,1); changeEntry(B, 1,1,1);
   
   //changeEntry(A, 1,1,3);
   
   changeEntry(A, 1,3,3); changeEntry(B, 1,3,1);
   
   changeEntry(A, 3,2,8); changeEntry(B, 3,2,1);
   
   changeEntry(A, 1,2,2); changeEntry(B, 1,2,0);
   //changeEntry(A, 1,3,3); changeEntry(B, 1,3,1);
   
   changeEntry(A, 2,3,6); changeEntry(B, 2,3,0);
   changeEntry(A, 2,1,4); changeEntry(B, 2,1,0);
   changeEntry(A, 2,2,5); changeEntry(B, 2,2,1);
  
   changeEntry(A, 3,1,7); changeEntry(B, 3,1,1);
  
   
   //changeEntry(B, 3,3,5);
    
  printf("non zero elements of A and B\n");
  
   printf("%d\n", NNZ(A));
   printMatrix(stdout, A);
   printf("\n");

   printf("%d\n", NNZ(B));
   printMatrix(stdout, B);
   printf("\n");
  
  printf("Scalar mult B\n");
   C = scalarMult(1.5, A);
   printf("%d\n", NNZ(C));
   printMatrix(stdout, C);
   printf("\n");
   
  printf("SUM A and B\n"); 
   D = sum(A, B);
   printf("%d\n", NNZ(D));
   printMatrix(stdout, D);
   printf("\n");
   
  printf("SUM A and A\n"); 
   D2 = sum(A, A);
   printf("%d\n", NNZ(D2));
   printMatrix(stdout, D2);
   printf("\n");
  
  
  printf("SUM X and X\n"); 
   changeEntry(X, 1, 1, 4);
    changeEntry(X, 1, 2, 2);
    changeEntry(X, 1, 3, 0);
    changeEntry(X, 2, 1, 2);
    changeEntry(X, 3, 1, 0);
    changeEntry(X, 2, 2, 2);
    changeEntry(X, 3, 3, 0);
    x2 = sum(X, X);
    
    printf("%d\n", NNZ(X));
   printMatrix(stdout, X);
   printf("\n");
    
    printf("%d\n", NNZ(x2));
   printMatrix(stdout, x2);
   printf("\n");
    

printf("diff a and b\n"); 
   E = diff(A, B);
   printf("%d\n", NNZ(E));
   printMatrix(stdout, E);
   printf("\n");

printf("equals tests\n"); 
  a2 = scalarMult(-2, A);
  Matrix As1 = diff(A, A);
  Matrix As2 = diff(As1, A);
  Matrix d = diff(As2, A);
  
  freeMatrix(&As1);
    freeMatrix(&As2);
    
  printMatrix(stdout, a2);
  
  printMatrix(stdout, d);
    
   freeMatrix(&d); 




  printf("Transpose B\n");
   F = transpose(B);
   printf("%d\n", NNZ(F));
   printMatrix(stdout, F);
   printf("\n");
   

   
  printf("Product BxB\n");
   G = product(B, B);
   printf("%d\n", NNZ(G));
   printMatrix(stdout, G);
   printf("\n");
   
   printf("Product BxA\n");
   G = product(B, A);
   printf("%d\n", NNZ(G));
   printMatrix(stdout, G);
   printf("\n");




  printf("copy A\n");
   H = copy(A);
   printf("%d\n", NNZ(H));
   printMatrix(stdout, H);
   printf("\n");


  printf("equals tests\n");
   printf("%s\n", equals(A, H)?"true":"false" );
   printf("%s\n", equals(A, B)?"true":"false" );
   printf("%s\n", equals(A, A)?"true":"false" );

  printf("Make zero A\n");
   makeZero(A);
   printf("%d\n", NNZ(A));
   printMatrix(stdout, A);



   freeMatrix(&A);
    freeMatrix(&a2);
   freeMatrix(&B);
   freeMatrix(&C);
   freeMatrix(&D);
   freeMatrix(&D2);
   freeMatrix(&E);
   freeMatrix(&F);
   freeMatrix(&G);
   freeMatrix(&H);
   freeMatrix(&X);
   freeMatrix(&x2);

   return EXIT_SUCCESS;
}

/*
Output of this program:
9
1: (1, 1.0) (2, 2.0) (3, 3.0)
2: (1, 4.0) (2, 5.0) (3, 6.0)
3: (1, 7.0) (2, 8.0) (3, 9.0)

6
1: (1, 1.0) (3, 1.0)
2: (2, 1.0)
3: (1, 1.0) (2, 1.0) (3, 1.0)

9
1: (1, 1.5) (2, 3.0) (3, 4.5)
2: (1, 6.0) (2, 7.5) (3, 9.0)
3: (1, 10.5) (2, 12.0) (3, 13.5)

9
1: (1, 2.0) (2, 2.0) (3, 4.0)
2: (1, 4.0) (2, 6.0) (3, 6.0)
3: (1, 8.0) (2, 9.0) (3, 10.0)

0

6
1: (1, 1.0) (3, 1.0)
2: (2, 1.0) (3, 1.0)
3: (1, 1.0) (3, 1.0)

7
1: (1, 2.0) (2, 1.0) (3, 2.0)
2: (2, 1.0)
3: (1, 2.0) (2, 2.0) (3, 2.0)

9
1: (1, 1.0) (2, 2.0) (3, 3.0)
2: (1, 4.0) (2, 5.0) (3, 6.0)
3: (1, 7.0) (2, 8.0) (3, 9.0)

true
false
true
0
*/

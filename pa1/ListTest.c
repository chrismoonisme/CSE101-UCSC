//Christopher Moon
//ckmoon
//pa1

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"List.h"

int main(int argc, char* argv[]){
   
   List A = newList();
   List B = newList();
   List C = NULL;
   int i;

   for(i=1; i<=20; i++){
      append(A,i);
      prepend(B,i);
   }
  
   printf("LIST A ");
   printList(stdout,A); 
   printf("\n");
   
   printf("LIST B ");
   printList(stdout,B); 
   printf("\n");

   for(moveFront(A); index(A)>=0; moveNext(A)){
      printf("%d ", get(A));
   }
   printf("\n");
   for(moveBack(B); index(B)>=0; movePrev(B)){
      printf("%d ", get(B));
   }
   printf("\n");
   
   printf("LIST A ");
   printList(stdout,A); 
   printf("\n");
   
   
   //printf("check");
   printf("FRONT OF A IS %d \n", front(A));
   
   printf("LIST B ");
   printList(stdout,B); 
   printf("\n");
   
   printf("FRONT OF B IS %d \n", front(B));
   
   C = copyList(A);
   
   printf("%s\n", equals(A,B)?"true":"false");
   
   printf("%s\n", equals(B,C)?"true":"false");
   
   printf("%s\n", equals(C,A)?"true":"false");


   moveFront(A);
   
   for(i=0; i<5; i++) moveNext(A); // at index 5
   
   //printf("done");
   insertBefore(A, -1);            // at index 6
   
   //printf("works\n");
   
   
   for(i=0; i<9; i++) moveNext(A); // at index 15
   insertAfter(A, -2);
   
   //printf("works\n");
   
   
   for(i=0; i<5; i++) movePrev(A); // at index 10
   delete(A);
   //printf("works\n");
   printList(stdout,A);
   printf("\n");
   
   printf("should be 21\n");
   printf("%d\n", length(A));
   //printf("works\n");
   
   clear(A);
   printf("should be 0\n");
   printList(stdout,A);
   printf("%d\n", length(A));

   freeList(&A);
   freeList(&B);
   freeList(&C);

   return(0);
}

/*
Output of this program:
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
false
false
true
1 2 3 4 5 -1 6 7 8 9 11 12 13 14 15 -2 16 17 18 19 20
21
0
*/

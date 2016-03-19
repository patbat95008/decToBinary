/* Patrick Russell pcrussel
//
// CMPS101 Program 1: decToBinary
//
// Usage: decToBinary [Number]
//        
//        Reads in a number from the standard input and 
//        converts it to binary.
*/


#include "intstack.h"
#include "myinclude.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main (int argc, char **argv){
   StackHndl *stack = NULL;
   stack = NewStack();
   int input = 0;
   /*Scan the input and if it is a number, continue*/
   if (scanf("%d", &input) != 1) {
      printf("Invalid Input. Please only use numbers.\n");
      return 1;
   }

   if (input == 0){
      /*push number onto stack, if it is only zero*/
      Push(stack, 0);
   }

   /*convert to binary*/
   while(input > 0){
      if(input%2 == 1){
         /*push 1 onto stack*/
         Push(stack, 1);
      }else{
         /*push 0 onto stack*/
         Push(stack, 0);
      }
      input = input / 2;
   }
   
   /*print stack*/
   while(!IsEmpty(stack)){
      printf("%d", Top(stack));
      Pop(stack);
   }
   
   printf("\n");
   return 0;
}

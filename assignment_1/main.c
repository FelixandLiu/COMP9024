/**
     main.c

     Program supplied as a starting point for
     Assignment 1: Transport card manager

     COMP9024 18s2
**/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#include "cardRecord.h"
#include "cardLL.h"

void printHelp();
void CardLinkedListProcessing();

int main(int argc, char *argv[]) {
   if (argc == 2) {
       int n = atoi(argv[1]);
       if (n<0) {
           printf("the single command line argument: %d is not a positive number",n);
           return 0;
       }
       cardRecordT *dynamic_array=  malloc(n * sizeof(cardRecordT));
       assert(dynamic_array != NULL);
       for (int i=0;i<n;i++) {
           dynamic_array[i].cardID=readValidID();
           dynamic_array[i].balance=readValidAmount();
       }
       for (int j=0;j<n;j++) {
           printCardData(dynamic_array[j]);
       }
       printf("Number of cards on file: %d\n",n);
       float total_amount=0;
       for (int k=0;k<n;k++) {
           total_amount +=dynamic_array[k].balance;
       }
       if (total_amount>=0){
           printf("Average balance: $%.2f\n",total_amount/n);
       }
       else{
           printf("Average balance: -$%.2f\n",-(total_amount/n));
       }
       free(dynamic_array);
      /*** Insert your code for stage 1 here ***/
      
   } else {
      CardLinkedListProcessing();
   }
   return 0;
}

/* Code for Stages 2 and 3 starts here */

void CardLinkedListProcessing() {
   int op, ch;
   int cardID;
   float amount;
   int n;
   float balance;


   List list = newLL();   // create a new linked list
   
   while (1) {
      printf("Enter command (a,g,p,q,r, h for Help)> ");

      do {
	 ch = getchar();
      } while (!isalpha(ch) && ch != '\n');  // isalpha() defined in ctype.h
      op = ch;
      // skip the rest of the line until newline is encountered
      while (ch != '\n') {
	 ch = getchar();
      }

      switch (op) {

         case 'a':
         case 'A':
         cardID= readValidID();
         amount= readValidAmount();
         insertLL(list,cardID,amount);
            /*** Insert your code for adding a card record ***/

	    break;

         case 'g':
         case 'G':
         getAverageLL(list, &n, &balance);
         printf("Number of cards on file: %d\n",n);
         if (balance>=0) {
             printf("Average balance: $%.2f\n",balance);
         }
         else{
             printf("Average balance: -$%.2f\n",-balance);
         }
            /*** Insert your code for getting average balance ***/

	    break;
	    
         case 'h':
         case 'H':
            printHelp();
	    break;
	    
         case 'p':
         case 'P':
         showLL(list);
            /*** Insert your code for printing all card records ***/

	    break;

         case 'r':
         case 'R':
         cardID=readValidID();
         removeLL(list, cardID);
            /*** Insert your code for removing a card record ***/

	    break;

	 case 'q':
         case 'Q':
            dropLL(list);       // destroy linked list before returning
	    printf("Bye.\n");
	    return;
      }
   }
}

void printHelp() {
   printf("\n");
   printf(" a - Add card record\n" );
   printf(" g - Get average balance\n" );
   printf(" h - Help\n");
   printf(" p - Print all records\n" );
   printf(" r - Remove card\n");
   printf(" q - Quit\n");
   printf("\n");
}

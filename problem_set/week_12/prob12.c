#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NTOSSES 20
/*
void main(void){
   srand(time(NULL));
   int index_arr[5];
   int i, count = 0;
   for (i=0;i<6;i++){
      index_arr[i]=0;
   }
   for (i=0; i<NTOSSES; i++) {
      int toss = rand() % 6; 
      printf("%d",toss+1);
      index_arr[toss]++;
   }
   printf("\nCounts = {%d,%d,%d,%d,%d,%d}\n",
   index_arr[0],index_arr[1],index_arr[2],
   index_arr[3],index_arr[4],index_arr[5]);
}

void main(void){
   char list_str[]="hippopotamus";
   srand(time(NULL));
   printf("%c",list_str[rand()%12]);
}
*/

void d(int length,int seed){
   int n=0;
   srand(seed);
   char *alphabet="abcdefghijklmnopkrstuvwxyz";
   while (n<length){
      printf("%c",alphabet[(rand()%26)]);
      n++;
   }
   printf("\n");
}
void main(int argc, char *argv[]){
   d(atoi(argv[1]),atoi(argv[2]));
}
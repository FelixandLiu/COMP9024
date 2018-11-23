#include <stdlib.h>
#include <stdio.h>
void main(void){
int answer;
printf("address of k is %p\n", &answer);
printf("address of k is %d\n", answer);
printf("Enter your answer: ");
scanf("%d", &answer);
printf("address of k is %p\n", &answer);
printf("address of k is %d\n", answer);
}
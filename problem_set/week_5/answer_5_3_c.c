#include <stdio.h>
#include <string.h>

int isPalindrome(char A[], int len) {
   int i = 0;
   int j = len-1;

   while (i < j) {
      if (A[i] != A[j])
	 return 0;
      i++;
      j--;
   }
   return 1;
}

int main(int argc, char *argv[]) {
   if (argc == 2) {
      if (isPalindrome(argv[1], strlen(argv[1])))
	 printf("yes\n");
      else
	 printf("no\n");
   }
   return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int agrc, char *agrv[]){
    if (agrc==2) {
        int i;
        int j=0;
        char *reverse_word=malloc(sizeof(agrv[1]));
        int len=strlen(agrv[1]);
    for (i=len-1;i>=0;i--){
        reverse_word[len-i-1]=agrv[1][i];
    }
    printf("%s%s\n",reverse_word,agrv[1]);
    char *p1=reverse_word;
    char *p2=agrv[1];
    if (strcmp(p1, p2)==0){
        printf("yes\n");
    }
    else{
        printf("no\n");
    }
    free(reverse_word);
    return 0;
    }
    
}
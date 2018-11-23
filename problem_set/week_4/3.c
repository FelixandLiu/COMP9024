#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
void fib(int,int *);
void main(int agrc, char *agrv[]){
    int n;
    if (agrc==2){
        n=atoi(agrv[1]);
    }
    unsigned long long int  *arra=malloc(n*sizeof( unsigned long long int  ));
    assert(arra!=NULL);
    arra[1]=1;
    arra[2]=2;
    
    int i;
    for (i=3;i<n;i++){
        arra[i]=arra[i-1]+arra[i-2];
    }
    printf("%llu\n",arra[n-1]);
    free(arra);
}

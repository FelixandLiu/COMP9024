#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "WGraph.h"
//#include "stack.h"
#include <string.h>
//#include "WGraph.c"
//#include "stack.c"
void sub_setofdivisor(Graph, int *, int *, int , int, int,int *, int );
void sub_setofdivisor(Graph g, int set_of_divisor[], int set[], int n, int max, int index,int subset[], int i){
   if (index == max) {
      int a=0;
      for (int j = 0; j < max-1; j++){
         if (adjacent(g,subset[j],subset[j+1])){
            a++;
         }
      }
      if (a==max-1){
         for (int j = 0; j < max-1; j++){
            printf("%d < ",set_of_divisor[subset[j]]);
         }
         printf("%d\n",set_of_divisor[subset[max-1]]);
      }
        return;
    }
    if (i >= n)
        return;
    subset[index] = set[i];
    sub_setofdivisor(g, set_of_divisor, set, n, max, index + 1, subset, i + 1);
    sub_setofdivisor(g, set_of_divisor, set, n, max, index, subset, i + 1);
}
/*
int no_out_point(int, Graph);
int no_out_point(int end, Graph g){
   for (int i=0;i<g->nV;i++){
      if (adjacent(g,end,i)){
         return 0;
      }
   }
   return 1;
}
*/
//////////////////////___________
void floydAPSP(Graph,int *);
void floydAPSP(Graph g,int *set_of_divisor){
   int V=numOfVertices(g);
   int dist[V][V];
   int path[V][V];
   for (int i=0;i<V;i++){
      dist[i][i]=0;
      for (int j=0;j<V;j++){
         if (i!=j){
            if (adjacent(g,i,j)){
               dist[i][j]=adjacent(g,i,j);
               path[i][j]=j;
            }
            else{
               dist[i][j]=-9999;
               path[i][j]=-1;
            }
         }
      }
   }

   for (int i=0;i<V;i++){
      for (int j=0;j<V;j++){
         for (int k=0;k<V;k++){
            if ( dist[j][i] + dist[i][k] > dist[j][k]){
               dist[j][k]=dist[j][i] + dist[i][k];
               path[j][k]=path[j][i];
            }
         }
      }
   }
   int max=0;
   for (int i=0;i<V;i++){
      for (int j=i+1;j<V;j++){
         if (dist[i][j]>max){
            max=dist[i][j];
         }
      }
   }
   /*
   int index=max;
   int longest_path[index+1];
   for (int i=0;i<V;i++){
      for (int j=i+1;j<V;j++){
         if (dist[i][j]==max){
            longest_path[index]=j;
            int v=j;
            while(v!=path[i][v]){
               v=path[i][v];
               index--;
               longest_path[index]=v;
            }
            longest_path[index-1]=i;
         } 
      }
   }
   */
   int subset[max+1];
   int set[numOfVertices(g)];
   for(int i=0;i<numOfVertices(g);i++){
      set[i]=i;
   }
   printf("Longest monotonically increasing sequences:\n");
   sub_setofdivisor(g, set_of_divisor, set, numOfVertices(g), max+1, 0,subset,0);
   /*
   for (int i=0; i<max;i++){
      printf("%d < ",set_of_divisor[longest_path[i]] );
   }
   printf("%d ",set_of_divisor[longest_path[max]] );
   */
}
///////////////////____through stack to caculate
/*
void show_longest_sequence(Graph, int *);
void show_longest_sequence(Graph g, int *set_of_divisor){
   //printf("Longest monotonically increasing sequences:\n");
   int vistied[g->nV];
   for (int i=0;i<g->nV;i++){
      vistied[i]=-1;
   }
   stack s=newStack();
   vistied[0]=0;
   for (int i=0;i<g->nV;i++){
      StackPush(s,i);
      while (!StackIsEmpty(s)){
         int start=StackPop(s);
         for (int j=g->nV-1;j>0;j--){
            if (adjacent(g,start,j) ){
               StackPush(s,j);
               vistied[j]=start;
            }
         }
      }
   }
   for (int i=0;i<g->nV;i++){
      printf(" %d ",vistied[i]) ;
   }
   printf("\n");
   dropStack(s);
}
*/
//////////////////////////////
int all_digits_included(int , int );
int all_digits_included(int x,int y){
   char str_x[10], str_y[10];
   sprintf(str_x,"%d",x);
   sprintf(str_y,"%d",y);
   int number_same=0;
   for (int i=0;i<strlen(str_x);i++){
      for (int j=0;j<strlen(str_y);j++){
         if (str_x[i]==str_y[j]){
            number_same++;
            break;
         }
      }
   }
   //printf("%s\n%s\n%d\n%d\n",str_x,str_y,number_same,strlen(str_x));
   if (number_same==strlen(str_x)){
      //printf("%s\n%s\n%d\n",str_x,str_y,strlen(str_y));
      return 1;
   }
   return 0;
}

int main(int argc, char *argv[]){
   if (argc==2){
      int p = atoi(argv[1]);
      if (p<1 || p>2147483647){
         printf("the input of %d in the command line argument is not correct ",p);
         return 0;
      }
      int set_of_divisor[1000];
      int i=1;
      int j=0;
      while (i<=p/2){
         if (p%i==0){
            set_of_divisor[j]=i;
            j++;
         }
         i++;
      }
      set_of_divisor[j]=p;
      int V=j+1;
      Graph g=newGraph(V);
      for (int i=0;i<V;i++){
         for (int j=i+1;j<V;j++){
            if (set_of_divisor[j] % set_of_divisor[i]==0 
            && all_digits_included(set_of_divisor[i],set_of_divisor[j])){
               Edge e;
               e.v=i;
               e.w=j;
               e.weight=1;
               insertEdge(g, e);
            }
         }
      }
      showGraph(g,set_of_divisor);
      printf("\n");
      //show_longest_sequence(g,set_of_divisor);
      floydAPSP(g,set_of_divisor);
      freeGraph(g);
   }
   
}

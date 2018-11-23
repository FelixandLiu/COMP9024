/*Task A: Time complexity: O((n*m)^2)
          Explanation:  1. the input of number is p, the number n of divisors of p, the length m of the decimal p
                        2. use a 'for loop' get the specific divisor set.
                        3. transfer two divisors into string, then use two 'for loop's to 
                           determine if the two divisors satisfy the rule of partial order.
                        4. use graph matrix representation to get the partial order graph. 
                        5. print the partial order graph.
  Task B: Time complexity: O(n^k+n^3)
          Explanation:  1. use floydAPSP method to get k, which is numbers of divisors in the longest path, 
                           and the n should be the size of divisor_set.
                        2. use Pascal’s Identity method to get all possble subsets given k within the divisor_set.
                        3. determine if each subset is monotonically increasing sequences.
                        4. output all longest monotonically increasing sequences
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "WGraph.h"

void sub_setofdivisor(Graph, int *, int *, int , int, int,int *, int );
void floydAPSP(Graph,int *);
int all_digits_included(int , int );
//O(n^k)
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

void floydAPSP(Graph g,int *set_of_divisor){
   int V=numOfVertices(g);
   int dist[V][V];
   int path[V][V];
   // O(n^2)
   for (int i=0;i<V;i++){
      dist[i][i]=0;
      for (int j=0;j<V;j++){
         if (i!=j){
            if (adjacent(g,i,j)){
               dist[i][j]=adjacent(g,i,j);
               path[i][j]=j;
            }
            else{
               dist[i][j]=-99999999;
               path[i][j]=-1;
            }
         }
      }
   }
    // O(n^3)
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
   // O(n^2)
   for (int i=0;i<V;i++){
      for (int j=i+1;j<V;j++){
         if (dist[i][j]>max){
            max=dist[i][j];
         }
      }
   }
   int subset[max+1];
   int set[numOfVertices(g)];
   for(int i=0;i<numOfVertices(g);i++){
      set[i]=i;
   }
   printf("Longest monotonically increasing sequences:\n");
   sub_setofdivisor(g, set_of_divisor, set, numOfVertices(g), max+1, 0,subset,0);
}

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
   if (number_same==strlen(str_x)){
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
      /*task A: */
      int set_of_divisor[1000];
      int i=1;
      int j=0;
      // O(n)
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
      // O((n*m)^2)
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
      // O(n)
      showGraph(g,set_of_divisor);
      printf("\n");

      /*task B: */
      floydAPSP(g,set_of_divisor);
      freeGraph(g);
   }
}

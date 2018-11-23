#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Graph.h"

int main(void){
    int number_vertices,i,j,k;
    Edge e;
    
   
    printf("Enter the number of vertices: ");
    scanf("%d",&number_vertices);
    Graph g=newGraph(number_vertices);
    int nV = numOfVertices(g);
    printf("Enter an edge (from): ");
    while( scanf("%d",&e.v)==1){
        printf("Enter an edge (to): ");
        scanf("%d",&e.w);
        insertEdge(g,e);   
        printf("Enter an edge (from): ");
    } 
    printf("Finished.\n");
    int vertice_degree[100]; 
    for (i=0;i<nV;i++){
        vertice_degree[i]=0;
    }
    for (i=0;i<nV;i++){
        for (j=0;j<nV;j++){
            if (adjacent(g,i,j)){
                vertice_degree[i]=vertice_degree[i]+1;
            }
        }
    }
    int min=vertice_degree[0];
    int max=vertice_degree[0];
    for (i=1;i<nV;i++){
        if (vertice_degree[i]>max){
            max=vertice_degree[i];
        }
        if (vertice_degree[i]<min){
            min=vertice_degree[i];
        }
    }
    printf("Minimum degree: %d\n",min);
    printf("Maximum degree: %d\n",max);
    printf("Nodes of minimum degree:\n");
    for (i=0;i<nV;i++){
        if (vertice_degree[i]== min){
            printf("%d\n",i);
        }
    }
    printf("Nodes of maximum degree:\n");
    for (i=0;i<nV;i++){
        if (vertice_degree[i]==max){
            printf("%d\n",i);
        }
    }
    printf("Triangles:\n");
    for (i = 0; i < nV-2; i++){
        for (j = i+1 ; j < nV-1; j++){
            for (k = j+1; k < nV; k++){
                if (adjacent(g,i,j) && adjacent(g,i,k) && adjacent(g,j,k)){
                    printf("%d-%d-%d\n", i, j, k);
                }
            }
        }
    }
    freeGraph(g);
    return 0;
}


#include "Graph.c"
void dfscomponents(Graph, int, int, int *);
int *components(Graph,int *);
int main(void){
    int number_vertices;
    Edge e;
    printf("Enter the number of vertices: ");
    scanf("%d",&number_vertices);
    Graph g=newGraph(number_vertices);
    printf("Enter an edge (from): ");
    while( scanf("%d",&e.v)==1){
        printf("Enter an edge (to): ");
        scanf("%d",&e.w);
        insertEdge(g,e);   
        printf("Enter an edge (from): ");
    } 
    printf("Finished.\n");
    int id;
    int nV = numOfVertices(g);
    int *comp = components(g,&id);
    printf("Number of components: %d\n",id);
    int i,j;
    for (i=1;i<id+1;i++){
        printf("Component %d:\n",i);
        for (j=0;j<nV;j++) {
            if (comp[j]==i){
                //printf("%d\n",&comp+j);
                printf("%d\n",j);
            }
        }
    }
    freeGraph(g);
    free(comp);
    
    return 0;
}
int *components(Graph g,int *id){
    int nV = numOfVertices(g);
    int i;
    int *componentof=malloc(nV*sizeof(int));
    for (i=0;i<nV;i++){
        componentof[i]=-1;
    }
    int compID=0;
    for (i=0;i<nV;i++){
        if (componentof[i]==-1){
            compID=compID+1;
            dfscomponents(g, i, compID, componentof);
        }
        //printf("%d\n",compID);
        //printf("%d%d\n",i,componentof[i]);
    }
    *id=compID;
    return componentof;
}
void dfscomponents(Graph g, int v, int id, int *com){
    int i;
    int nV = numOfVertices(g);
    com[v]=id;
    for (i=0;i<nV;i++){
        if (adjacent(g,v,i) && com[i]==-1){
            dfscomponents(g, i, id,com);
        }
    }
}

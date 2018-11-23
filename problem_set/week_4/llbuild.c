#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node{
   int data;
   struct node *next;
} NodeT;
NodeT *makeNode(int);
void showLL(NodeT *);
void freeLL(NodeT *);
void joinLL(NodeT *, NodeT *);


NodeT *makeNode(int v) {
   NodeT *new = malloc(sizeof(NodeT));
   assert(new != NULL);
   new->data = v;       // initialise data
   new->next = NULL;    // initialise link to next node
   return new;          // return pointer to new node
}

void showLL(NodeT *list) {
   NodeT *p;
   if (list!=NULL){
       printf("List is %d", list->data);
   }
   for (p = list->next; p != NULL; p = p->next)
      printf("->%d", p->data);
}

void freeLL(NodeT *list) {
   NodeT *p;

   p = list;
   while (p != NULL) {
      NodeT *temp = p->next;
      free(p);
      p = temp;
   }
}

void joinLL(NodeT *head1, NodeT *head2){
    head1->next=head2;
}
int main(void){
    int n;
    NodeT *node;
    NodeT *all=NULL;
    
    printf("Enter an integer: ");
    while( scanf("%d",&n)==1){
        NodeT *p;
        node=makeNode(n);
        if (all==NULL){
            all=node;
        }else{
            p=all;
            while (p->next!=NULL){
                p=p->next;
            }
            joinLL(p, node);
        }
       printf("Enter an integer: ");
       
    } 
    printf("Finished.  ");
    if (all==NULL){
        return 0;
    }
    showLL(all);
    freeLL(all);
    return 0;
}
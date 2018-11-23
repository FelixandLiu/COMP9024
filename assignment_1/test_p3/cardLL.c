// Linked list of transport card records implementation ... Assignment 1 COMP9024 18s2
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "cardLL.h"
#include "cardRecord.h"

// linked list node type
// DO NOT CHANGE
typedef struct node {
    cardRecordT data;
    struct node *next;
} NodeT;

// linked list type
typedef struct ListRep {
   NodeT *head;
/* Add more fields if you wish */

} ListRep;

/*** Your code for stages 2 & 3 starts here ***/

// Time complexity: O(1)
// Explanation: the time of building any empty linked list is contanst
List newLL() {
    ListRep *new_linked_list= malloc(sizeof(ListRep));
    assert(new_linked_list!=NULL);
    new_linked_list->head=NULL;
    return new_linked_list;  /* needs to be replaced */
}

// Time complexity: O(n)
// Explanation: each node has to be free() in a linked list
void dropLL(List listp) {
    NodeT *p = listp->head;
    while(p !=NULL){
        NodeT *temp_pointer=p->next;
        free(p);
        p=temp_pointer;
    }

   return;  /* needs to be replaced */
}

// Time complexity: O(n)
// Explanation: if the cardid removed is at the end of linked list, it wil search each node
void removeLL(List listp, int cardID) {
    if (listp->head->data.cardID==cardID){
        NodeT *temp_pointer_1=listp->head->next;
        free(listp->head);
        listp->head=temp_pointer_1;
    }
    else{
        NodeT *p1;
        NodeT *temp_pointer_2;
        NodeT *p=listp->head;
        while (p!=NULL){
            if(p->next !=NULL){
                p1=p->next;
                if (p1->data.cardID==cardID && p1->next !=NULL){
                    temp_pointer_2=p1->next;
                    free(p1);
                    p->next=temp_pointer_2;
                    printf("Card removed.\n");
                    return;
                }
                if (p1->data.cardID==cardID && p1->next ==NULL) {
                    free(p1);
                    p->next=NULL;
                    printf("Card removed.\n");
                    return;
                }
            }
            if (p->data.cardID!=cardID && p->next ==NULL){
                printf("Card not found.\n");
            }
            p=p->next;
        }
    }
   return;  /* needs to be replaced */
}

// Time complexity: stage2 is O(1), stage3 is O(n)
// Explanation: stage2 is the reason that new card only is inserted at the beginning of the list
//               stage3 is because that new card number need to be compared with nodes of list
void insertLL(List listp, int cardID, float amount) {
    if(listp->head == NULL) {
        listp->head = malloc(sizeof(NodeT));
        assert(listp->head != NULL);
        listp->head->data.cardID=cardID;
        listp->head->data.balance=amount;
        listp->head->next=NULL;
        printf("Card added.\n");
        return;
    }
    else{
        if (listp->head!=NULL && listp->head->data.cardID>cardID){
                NodeT *new_card= malloc(sizeof(NodeT));
                assert(new_card != NULL);
                new_card->data.cardID=cardID;
                new_card->data.balance=amount;
                new_card->next=listp->head;
                listp->head=new_card;
                printf("Card added.\n");
                return;
        }
        NodeT *p;
        p=listp->head;
        while(p!=NULL){
            if(p->next!=NULL){
                if(p->data.cardID<cardID && p->next->data.cardID>cardID){
                    NodeT *new_card= malloc(sizeof(NodeT));
                    assert(new_card != NULL);
                    new_card->data.cardID=cardID;
                    new_card->data.balance=amount;
                    new_card->next=p->next;
                    p->next=new_card;
                    printf("Card added.\n");
                    return;
                }
            }
            if (p->next==NULL && p->data.cardID<cardID){
                NodeT *new_card= malloc(sizeof(NodeT));
                assert(new_card != NULL);
                new_card->data.cardID=cardID;
                new_card->data.balance=amount;
                new_card->next=NULL;
                p->next=new_card;
                printf("Card added.\n");
                return;
            }
            if (p->next==NULL && p->data.cardID>cardID){
                NodeT *new_card= malloc(sizeof(NodeT));
                assert(new_card != NULL);
                new_card->data.cardID=cardID;
                new_card->data.balance=amount;
                new_card->next=p;
                listp->head=new_card;
                printf("Card added.\n");
                return;
            }
            if (p->data.cardID==cardID){
                p->data.balance +=amount;
                printCardData(p->data);
                return;
            }
            p=p->next;
        }


        /**
        NodeT *new_card= malloc(sizeof(NodeT));
        assert(new_card != NULL);
        new_card->data.cardID=cardID;
        new_card->data.balance=amount;
        new_card->next=listp->head;
        listp->head=new_card;
        printf("Card added.\n");
        **/ 
    }

   return;  /* needs to be replaced */
}

// Time complexity: O(n)
// Explanation: add all balance of nodes of list
void getAverageLL(List listp, int *n, float *balance) {
    float total_amount=0;
    int total_number=0;
    for(NodeT *p = listp->head; p!=NULL;p=p->next){
        total_number += 1;
        total_amount += p->data.balance;
    }
    
    *n=total_number;
    *balance=total_amount/total_number;
   return;  /* needs to be replaced */
}

// Time complexity: O(n)
// Explanation: print each node of list
void showLL(List listp) {
    for (NodeT *p = listp->head; p !=NULL; p=p->next){
        printCardData(p->data);
    }
   return;  /* needs to be replaced */
}

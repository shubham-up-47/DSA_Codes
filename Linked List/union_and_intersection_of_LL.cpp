#include <stdio.h>
#include <stdlib.h>
  
/* A structure of linked list node */
struct node {
  int data;
  struct node *next;
} *LLOne, *LLTwo, *unionLL, *intersectionLL;
 
void initialize(){
    LLOne = LLTwo = NULL;
}
/* 
Given a Inserts a node in front of a singly linked list. 
*/
void insert(struct node **head, int num) {
    /* Create a new Linked List node */
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data  = num;
    /* Next pointer of new node will point to head node of linked list  */
    newNode->next = *head;
    /* make new node as new head of linked list */
    *head = newNode;
}
 
/* Searches an element in Linked List by 
linearly traversing from head to tail */
int search(struct node *head, int num) {
    while (head != NULL) {
        if (head->data == num){
            return 1;
        }
        head = head->next;
    }
    return 0;
}
 
/* 
Returns the union of two given linked list 
*/
struct node* findunion(struct node *LLOne, struct node *LLTwo) {
    unionLL = NULL;
    /* Add all nodes of first Linked List to unionLL */
    struct node *temp = LLOne;
    while(temp != NULL){
        insert(&unionLL, temp->data);
        temp = temp->next;
    }
    /* Insert those nodes of LLTwo which is not present in LLOne */
    while(LLTwo != NULL){
        if(!search(LLOne, LLTwo->data)){
            insert(&unionLL, LLTwo->data);
        }
        LLTwo = LLTwo->next;
    }
    return unionLL;
}
/*
Returns the Linked List which contains common nodes of two given linked list 
*/
struct node* intersection(struct node *LLOne, struct node *LLTwo) {
    intersectionLL = NULL;
    /* Search every element of LLOne in LLTwo, 
    If found then add it to intersection List */
    while(LLOne != NULL){
        if(search(LLTwo, LLOne->data)){
            insert(&intersectionLL, LLOne->data);
        }
        LLOne = LLOne->next;
    }
    return intersectionLL;
}
/*
Prints a linked list from head node till tail node 
*/
void printLinkedList(struct node *nodePtr) {
  while (nodePtr != NULL) {
     printf("%d", nodePtr->data);
     nodePtr = nodePtr->next;
     if(nodePtr != NULL)
         printf("-->");
  }
}
  
int main() {
    int i, LLOneCount, LLTwoCount, temp;
    initialize();
    /* Creating First linked List*/
    printf("Enter number of nodes in first Linked List\n");
    scanf("%d", &LLOneCount);
    printf("Enter %d integers\n", LLOneCount);
    for(i=0; i<LLOneCount; i++){
        scanf("%d", &temp);
        insert(&LLOne, temp);  
    }
    printLinkedList(LLOne);
    printf("\nEnter number of nodes in second Linked List\n");
    scanf("%d", &LLTwoCount);
    printf("Enter %d integers\n", LLTwoCount);
    for(i=0; i<LLTwoCount; i++){
        scanf("%d", &temp);
        insert(&LLTwo, temp);  
    }
    printLinkedList(LLTwo);
    /* printing Union of two given linked list */
    findunion(LLOne, LLTwo); 
    intersection(LLOne, LLTwo);
    printf("\nUnion Linked List\n");
    printLinkedList(unionLL);
    printf("\nIntersection Linked List\n");
    printLinkedList(intersectionLL);    
 
    return 0;
}


/*

4  1 2 3 4
4  3 4 5 6

*/



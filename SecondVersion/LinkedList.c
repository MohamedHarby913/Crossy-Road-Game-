#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

/*****************************************
Name: createNode
Import: int* x, int* y, char* symbol

Export: (LinkedListNode*) newNode
Purpose: This function's role is to create a new node 
******************************************/

LinkedListNode* createNode(int* x, int* y, char* symbol) {
    LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    
    newNode->x = (int*)malloc(sizeof(int)); 
    *(int*)newNode->x = *x;  
    
    newNode->y = (int*)malloc(sizeof(int)); 
    *(int*)newNode->y = *y;  
    
    newNode->symbol = (char*)malloc(sizeof(char)); 
    *(char*)newNode->symbol = *symbol;  
    
    newNode->next = NULL;
    
    return newNode;
}

/*****************************************
Name: insertFirst
Import: LinkedList* list, int* x, int* y, char* symbol
Export: none
Purpose: This function's role is to insert the new node in the start of the list
******************************************/

void insertFirst(LinkedList* list, int* x, int* y, char* symbol) {
    LinkedListNode* newNode = createNode(x, y, symbol);
    newNode->next = list->head;
    list->head = newNode;
}



/*****************************************
Name: insertFirst
Import: LinkedList* list
Export: none
Purpose: This function's role is to delete the first node of the list
******************************************/

void deleteFirst(LinkedList* list) {
    LinkedListNode* temp;
    if (list->head == NULL) {
        printf("List is empty, cannot delete\n");
        return;
    }
    temp = list->head;
    list->head = list->head->next;
    free(temp->x); 
    free(temp->y);
    free(temp->symbol); 
    free(temp); 
  
}

/*****************************************
Name: listLength
Import: LinkedListNode* node)
Export: (int) length
Purpose: This function's role is to return the list's length
******************************************/

int listLength(LinkedListNode* node) {
  int length = 0;
  if(node != NULL)
  length = 1 + listLength((*node).next);
  return length;
  }

/*****************************************
Name: listLength
Import: LinkedListNode* node)
Export: (int) length
Purpose: This function's role is to return the list's length
******************************************/

void freeNode(LinkedListNode* node) {
    if (node != NULL) {
        freeNode(node->next); 
        free(node->x); 
        free(node->y); 
        free(node->symbol);
        free(node);
    }
}


void freeLinkedList(LinkedList* list) {
    freeNode(list->head);
    free(list);
}

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedListNode {
    void* x;
    void* y;
    void* symbol; 
    struct LinkedListNode* next;
} LinkedListNode;

typedef struct {
    LinkedListNode* head;
} LinkedList;




LinkedListNode* createNode(int* x, int* y, char* symbol);
void insertFirst(LinkedList* list, int* x, int* y, char* symbol);
void deleteFirst(LinkedList* list);
int listLength(LinkedListNode* node);
void freeNode(LinkedListNode* node);
void freeLinkedList(LinkedList* list);
#endif

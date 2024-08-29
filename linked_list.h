//
// Created by skorsens on 8/28/2024.
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdbool.h>

typedef struct SLinkedListNode {
    struct SLinkedListNode *next;
    int data;
} TLinkedListNode;


TLinkedListNode *createNode(int data);
TLinkedListNode *getListNode(TLinkedListNode* head, int data);
TLinkedListNode *insertNode(TLinkedListNode *head, int data);
TLinkedListNode *appendNode(TLinkedListNode *head, int data);
TLinkedListNode *insertNodeSorted(TLinkedListNode *head, int data);
TLinkedListNode *deleteNodeByData(TLinkedListNode *head, int data);
TLinkedListNode *deleteAllNodes(TLinkedListNode *head);
int length(TLinkedListNode *head);
int listToArray(int a[], int len_a, TLinkedListNode *head);
void printList(TLinkedListNode *head);

bool findMthToLastElem(TLinkedListNode *head, int m, TLinkedListNode **elem);

#endif //LINKED_LIST_H

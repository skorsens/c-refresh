//
// Created by skorsens on 8/28/2024.
//

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

#include <stdbool.h>


TLinkedListNode *createNode(int data) {
    struct SLinkedListNode *node = malloc(sizeof(struct SLinkedListNode));
    if (node != NULL){
        node->data = data;
        node->next = NULL;
    }
    return node;
}

TLinkedListNode *getListNode(TLinkedListNode* head, int data) {
    for (TLinkedListNode *curr = head; curr != NULL; curr = curr->next) {
        if (curr->data == data) {
            return curr;
        }
    }
    return NULL;
}

TLinkedListNode *insertNode(TLinkedListNode *head, int data) {
    TLinkedListNode *newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

TLinkedListNode *appendNode(TLinkedListNode *head, int data) {
    TLinkedListNode *newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        return head;
    }

    TLinkedListNode *curr = head;
    for (; curr->next != NULL; curr = curr->next) {
        ;
    }

    curr->next = newNode;

    return head;
}


TLinkedListNode *insertNodeSorted(TLinkedListNode *head, int data) {
    TLinkedListNode *newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        return head;
    }

    TLinkedListNode *prev = NULL;
    TLinkedListNode *curr = head;

    for (; curr != NULL; prev = curr, curr = curr->next) {
        if (data == curr->data || data < curr->data){
            break;
        }
    }

    if (prev == NULL) {
        newNode->next = head;
        head = newNode;
    }
    else if (curr == NULL) {
        prev->next = newNode;
    }
    else {
        newNode->next = curr;
        prev->next = newNode;
    }
    return head;
}


TLinkedListNode *deleteAllNodes(TLinkedListNode *head) {
    /* deleteAllNodes */
    if (head == NULL) {
        return head;
    }

    TLinkedListNode *curr = head;

    for (; curr->next != NULL; curr = curr->next) {
        TLinkedListNode *prev = curr;
        curr = curr->next;
        free(prev);
    }

    free(curr);

    return NULL;
}


TLinkedListNode * deleteNodeByData(TLinkedListNode *head, int data) {
    /* deleteNodeByData
     */
    for (TLinkedListNode *prev = NULL, *curr = head; curr != NULL; prev = curr, curr = curr->next) {
        if (curr->data == data) {
            if (prev == NULL) {
                head = curr->next;
            }
            else {
                prev->next = curr->next;
            }
            free(curr);

            break;
        }
    }
    return head;
}


int length(TLinkedListNode *head) {
    int length = 0;

    for (TLinkedListNode *curr = head; curr != NULL; curr = curr->next) {
        length++;
    }
    return length;
}


int listToArray(int a[], int len_a, TLinkedListNode *head) {
    int listLength = length(head);

    if (listLength == 0)
        return 0;

    int i = 0;

    for (TLinkedListNode *curr = head; curr != NULL && i < len_a; curr = curr->next, i++) {
        a[i] = curr->data;
    }

    return i-1;
}


void printList(TLinkedListNode *head) {
    printf("[");
    for (TLinkedListNode *curr = head; curr != NULL; curr = curr->next) {
        printf("%d; ", curr->data);
    }
    printf("]\n");
}

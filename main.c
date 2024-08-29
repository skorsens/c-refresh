#include <stdio.h>

#include "linked_list.h"


TLinkedListNode *_fillUpListInsert(TLinkedListNode *head, int aData[], int aDataLength) {
    for (int i = 0; i < aDataLength; i++) {
        head = insertNode(head, aData[i]);
    }

    return head;
}

TLinkedListNode *_fillUpListAppend(TLinkedListNode *head, int aData[], int aDataLength) {
    for (int i = 0; i < aDataLength; i++) {
        head = appendNode(head, aData[i]);
    }

    return head;
}

TLinkedListNode *_fillUpListSorted(TLinkedListNode *head, int aData[], int aDataLength) {
    for (int i = 0; i < aDataLength; i++) {
        head = insertNodeSorted(head, aData[i]);
    }

    return head;
}


int main(void) {
    printf("Hello, World!\n");

    int aData[] = {10, 20, 30, 40};
    TLinkedListNode *head = NULL;
    head = _fillUpListInsert(head, aData, sizeof(aData)/sizeof(int));

    printList(head);

    printf("deleteNodeByData(head,100)\n");
    head = deleteNodeByData(head,100);
    printList(head);

    printf("deleteNodeByData(head,30)\n");
    head = deleteNodeByData(head,30);
    printList(head);

    printf("deleteNodeByData(head,40)\n");
    head = deleteNodeByData(head,40);
    printList(head);

    printf("deleteNodeByData(head,10)\n");
    head = deleteNodeByData(head,10);
    printList(head);

    printf("deleteNodeByData(head,20)\n");
    head = deleteNodeByData(head,20);
    printList(head);

    printf("deleteNodeByData(head,20)\n");
    head = deleteNodeByData(head,20);
    printList(head);

    printf("********** Append node **********\n");
    head = _fillUpListAppend(head, aData, sizeof(aData)/sizeof(int));

    printList(head);

    printf("********** Insert sorted **********\n");
    head = insertNodeSorted(head, 5);
    printList(head);
    head = insertNodeSorted(head, 25);
    printList(head);
    head = insertNodeSorted(head, 45);
    printList(head);

    printf("********** deleteAllNodes **********\n");
    head = deleteAllNodes(head);
    printList(head);
    return 0;
}

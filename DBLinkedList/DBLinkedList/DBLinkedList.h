//
//  DBLinkedList.h
//  DBLinkedList
//
//  Created by abc on 2021/02/13.
//

#ifndef DBLinkedList_h
#define DBLinkedList_h

#define TRUE 1
#define FALSE 0

#include <stdio.h>

typedef int Data;

typedef struct _node {
    Data data;
    struct _node* next;
    struct _node* prev;
} Node;

typedef struct _DLinkedList{
    Node* cur;
    Node* head;
    int numOfData;
} DBLinkedList;

typedef DBLinkedList List;

void ListInit(List* plist);
void LInsert(List* plist, Data data);

int LFirst(List* plist, Data* pdata);
int LNext(List* plist, Data* pdata);
int LPrevious(List* plist, Data* pdata);

int Lcount(List* plist);

#endif /* DBLinkedList_h */

//
//  CLinkedList.h
//  LinkedListBaseStack2
//
//  Created by abc on 2021/02/14.
//

#ifndef CLinkedList_h
#define CLinkedList_h

#define TRUE 1
#define FALSE 0
#include <stdio.h>

typedef int Data;

typedef struct _node{
    Data data;
    struct _node* next;
} Node;

typedef struct _list{
    int numOfdata;
    Node* tail;
    Node* cur;
    Node* before;
} CList;

typedef CList List;

void ListInit(List* plist);
void LInsert(List* plist, Data data);
void LInsertFront(List* plist, Data data);

int LFirst(List* plist, Data* pdata);
int LNext(List* plist, Data* pdata);

Data LRemove(List* plist);

int LCount(List* plist);



#endif /* CLinkedList_h */

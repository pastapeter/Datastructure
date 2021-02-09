//
//  CLinkedList.h
//  Circular Linked List
//
//  Created by abc on 2021/02/09.
//

#ifndef CLinkedList_h
#define CLinkedList_h
#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node{
    Data data;
    struct _node* next;
} Node;

typedef struct _CLL{
    Node* tail;
    Node* cur;
    Node* before;
    int NumofData;
} CList;

typedef CList List;

void ListInit(List* plist);
void LInsert(List* plist, Data data); //꼬리에 노드를 추가
void LInsertFront(List* plist, Data data); // 머리에 노드를 추가

int LFirst(List* plist, Data* pdata);
int LNext(List* plist, Data* pdata);
Data LRemove(List* plist);
int LCount(List* plist);

#endif /* CLinkedList_h */

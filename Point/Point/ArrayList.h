//
//  ArrayList.h
//  Point
//
//  Created by abc on 2021/01/16.
//
#include "Point.h"
#include <stdio.h>
#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE 1
#define FALSE 0

#define LIST_LEN 100
typedef Point* LData;

typedef struct _node{
    LData data;
    struct _node* next;
}Node;

typedef struct __ArrayList{
    Node* head;
    Node* before;
    Node* cur;
    int (*comp)(LData d1, LData d2);
    int numOfdata;
} LinkedList;

typedef LinkedList List;

void ListInit(List* plist);
void LInsert(List* plist, LData data);
void FInsert(List* plist, LData data);
int LFirst(List* plist, LData *pdata);
int LNext(List *plist, LData *pdata);
LData LRemove(List *plist);
int LCount(List* plist);
void SetSortRule(List* plist, int(*comp)(LData d1, LData d2));

#endif /* ArrayList_h */

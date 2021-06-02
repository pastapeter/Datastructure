//
//  LinkedList.h
//  graph
//
//  Created by abc on 2021/06/03.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int data;
    struct _node* next;
}Node;

typedef struct _linkedlist{
    Node* head;
    Node* cur;
    Node* before;
}List;

void listInit(List* plist);
void Insert(List* plist, int input);
int LFirst(List* plist, int* pdata);
int LNext(List* plist, int* pdata);
int isEmpty(List* plist);

#endif /* LinkedList_h */

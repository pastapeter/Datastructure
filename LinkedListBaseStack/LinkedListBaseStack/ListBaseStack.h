//
//  ListBaseStack.h
//  LinkedListBaseStack
//
//  Created by abc on 2021/02/14.
//

#ifndef ListBaseStack_h
#define ListBaseStack_h

#define TRUE 1
#define FALSE 0
#include <stdio.h>

typedef int Data;

typedef struct _node{
    Data data;
    struct _node* next;
} Node;

typedef struct _listStack{
    Node* head;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);

#endif /* ListBaseStack_h */

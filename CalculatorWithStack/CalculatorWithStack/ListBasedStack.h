//
//  ListBasedStack.h
//  CalculatorWithStack
//
//  Created by abc on 2021/02/16.
//

#ifndef ListBasedStack_h
#define ListBasedStack_h
#define TRUE 1
#define FALSE 0

typedef int Data;

#include <stdio.h>


typedef struct _node{
    Data data;
    struct _node* next;
} Node;

typedef struct _liststack{
    Node* head;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack* pstack);
void SPush(Stack* pstack, Data data);
int SIsEmpty(Stack* pstack);
Data SPop(Stack* pstack);
Data SPeekl(Stack* pstack);

#endif /* ListBasedStack_h */

//
//  CLinkedListBaseStack.h
//  LinkedListBaseStack2
//
//  Created by abc on 2021/02/14.
//

#ifndef CLinkedListBaseStack_h
#define CLinkedListBaseStack_h

#include <stdio.h>
#include "CLinkedList.h"

typedef struct _CLinkStack{
    List* plist;
} CLinkedStack;

typedef CLinkedStack Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);

#endif /* CLinkedListBaseStack_h */

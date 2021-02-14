//
//  ArrayBaseStack.h
//  ArrayBaseStack
//
//  Created by abc on 2021/02/14.
//

#ifndef ArrayBaseStack_h
#define ArrayBaseStack_h

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100

#include <stdio.h>

typedef int Data;

typedef struct _arrayStack{
    Data stackArray[STACK_LEN];
    int topIndex;
} ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack* pstack); //스택의 초기화
int SIsEmpty(Stack* pstack); // 스택이 비었는지 확인

void SPush(Stack* pstack, Data data); // 스택의 push 연산
Data SPop(Stack* pstack); // 스택의 pop연산
Data SPeek(Stack* pstack); // 스택의 peek연산


#endif /* ArrayBaseStack_h */

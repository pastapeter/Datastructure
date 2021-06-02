//
//  Stack.h
//  DFS, BFS
//
//  Created by abc on 2021/06/02.
//

#ifndef Stack_h
#define Stack_h

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100
#define MAX_NUM 10
#include <stdio.h>
#include <stdlib.h>
typedef struct _arrayStack{
    int stackArray[STACK_LEN];
    int topIndex;
} ArrayStack;


void ArrayStackInit(ArrayStack* pstack); //스택의 초기화
int SIsEmpty(ArrayStack* pstack); // 스택이 비었는지 확인

void SPush(ArrayStack* pstack, int data); // 스택의 push 연산
int SPop(ArrayStack* pstack); // 스택의 pop연산
int SPeek(ArrayStack* pstack); // 스택의 peek연산

#endif /* Stack_h */

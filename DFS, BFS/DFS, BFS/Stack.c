//
//  Stack.c
//  DFS, BFS
//
//  Created by abc on 2021/06/02.
//

#include "Stack.h"


void ArrayStackInit(ArrayStack* pstack){//스택의 초기화
    pstack->topIndex = -1;
}
int SIsEmpty(ArrayStack* pstack) {// 스택이 비었는지 확인
    if(pstack->topIndex == -1){
        return TRUE;
    } else {
        return FALSE;
    }
}

void SPush(ArrayStack* pstack, int data){// 스택의 push 연산
    pstack->topIndex += 1;
    pstack->stackArray[pstack->topIndex] = data;
}
int SPop(ArrayStack* pstack){// 스택의 pop연산
    int rIdx;
    if(pstack->topIndex == -1){
        printf("ERROR");
        exit(-1);
    }
    rIdx = pstack->topIndex;
    pstack->topIndex -= 1;
    return pstack->stackArray[rIdx];
}
int SPeek(ArrayStack* pstack){// 스택의 peek연산
    if(SIsEmpty(pstack)){
        printf("ERROR");
        exit(-1);
    }
    return pstack->stackArray[pstack->topIndex];
}

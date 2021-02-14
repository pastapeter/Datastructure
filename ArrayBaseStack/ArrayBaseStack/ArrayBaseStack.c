//
//  ArrayBaseStack.c
//  ArrayBaseStack
//
//  Created by abc on 2021/02/14.
//

#include "ArrayBaseStack.h"
#include <stdlib.h>

void StackInit(Stack* pstack){//스택의 초기화
    pstack->topIndex = -1;
}
int SIsEmpty(Stack* pstack) {// 스택이 비었는지 확인
    if(pstack->topIndex == -1){
        return TRUE;
    } else {
        return FALSE;
    }
}

void SPush(Stack* pstack, Data data){// 스택의 push 연산
    pstack->topIndex += 1;
    pstack->stackArray[pstack->topIndex] = data;
}
Data SPop(Stack* pstack){// 스택의 pop연산
    int rIdx;
    if(pstack->topIndex == -1){
        printf("ERROR");
        exit(-1);
    }
    rIdx = pstack->topIndex;
    pstack->topIndex -= 1;
    return pstack->stackArray[rIdx];
}
Data SPeek(Stack* pstack){// 스택의 peek연산
    if(SIsEmpty(pstack)){
        printf("ERROR");
        exit(-1);
    }
    return pstack->stackArray[pstack->topIndex];
}

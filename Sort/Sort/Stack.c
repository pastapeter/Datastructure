#include "Stack.h"

void stackInit(stack* pstack){
    pstack->stackArray = (Data*)malloc(sizeof(Data)*MAX_NUM);
    pstack->topIndex = -1;
}

int isFull(stack* pstack){
    if(pstack->topIndex >= MAX_NUM-1){
        return  TRUE;
    } else return FALSE;
}

void push(stack* pstack, Data input){
    if(isFull(pstack)){
        printf("ERROR");
        exit(-1);
    }
    pstack->topIndex += 1;
    pstack->stackArray[pstack->topIndex] = input;
}

Data pop(stack* pstack){
    int rIdx;
    rIdx = pstack->topIndex;
    pstack->topIndex -= 1;
    return pstack->stackArray[rIdx];
}

Data peek(stack* pstack){
    if(isEmpty(pstack)){
        printf("ERROR");
        exit(-1);
    }
    return pstack->stackArray[pstack->topIndex];
}

int isEmpty(stack* pstack){
    if(pstack->topIndex == -1){
        return TRUE;
    } else return FALSE;
}


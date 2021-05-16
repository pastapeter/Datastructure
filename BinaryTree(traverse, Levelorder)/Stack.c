#include "Stack.h"


void stackInit(Stack* pstack){
    pstack->top = -1;
    pstack->capacity = 1;
    pstack->stackArray = (Btree**)malloc(sizeof(Btree*)*pstack->capacity);
}
void push(Stack* pstack, Btree* input){
    if(isFull(pstack)){
        pstack->capacity *= 2;
        pstack->stackArray = (Btree**)realloc(pstack->stackArray, sizeof(Btree*)*pstack->capacity);
    }
    pstack->top += 1;
    pstack->stackArray[pstack->top] = input;
}
int isEmpty(Stack* pstack){
    if(pstack->top == -1){
        return TRUE;
    } else{
        return FALSE;
    }
}
int isFull(Stack* pstack){
    if(pstack->top >= pstack->capacity - 1){
        return TRUE;
    } else {
        return FALSE;
    }
}
Btree* pop(Stack* pstack){
    int ridx = pstack->top;
//    if(isEmpty(pstack)){
//        printf("OUT OF RANGE");
//        exit(-1);
//    }
    pstack->top -= 1;
    return pstack->stackArray[ridx];
}
Btree* peek(Stack* pstack){
//    if(isEmpty(pstack)){
//        printf("OUT OF RANGE");
//        exit(-1);
//    }
    return pstack->stackArray[pstack->top];
}

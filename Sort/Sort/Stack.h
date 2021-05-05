
#ifndef Stack_h
#define Stack_h
#define MAX_NUM 100
#define TRUE 1
#define FALSE 0
#define N 10;

#include <stdio.h>
#include <stdlib.h>

typedef struct Qsort{
    int left;
    int right;
}Qsort;

typedef Qsort Data;

typedef struct Stack{
    Data *stackArray;
    int topIndex;
} stack;




void stackInit(stack* pstack);
void push(stack* pstack, Data input);
Data pop(stack* pstack);
Data peek(stack* pstack);
int isEmpty(stack* pstack);
int isFull(stack* pstack);

#endif /* Stack_h */


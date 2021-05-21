
#ifndef Stack_h
#define Stack_h

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _binaryTree{
    Data data;
    struct _binaryTree* left;
    struct _binaryTree* right;
}Btree;

typedef struct dstack{
    Btree** stackArray;
    int top;
    int capacity;
}Stack;



void stackInit(Stack* pstack);
void push(Stack* pstack, Btree* input);
int isEmpty(Stack* pstack);
int isFull(Stack* pstack);
Btree* pop(Stack* pstack);
Btree* peek(Stack* pstack);


#endif /* Stack_h */

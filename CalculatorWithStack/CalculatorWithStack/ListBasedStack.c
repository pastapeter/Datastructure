//
//  ListBasedStack.c
//  CalculatorWithStack
//
//  Created by abc on 2021/02/16.
//

#include "ListBasedStack.h"
#include <stdlib.h>

void StackInit(Stack* pstack){
    pstack->head = NULL;
}
void SPush(Stack* pstack, Data data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = pstack->head;
    pstack->head = newNode;
}
int SIsEmpty(Stack* pstack){
    if(pstack->head == NULL) return TRUE;
    else return FALSE;
}
Data SPop(Stack* pstack){
    Data rdata;
    Node* rnode;
    
    if(SIsEmpty(pstack)){
        printf("Error");
        exit(-1);
    }
    rdata = pstack->head->data;
    rnode = pstack->head;
    
    pstack->head = pstack->head->next;
    free(rnode);
    
    return rdata;
}
Data SPeekl(Stack* pstack){
    if(SIsEmpty(pstack)){
        printf("Error");
        exit(-1);
    }
    return pstack->head->data;
}

//
//  ListBaseStack.c
//  LinkedListBaseStack
//
//  Created by abc on 2021/02/14.
//

#include "ListBaseStack.h"
#include <stdlib.h>

void StackInit(Stack* pstack){
    pstack->head = NULL;
}

int SIsEmpty(Stack* pstack){
    if(pstack->head == NULL){
        return TRUE;
    } else {
        return FALSE;
    }
}

void SPush(Stack* pstack, Data data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    newNode->data = data;
    newNode->next = pstack->head;
    pstack->head = newNode;
    
}
Data SPop(Stack* pstack){
    Data rdata;
    Node* rnode;
    
    if(SIsEmpty(pstack)){
        printf("ERROR");
        exit(-1);
    }
    rdata = pstack->head->data;
    rnode = pstack->head;
    
    pstack->head = pstack->head->next;
    free(rnode);
    
    return rdata;
}
Data SPeek(Stack* pstack){
    if(SIsEmpty(pstack)){
        printf("ERROR");
        exit(-1);
    }
    return pstack->head->data;
}

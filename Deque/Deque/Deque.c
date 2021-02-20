//
//  Deque.c
//  Deque
//
//  Created by abc on 2021/02/20.
//

#include "Deque.h"
#include <stdlib.h>

void DequeInit(Deque* pdeq){
    pdeq->head = NULL;
    pdeq->tail = NULL;
}

int DQIsEmpty(Deque* pdeq){
    if(pdeq->head == NULL){
        return TRUE;
    } else {
        return FALSE;
    }
}

void DQAddFirst(Deque* pdeq, Data data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    newNode->next = pdeq->head;
    if(DQIsEmpty(pdeq)){
        pdeq->tail = newNode;
    } else {
        pdeq->head->prev = newNode;
    }
    pdeq->head = newNode;
    newNode->prev = NULL;
}
void DQAddLast(Deque* pdeq, Data data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = pdeq->tail;
    if(pdeq->tail == NULL){
        pdeq->head = newNode;
        
    } else {
        pdeq->tail->next = newNode;
    }
    newNode->next = NULL;
    pdeq->tail = newNode;
}

Data DQRemoveFirst(Deque* pdeq){
    if(DQIsEmpty(pdeq)){
        printf("error");
        exit(-1);
    }
    Node* rpos = pdeq->head;
    Data rdata = pdeq->head->data;
    pdeq->head = pdeq->head->next;
    free(rpos);
    
    if(pdeq->head == NULL){
        pdeq->tail = NULL;
    } else {
        pdeq->head->prev = NULL;
    }
    return rdata;
}
Data DQRemoveLast(Deque* pdeq){
    if(DQIsEmpty(pdeq)){
        printf("error");
        exit(-1);
    }
    Node* rpos = pdeq->tail;
    Data rdata = pdeq->tail->data;
    pdeq->tail = pdeq->tail->prev;
    free(rpos);
    
    
    if(pdeq->tail == NULL){
        pdeq->head = NULL;
    } else {
        pdeq->tail->next = NULL;
    }
    
    return rdata;
}

Data DQGetFirst(Deque* pdeq){
    if(DQIsEmpty(pdeq)){
        printf("error");
        exit(-1);
    }
    return pdeq->head->data;
}
Data DQGetLast(Deque* pdeq){
    if(DQIsEmpty(pdeq)){
        printf("error");
        exit(-1);
    }
    return pdeq->tail->data;
}

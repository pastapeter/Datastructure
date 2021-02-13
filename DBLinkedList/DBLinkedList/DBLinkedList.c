//
//  DBLinkedList.c
//  DBLinkedList
//
//  Created by abc on 2021/02/13.
//

#include "DBLinkedList.h"
#include <stdlib.h>


void ListInit(List* plist){
    plist->head = (Node*)malloc(sizeof(Node));
    plist->tail = (Node*)malloc(sizeof(Node));
    
    plist->head->prev = NULL;
    plist->tail->next = NULL;
    
    plist->head->next = plist->tail;
    plist->tail->prev = plist->head;
    plist->numOfData = 0;
}

void LInsert(List* plist, Data data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
  
    newNode->prev = plist->tail->prev;
    plist->tail->prev->next = newNode;
    
    plist->tail->prev = newNode;
    newNode->next = plist->tail;
    
    (plist->numOfData)++;
}

int LFirst(List* plist, Data* pdata){
    if(plist->head->next == NULL){
        return FALSE;
    }
    plist->cur = plist->head->next;
    *pdata = plist->cur->data;
    return TRUE;
}

int LNext(List* plist, Data* pdata){
    if(plist->cur->next == plist->tail) {
        return FALSE;
    }
    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
    
    return TRUE;
}

int LPrevious(List* plist, Data* pdata){
    if(plist->cur->prev == plist->head) {
        return FALSE;
    }
    plist->cur = plist->cur->prev;
    *pdata = plist->cur->data;
    return TRUE;
}

int LCount(List* plist){
    return plist->numOfData;
}

Data LRemove(List* plist){
    Node* rpos = plist->cur;
    Data rdata = rpos->data;
    
    rpos->prev->next = rpos->next;
    rpos->next->prev = rpos->prev;
    plist->cur = plist->cur->prev;
    
    free(rpos);
    (plist->numOfData)--;
    
    return rdata;
}

//
//  CLinkedList.c
//  Circular Linked List
//
//  Created by abc on 2021/02/09.
//

#include "CLinkedList.h"
#include <stdlib.h>

void ListInit(List* plist){
    plist->tail = NULL;
    plist->cur = NULL;
    plist->before = NULL;
    plist->NumofData = 0;
}

void LInsert(List* plist, Data data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if(plist->tail == NULL){
        plist->tail = newNode;
        plist->tail->next = newNode;
    }
    else{
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
        plist->tail = newNode;
    }
    (plist->NumofData)++;
}

void LInsertFront(List* plist, Data data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if(plist->tail == NULL){
        plist->tail = newNode;
        plist->tail->next = newNode;
    }
    else {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
    }
    (plist->NumofData)++;
}

int LFirst(List* plist, Data* pdata){
    if(plist->tail == NULL){
        return FALSE;
    }
    plist->cur = plist->tail->next;
    plist->before = plist->tail;
    
    *pdata = plist->cur->data;
    return TRUE;
}

int LNext(List* plist, Data* pdata){
    if(plist->tail == NULL){
        return FALSE;
    }
    plist->before = plist->cur;
    plist->cur = plist->cur->next;
    
    *pdata = plist->cur->data;
    return TRUE;
}

Data LRemove(List* plist){
    Node* rpos = plist->cur;
    Data rdata = rpos->data;
    if(rpos == plist->tail){
        if(plist->tail == plist->tail->next) plist->tail = NULL;
        else{
            plist->tail = plist->before;
        }
    }
    plist->before->next = plist->cur->next;
    plist->cur = plist->before;
    free(rpos);
    (plist->NumofData)--;
    return rdata;
}

int LCount(List* plist){
    return plist->NumofData;
}

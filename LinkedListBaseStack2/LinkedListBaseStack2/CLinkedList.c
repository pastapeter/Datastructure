//
//  CLinkedList.c
//  LinkedListBaseStack2
//
//  Created by abc on 2021/02/14.
//

#include "CLinkedList.h"
#include <stdlib.h>

void ListInit(List* plist){
    plist->tail = NULL;
    plist->cur = NULL;
    plist->before = NULL;
    plist->numOfdata = 0;
}
void LInsert(List* plist, Data data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if(plist->tail == NULL){
        plist->tail = newNode;
        newNode->next = newNode;
    }
    else {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
        plist->tail = newNode;
    }
    (plist->numOfdata)++;
}

void LInsertFront(List* plist, Data data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if(plist->tail == NULL){
        plist->tail = newNode;
        newNode->next = newNode;
    }
    else {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
    }
    (plist->numOfdata)++;
    
}

int LFirst(List* plist, Data* pdata){
    if(plist->tail == NULL) return FALSE;
    plist->before = plist->tail;
    plist->cur = plist->tail->next;
    *pdata = plist->cur->data;
    return TRUE;
}
int LNext(List* plist, Data* pdata){
    if(plist->tail == NULL) return FALSE;
    plist->before = plist->cur;
    plist->cur = plist->cur->next;
    
    *pdata = plist->cur->data;
    return TRUE;
}

Data LRemove(List* plist){
    Data rdata;
    Node* rpos;
    rpos = plist->cur;
    rdata = rpos->data;
    //원형은 나눠서 만듬 1.지워야하는것이 tail pointer가 가르키는 것이라면? 이랑 아닐때
    if(rpos == plist->tail){
        if(plist->tail == plist->tail->next){ //1개라면
            plist->tail = NULL;
        } else { //2개이상이라면
            plist->tail = plist->before;
        }
    }
    
    plist->before->next = plist->cur->next;
    plist->cur = plist->before;
    
    free(rpos);
    (plist->numOfdata)--;
    return rdata;
}

int LCount(List* plist){
    return plist->numOfdata;
}

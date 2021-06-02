//
//  LinkedList.c
//  graph
//
//  Created by abc on 2021/06/03.
//

#include "LinkedList.h"

void listInit(List* plist){
    plist->head = (Node*)malloc(sizeof(Node));
    plist->head->next = NULL;
}
void Insert(List* plist, int input){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = input;
    newNode->next = plist->head->next;
    plist->head->next = newNode;
}
int LFirst(List* plist, int* pdata){
    if(plist->head->next == NULL) return 0;
    plist->before = plist->head;
    plist->cur = plist->head->next;
    *pdata = plist->cur->data;
    return 1;
}
int LNext(List* plist, int* pdata){
    if(plist->cur->next == NULL) return 0;
    plist->before = plist->cur;
    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
    return 1;
}
int isEmpty(List* plist){
    if(!plist->head->next) return 1;
    return 0;
}

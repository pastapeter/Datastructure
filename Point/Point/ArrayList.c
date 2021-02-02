//
//  ArrayList.c
//  Point
//
//  Created by abc on 2021/01/16.
//

#include "ArrayList.h"
#include <stdio.h>
#include <stdlib.h>

void ListInit(List* plist){ // 초기화
    plist->head = (Node*)malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->numOfdata = 0;
}

void LInsert(List* plist, LData data){
    FInsert(plist, data);
}

void FInsert(List* plist, LData data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = plist->head->next;
    plist->head->next = newNode;
    (plist->numOfdata)++;
}

int LFirst(List* plist, LData *pdata){
/*
- 첫번째 데이터가 pdata가 가르키는 메모리에 저장된다.
- 데이터의 참조를 위한 초기화가 진행된다
- 참조 성공시 TRUE(1), 실패시 FALSE(0)을 반환
*/
    if(plist->head->next == NULL) return FALSE;
    plist->cur = plist->head->next;
    plist->before = plist->head;
    *pdata = plist->cur->data;
    return TRUE;
}

int LNext(List *plist, LData *pdata){
/*
- 참조된 데이터의 다음 데이터가 pdata가 가리키는 메모리에 저장된다.
- 순파적인 참조를 위해서 반복 호출이 가능하다.
- 참조를 새로 시작하려면 먼저 LFirst 함수를 호출해야한다.
- 참조 성공시 TRUE(1), 실패시 FALSE(0) 반환
*/
    if(plist->cur->next == NULL) return FALSE;
    
    plist->before = plist->cur;
    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
    return TRUE;
}


LData LRemove(List *plist){
/*
- LFirst 또는 LNext 함수의 마지막 반환 데이터를 삭제한다.
- 삭제된 데이터는 반환한다.
- 마지막 반환 데이터를 삭제하므로 연이은 반복호출을 허용하지 않는다.
*/
    Node* rpos = plist->cur;
    LData rData = rpos->data;
    plist->before->next = plist->cur->next;
    plist->cur = plist->before;
    free(rpos);
    (plist->numOfdata)--;
    return rData;
}

int LCount(List* plist){
/*
 - 리스트에 저장되어 있는 데이터의 수를 반환한다.
*/
    return plist->numOfdata;
}

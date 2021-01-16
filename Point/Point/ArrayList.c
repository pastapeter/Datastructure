//
//  ArrayList.c
//  Point
//
//  Created by abc on 2021/01/16.
//

#include "ArrayList.h"
#include <stdio.h>

void ListInit(List* plist){ // 초기화
    (plist->numOfData) = 0; // 현재 리스트에 저장된 데이터 수는 0
    (plist->curPosition) = -1; // 현재 아무 위치도 가르키지 않음
}

void LInsert(List* plist, LData data){
/*
리스트에 데이터를 저장한다. 매개변수 data에 전달된 값을 저장한다.
*/
    if(plist->numOfData >= LIST_LEN){
        printf("저장이 불가합니다.\n");
        return;
    }
    plist->arr[plist->numOfData] = data;
    (plist->numOfData)++;
}

int LFirst(List* plist, LData *pdata){
/*
- 첫번째 데이터가 pdata가 가르키는 메모리에 저장된다.
- 데이터의 참조를 위한 초기화가 진행된다
- 참조 성공시 TRUE(1), 실패시 FALSE(0)을 반환
*/
    if(plist->numOfData == 0){
        return FALSE;
    }
    (plist->curPosition) = 0;
    *pdata = plist->arr[0];
    return TRUE;
}

int LNext(List *plist, LData *pdata){
/*
- 참조된 데이터의 다음 데이터가 pdata가 가리키는 메모리에 저장된다.
- 순파적인 참조를 위해서 반복 호출이 가능하다.
- 참조를 새로 시작하려면 먼저 LFirst 함수를 호출해야한다.
- 참조 성공시 TRUE(1), 실패시 FALSE(0) 반환
*/
    if(plist->curPosition >= (plist->numOfData)-1)
        return FALSE;
    (plist->curPosition)++;
    *pdata = plist->arr[plist->curPosition];
    return TRUE;
}


LData LRemove(List *plist){
/*
- LFirst 또는 LNext 함수의 마지막 반환 데이터를 삭제한다.
- 삭제된 데이터는 반환한다.
- 마지막 반환 데이터를 삭제하므로 연이은 반복호출을 허용하지 않는다.
*/
    int rpos = plist->curPosition; //삭제할 데이터의 인덱스 값 참조
    int num = plist->numOfData;
    int i;
    LData rdata = plist->arr[rpos]; // 삭제할 데이터를 임시로 저장

    // 삭제를 위한 데이터의 이동을 진행하는 반복문
    for(i=rpos;i<num-1;i++){
        plist->arr[i] = plist->arr[i+1];
    }
    (plist->numOfData)--;
    (plist->curPosition)--;
    return rdata;
}

int LCount(List* plist){
/*
 - 리스트에 저장되어 있는 데이터의 수를 반환한다.
*/
    return plist->numOfData;
}

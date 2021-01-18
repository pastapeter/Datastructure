//
//  ArrayList.c
//  Namecard
//
//  Created by abc on 2021/01/16.
//

#include "ArrayList.h"

void ListInit(List* plist){// 초기화
    plist->numOfData = 0;
    plist->curPosition = -1;
}
void LInsert(List* plist, LData data){//데이터 저장
    if(plist->numOfData >= LIST_LEN){
        printf("error");
        return;
    }
    plist->arr[plist->numOfData] = data;
    (plist->numOfData)++;
}
int LFirst(List* plist, LData* pdata){
    if(plist->numOfData ==0){
        return FALSE;
    }
    plist->curPosition =0;
    (*pdata) = plist->arr[0];
    return TRUE;
} // 첫 데이터 참조
int LNext(List* plist, LData* pdata){
    if(plist->curPosition>=(plist->numOfData)-1)
        return FALSE;
    (plist->curPosition)++;
    (*pdata) = plist->arr[plist->curPosition];
    return TRUE;
} // 두번쨰 이후 데이터 참조

LData LRemove(List* plist){
    int removePosition = plist->curPosition;
    int num = plist->numOfData;
    LData removeData = plist->arr[removePosition];
    int i;
    for(i=removePosition;i<num;i++){
        plist->arr[i] = plist->arr[i+1];
    }
    (plist->numOfData)--;
    (plist->curPosition)--;
    return removeData;
}
int LCount(List* plist){
    return plist->numOfData;
}

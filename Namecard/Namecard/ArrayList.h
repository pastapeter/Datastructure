//
//  ArrayList.h
//  Namecard
//
//  Created by abc on 2021/01/16.
//

#ifndef ArrayList_h
#define ArrayList_h
#include "Namecard.h"
#define LData NameCard*
#define TRUE 1
#define FALSE 0
#define LIST_LEN 100
#include <stdio.h>

typedef struct __ArrayList{
    LData arr[LIST_LEN];
    int numOfData;
    int curPosition;
}ArrayList;

typedef ArrayList List;

void ListInit(List* plist); // 초기화
void LInsert(List* plist, LData data); //데이터 저장
int LFirst(List* plist, LData* pdata); // 첫 데이터 참조
int LNext(List* plist, LData* pdata); // 두번쨰 이후 데이터 참조

LData LRemove(List* plist);
int LCount(List* plist);

#endif /* ArrayList_h */

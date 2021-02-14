//
//  CLinkedListBaseStack.c
//  LinkedListBaseStack2
//
//  Created by abc on 2021/02/14.
//

#include "CLinkedListBaseStack.h"
#include <stdlib.h>

void StackInit(Stack* pstack){
    pstack->plist = (List*)malloc(sizeof(List));
    ListInit(pstack->plist);
}
int SIsEmpty(Stack* pstack){
    if(LCount(pstack->plist) == 0){
        return TRUE;
    } else {
        return FALSE;
    }
}

void SPush(Stack* pstack, Data data){
    LInsertFront(pstack->plist, data);
}

Data SPop(Stack* pstack){
    Data data;
    if(SIsEmpty(pstack)){
        printf("ERROR");
        exit(-1);
    }
    LFirst(pstack->plist, &data);
    LRemove(pstack->plist);
    return data;

}

Data SPeek(Stack* pstack){
    Data data;
    if(SIsEmpty(pstack)){
        printf("ERROR");
        exit(-1);
    }
    LFirst(pstack->plist, &data);
    return data;
}

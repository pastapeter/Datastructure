//
//  main.c
//  Point
//
//  Created by abc on 2021/01/16.
//

#include <stdio.h>
#include <stdlib.h>
#include "Point.h"
#include "ArrayList.h"

int main(int argc, const char * argv[]) {
    List list;
    Point compPos;
    Point* ppos;
    
    ListInit(&list);
    
    //4개 데이터 저장
    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 1);
    LInsert(&list, ppos);
    
    ppos=(Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 2);
    LInsert(&list, ppos);
    
    ppos=(Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 1);
    LInsert(&list, ppos);
    
    ppos=(Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 2);
    LInsert(&list, ppos);
    
    // 저장된 데이터 출력
    if(LFirst(&list, &ppos)){
        ShowPointPos(ppos);
        while(LNext(&list, &ppos)){
            ShowPointPos(ppos);
        }
    }
    printf("\n\n");
    compPos.xpos = 2;
    compPos.ypos = 0;
    
    if(LFirst(&list, &ppos)){
        if(PointComp(&compPos, ppos)==1){
            ppos = LRemove(&list);
            free(ppos);
        }
        while(LNext(&list, &ppos)){
            if(PointComp(&compPos, ppos)==1){
                ppos=LRemove(&list);
                free(ppos);
            }
        }
    }
    
    // 남은 데이터 출력
    if(LFirst(&list, &ppos)){
        ShowPointPos(ppos);
        while(LNext(&list, &ppos)){
            ShowPointPos(ppos);
        }
    }
    printf("\n");
    return 0;
    
    
    
}

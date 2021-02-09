//
//  main.c
//  Circular Linked List
//
//  Created by abc on 2021/02/09.
//

#include <stdio.h>
#include "CLinkedList.h"
#define EMPOLYEE_NUM 4


void whoIsShift(List* plist, char* name, int date){
    int shiftNum = date%4;
    int nameNum = 0;
    int realNum = 0;
    Data data;
    if(LCount(plist)!=0){
        LFirst(plist, &data);
        if(data->name == name){
            nameNum = 0;
        }
        for(int i=1;i<LCount(plist);i++){
            LNext(plist, &data);
            if(data->name == name){
                nameNum = i;
                break;
            }
        }
    }
    realNum = (shiftNum + nameNum)%4;
    printf("%d\n", shiftNum);
    printf("%d\n", nameNum);
    printf("%d\n", realNum);
    LFirst(plist, &data);
    if(realNum == 0) printf("%s", data->name);
    for(int i=1;i<LCount(plist);i++){
        LNext(plist, &data);
        if(realNum == i){
            printf("%s", data->name);
            break;
        }
    }
}

int main(int argc, const char * argv[]) {
    List list;
    Data data;
    ListInit(&list);
    
    Identifier empolyees[4] = {
        {.name = "도현", .number = 1010}, {.name = "승은", .number = 1011}, {.name = "혜승", .number = 1012}, {.name = "채은", .number = 1013}
    };
    
    LInsert(&list, &empolyees[0]);
    LInsert(&list, &empolyees[1]);
    LInsert(&list, &empolyees[2]);
    LInsert(&list, &empolyees[3]);
    
    
    if(LFirst(&list, &data)){
        printf("%s ", data->name);
        for(int i=0;i<LCount(&list)*3-1 ;i++){
            if(LNext(&list, &data)){
                printf("%s ", data->name);
            }
        }
    }
    printf("\n\n");
    
    //2의배수를 모두 찾아서 삭제
//    if(LFirst(&list, &data)){
//        if(data%2==0){
//            LRemove(&list);
//        }
//        for(int i=0;i<LCount(&list)-1;i++){
//            if(LNext(&list, &data)){
//                if(data%2 == 0){
//                    LRemove(&list);
//                }
//            }
//        }
//    }
//    if(LCount(&list)!=0){
//        LFirst(&list, &data);
//        if(data%2==0) LRemove(&list);
//        for(int i=0;i<LCount(&list) - 1;i++){
//            LNext(&list, &data);
//            if(data%2==0) LRemove(&list);
//        }
//    }
    whoIsShift(&list, "승은", 2);
    printf("\n");
    
    if(LFirst(&list, &data)){
        printf("%s ", data->name);
        for(int i=0;i<LCount(&list)-1 ;i++){
            if(LNext(&list, &data)){
                printf("%s ", data->name);
            }
        }
    }
    printf("\n\n");
    
}

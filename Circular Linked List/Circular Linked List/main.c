//
//  main.c
//  Circular Linked List
//
//  Created by abc on 2021/02/09.
//

#include <stdio.h>
#include "CLinkedList.h"

int main(int argc, const char * argv[]) {
    List list;
    int data;
    ListInit(&list);
    
    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 5);
    LInsertFront(&list, 7);
    LInsertFront(&list, 1);
    
    if(LFirst(&list, &data)){
        printf("%d ", data);
        for(int i=0;i<LCount(&list)*3-1 ;i++){
            if(LNext(&list, &data)){
                printf("%d ", data);
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
    if(LCount(&list)!=0){
        LFirst(&list, &data);
        if(data%2==0) LRemove(&list);
        for(int i=0;i<LCount(&list) - 1;i++){
            LNext(&list, &data);
            if(data%2==0) LRemove(&list);
        }
    }
    
    if(LFirst(&list, &data)){
        printf("%d ", data);
        for(int i=0;i<LCount(&list)-1 ;i++){
            if(LNext(&list, &data)){
                printf("%d ", data);
            }
        }
    }
    printf("\n\n");
    
}

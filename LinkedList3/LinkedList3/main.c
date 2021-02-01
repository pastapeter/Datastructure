//
//  main.c
//  LinkedList3
//
//  Created by abc on 2021/02/01.
//

#include <stdio.h>
#include "DLinkedList.h"


int main(int argc, const char * argv[]) {
    
    // 리스트 생성 및 초기화
    List list;
    int data;
    ListInit(&list);
    
    // 5개의 데이터 저장
    LInsert(&list, 11);
    LInsert(&list, 22);
    LInsert(&list, 33);
    LInsert(&list, 11);
    LInsert(&list, 22);
    
    // 저장한 데이터 전체 출력
    printf("현재 데이터 수: %d \n", LCount(&list));
    
    if(LFirst(&list, &data)){
        printf("%d ", data);
        while(LNext(&list, &data)){
            printf("%d ", data);
        }
    }
    printf("\n\n");
    
    // 숫자 22를 모두 삭제
    if(LFirst(&list, &data)){
        if(data == 22){
            LRemove(&list);
        }
        while (LNext(&list, &data)) {
            if(data == 22){
                LRemove(&list);
            }
        }
    }
    
    // 삭제 후 남아있는 데이터 전체 출력
    printf("현재 남아있는 데이터 수 : %d \n", LCount(&list));
    
    if(LFirst(&list, &data)){
        printf("%d ", data);
        while(LNext(&list, &data)){
            printf("%d ", data);
        }
    }
    printf("\n\n");
    return 0;
}

//
//  main.c
//  DBLinkedList
//
//  Created by abc on 2021/02/13.
//

#include <stdio.h>
#include "DBLinkedList.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    List list;
    int data;
    
    // list 초기화
    ListInit(&list);
    
    // 8개 데이터 저장
    LInsert(&list, 1);
    LInsert(&list, 2);
    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 5);
    LInsert(&list, 6);
    LInsert(&list, 7);
    LInsert(&list, 8);
    
    // 저장된 데이터 조회
    if(LFirst(&list, &data)){
        printf("%d ", data);
        
        //오른쪽 노드로 이동하며 데이터 조회
        while(LNext(&list, &data)){
            printf("%d ", data);
        }
        // 왼쪽 노드로 이동하며 데이터 조회
        while(LPrevious(&list, &data)){
            printf("%d ", data);
        }
        
        printf("\n\n");
    }
    
    
    return 0;
}

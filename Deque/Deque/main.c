//
//  main.c
//  Deque
//
//  Created by abc on 2021/02/20.
//

#include <stdio.h>
#include "Deque.h"

int main(int argc, const char * argv[]) {
   
    Deque deq;
    DequeInit(&deq);
    
    DQAddFirst(&deq, 3);
    DQAddFirst(&deq, 2);
    DQAddFirst(&deq, 1);
    DQAddLast(&deq, 4);
    DQAddLast(&deq, 5);
    DQAddLast(&deq, 6);
    
    //데이터 꺼내기
    
    while(!DQIsEmpty(&deq)){
        printf("%d ", DQRemoveFirst(&deq));
    }
    
    printf("\n\n");
    
    DQAddFirst(&deq, 3);
    DQAddFirst(&deq, 2);
    DQAddFirst(&deq, 1);
    DQAddLast(&deq, 4);
    DQAddLast(&deq, 5);
    DQAddLast(&deq, 6);
    
    while (!DQIsEmpty(&deq)) {
        printf("%d ", DQRemoveLast(&deq));
    }
    printf("\n\n");
    return 0;
}

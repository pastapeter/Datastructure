//
//  main.c
//  Deque
//
//  Created by abc on 2021/02/20.
//

#include <stdio.h>
#include "DequeBaseQueue.h"

int main(int argc, const char * argv[]) {
    
    Queue que;
    
    QueueInit(&que);
    Enqueue(&que, 1);
    Enqueue(&que, 2);
    Enqueue(&que, 3);
    Enqueue(&que, 4);
    Enqueue(&que, 5);
    Enqueue(&que, 6);
    
    while(!QIsEmpty(&que)){
        printf("%d ", Dequeue(&que));
    }
    
    
   
    
 // 덱 ------------------------------------------
//    Deque deq;
//    DequeInit(&deq);
//
//    DQAddFirst(&deq, 3);
//    DQAddFirst(&deq, 2);
//    DQAddFirst(&deq, 1);
//    DQAddLast(&deq, 4);
//    DQAddLast(&deq, 5);
//    DQAddLast(&deq, 6);
//
//    //데이터 꺼내기
//
//    while(!DQIsEmpty(&deq)){
//        printf("%d ", DQRemoveFirst(&deq));
//    }
//
//    printf("\n\n");
//
//    DQAddFirst(&deq, 3);
//    DQAddFirst(&deq, 2);
//    DQAddFirst(&deq, 1);
//    DQAddLast(&deq, 4);
//    DQAddLast(&deq, 5);
//    DQAddLast(&deq, 6);
//
//    while (!DQIsEmpty(&deq)) {
//        printf("%d ", DQRemoveLast(&deq));
//    }
//    printf("\n\n");
    return 0;
}

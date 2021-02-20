//
//  main.c
//  CircularQueue
//
//  Created by abc on 2021/02/19.
//

#include <stdio.h>
#include "CircularQueue.h"

int main(int argc, const char * argv[]) {
    Queue q;
    
    QueueInit(&q);
    
    Enqueue(&q, 1);
    Enqueue(&q, 2);
    Enqueue(&q, 3);
    Enqueue(&q, 4);
    Enqueue(&q, 5);
    Enqueue(&q, 6);
    
    
    while(!QIsEmpty(&q)){
        printf("%d ", Dequeue(&q));
    }
    return 0;
}

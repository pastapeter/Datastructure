//
//  queue.h
//  Sort
//
//  Created by abc on 2021/04/18.
//

#ifndef queue_h
#define queue_h

#define MAX_NUM 21 //20개 이상 입력큐에 들어온다면 오류
#define TRUE 1
#define FALSE 0


#include <stdio.h>
#include <stdlib.h>

typedef char Data;

typedef struct Queue {
    Data queueArray[MAX_NUM];
    int front;
    int rear;
} queue;

void QueueInit(queue* pq);
int isEmpty(queue* pq);
int isFull(queue* pq);
void enqueue(queue* pq,Data input);
Data dequeue(queue* pq);
#endif /* queue_h */

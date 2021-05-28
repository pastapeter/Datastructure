//
//  Queue.h
//  BinaryTree3
//
//  Created by abc on 2021/05/27.
//

#ifndef Queue_h
#define Queue_h

#define MAX_NUM 30 //20개 이상 입력큐에 들어온다면 오류
#define TRUE 1
#define FALSE 0

#include "Stack.h"

typedef struct Queue {
    Btree* queueArray[MAX_NUM];
    int front;
    int rear;
} queue;

void QueueInit(queue* pq);
int QisEmpty(queue* pq);
int QisFull(queue* pq);
void enqueue(queue* pq,Btree* input);
Btree* dequeue(queue* pq);

#endif /* Queue_h */

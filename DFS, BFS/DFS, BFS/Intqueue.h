//
//  Intqueue.h
//  DFS, BFS
//
//  Created by abc on 2021/06/02.
//

#ifndef Intqueue_h
#define Intqueue_h
#include "Stack.h"

typedef struct Queue {
    int queueArray[MAX_NUM];
    int front;
    int rear;
} queue;

void QueueInit(queue* pq);
int isEmpty(queue* pq);
int isFull(queue* pq);
void enqueue(queue* pq,int input);
int dequeue(queue* pq);

#endif /* Intqueue_h */

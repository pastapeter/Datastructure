//
//  queue.h
//  DFS, BFS
//
//  Created by abc on 2021/06/02.
//

#ifndef queue_h
#define queue_h

#include ""


typedef struct Queue {
    Graph* queueArray[MAX_NUM];
    int front;
    int rear;
} queue;

void QueueInit(queue* pq);
int QisEmpty(queue* pq);
int QisFull(queue* pq);
void enqueue(queue* pq,Graph* input);
Graph* dequeue(queue* pq);

#endif /* queue_h */

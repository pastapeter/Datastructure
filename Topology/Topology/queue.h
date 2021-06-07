//
//  queue.h
//  Topology
//
//  Created by abc on 2021/06/07.
//

#ifndef queue_h
#define queue_h
#define MAX_LEN 100

#include "LinkedList.h"


typedef int Data;

typedef struct _queue{
    int front;
    int rear;
    Data queueArray[MAX_LEN];
}queue;

void queueInit(queue* pq);
void enqueue(queue* pq, Data input);
Data dequeue(queue* pq);
int qisEmpty(queue* pq);
int isFull(queue* pq);



#endif /* queue_h */

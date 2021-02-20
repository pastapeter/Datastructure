//
//  CircularQueue.h
//  CircularQueue
//
//  Created by abc on 2021/02/19.
//

#ifndef CircularQueue_h
#define CircularQueue_h
#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define QUE_LEN 100
typedef int Data;

typedef struct _cQueue{
    int front;
    int rear;
    Data queArr[QUE_LEN];
} CQueue;

typedef CQueue Queue;

void QueueInit(Queue* pq);
int QIsEmpty(Queue *pq);

void Enqueue(Queue* pq, Data data);
Data Dequeue(Queue* pq);
Data QPeek(Queue* pq);

#endif /* CircularQueue_h */

//
//  DequeBaseQueue.h
//  Deque
//
//  Created by abc on 2021/02/20.
//

#ifndef DequeBaseQueue_h
#define DequeBaseQueue_h

#define TRUE 1
#define FALSE 0

#include "Deque.h"
#include <stdio.h>

typedef Deque Queue; // 해더파일에서는 별도의 구조체를 정의할 필요없이 그냥 deque 구조체를 가지고 queue를 해결가능함

void QueueInit(Queue* pq);
int QIsEmpty(Queue* pq);
void Enqueue(Queue* pq, Data data);
Data Dequeue(Queue* pq);
Data QPeek(Queue* pq);

#endif /* DequeBaseQueue_h */

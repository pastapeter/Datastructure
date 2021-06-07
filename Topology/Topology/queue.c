//
//  queue.c
//  Topology
//
//  Created by abc on 2021/06/07.
//

#include "queue.h"

void queueInit(queue* pq){
    pq->front = 0;
    pq->rear = 0;
}
void enqueue(queue* pq, Data input){
    if(isFull(pq)){
        exit(-1);
    }
    pq->rear = (pq->rear+1) % MAX_LEN;
    pq->queueArray[pq->rear] = input;
}

Data dequeue(queue* pq){
    if(qisEmpty(pq)){
        exit(-1);
    }
    pq->front = (pq->front+1)%MAX_LEN;
    return pq->queueArray[pq->front];
}

int qisEmpty(queue* pq){
    return pq->front == pq->rear;
}

int isFull(queue* pq){
    return (pq->rear+1)%MAX_LEN == pq->front;
}

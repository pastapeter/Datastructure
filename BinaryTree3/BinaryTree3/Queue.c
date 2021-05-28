//
//  Queue.c
//  BinaryTree3
//
//  Created by abc on 2021/05/27.
//

#include "Queue.h"

void QueueInit(queue* pq){
    pq->front = 0;
    pq->rear = 0;
}

int QisEmpty(queue* pq){
    if(pq->front == pq->rear){
        return TRUE;
    } else return FALSE;
}

int QisFull(queue* pq){
    return (pq->rear+1)%MAX_NUM == pq->front;
}

void enqueue(queue* pq,Btree* input){
    if(QisFull(pq)){
        printf("ERROR");
        exit(-1);
    }
    pq->rear = (pq->rear+1) % MAX_NUM ;
    pq->queueArray[pq->rear] = input;
}

Btree* dequeue(queue* pq){
    if(QisEmpty(pq)){
        printf("ERROR");
        exit(-1);
    }
    pq->front = (pq->front+1) % MAX_NUM;
    return pq->queueArray[pq->front];
}

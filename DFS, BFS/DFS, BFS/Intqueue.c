//
//  Intqueue.c
//  DFS, BFS
//
//  Created by abc on 2021/06/02.
//

#include "Intqueue.h"

void QueueInit(queue* pq){
    pq->front = 0;
    pq->rear = 0;
}

int isEmpty(queue* pq){
    if(pq->front == pq->rear){
        return TRUE;
    } else return FALSE;
}

int isFull(queue* pq){
    return (pq->rear+1)%MAX_NUM == pq->front;
}

void enqueue(queue* pq,int input){
    if(isFull(pq)){
        printf("ERROR");
        exit(-1);
    }
    pq->rear = (pq->rear+1) % MAX_NUM ;
    pq->queueArray[pq->rear] = input;
}

int dequeue(queue* pq){
    if(isEmpty(pq)){
        printf("ERROR");
        exit(-1);
    }
    pq->front = (pq->front+1) % MAX_NUM;
    return pq->queueArray[pq->front];
}

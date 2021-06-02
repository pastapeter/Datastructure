//
//  queue.c
//  DFS, BFS
//
//  Created by abc on 2021/06/02.
//

#include "queue.h"

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

void enqueue(queue* pq,Graph* input){
    if(QisFull(pq)){
        printf("ERROR");
        exit(-1);
    }
    pq->rear = (pq->rear+1) % MAX_NUM ;
    pq->queueArray[pq->rear] = input;
}

Graph* dequeue(queue* pq){
    if(QisEmpty(pq)){
        printf("ERROR");
        exit(-1);
    }
    pq->front = (pq->front+1) % MAX_NUM;
    return pq->queueArray[pq->front];
}


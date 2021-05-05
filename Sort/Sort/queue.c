//
//  queue.c
//  Sort
//
//  Created by abc on 2021/04/18.
//

#include "queue.h"



void QueueInit(queue* pq){
    pq->front = 0;
    pq->rear = 0;
}

int isEmpty(queue* pq){
    if(pq->front == pq->rear){
        return TRUE;
    } else return FALSE;
}

int NextposIdx(int pos){
    if(pos == MAX_NUM - 1){
        return FALSE;
    } else {
        return pos+1;
    }
}

int isFull(queue* pq){
    return (pq->rear+1)%MAX_NUM == pq->front;
}

void enqueue(queue* pq,Data input){
    if(isFull(pq)){
        printf("ERROR");
        exit(-1);
    }
    pq->rear = (pq->rear+1) % MAX_NUM ;
    pq->queueArray[pq->rear] = input;
}

Data dequeue(queue* pq){
    if(isEmpty(pq)){
        printf("ERROR");
        exit(-1);
    }
    pq->front = (pq->front+1) % MAX_NUM;
    return pq->queueArray[pq->front];
}

//
//  RadixSort.c
//  Sort
//
//  Created by abc on 2021/04/18.
//

#include <stdio.h>
#include "queue.h"
#define BUCKETS 10 // 0-9
#define DIGITS 4

void radixSort(int arr[], int n){
    // 기수정렬의 bucket들은 모두 큐이다.
    // 각자리에 맞춰서 정렬시키면 정렬시킨대로 선입선출해야하기 때문이다. 이렇기 때문에 큐를 사용한다.
    int i, b, d, factor = 1; //
    queue queues[BUCKETS]; // 큐 배열 선언;
    for(b=0;b<BUCKETS;b++){
        QueueInit(&queues[b]);
    }
    
    for(d=0; d<DIGITS; d++){
        for(i=0;i<n;i++){
            enqueue(&queues[(arr[i]/factor)%10], arr[i]); //자리수에 맞게 한다. 처음에는 1의자리 그리고 다음에는 10의자리 이렇게 진행된다. factor가 *10씩되면서 1자리 10자리...로 간다.
        }
        for(b=i=0;b<BUCKETS;b++){ // 1의자리에 맞게 정렬한뒤에 다시 arr에 집어넣고 10자리로 다시 정렬할 생각을한다.
            while(!isEmpty(&queues[b])){
                arr[i++] = dequeue(&queues[b]);
            }
        }
        factor *= 10; // 자리수가 끝나면 올려서 자리수를 더해준다. 
    }
}

int main(){
    int arr[10] = {112,43,2,5,68,8,1,77,23,89};
    radixSort(arr, 10);
    for(int i=0;i<10;i++){
        printf("%d ", arr[i]);
    }
    
}

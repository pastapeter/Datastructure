//
//  QuicksortStack.c
//  Sort
//
//  Created by abc on 2021/04/18.
//

#include <stdio.h>
#include "Stack.h"
#define SWAP(a, b, t) ((t)=(a), (a)= (b), (b) = (t))

int partition(int arr[], int left, int right){
    int temp;
    int pivot = arr[left];
    int low = left + 1;
    int high = right;
    while(low <= high){
        while(arr[low] < pivot && low <= right){
            low ++;
        }
        while(arr[high] > pivot && high >= left){
            high--;
        }
        if(low <= high){
            SWAP(arr[low], arr[high], temp);
        }
    }
    SWAP(arr[left], arr[high], temp);
    
    return high;
}

void Quicksort(int arr[], int left, int right){
    stack stack;
    stackInit(&stack);
    Qsort start;
    start.left = left;
    start.right = right;
    push(&stack, start);
    
    while(!isEmpty(&stack)){
        Qsort popelement = pop(&stack);
        left = popelement.left;
        right = popelement.right;
        
        if(left < right){
            int pivot = partition(arr, left, right);
            Qsort first, second;
            first.left = left;
            first.right = pivot - 1;
            second.left = pivot + 1;
            second.right = right;
            push(&stack, first);
            push(&stack, second);
        }
    }
}

int main(){
    int arr[10] = {10,8,6,20,4,3,22,1,0,15};
    Quicksort(arr, 0, 9);
    for(int i =0; i<10;i++){
        printf("%d ", arr[i]);
    }
}

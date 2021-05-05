//
//  QuickSort.c
//  Sort
//
//  Created by abc on 2021/04/18.
//

#include <stdio.h>
#define SWAP(a, b, t) ((t)=(a), (a)= (b), (b) = (t))

int partition(int arr[], int left, int right){
    int temp;
    int low = left+1; // pivot 다음이 left니깐 ㅇㅇ ㅇㅈㅇㅈ
    int high = right;
    int pivot = arr[left];
    while(low <= high){
        while(arr[low] < pivot && low <= right){
            low++;
        }
        while(arr[high] > pivot && high >= left){
            high --;
        }
        if(low <= high){
            SWAP(arr[low], arr[high], temp);
        }
    }
    SWAP(arr[left], arr[high], temp);
    printf("high %d\n", high);
    return high;
}

void QuickSort(int arr[], int left, int right){
    if (left < right) {
        int pivot = partition(arr, left, right);
        QuickSort(arr, left, pivot-1);
        QuickSort(arr, pivot+1, right);
    }
}

int main(){
    int arr[5] = {3,2,4,5,8};
    QuickSort(arr, 0, 4);
    for(int i =0; i<5;i++){
        printf("%d ", arr[i]);
    }
}

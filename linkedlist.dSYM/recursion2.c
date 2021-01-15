#include <stdio.h>
/*
이진탐색 재귀
1. 탐색 범위의 중앙에 목표값 저장되어있는지 확인
2. 아니라면? 탐색범위를 반으로 나눠서 다시 시작

이진탐색 탈출 조건
탐색 범위의 시작위치를 의미하는 first가 탐색 범위의 끝을 의미하는 last보다 커지는 경우
*/

int BsearchRecur(int arr[], int first, int last, int target){
    int mid = (first + last)/2;
    if(first>last)
        return -1;
    else if(arr[mid]==target){
        return mid;
    }
    else{
        if(arr[mid]>target){
            return BsearchRecur(arr, first, mid-1, target);
        }
        else{
            return BsearchRecur(arr, mid+1, last, target);
        }
    }
}

int main(){
    int arr[] = {1,3,5,7,9};
    int idx;
    idx = BsearchRecur(arr, 0, sizeof(arr)/sizeof(int)-1, 7);
    if(idx==-1){
        printf("failed\n");
    }
    else{
        printf("Target index %d\n", idx);
    }
    
}
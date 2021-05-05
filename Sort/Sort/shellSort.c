//
//  shellSort.c
//  Sort
//
//  Created by abc on 2021/04/18.
//

#include <stdio.h>

void insertionSort(int array[], int first, int last, int gap){
    int j = 0;
    int key = 0;
    int temp = 0;
    for(int i=first+gap; i<=last; i += gap){ // 정렬안된것중에하나 고르기
                key = array[i]; // key는 정렬안된것 중에 하나임
                j = i-gap;
                while(j>=0){ //정렬되어있는 배열에서 내려가기임, array[j]가 key보다 크다면 뒤로 미뤄야함.
                    if(array[j]>key){
                        array[j+gap] = array[j];
                    } else {break;}
                    j -= gap;
                }
                array[j+gap] = key; // 하나 더 뺏으니 ㅇㅇ
    }
}

int main(){
    int i, gap;
    int arr[11] = {10,8,6,20,4,3,22,1,0,15,16};
    int n= 11;
    for(gap = n/2; gap > 0; gap=gap/2){
        if(gap%2==0)gap++;
        for(i=0;i<gap;i++){
            //printf("insertion sort에 들어가는 갭 gap %d\n", gap);
            insertionSort(arr, i, n-1, gap);
            //printf("insertion sort에 나오는 갭 gap %d\n", gap); // 여기서 gap이 갑자기 바뀜 .
        }
        
    }
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
}
    


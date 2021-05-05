//
//  bubbleSort.c
//  Sort
//
//  Created by abc on 2021/04/18.
//

#include <stdio.h>

int main(){
    int arr[10] = {2,5,1,7,3,23,8,12,14,0};
    int i,j,temp;
    for(i=9;i>0;i--){ // 비교 횟수는 n-1번 한다. 여기서 i는 n번쨰 수를 결정지어줌
        // i가 9면 9번째 element를 결정짓는것임
        for(j=0;j<i;j++){
            // j<i인 것은 우리는 10개의 데이터가 있으면 swap은 9개까지 일어날수 있다.
            //따라서 j 는 0 ~ i까지 스왑이 일어나는것이다.
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for(int i=0;i<10;i++){
        printf("%d ", arr[i]);
    }
}

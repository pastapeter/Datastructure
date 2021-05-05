//
//  SelectionSort.c
//  Sort
//
//  Created by abc on 2021/04/18.

// 버블소트 이동 3*비교횟수 , 비교는 어차피 계속되어야한ㄷ ㅏ.
// 버블소트의 단점은 데이터의 이동이 많다는 것이다.
// insertino도 데이터의 이동은 많지만, 정렬이 거의 되어있을때 매우 효울적이라는 것 -> 레코드가 클 경우 불리하다.
// 선택정렬은 i를 기준으로 i+1은 정렬이 되지 않은 부분이다. 정렬되지 않은 부분의 최소값을 정렬되지 않은 부분의 첫부분에 넣는 것이다.
// 오른쪽 부분의 데이터가 없을때 ㄱ까지 반복한ㄷㅏ. 선택정렬은 이동횟수가 적다 왜냐면 최소값을 찾아서 저열ㄹ안된곳 맨앞에 꽂즌ㄴ다


#include <stdio.h>
#define SWAP(a,b,t) ((t)=(a), (a)=(b), (b)=(t))


int main() {
    int arr[10] = {6,2,1,3,4,5,7,8,9,10};
    int i,j,temp;
    int least;
    for(i=0;i<9;i++){
        least = i;
        for(j=i+1;j<10;j++){
            if(arr[least]>arr[j]){
                least = j;
            }
        }
        SWAP(arr[least], arr[i], temp);
    }
    for(int i=0;i<10;i++){
        printf("%d ", arr[i]);
    }
}

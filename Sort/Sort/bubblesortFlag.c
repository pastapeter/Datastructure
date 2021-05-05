//
//  bubblesortFlag.c
//  Sort
//
//  Created by abc on 2021/04/18.
//

// 버블소트 이동 3*비교횟수
// 버블소트의 단점은 데이터의 이동이 많다는 것이다.
// insertino도 데이터의 이동은 많지만, 정렬이 거의 되어있을때 매우 효울적이라는 것 -> 레코드가 클 경우 불리하다.


#include <stdio.h>
#define SWAP(a,b,t) ((t)=(a), (a)=(b), (b)=(t))

int main(){
    int arr[10] = {0,2,1,3,4,5,7,8,9,10};
    int i,j,temp;
    int flag;
    for(i=9;i>0;i--){ // 비교 횟수는 n-1번 한다. 여기서 i는 n번쨰 수를 결정지어줌
        flag = 0;
        for(j=0;j<i;j++){
            if(arr[j] > arr[j+1]){
                SWAP(arr[j], arr[j+1], temp);
                flag = 1;
            }
        }
        //j가 0에서 i까지 돌아가보니, 한번도 수왑을 한적이 없어진다. 즉, 다 sort가 되어있다는 것이다. 그렇다면 바로 break로 빠져나간다.
        if (flag == 0) {
            printf("정렬완료\n");
            break;
        }
    }
    for(int i=0;i<10;i++){
        printf("%d ", arr[i]);
    }
}

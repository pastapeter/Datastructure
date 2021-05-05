#include <stdio.h>
#define SWAP(a, b, t) ((t)=(a), (a)= (b), (b) = (t))


void adjust(int arr[], int root, int n){ // 4 3 2 1 0
    int child, temp, rootkey;
    rootkey = arr[root];
    child = (root+1) * 2 - 1; // 1
    temp = arr[root];
    while(child < n){
        if(arr[child]<arr[child+1] && child < n-1){
            child++; // 여기서 이진 트리를 떠날생각은 할 필요없음 왜냐면 아래서부터 bottomup 방식으로 힙을 짜기 때문에 넘어갈일이 없다고 보면 댐ㅇㅇ 
        }
        if(rootkey > arr[child]){
            break;
        }
        else{
            arr[(child-1) /2] = arr[child];
            child  = (child+1)*2 - 1; //밑으로 한단계 내려가겠다.
        }
    }
    arr[(child-1) / 2] = temp;
}

void heapSort(int arr[], int n){
    // 1/2 해주는 것은 root 를 찾기 위한 것  1 2 3 이고 있다면 1이 루트고, 2,3 은 자식이라고 생각하면된다.
    // 일단 첫 포문은 initial heap을 만들어 주는 과정임
    int i;
    int temp;
    for(i = (n-1)/2; i>=0;i--){ // 5 4 3 2 1 0
        adjust(arr, i, n); // n = 9;
    }
    for(i=n-1; i>0; i--){
        SWAP(arr[0], arr[i], temp);
        adjust(arr, 0, i);
    }
    
}


int main() {
    int arr[12] = {77, 61, 59, 60, 100, 101, 26, 85 ,1, 5, 88,12};
    int i;
    heapSort(arr, 12);
    for(i = 0; i<12;i++){
        printf("arr[%d] %d\n", i, arr[i]);
    }
}

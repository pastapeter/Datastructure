//
//  main.c
//  Sort
//
//  Created by abc on 2021/04/18.
//

#include <stdio.h>


int main(int argc, const char * argv[]) {
    int array[10] = {2,5,1,7,3,23,8,12,14,0};
    int key = 0;
    int i=0, j = 0;
    
    for(i=1;i<10;i++){ //array[0] 값은 이미 정렬되어있다고 생각하는 것임
        key = array[i];
        for(j = i-1; j>=0 && array[j] > key; j--){
            array[j+1] = array[j];
        }
        array[j+1] = key;
    }
    
//    for(int i=1;i<10;i++){ // 정렬안된것중에하나 고르기
//        key = array[i]; // key는 정렬안된것 중에 하나임
//        j = i-1;
//        while(j>=0){ //정렬되어있는 배열에서 내려가기임, array[j]가 key보다 크다면 뒤로 미뤄야함.
//            if(array[j]>key){
//                array[j+1] = array[j];
//            } else {break;}
//            j--;
//        }
//        array[j+1] = key; // 하나 더 뺏으니 ㅇㅇ
//    }
    
    
    
    
//    for(int i=1;i<10;i++){
//        for(j = i;j>0;j--){
//            if(array[j] <array[j-1]){
//                int temp = array[j];
//                array[j] = array[j-1];
//                array[j-1] = temp;
//            }
//            else break;
//        }
//    }
    for(int i=0;i<10;i++){
        printf("%d ", array[i]);
    }
    return 0;
}

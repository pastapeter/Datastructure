////
////  MergeSort.c
////  Sort
////
////  Created by abc on 2021/04/18.
////
//
//#include <stdio.h>
//int sorted[10];


# include <stdio.h>
# define MAX_SIZE 10
int sorted[MAX_SIZE];

//void merge(int list[], int left, int mid, int right){
//  int i, j, k, l;
//  i = left;
//  j = mid+1;
//  k = left;
//
//  /* 분할 정렬된 list의 합병 */
//  while(i<=mid && j<=right){
//    if(list[i]<=list[j])
//      sorted[k++] = list[i++];
//    else
//      sorted[k++] = list[j++];
//  }
//
//  // 남아 있는 값들을 일괄 복사
//  if(i>mid){
//      for(l=j; l<=right; l++) sorted[k++] = list[l];
//    } else{
//    for(l=i; l<=mid; l++){sorted[k++] = list[l];}
//}
//
//      // 배열 sorted[](임시 배열)의 리스트를 배열 list[]로 재복사
//    for(l=left; l<=right; l++){
//        list[l] = sorted[l];
//      }
//}
//
//void mergeSort(int list[], int left, int right){
//  int mid;
//
//  if(left<right){
//      mid = (left+right)/2 ;
//    mergeSort(list, left, mid); // 앞쪽 부분 리스트 정렬 -정복(Conquer)
//    mergeSort(list, mid+1, right); // 뒤쪽 부분 리스트 정렬 -정복(Conquer)
//    merge(list, left, mid, right); // 정렬된 2개의 부분 배열을 합병하는 과정 -결합(Combine)
//  }
//}

void merge(int arr[], int left, int mid, int right){
    int l = left;
    int m = mid;
    int nl = mid+1;

    int sortIndex = left;
    while(l<=m && nl<=right){
        if(arr[l] <= arr[nl]){
            sorted[sortIndex++] = arr[l++];
        }
        else{
            sorted[sortIndex++] = arr[nl++];
        }
    }
    
    if(l > m){
        for(int i = nl; i<=right;i++){
            sorted[sortIndex++] = arr[i];
        }
    } else {
        for(int i = l; i<=m;i++){
            sorted[sortIndex++] = arr[i];
        }
    }

    for(int i=left;i<=right;i++){
        arr[i] = sorted[i];
    }
}


void mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = (right + left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int main(){
  int i;
  int n = MAX_SIZE;
  int list[MAX_SIZE] = {10,8,6,20,4,3,22,1,0,15};

  // 합병 정렬 수행(left: 배열의 시작 = 0, right: 배열의 끝 = 7)
  mergeSort(list, 0, n-1);

  // 정렬 결과 출력
  for(i=0; i<n; i++){
    printf("%d\n", list[i]);
  }
}


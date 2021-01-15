#include <stdio.h>

int Lsearch(int arr[], int len, int target){
    int i;
    for(i=0;i<len;i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {3,5,2,4,9};
    int idx;
    idx = Lsearch(arr,sizeof(arr)/sizeof(int), 4 );
    if(idx==-1){
        printf("error\n");
    }
    else{
        printf("target index %d\n", idx);
    }
    
}
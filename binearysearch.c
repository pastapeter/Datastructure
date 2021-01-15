#include <stdio.h>

int Bsearch(int arr[], int len, int target){
    int first = 0;
    int last = len-1;
    int mid;
    while(first<=last){
        mid = (first+last)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            last = mid-1;
        }
        else{
            first = mid+1;
        }
    }
    return -1;
}
int main(){
    int arr[] = {1,3,5,7,9};
    int index;
    index = Bsearch(arr, sizeof(arr)/sizeof(int), 7);
    if(index==-1){
        printf("error\n");
    }
    else{
        printf("target index %d\n", index);
    }
    index = Bsearch(arr, sizeof(arr)/sizeof(int), 4);
    if(index==-1){
        printf("error\n");
    }
    else{
        printf("target index %d\n", index);
    }
    
}
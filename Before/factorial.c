#include <stdio.h>
int factorial(int num){
    if(num==0)
        return 1;
    else
    {
     return num*factorial(num-1);   
    }
}
int main(){
    int result=0;
    result = factorial(5);
    printf("%d\n", result);
}
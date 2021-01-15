#include <stdio.h>

void Recursive(int num){
   if(num<=0)
        return;
    printf("Recursive call\n");
    Recursive(num-1);
}
int main(){
    Recursive(3);
}
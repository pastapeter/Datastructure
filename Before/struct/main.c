#include <stdio.h>
#include "stdiv.h"
#include "intdiv3.h"

//extern Div IntDiv(int num1, int num2);

int main(){
    Div val = IntDiv(5,2);
    printf("목: %d \n", val.quotient);
    printf("나머지 %d \n", val.remainder);
    return 0;
}
#include "stdiv.h"

Div IntDiv(num1, num2){
    Div dval;
    dval.quotient = num1/num2;
    dval.remainder = num1%num2;
    return dval;
}
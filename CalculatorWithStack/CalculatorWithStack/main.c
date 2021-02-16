//
//  main.c
//  CalculatorWithStack
//
//  Created by abc on 2021/02/16.
//

#include <stdio.h>
#include "InfixCalculator.h"


int main(int argc, const char * argv[]) {
    // insert code here...
    char exp1[] = "3-2+4";
    char exp2[] = "(1+2)*3";
    char exp3[] = "((1-2)+3)*(5-2)";
    
    
    printf("%s  = %d\n", exp1, EvalInfixExp(exp1));
    printf("%s  = %d\n", exp2, EvalInfixExp(exp2));
    printf("%s  = %d\n", exp3, EvalInfixExp(exp3));

    return 0;
}

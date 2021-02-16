//
//  InfixCalculator.c
//  CalculatorWithStack
//
//  Created by abc on 2021/02/16.
//

#include "InfixCalculator.h"
#include "InfixToPostfix.h"
#include "PostCalculator.h"
#include <string.h>
#include <stdlib.h>

int EvalInfixExp(char exp[]){
    int len  = strlen(exp);
    int result;
    char* expcpy = (char*)malloc(len+1);
    strcpy(expcpy, exp);
    ConvToRPNExp(expcpy);
    result = EvalRPNExp(expcpy);
    
    free(expcpy);
    return result;
}

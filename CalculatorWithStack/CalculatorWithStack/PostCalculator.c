//
//  PostCalculator.c
//  CalculatorWithStack
//
//  Created by abc on 2021/02/16.
//

#include "PostCalculator.h"
#include <ctype.h>
#include <string.h>
#include "ListBasedStack.h"

int EvalRPNExp(char exp[]){
    Stack stack;
    int expLen = strlen(exp);
    char tok, op1, op2;
    StackInit(&stack);
    
    for(int i=0;i<expLen;i++){
        tok = exp[i];
        if(isdigit(tok)){
            SPush(&stack, tok - '0');
        } else {
            op2 = SPop(&stack);
            op1 = SPop(&stack);
            switch (tok) {
                case '+':
                    SPush(&stack,op1 + op2);
                    break;
                case '-':
                    SPush(&stack,op1 - op2);
                    break;
                case '*':
                    SPush(&stack,op1 * op2);
                    break;
                case '/':
                    SPush(&stack,op1 / op2);
                    break;
                    
            }
        }
    }
    return SPop(&stack);
}

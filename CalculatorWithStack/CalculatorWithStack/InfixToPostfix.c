//
//  InfixToPostfix.c
//  CalculatorWithStack
//
//  Created by abc on 2021/02/16.
//

#include "InfixToPostfix.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ListBasedStack.h"

int GetOpPred(char op){
    switch (op) {
        case '*':
        case '/':
            return 5;
        case '+':
        case '-':
            return 3;
        case '(':
            return 1;
    }
    
    return -1; // 등록되지 않은 연산자임을 알림
}


int WhoPrecOp(char op1, char op2){
    int op1Prec = GetOpPred(op1);
    int op2Prec = GetOpPred(op2);
    
    if(op1Prec > op2Prec) return 1;
    else if(op1Prec < op2Prec) return -1;
    else return 0;
}

void ConvToRPNExp(char exp[]){
    Stack stack;
    int expLen = strlen(exp);
    char* convExp = (char*)malloc(expLen + 1);
    
    int i, idx = 0;
    char tok, popOp;
    
    memset(convExp, 0, sizeof(char)*expLen+1);
    StackInit(&stack);
    
    for(i=0;i<expLen;i++){
        tok = exp[i];
        if(isdigit(tok)){
            convExp[idx++] = tok; // 저장하고 ++ 하는것임
        } else { // 연산자라면
            switch (tok) {
                case '(':
                    SPush(&stack, tok);
                    break;
                case ')':
                    while(1){
                        popOp = SPop(&stack);
                        if(popOp == '(')
                            break;
                        convExp[idx++] = popOp;
                    }
                    break;
                case '+': case '-':
                case '*': case '/':
                    while(!SIsEmpty(&stack) && WhoPrecOp(SPeekl(&stack), tok) >= 0){
                        convExp[idx++] = SPop(&stack);
                    }
                    SPush(&stack, tok);
                    break;
            }
        }
    }
    
    while(!SIsEmpty(&stack))
        convExp[idx++] = SPop(&stack);
    
    strcpy(exp, convExp);
    free(convExp);
}



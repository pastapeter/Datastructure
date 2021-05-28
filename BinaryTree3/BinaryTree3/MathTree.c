//
//  MathTree.c
//  BinaryTree3
//
//  Created by abc on 2021/05/27.
//

#include "MathTree.h"


int Operator(char op){ // 연산자에 우선순위 두기
    switch (op) {
        case '*': case '/':
            return 3;
        case '+': case '-':
            return 2;
    }
    return -1;
}

int whoPrecede(char op1, char op2){ //어떤 연산자가 우선순위 인지비교 함수
    if(Operator(op1)> Operator(op2)){
        return 1;
    } else if (Operator(op1)< Operator(op2)) {
        return -1;
    } else {
        return 0;
    }
}


Btree* makeMathTree(char* input){
    ArrayStack stack;
    ArrayStackInit(&stack);
    Stack treeStack;
    stackInit(&treeStack);
    Btree* node;
    
    
    // 후위 수식
    char* result = (char*)malloc(sizeof(char)*strlen(input)*2); //문자열 공간을 하나 마련해준다.
    memset(result, 0, sizeof(char)*strlen(input)*2); // 문자열 공간 초기화
    
    int rindex = 0;
    int i=0;
    while(input[i] != '\0'){
        if(isdigit(input[i])){
            result[rindex++] = input[i];
        } else {
            while(!SIsEmpty(&stack) && whoPrecede(SPeek(&stack),input[i]) >= 0){ // 스택 안에있는 연산자가 우선순위가 더 높거나 같다면,
                if(SIsEmpty(&stack)){
                    printf("ERROR");
                    exit(-1);
                }
                result[rindex++] = SPop(&stack);
            }
            SPush(&stack, input[i]);
        }
        i++;
    }
    while(!SIsEmpty(&stack)){ //연산자 스택이 비지 않았다면 마지막에 다 빼준다.
        if(SIsEmpty(&stack)){
            printf("ERROR");
            exit(-1);
        }
        result[rindex++] = SPop(&stack);
    }
    printf("후위수식 %s\n", result);
    // 수식트리만들기
    for(int j=0;j<rindex;j++){
        
        node = MakeBtree();
        
        if(isdigit(result[j])){
            printf("%c", result[j]);
            setData(node, result[j] - '0');
        } else {
            makeRightSubtree(node, pop(&treeStack));
            makeLeftSubtree(node, pop(&treeStack));
            setData(node, result[j]);
        }
        push(&treeStack, node);
    }
    return pop(&treeStack);
}

int evaluate(Btree* root){
    if(root == NULL) return 0;
    if(getRightNode(root) == NULL && getLeftNode(root) == NULL) return root->data;
    
    int op1, op2;
    op1 = evaluate(getLeftNode(root));
    op2 = evaluate(getRightNode(root));
    
    switch (root->data) {
        case '+':
            return op1+op2;
            break;
        case '*':
            return op1*op2;
            break;
        case '-':
            return op1-op2;
            break;
        case '/':
            return op1/op2;
            break;
    }
    
    return 0;
}

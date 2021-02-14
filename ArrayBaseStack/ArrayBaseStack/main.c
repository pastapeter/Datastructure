//
//  main.c
//  ArrayBaseStack
//
//  Created by abc on 2021/02/14.
//

#include <stdio.h>
#include "ArrayBaseStack.h"

int main(int argc, const char * argv[]) {
    
    Stack stack;
    StackInit(&stack);
    
    SPush(&stack, 1);
    SPush(&stack, 2);
    SPush(&stack, 3);
    SPush(&stack, 4);
    SPush(&stack, 5);
    
    // 데이터 꺼내기
    while(!SIsEmpty(&stack)){
        printf("꺼내야할 데이터 %d\n", SPeek(&stack));
        printf("%d 꺼냄완료\n", SPop(&stack));
    }
    
    
    return 0;
}

//
//  main.c
//  LinkedListBaseStack
//
//  Created by abc on 2021/02/14.
//

#include <stdio.h>
#include "ListBaseStack.h"

int main(int argc, const char * argv[]) {
    
    Stack stack;
    StackInit(&stack);
    
    SPush(&stack, 1);
    SPush(&stack, 2);
    SPush(&stack, 3);
    SPush(&stack, 4);
    SPush(&stack, 5);
    
    while(!SIsEmpty(&stack)){
        printf("%d ",SPop(&stack));
    }
    
    return 0;
}

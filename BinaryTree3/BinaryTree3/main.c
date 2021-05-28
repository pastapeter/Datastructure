#include <stdio.h>
#include "binaryTree.h"
#include "MathTree.h"
#include "time.h"

int main(int argc, const char * argv[]) {
    
    // 문제 1번 ---------------------------------------------------
    srand((unsigned)time(NULL));
    int input = rand()%30+1;
    Btree* root = MakeBtree();
    
    setData(root, input);
    Btree* root2 = MakeBtree();
    setData(root2, input);
    
    for(int i=0;i<20;i++){
        while(1){
            input = rand()%30+1;
            if(!search(root, input) && !search(root2, input)) break;
        }
        insert(&root, input);
        insertRecursive(&root2, input);
    }
    inorderTraverseRecursive(root);
    printf("\n");
    inorderTraverseRecursive(root2);
    
    
    // 문제 2번 -----------------------------------------------------------
    Data target;
    printf("\nenter the input(1 ~ 30)\n");
    scanf("%d", &target);
    Btree* delnode;
    delnode = deleteNode(&root, target);
    if(delnode){
        inorderTraverseRecursive(root);
        printf("\n");
    } else {
        printf("Cannot find the target\n");
    }
    
    // 문제 3번 --------------------------------------------------------------
    char expression[20];
    getchar();
    fgets(expression, 20, stdin);
    expression[strlen(expression)-1] = '\0';
    printf("expression %s\n", expression);
    Btree* mathRoot;
    mathRoot = makeMathTree(expression);
    printf("answer %d\n", evaluate(mathRoot));
}

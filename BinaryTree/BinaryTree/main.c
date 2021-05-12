//
//  main.c
//  BinaryTree
//
//  Created by abc on 2021/05/12.
//

#include "BinaryTree.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    BtreeNode* bt1 = makeBtreeNode();
    BtreeNode* bt2 = makeBtreeNode();
    BtreeNode* bt3 = makeBtreeNode();
    BtreeNode* bt4 = makeBtreeNode();
    
    setData(bt1, 1);
    setData(bt2, 2);
    setData(bt3, 3);
    setData(bt4, 4);
    
    makeLeftSubTree(bt1, bt2);
    makeRightSubTree(bt1, bt3);
    makeLeftSubTree(bt2, bt4);
    
    printf("%d \n", getData(getLeftSubTree(bt1)));
    printf("%d \n", getData(getLeftSubTree(getLeftSubTree(bt1))));
    return 0;
}

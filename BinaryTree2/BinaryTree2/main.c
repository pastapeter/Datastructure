//
//  main.c
//  BinaryTree2
//
//  Created by abc on 2021/05/21.
//

#include "Binarytree.h"


int main(int argc, const char * argv[]) {
    
    Btree* bt1 = treeInit();
    Btree* bt2 = treeInit();
    Btree* bt3 = treeInit();
    Btree* bt4 = treeInit();
    Btree* bt5 = treeInit();
    Btree* bt6 = treeInit();
    Btree* bt7 = treeInit();
    
    setData(bt1, 1);
    setData(bt2, 2);
    setData(bt3, 3);
    setData(bt4, 4);
    setData(bt5, 5);
    setData(bt6, 6);
    setData(bt7, 7);
    
    MakeLeftSubtree(bt1, bt2);
    MakeRightSubtree(bt1, bt3);
    MakeLeftSubtree(bt2, bt4);
    MakeRightSubtree(bt2, bt5);
    MakeLeftSubtree(bt3, bt6);
    MakeRightSubtree(bt3, bt7);
    
    Btree* copyedTree1 = treeCopy(bt1);
    postorderTraverseRecursive(copyedTree1);
    printf("\n");
    Btree* copyedTree2= treeCopyIterative(bt1);
    postorderTraverseRecursive(copyedTree2);
    
    printf("equal %d\n", equalTree(copyedTree1, copyedTree2));
    
    
    
    return 0;
}

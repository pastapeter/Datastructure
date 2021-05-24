//
//  main.c
//  BinaryTree2
//
//  Created by abc on 2021/05/21.
//

#include "Binarytree.h"
#include <time.h>
#include <ctype.h>

Btree* iterativeTree(Btree* root){
    Btree* temp = root;
    int count = 1;
    while(count < 10){
        int command = rand()%2+1;
        Data input = rand()%2+10;
    
        if(command == 1){
            if(getLeftSubtree(temp)==NULL){
                Btree* node = treeInit();
                setData(node, input);
                MakeLeftSubtree(temp, node);
                count++;
            } else {

                temp = temp->left;
            }
        } else {
            if(getRightSubtree(temp)==NULL){
                Btree* node = treeInit();
                setData(node, input);
                MakeRightSubtree(temp, node);
                count++;
            } else {
                temp = temp->right;
            }
        }
    }
    return root;
}

int main(int argc, const char * argv[]) {
    
//    srand((unsigned int)time(NULL));
//    Btree* root = treeInit();
//    setData(root, rand()%2+10);
//
//    iterativeTree(root);
    Btree* bt1 = treeInit();
    Btree* bt2 = treeInit();
    Btree* bt3 = treeInit();
    Btree* bt4 = treeInit();
    Btree* bt5 = treeInit();
    Btree* bt6 = treeInit();
    Btree* bt7 = treeInit();
    Btree* bt8 = treeInit();
    
    setData(bt1, 1);
    setData(bt2, 2);
    setData(bt3, 3);
    setData(bt4, 4);
    setData(bt5, 5);
    setData(bt6, 6);
    setData(bt7, 7);
    setData(bt8, 8);
    
    MakeLeftSubtree(bt1, bt2);
    MakeRightSubtree(bt1, bt3);
    MakeLeftSubtree(bt2, bt4);
    MakeRightSubtree(bt2, bt5);
    MakeLeftSubtree(bt3, bt6);
    MakeRightSubtree(bt3, bt7);
    MakeRightSubtree(bt7, bt8);

    Btree* copyedTree1 = treeCopy(bt1);
    postorderTraverseRecursive(copyedTree1);
    printf("\n");
    Btree* copyedTree2= treeCopyIterative(bt1);
    postorderTraverseRecursive(copyedTree2);
    printf("\n");
    
    printf("equal %d\n", equalTree(copyedTree1, copyedTree2));
    printf("equalIter %d\n", equalTreeIterative(copyedTree1, copyedTree2));
    
    printf("heightRecurive %d\n", getHeight(copyedTree1));
    printf("heightIter %d\n", getHeightIterative(copyedTree1));
    
    printf("getnodecount %d\n", getNodeCount(3, copyedTree1));
    
    return 0;
}

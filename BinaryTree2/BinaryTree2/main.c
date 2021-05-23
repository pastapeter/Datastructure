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
    
    srand((unsigned int)time(NULL));
    Btree* root = treeInit();
    setData(root, rand()%2+10);

    iterativeTree(root);
    
    Btree* copyedTree1 = treeCopy(root);
    postorderTraverseRecursive(copyedTree1);
    printf("\n");
    Btree* copyedTree2= treeCopyIterative(root);
    postorderTraverseRecursive(copyedTree2);
    printf("\n");
    
    printf("equal %d\n", equalTree(copyedTree1, copyedTree2));
    printf("equalIter %d\n", equalTreeIterative(copyedTree1, copyedTree2));
    
    printf("heightRecurive %d\n", getHeight(copyedTree1));
    printf("heightIter %d\n", getHeightIterative(copyedTree1));
    
    printf("getnodecount %d\n", getNodeCount(3, copyedTree1));
    
    return 0;
}

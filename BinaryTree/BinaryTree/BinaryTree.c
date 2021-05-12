//
//  BinaryTree.c
//  BinaryTree
//
//  Created by abc on 2021/05/12.
//

#include "BinaryTree.h"

BtreeNode* makeBtreeNode(void){
    BtreeNode* nd = (BtreeNode*)malloc(sizeof(BtreeNode));
    nd->left = NULL;
    nd->right = NULL;
    return nd;
}
Data getData(BtreeNode* bt){
    return bt->data;
}
void setData(BtreeNode* bt, Data input){
    bt->data = input;
}

BtreeNode* getLeftSubTree(BtreeNode* bt){
    return bt->left;
}
BtreeNode* getRightSubTree(BtreeNode* bt){
    return bt->right;
}

void makeLeftSubTree(BtreeNode* main, BtreeNode* sub){
    if(main->left != NULL){
        free(main->left);
    }
    main->left = sub;
}
void makeRightSubTree(BtreeNode* main, BtreeNode* sub){
    if(main->right != NULL){
        free(main->right);
    }
    main->right = sub;
}

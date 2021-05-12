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

void InorderTraverse(BtreeNode* bt, VisitFuncPtr action){
    if(bt == NULL) return;
    InorderTraverse(bt->left, action);
    action(bt->data);
    InorderTraverse(bt->right, action);
}

void PreorderTraverse(BtreeNode* bt, VisitFuncPtr action){
    if(bt == NULL) return;
    action(bt->data);
    PreorderTraverse(bt->left, action);
    PreorderTraverse(bt->right, action);
}
void PostorderTraverse(BtreeNode* bt, VisitFuncPtr action){
    if(bt == NULL) return;
    PostorderTraverse(bt->left, action);
    PostorderTraverse(bt->right, action);
    action(bt->data);

}

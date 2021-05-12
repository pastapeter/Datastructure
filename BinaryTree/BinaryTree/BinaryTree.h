//
//  BinaryTree.h
//  BinaryTree
//
//  Created by abc on 2021/05/12.
//

#ifndef BinaryTree_h
#define BinaryTree_h

#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct _btreeNode{
    Data data;
    struct _btreeNode* left;
    struct _btreeNode* right;
} BtreeNode;

BtreeNode* makeBtreeNode(void);
Data getData(BtreeNode* bt);
void setData(BtreeNode* bt, Data input);

BtreeNode* getLeftSubTree(BtreeNode* bt);
BtreeNode* getRightSubTree(BtreeNode* bt);

void makeLeftSubTree(BtreeNode* main, BtreeNode* sub);
void makeRightSubTree(BtreeNode* main, BtreeNode* sub);

typedef void VisitFuncPtr(Data data);

void InorderTraverse(BtreeNode* bt, VisitFuncPtr action);
void PreorderTraverse(BtreeNode* bt, VisitFuncPtr action);
void PostorderTraverse(BtreeNode* bt, VisitFuncPtr action);

#endif /* BinaryTree_h */

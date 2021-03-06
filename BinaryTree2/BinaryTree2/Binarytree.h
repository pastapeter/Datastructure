//
//  Binarytree.h
//  BinaryTree2
//
//  Created by abc on 2021/05/21.
//

#ifndef Binarytree_h
#define Binarytree_h



#include "Stack.h"
#include "Queue.h"

Btree* treeInit(void);
Data getData(Btree* node);
void setData(Btree* node, Data input);
Btree* getLeftSubtree(Btree* node);
Btree* getRightSubtree(Btree* right);
void MakeLeftSubtree(Btree* main, Btree* node);
void MakeRightSubtree(Btree* main, Btree* node);
void inorderTraverseRecursive(Btree* root);
void postorderTraverseRecursive(Btree* root);
void inorderTraverseIterative(Btree* root);
void posMakeLeftSubtreeterative(Btree* root);
Btree* treeCopy(Btree* root);
Btree* treeCopyIterative(Btree* root);
int equalTreeIterative(Btree* root1, Btree* root2);
int equalTree(Btree* root1, Btree* root2);
int getHeight(Btree* root);
int getHeightIterative(Btree* root);
int getNodeCount(int level, Btree* root);

#endif /* Binarytree_h */

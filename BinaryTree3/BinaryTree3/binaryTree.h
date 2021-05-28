//
//  binaryTree.h
//  BinaryTree3
//
//  Created by abc on 2021/05/27.
//

#ifndef binaryTree_h
#define binaryTree_h

#include "Stack.h"
#include "Queue.h"

typedef Btree* VisitedFunc(Btree* root, Btree* parent);

// basic
Btree* MakeBtree(void);
void setData(Btree* bt, Data input);
Btree* getLeftNode(Btree* bt);
Btree* getRightNode(Btree* bt);
void makeLeftSubtree(Btree* main, Btree* sub);
void makeRightSubtree(Btree* main, Btree* sub);

//traverse Recursive
void inorderTraverseRecursive(Btree* root);
void preorderTraverseRecursive(Btree* root);
void postorderTraverseRecursive(Btree* root);

//traverse iterative
void inorderTraverseIterative(Btree* root);
void preorderTraverseIterative(Btree* root);
void postorderTraverseIterative(Btree* root);

//Search
Btree* search(Btree* root, Data key);

//Search and Delete

//level Traverse
void levelTraverse(Btree* root);


void insertRecursive(Btree** root, int key);
void insert(Btree** root, int key);

Btree* deleteNode(Btree** root, Data target);


#endif /* binaryTree_h */

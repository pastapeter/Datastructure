//
//  binaryTree.h
//  hW9
//
//  Created by abc on 2021/05/16.
//

#ifndef binaryTree_h
#define binaryTree_h


#include "Stack.h"
#include "Queue.h"



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

//findduplicate
Btree* search(Btree* root, Data key);

//level Traverse
void levelTraverse(Btree* root);


#endif /* binaryTree_h */

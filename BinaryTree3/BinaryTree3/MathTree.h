//
//  MathTree.h
//  BinaryTree3
//
//  Created by abc on 2021/05/27.
//

#ifndef MathTree_h
#define MathTree_h

#include "binaryTree.h"
#include "ArrayBaseStack.h"
#include <ctype.h>
#include <string.h>

Btree* makeMathTree(char* input);
int evaluate(Btree* root);

#endif /* MathTree_h */

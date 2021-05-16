//
//  main.c
//  hW9
//
//  Created by abc on 2021/05/16.
//

#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include "binaryTree.h"


Btree* RecursiveTree(Btree* root, int count){
    Data input;
    if(count>9) return root;
    int command = rand()%2+1;
    while(1){
        input = rand()%100+1;
        if(!search(root, input)) break;
    }
    if(command == 1){
        if(getLeftNode(root)==NULL){
            Btree* node = MakeBtree();
            setData(node, input);
            makeLeftSubtree(root, node);
            count ++;
            return RecursiveTree(root, count);
        } else {
            return RecursiveTree(root->left, count);
        }
    } else{
        if(getRightNode(root)==NULL){
            Btree* node = MakeBtree();
            setData(node, input);
            makeRightSubtree(root, node);
            count ++;
            return RecursiveTree(root, count);
        } else {
            return RecursiveTree(root->right, count);
        }
    }
    return NULL;
}

Btree* iterativeTree(Btree* root){
    Btree* temp = root;
    int count = 1;
    while(count < 10){
        int command = rand()%2+1;
        Data input;
        while(1){
            input = rand()%100+1;
            if(!search(root, input)) break;
        }
    
        if(command == 1){
            if(getLeftNode(temp)==NULL){
                Btree* node = MakeBtree();
                setData(node, input);
                makeLeftSubtree(temp, node);
                count++;
            } else {

                temp = temp->left;
            }
        } else {
            if(getRightNode(temp)==NULL){
                Btree* node = MakeBtree();
                setData(node, input);
                makeRightSubtree(temp, node);
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
    Btree* root = MakeBtree();
    setData(root, rand()%100+1);
    
    Btree* root2 = MakeBtree();
    setData(root2, rand()%100+1);
    int count = 1;
    
    iterativeTree(root);
    inorderTraverseRecursive(root);
    preorderTraverseRecursive(root);
    postorderTraverseRecursive(root);
    
    inorderTraverseIterative(root);
    preorderTraverseIterative(root);
    postorderTraverseIterative(root);
    
    printf("________________________________________\n");
    RecursiveTree(root2, count);
    inorderTraverseRecursive(root2);
    preorderTraverseRecursive(root2);
    postorderTraverseRecursive(root2);
    
    inorderTraverseIterative(root2);
    preorderTraverseIterative(root2);
    postorderTraverseIterative(root2);
    
    
    printf("Level traverse\n\n");
    levelTraverse(root);
    printf("\n");
    levelTraverse(root2);

    return 0;
}

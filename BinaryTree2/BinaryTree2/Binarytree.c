//
//  Binarytree.c
//  BinaryTree2
//
//  Created by abc on 2021/05/21.
//

#include "Binarytree.h"

Btree* treeInit(void){
    Btree* node = (Btree*)malloc(sizeof(Btree));
    node->left = NULL;
    node->right = NULL;
    return node;
}
Data getData(Btree* node){
    return node->data;
}
void setData(Btree* node, Data input){
    node->data = input;
}
Btree* getLeftSubtree(Btree* node){
    return node->left;
}
Btree* getRightSubtree(Btree* node){
    return node->right;
}
void MakeLeftSubtree(Btree* main, Btree* node){
    if(main->left != NULL){
        free(main->left);
    }
    main->left = node;
}
void MakeRightSubtree(Btree* main, Btree* node){
    if(main->right != NULL){
        free(main->right);
    }
    main->right = node;
}

void inorderTraverseRecursive(Btree* root){
    if(root == NULL) return;
    inorderTraverseRecursive(root->left);
    printf("%d ", root->data);
    inorderTraverseRecursive(root->right);
}

void postorderTraverseRecursive(Btree* root){
    if(root == NULL) return;
    postorderTraverseRecursive(root->left);
    postorderTraverseRecursive(root->right);
    printf("%d ", root->data);
}

void inorderTraverseIterative(Btree* root){
    Stack stack;
    stackInit(&stack);
    while(1){
        for(;root; root = root->left){
            push(&stack, root);
        }
//        while(root != NULL){
//            push(&stack, root);
//            root = root->left;
//        }
        root = pop(&stack);
        if(!root) break;
        printf("%d ", root->data);
        root = root->right;
    }
}

void postorderTraverseIterative(Btree* root){
    Stack stack;
    stackInit(&stack);
    do {
        while(root != NULL){
            if(root->right != NULL){
                push(&stack, root->right);
            }
            push(&stack, root);
            root = root->left;
        }
        root = pop(&stack);
        if(root->right != NULL && root->right == peek(&stack)){
            pop(&stack);
            push(&stack, root);
            root = root->right;
        } else {
            printf("%d ", root->data);
            root = NULL;
        }
    } while(!isEmpty(&stack));
}

Btree* treeCopy(Btree* root){
    Btree* temp;
    if(root){
        temp = treeInit();
        temp->left = treeCopy(root->left);
        temp->right = treeCopy(root->right);
        temp->data = root->data;
        return temp;
    }
    return NULL;
}

Btree* treeCopyIterative(Btree* root){
    Btree* temp;
    while(root){
        temp = treeInit();
        temp->data = root->data;
        
        temp->left = root->left;
        root = root->left;
        
        temp->right = root->right;
    }
}

int equalTree(Btree* root1, Btree* root2){
    if((root1 != NULL && root2 != NULL) || (root1 && root2 && (root1->data == root2->data) && equalTree(root1->left, root2->left) && equalTree(root1->right, root2->right))){
        return TRUE;
    }
    else return FALSE;
}

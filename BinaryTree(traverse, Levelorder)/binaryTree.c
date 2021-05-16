//
//  binaryTree.c
//  hW9
//
//  Created by abc on 2021/05/16.
//

#include "binaryTree.h"

Btree* MakeBtree(void){
    Btree* node = (Btree*)malloc(sizeof(Btree));
    node->right = NULL;
    node->left = NULL;
    return node;
}
void setData(Btree* bt, Data input){
    bt->data = input;
}
Btree* getLeftNode(Btree* bt){
    return bt->left;
}
Btree* getRightNode(Btree* bt){
    return bt->right;
}
void makeLeftSubtree(Btree* main, Btree* sub){
//    if(main->left != NULL) free(main->left);
    main->left = sub;
}
void makeRightSubtree(Btree* main, Btree* sub){
//    if(main->right != NULL) free(main->right);
    main->right = sub;
}

//traverse Recursive
void inorderTraverseRecursive(Btree* root){
    if(root == NULL) return;
    inorderTraverseRecursive(root->left);
    printf("%d \n", root->data);
    inorderTraverseRecursive(root->right);
}
void preorderTraverseRecursive(Btree* root){
    if(root == NULL) return;
    printf("%d \n", root->data);
    preorderTraverseRecursive(root->left);
    preorderTraverseRecursive(root->right);
}
void postorderTraverseRecursive(Btree* root){
    if(root == NULL) return;
    postorderTraverseRecursive(root->left);
    postorderTraverseRecursive(root->right);
    printf("%d \n", root->data);
}

//traverse iterative
void inorderTraverseIterative(Btree* root){
    Stack stack;
    stackInit(&stack);
    while(1){
//        for(;root; root = root->left){
//            push(&stack, root);
//        }
        while(root != NULL){
            push(&stack, root);
            root = root->left;
        }
        root = pop(&stack);
        if(root == NULL) break;
        printf("%d \n", root->data);
        root = root->right;
    }
}
void preorderTraverseIterative(Btree* root){
    Stack stack;
    stackInit(&stack);
    push(&stack, root);
    while(!isEmpty(&stack)){
        root = pop(&stack);
        printf("%d \n", root->data);
        if(root->right != NULL){
            push(&stack, root->right);
        }
        if(root->left != NULL){
            push(&stack, root->left);
        }
        
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
            printf("%d \n", root->data);
            root = NULL;
        }
    } while(!isEmpty(&stack));
}

//search
Btree* search(Btree* root, Data key){
    if(root == NULL) return NULL;
    if(key==root->data) return root;
    else if(key < root->data){
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
};

//level Traverse
void levelTraverse(Btree* root){
    queue queue;
    QueueInit(&queue);
    enqueue(&queue, root);
    while(!QisEmpty(&queue)){
        root = dequeue(&queue);
        if(root != NULL){
            printf("%d ", root->data);
        }
        if(root->left != NULL){
            enqueue(&queue, root->left);
        }
        if(root->right != NULL){
            enqueue(&queue, root->right);
        }
    }
}

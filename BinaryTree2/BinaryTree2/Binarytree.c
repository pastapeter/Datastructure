//
//  Binarytree.c
//  BinaryTree2
//
//  Created by abc on 2021/05/21.
//

#include "Binarytree.h"
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

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
    Btree* temp = NULL;
    Stack stack;
    stackInit(&stack);
    do {
        while(root != NULL){
            if(getRightSubtree(root) != NULL){
                push(&stack, root);
            }
            push(&stack, root);
            root = root->left;
        }
        root = pop(&stack);
        if(root->right != NULL && root->right == peek(&stack)){
            pop(&stack);
            push(&stack, root);
            root = root->right;
        } else{
            temp = treeInit();
            temp->data = root->data;
            temp->left = root->left;
            temp->right = root->right;
            root = NULL;
        }
    } while(!isEmpty(&stack));
    return temp;
}

int equalTree(Btree* root1, Btree* root2){
    if((root1 != NULL && root2 != NULL) || (root1 && root2 && (root1->data == root2->data) && equalTree(root1->left, root2->left) && equalTree(root1->right, root2->right))){
        return TRUE;
    }
    else return FALSE;
}

int equalTreeIterative(Btree* root1, Btree* root2){
    if(!(root1 != NULL && root2 != NULL)){return FALSE;}
    Stack stack1;
    stackInit(&stack1);
    push(&stack1, root2);
    push(&stack1, root1);
    while(!isEmpty(&stack1)){
        root1 = pop(&stack1);
        root2 = pop(&stack1);
        if(root1->data != root2->data){return FALSE;}
        if((root1->right != NULL && root2->right != NULL)){
            push(&stack1, root2->right);
            push(&stack1, root1->right);
        }
        if(root1->left != NULL && root2->left != NULL){
            push(&stack1, root2->left);
            push(&stack1, root1->left);
        }
    }
    return TRUE;
}

int getHeight(Btree* root){
    int height = 0;
    if(root != NULL){
        height = 1 + MAX(getHeight(root->left), getHeight(root->right));
    }
    return height;
}

int getHeightIterative(Btree* root){
    Stack stack;
    stackInit(&stack);
    int height = 0;
    int flag = 1;
    int maxHeight = 0;
    int i = 0;
    Btree* temp = root;
    int array[20] = {0};
    do {
        while(root != NULL){
            if(root->right != NULL){
                push(&stack, root->right);
            }
            push(&stack, root);
            root = root->left;
            height++;
        }
        root = pop(&stack);
        height--;
        if(root->right != NULL && root->right == peek(&stack)){
            pop(&stack);
            push(&stack, root);
            if(peek(&stack) == temp){
                height = 0;
            }
            root = root->right;
            height++;
            flag = 0;
        } else {
            array[i++] = height;
            root = NULL;
        }
    } while (!isEmpty(&stack));
    
    for(int j=0;j<i;j++){
        if(maxHeight < array[j]){
            maxHeight = array[j];
        }
    }
    return maxHeight+1;
}

int getNodeCount(int level, Btree* root){
    int count = 1;
    int next = 0;
    int limit = getHeight(root);
    if(level > limit){
        printf("ERROR");
        exit(-1);
    }
    Btree* visited[20] = {NULL};
    int levelList[20] = {0};
    int index = 0;
    
    queue queue;
    QueueInit(&queue);
    enqueue(&queue, root);
    levelList[count]++;
    while(!QisEmpty(&queue)){
        int key = 1;
        Btree* node = dequeue(&queue);
        // visitedList에 추가
        visited[index++] = node;
        if(node->left != NULL){
            count++;
            levelList[count]++;
            count--;
            enqueue(&queue, node->left);
        }
        next++;
        if(node->right != NULL){
            count++;
            levelList[count]++;
            count--;
            enqueue(&queue, node->right);
        }
        next++;
        for(int i=0;i<count;i++){
            key *= 2;
        }
        if(key <= next){
            next = 0;
            count++;
        }
    }
    for(int i=0;i<20;i++){
        printf("%d ", levelList[i]);
    }
    return levelList[level];
}


//
//  binaryTree.c
//  BinaryTree3
//
//  Created by abc on 2021/05/27.
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
    printf("%d ", root->data);
    inorderTraverseRecursive(root->right);
}

void postorderTraverseRecursive(Btree* root){
    if(root == NULL) return;
    postorderTraverseRecursive(root->left);
    postorderTraverseRecursive(root->right);
    printf("%d ", root->data);
}

void insert(Btree** root, int key){
    Btree* parent, *cur, *newNode;
    cur = *root;
    parent = NULL;
    
    // 찾고 싶은 부모노드 찾기
    while(cur != NULL){
        if(key == cur->data){
            return;
        }
        parent = cur;
        if (key < cur->data){
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    
    //노드 생성 & 초기화
    newNode = (Btree*)malloc(sizeof(Btree));
    if(newNode == NULL) return;
    newNode->data = key;
    newNode->left = NULL;
    newNode->right = NULL;
    
    //부모노드와 링크 연결
    if(parent != NULL){
        if(key < parent->data){
            makeLeftSubtree(parent, newNode);
        } else {
            makeRightSubtree(parent, newNode);
        }
    }
    // 부모가 없다 => 자기가 부모
    else *root = newNode;
}

void insertRecursive(Btree** root, int key){
    if(*root == NULL){
        Btree* newNode = (Btree*)malloc(sizeof(Btree));
        newNode->data = key;
        newNode->left = NULL;
        newNode->right = NULL;
        *root = newNode;
    }
    else{
        if((*root)->data >= key){
            if((*root)->left != NULL){
                insertRecursive(&((*root)->left), key);
            }
            else {
                Btree* newNode = (Btree*)malloc(sizeof(Btree));
                newNode->data = key;
                newNode->left = NULL;
                newNode->right = NULL;
                (*root)->left = newNode;
            }
        } else {
            if((*root)->right != NULL){
                insertRecursive(&((*root)->right), key);
            }
            else {
                Btree* newNode = (Btree*)malloc(sizeof(Btree));
                newNode->data = key;
                newNode->left = NULL;
                newNode->right = NULL;
                (*root)->right = newNode;
            }
        }
    }
}

Btree* search(Btree* root, Data key){
    if(root == NULL) return NULL;
    if(key==root->data){
        return root;
        }
    else if(key < root->data){
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
};

Btree* deleteNode(Btree** root, Data target){
    Btree* pVRoot = MakeBtree();
    Btree* parentNode = pVRoot;
    Btree* currentNode = *root;
    Btree* delNode = NULL;
    
    // 루트노드를 pvRoot가 가리키는 노드의 오른쪽 자식이 되게한다.
    pVRoot->right = *root;
    
    //탐색 후, 삭제노드에 할당해줌
    while(currentNode != NULL && currentNode->data != target){
        parentNode = currentNode;
        currentNode = (target < currentNode->data) ? currentNode->left : currentNode->right;
    }
    if(currentNode == NULL) return NULL;
    delNode = currentNode;
    
    if(getLeftNode(delNode) == NULL && getRightNode(delNode) == NULL){ //leaf node
        if(getLeftNode(parentNode) == delNode){
            parentNode->left = NULL;
        } else {
            parentNode->right = NULL;
        }
    }
    else if(getLeftNode(delNode) == NULL || getRightNode(delNode) == NULL){ // 한쪽만 있는경우
        Btree* child = (getLeftNode(delNode) == NULL) ? getRightNode(delNode) : getLeftNode(delNode);
        if(parentNode->left == delNode){
            parentNode->left = child;
        } else {
            parentNode->right = child;
        }
    }
    else { // 다 달려있는 경우
        Btree* changeNode = delNode->right;
        Btree* parentChangeNode = delNode;
        
        //삭제노드보다 크지만, 큰 노드중에 가장 작은 노드 찾기
        while(getLeftNode(changeNode) != NULL){
            parentChangeNode = changeNode;
            changeNode = getLeftNode(changeNode);
        }
        
        //대입
        Data delData = delNode->data;
        delNode->data = changeNode->data;
        
        // 대체노드의 부모노드와 자식노드를연결
        if(getLeftNode(parentChangeNode) == changeNode){
            parentChangeNode->left = changeNode->right;
        } else {
            parentChangeNode->right = changeNode->right;
        }
        
        delNode = changeNode;
        delNode->data = delData;
    }
    if(pVRoot->right != *root){
        *root = getRightNode(pVRoot);
    }
    free(pVRoot);
    return  delNode;
}


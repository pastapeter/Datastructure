//
//  LinkedRead2.c
//  linkedlist2
//
//  Created by abc on 2021/01/18.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct __node{
    int data;
    struct __node* next;
}Node;

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    Node* cur = NULL;
    
    Node* newNode = NULL;
    int newdata;
    
    while(1){
        //데이터 받기
        scanf("%d", &newdata);
        if(newdata<1){
            printf("ERROR");
            break;
        }
        // 바구니만들기
        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = newdata;
        newNode->next = NULL;
        
        
        // 바구니에 위치 연결
        if(head == NULL){
            tail=newNode;
            head=newNode;
        }
        else{
            head->next = newNode;
        }
        head = newNode;
    }
    // 출력
    if(tail == NULL){
        printf("Error");
    }
    else{
        cur = tail;
        printf("%d", cur->data);
        while(cur->next != NULL){
            cur = cur->next;
            printf("%d", cur->data);
        }
    }
    printf("\n\n");
    
    //메모리해제
    if(tail == NULL){
        return 0;
    }
    else{
        Node* delnode = tail;
        Node* delnextnode = tail->next;
        printf("%d 삭제\n", delnode->data);
        free(delnode);
        while(delnextnode!=NULL){
            delnode = delnextnode;
            delnextnode = delnextnode->next;
            printf("%d 삭제\n", delnode->data);
            free(delnode);
        }
    }
    
}

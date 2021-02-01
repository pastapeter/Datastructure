//
//  main.c
//  linkedlist2
//
//  Created by abc on 2021/01/18.
//  자연수받는 간단한 linkedlist
//  Insert Dummy node

#include <stdio.h>
#include <stdlib.h>

typedef struct __node{
    int data;
    struct __node* Next;
} Node;

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    Node* cur = NULL;
    Node* newNode = NULL;
    int readdata;
    
    head = (Node*)malloc(sizeof(Node));
    //head->data = NULL;
    tail = head;
    //데이터를 받는 과정
    while(1){
        printf("자연수 입력 :");
        scanf("%d",&readdata);
        if(readdata < 1){
            printf("Error\n");
            break;
        }
        //노드 추가
        newNode = (Node*)malloc(sizeof(Node)); // 노드(바구니) 생성
        newNode->data = readdata; //노드에 데이터 저장
        newNode->Next = NULL; // 노드의 next를 NULL로  초기화
        
        
        tail->Next = newNode; //마지막 노드의 다음노드가 새로운 노드를 가르킴
        tail = newNode; //마지막 노드가 새로운 노드를 가르키게함

    }
        
        //입력받은 데이터 출력과정
        if(head==tail)
            printf("출력할 자연수가 존재하지 않음\n");
        else{
            cur = head; //현재 포인터가 head와 같은 노드 가르킴
           // printf("%d", cur->data); // 첫번쨰 노드 데이터 출력
            while(cur->Next!=NULL){ //그 노드에 연결된 노드가 있다면
                cur = cur->Next; // 다음노드로 현재 포인터 이동
                printf("%d", cur->data); //담노드 데이터 출력
            }
        }
        printf("\n\n");
        
        //메모리 해제 과정
        
        Node* delNode = head;
        Node* delNextNode = head->Next;
        //printf("%d를 삭제합니다.", delNode->data);
        //free(delNode);
        while (delNextNode!= NULL) {
            delNode = delNextNode;
            delNextNode = delNextNode->Next;
            printf("%d를 삭제합니다.", delNode->data);
            free(delNode);
        }
        
    return 0;
}


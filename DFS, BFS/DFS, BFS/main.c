//
//  main.c
//  DFS, BFS
//
//  Created by abc on 2021/06/02.
//


#define FALSE 0
#define TRUE 1

#include "Intqueue.h"

int adjc[10][10] = {0};
// 10*10

typedef struct vertex{
    int data;
    struct vertex* next;
    
}vertex;

typedef struct ajcdList{
    vertex* head;
    vertex* tail;
    int count;
}List;

void Listinit(List* plist){
    plist->tail = (vertex*)malloc(sizeof(vertex));
    plist->head = plist->tail;
    plist->head->next = NULL;
    plist->tail->next = NULL;
    plist->count = 0;
}

void append(List* plist, int input){
    vertex* newVertex = (vertex*)malloc(sizeof(vertex));
    newVertex->data = input;
    newVertex->next = NULL;
    plist->tail->next = newVertex;
    plist->tail = plist->tail->next;
    (plist->count)++;
}

//간선 갯수
int m;
int visited[10] = {0};


void dfsMatrix(int matrix[10][10], int start){
    int w;
    visited[start] = 1;
    printf("%d ", start);
    for(w=0;w<10;w++){
        if(matrix[start][w] == 1 && visited[w] == 0){
            dfsMatrix(matrix, w);
        }
    }
}

void dfsMatrixStack(int matrix[10][10], int start){
    int w;
    int visited[10] = {0};
    ArrayStack stack;
    ArrayStackInit(&stack);
    SPush(&stack, start);
    while(!SIsEmpty(&stack)){
        int popelement = SPop(&stack);
        if(visited[popelement]) continue;
        visited[popelement] = 1;
        printf("%d ", popelement);
        for(w=0;w<10;w++){
            if(matrix[w][popelement] == 1){
                SPush(&stack, w);
            }
        }
    }
}

void dfsList(List adlist[], int start){
    vertex* w;
    visited[start] = 1;
    printf("%d ", start);
    for(w=adlist[start].head->next;w!=NULL;w=w->next){
        if(visited[w->data] == 0){
            dfsList(adlist, w->data);
        }
    }
}

void dfsListStack(List adlist[], int start){
    vertex* w;
    int visited[10] = {0};
    ArrayStack stack;
    ArrayStackInit(&stack);
    SPush(&stack, start);
    while(!SIsEmpty(&stack)){
        int popelement = SPop(&stack);
        if(visited[popelement]) continue;
        visited[popelement] = 1;
        printf("%d ", popelement);
        for(w=adlist[popelement].head->next;w;w=w->next){
            SPush(&stack, w->data);
        }
    }
}

void Bfsmatrix(int matrix[10][10], int start){
    int visited[10] = {0};
    int w;
    queue queue;
    QueueInit(&queue);
    enqueue(&queue, start);
    while(!isEmpty(&queue)){
        int dequeued = dequeue(&queue);
        if(visited[dequeued] == 1) continue;
        visited[dequeued] = 1;
        printf("%d ", dequeued);
        for(w=0;w<10;w++){
            if(matrix[dequeued][w] == 1 && visited[w] == 0){
                enqueue(&queue, w);
            }
        }
    }
}

void BfsList(List adlist[], int start){
    int visited[10] = {0};
    queue queue;
    vertex* w;
    QueueInit(&queue);
    enqueue(&queue, start);
    while(!isEmpty(&queue)){
        int dequeued = dequeue(&queue);
        if(visited[dequeued] == 1) continue;
        visited[dequeued] = 1;
        printf("%d ", dequeued);
        for(w=adlist[dequeued].head->next;w;w=w->next){
            enqueue(&queue, w->data);
        }
    }
}

int main(int argc, const char * argv[]) {
    List adlist[10];
    for(int i=0;i<10;i++){
        Listinit(&adlist[i]);
    }
    
    //인접행렬 구성하기
    
    scanf("%d", &m);
    
    for(int i = 0; i<m;i++){
        int x,y;
        scanf("%d %d", &x, &y);
        append(&adlist[x], y);
        append(&adlist[y], x);
        adjc[y][x] = 1;
        adjc[x][y] = 1;
    }
    // 인접리스트로 받기
    
    //인접행렬 print
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            printf("%d ", adjc[i][j]);
        }
        printf("\n");
    }
    
    
    for(int i=0;i<10;i++){
        vertex* temp = adlist[i].head->next;
        if(temp != NULL){
           printf("%d-", i);
           printf("%d-", temp->data);
            temp = temp->next;
            while(temp != NULL){
                printf("%d-", temp->data);
                temp = temp->next;
            }
            printf("\n");
        }
        
    }
    
    //dfs print
    dfsMatrix(adjc, 0);
    printf("\n");
    dfsMatrixStack(adjc, 0);
    for(int i=0;i<10;i++){
        visited[i] = 0;
    }
    printf("\n");
    dfsList(adlist, 0);
    printf("\n");
    dfsListStack(adlist, 0);
    printf("\n");
    printf("BFS");
    Bfsmatrix(adjc, 0);
    printf("\n");
    printf("BFS");
    BfsList(adlist, 0);
}

//
//  main.c
//  Topology
//
//  Created by abc on 2021/06/07.
//
// 위상정렬
#define NUM 10
#include "queue.h"
#include "Stack.h"

enum Subject {미적분학, 프로그래밍1, 프로그래밍2, 자료구조, 알고리즘, 소프트웨어공학, 운영체제, 웹프로그래밍, 머신러닝, 캡스톤};

char* subjectName[10] = {"미적분학", "프로그래밍1", "프로그래밍2", "자료구조", "알고리즘", "소프트웨어공학", "운영체제", "웹프로그래밍", "머신러닝", "캡스톤"};

int inDegree[NUM] = {0};
int result[NUM] = {0};

typedef struct Graph{
    int v;
    List* fromList;
}graph;

void graphInit(graph* pg, int v){
    pg->v = v;
    pg->fromList = (List*)malloc(sizeof(List)*v);
    for(int i=0;i<v;i++){
        listInit(&(pg->fromList[i]));
    }
}

void addEdge(graph* pg, int from, int to){
    Insert(&(pg->fromList[from]), to);
}

int topologySortStack(graph* pg){
    int index=0;
    //indegree 배열 초기화
    Node* w;
    ArrayStack stack;

    for(int i=0;i<NUM;i++){
        for(w=pg->fromList[i].head->next;w;w=w->next){
            //지금 vertex에서 나온 edge가 진입하는 vertex index에 ++해준다.
            inDegree[w->data]++;
        }
    }
    for(int i=0;i<NUM;i++){
        printf("%d ", inDegree[i]);
    }
    ArrayStackInit(&stack);
    // 진입차수가 0인게 들어가야하느데,,
    for(int i=0;i<NUM;i++){
        if(inDegree[i] == 0) SPush(&stack, i);
    }
    while (!SIsEmpty(&stack)) {
        int popelement = SPop(&stack);
        result[index++] = popelement;
        // 각 정점의 진입차수 변경
        for(w = pg->fromList[popelement].head;w;w=w->next){ //여기가 그래프의 키포인트 인접한 곳을 방문하라
            if(--inDegree[w->data] == 0){ //들어오는 edge를 삭제했을때 진입차수가 0이된다면
                SPush(&stack, w->data);
            }
        }
    }
    for(int i=0;i<NUM;i++){
        printf("%s -> ", subjectName[result[i]]);
    }
    if(index != 10) return TRUE;
    else return FALSE;
}

void topologySort(graph* pg){
    int index=0;
    //indegree 배열 초기화
    Node* w;
    for(int i=0;i<NUM;i++){
        for(w=pg->fromList[i].head->next;w;w=w->next){
            inDegree[w->data]++;
        }
    }
    for(int i=0;i<NUM;i++){
        printf("%d ", inDegree[i]);
    }
    printf("\n");
    //queue 선언
    queue queue;
    queueInit(&queue);
    for(int i=0;i<NUM;i++){
        if(inDegree[i] == 0){
            enqueue(&queue, i);
        }
    }
    // vertex개수많큼 해야지 위상정렬 수행됨
    for(int i=0;i<NUM;i++){
        // 다 돌기 전에 큐가 비었다면, 사이클 발생
        if(qisEmpty(&queue)){
            printf("싸이클 발생\n");
            exit(-1);
        }
        int dequeued = dequeue(&queue);
        result[index++] = dequeued;
        for(w=pg->fromList[dequeued].head->next;w;w=w->next){
            int y = w->data;
            if(--inDegree[y] == 0){
                enqueue(&queue, y);
            }
        }
    }
    for(int i=0;i<NUM;i++){
        printf("%s -> ", subjectName[result[i]]);
    }
}

void showGrpah(graph* pg){
    int data;
    for(int i=0;i<pg->v;i++){
        printf("%d와 연결된 정점: ", i);
        if(LFirst(&(pg->fromList[i]), &data)){
            printf("%d ", data);
            while(LNext(&(pg->fromList[i]), &data)){
                printf("%d ", data);
            }
        }
        printf("\n");
    }
}

int main(int argc, const char * argv[]) {
    graph graph;
    graphInit(&graph, NUM);

    addEdge(&graph, 미적분학, 프로그래밍1);
    addEdge(&graph, 미적분학, 웹프로그래밍);
    addEdge(&graph, 웹프로그래밍, 프로그래밍2);
    addEdge(&graph, 프로그래밍1, 프로그래밍2);
    addEdge(&graph, 프로그래밍2, 자료구조);
    addEdge(&graph, 자료구조, 운영체제);
    addEdge(&graph, 자료구조, 알고리즘);
    addEdge(&graph, 자료구조, 소프트웨어공학);
    addEdge(&graph, 운영체제, 머신러닝);
    addEdge(&graph, 머신러닝, 캡스톤);
    addEdge(&graph, 소프트웨어공학, 캡스톤);
    addEdge(&graph, 알고리즘, 캡스톤);
    showGrpah(&graph);
//    topologySort(&graph);
    printf("사이클 존재여부 %d\n", topologySortStack(&graph));
}

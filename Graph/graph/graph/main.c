//
//  main.c
//  graph
//
//  Created by abc on 2021/06/03.
//

#include "LinkedList.h"

int vertex[10] = {0,10,20,30,40,50,60,70,80,90};

int visited[10] = {0};

typedef struct _graph{
    int V;
    int E;
    List* adjList;
}Graph;

void graphInit(Graph* pg, int num){
    pg->adjList = (List*)malloc(sizeof(List)*num);
    pg->V = num;
    pg->E = 0;
    for(int i=0;i<num;i++){
        listInit(&(pg->adjList[i]));
    }
}
void AddEdge(Graph* pg, int from, int to){
    from = (int)(from/10);
    to = (int)(to/10);
    Insert(&(pg->adjList[from]), to);
    Insert(&(pg->adjList[to]), from);
}

void dfs(List list[], int start){
    Node* w;
    visited[start] = 1;
    printf("%d ", start*10);
    for(w=list[start].head->next;w;w=w->next){
        if(visited[w->data] == 0){
            dfs(list, w->data);
        }
    }
}

void showGrpah(Graph* pg){
    int data;
    for(int i=0;i<pg->V;i++){
        printf("%d와 연결된 정점: ", i);
        if(LFirst(&(pg->adjList[i]), &data)){
            printf("%d ", data);
            while(LNext(&(pg->adjList[i]), &data)){
                printf("%d ", data);
            }
        }
        printf("\n");
    }
}

int main(int argc, const char * argv[]) {
    Graph graph;
    graphInit(&graph, 10);
    AddEdge(&graph, 0, 90);
    AddEdge(&graph, 0, 80);
    AddEdge(&graph, 10, 20);
    AddEdge(&graph, 10, 90);
    AddEdge(&graph, 20, 80);
    
    AddEdge(&graph, 30, 40);
    AddEdge(&graph, 70, 40);
    AddEdge(&graph, 50, 70);
    AddEdge(&graph, 50, 60);
    showGrpah(&graph);
    int components = 0;
    for(int i=0;i<10;i++){
        if(visited[i] == 0){
            dfs(graph.adjList, i);
            printf("\n");
            components++;
        }
    }
    printf("components %d\n",components);
}

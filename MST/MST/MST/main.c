//
//  main.c
//  MST
//
//  Created by abc on 2021/06/06.
//

#include "City.h"
int getParent(int* parent, int x){
    if (parent[x] == x) {
        return x;
    }
    parent[x] = getParent(parent, parent[x]);
    return parent[x];
}

void unionParent(int* parent, int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a<b){
        parent[b] = a;
    }
    else{
        parent[a] = b;
    }
}

int findParent(int* parent, int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a == b)return 1;
    else return 0;
}


enum City {Seoul, NewYork, Incheon, Busan, Tokyo, Beijing, London, Paris, Daejeon, Jeju};
char* city[10] = {"Seoul", "NewYork", "Incheon", "Busan", "Tokyo", "Beijing", "London", "Paris", "Daejeon", "Jeju"};

int compare(const void *a, const void *b){
    Edge* num1 = (Edge *)a;
    Edge* num2 = (Edge *)b;
    
    if (num1->distance < num2->distance) return -1;
    if (num1->distance > num2->distance) return 1;
    
    return 0;
}

int main(int argc, const char * argv[]) {
    
    int parent[10] = {0};
    for(int i=0;i<10;i++){
        parent[i] = i;
    }
    
    int n = 15;
    Edge* EdgeList = (Edge*)malloc(sizeof(Edge)*n);
    for(int i=0;i<15;i++){
        EdgeInit(&EdgeList[i]);
    }
    addEdge(&EdgeList[0], Seoul, Busan, 50);
    addEdge(&EdgeList[1], Seoul, Daejeon, 25);
    addEdge(&EdgeList[2], Seoul, Incheon, 15);
    addEdge(&EdgeList[3], Busan, Daejeon, 25);
    addEdge(&EdgeList[4], Busan, Incheon, 60);
    addEdge(&EdgeList[5], NewYork, London, 35);
    addEdge(&EdgeList[6], NewYork, Paris, 45);
    addEdge(&EdgeList[7], Seoul, NewYork, 90);
    addEdge(&EdgeList[8], Tokyo, Beijing, 17);
    addEdge(&EdgeList[9], Incheon, Tokyo, 20);
    addEdge(&EdgeList[10], Jeju, London, 100);
    addEdge(&EdgeList[11], Daejeon, Jeju, 33);
    addEdge(&EdgeList[12], Beijing, London, 77);
    addEdge(&EdgeList[13], London, Paris, 8);
    addEdge(&EdgeList[14], Jeju, Tokyo, 20);
    
    qsort(EdgeList, n, sizeof(EdgeList[0]), compare);
    
    int sum = 0;
    for(int i=0; i<15;i++){
        if(!findParent(parent, EdgeList[i].city1, EdgeList[i].city2)){
            printf("%s - %s distance: %d\n", city[EdgeList[i].city1], city[EdgeList[i].city2], EdgeList[i].distance);
            sum += EdgeList[i].distance;
            unionParent(parent,EdgeList[i].city1, EdgeList[i].city2);
        }
    }
    printf("sum %d\n", sum);
    
}


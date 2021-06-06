//
//  City.h
//  MST
//
//  Created by abc on 2021/06/06.
//

#ifndef City_h
#define City_h
#define MAX_V 10

#include <stdio.h>
#include <stdlib.h>

typedef struct Edge{
    int city1;
    int city2;
    int distance;
}Edge;

void EdgeInit(Edge* edge);
void addEdge(Edge* edge, int city1, int city2, int distance);


#endif /* City_h */

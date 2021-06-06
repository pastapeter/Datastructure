//
//  City.c
//  MST
//
//  Created by abc on 2021/06/06.
//

#include "City.h"

void EdgeInit(Edge* edge){
    edge->city1 = 0;
    edge->city2 = 0;
    edge->distance = 0;
}

void addEdge(Edge* edge, int city1, int city2, int distance){
    edge->city1 = city1;
    edge->city2 = city2;
    edge->distance = distance;
}

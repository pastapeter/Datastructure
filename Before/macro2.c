#include <stdio.h>
#define MULTIPLY(X,Y,Z) X*Y*Z
#define ADD(X,Y,Z) X+Y+Z

int main(){
    printf("%d %d\n", MULTIPLY(2,3,4), ADD(2,3,4));
}
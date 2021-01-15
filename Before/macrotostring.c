#include <stdio.h>
#define STRONG_JOB(A,B) #A"의 직업은" #B"입니다"

int main(){
    printf("%s \n", STRONG_JOB(이동춘, 나무꾼));
}
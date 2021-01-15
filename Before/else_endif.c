#include <stdio.h>
#define HIT_NUM 5

int main(){
#if HIT_NUM ==5
    puts("메크로 상수 HIT_NUM은 현재 5 입니다.");
#else
    puts("매크로 상수 HIT_NUM은 현재 5가 아닙니다. ");
#endif
}
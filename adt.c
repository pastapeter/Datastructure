#include <stdio.h>
#include <stdlib.h>

typedef struct_wallet{
    int coin100num;
    int bill5000num;
}Wallet;

int TakeOutMoney(Wallet *pw, int coinNum, int billNum){
    //첫번째 인자로 전달된 주소의 지갑에서 돈을꺼낸다.
    //두번째 인자로 꺼낼 동전의 수, 세번째 인자로 꺼낼 지폐의 수를 전달한다.
    //꺼내고자 하는 돈의 총액을 반환한다.그리고 차감한다.
}
void PutMoney(Wallet *pw, int coinNum, int billNum){
    //첫번째 인자로 전달된 주소의 지갑에서 돈을 넣는다.
    //두번째 인자로 넣을 동전의 수, 세번째 인자로 넣을 지폐의 수를 전달한다.
    //넣은만큼 동전과 지폐의 수가 증가한다.
}

int main(){
    Wallet myWallet;
    PutMoney(&myWallet, 5,10);
    ret = TakeOutMoney(&myWallet, 2, 5);
}
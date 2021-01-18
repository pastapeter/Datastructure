//
//  main.c
//  Namecard
//
//  Created by abc on 2021/01/16.
//

#include <stdio.h>
#include <string.h>
#include "Namecard.h"
#include "ArrayList.h"
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    List list;
    NameCard* pcard;
    ListInit(&list);
    
    pcard = MakeNameCard("정도현", "01027160593");
    LInsert(&list, pcard);
    pcard = MakeNameCard("배승은", "01075971468");
    LInsert(&list, pcard);
    pcard = MakeNameCard("또로롱", "01012345678");
    LInsert(&list, pcard);
    
    // 그 사람의 정보를 출력한다.
    if(LFirst(&list, &pcard)){
        if(!NameCompare(pcard,"정도현")){
            ShowNameCardInfo(pcard);
        }
        else{
            while(LNext(&list, &pcard)){
                if(!NameCompare(pcard,"정도현")){
                    ShowNameCardInfo(pcard);
                    break;
                }
            }
        }
    }
    // 그사람의 전화번호를 변경한다.
    if(LFirst(&list, &pcard)){
        if(!NameCompare(pcard, "배승은")){
            ChangePhoneNum(pcard, "01075970593");
        }
        else{
            while(LNext(&list,&pcard)){
                if(!NameCompare(pcard, "배승은")){
                    ChangePhoneNum(pcard, "01075970593");
                    break;
                }
            }
        }
    }


    // 그사람의 정보를 삭제한다.
    if(LFirst(&list, &pcard)){
        if(!NameCompare(pcard, "또로롱")){
            LRemove(&list);
            free(pcard);
        }
        else{
            while(LNext(&list, &pcard)){
                if(!NameCompare(pcard, "또로롱")){
                    LRemove(&list);
                    free(pcard);
                }
            }
        }
    }
    //전부 출력하기
    if(LFirst(&list, &pcard)){
        ShowNameCardInfo(pcard);
        while(LNext(&list, &pcard)){
            ShowNameCardInfo(pcard);
        }
    }
}

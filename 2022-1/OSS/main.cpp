#include <iostream>
#include <limits>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "header.h"
#include "memberList.h"
#include "menuList.h"

//using namespace std;
using std::string; using std::vector;
using std::cout; using std::endl;
using std::cin; using std::numeric_limits;


//OSS FINAL PROJECT
//BabgoToday

/*

일단 menu driven 형식으로... 단 모든 기능 모듈화해서 어쩌구 해두자. 그... 헤더파일...? 그방식을 써야하려나 일단 핸두고보자구

printinfo
main에서는 while로 무한반복시키고

멤버 목록 하나랑 class
메뉴 string으로 저장하는 메뉴리스트 class

1. 멤버등록
    1-1 멤버목록 조회(이름, 금액(0으로 세팅))
    1-2 멤버 추가
    1-3 멤버 삭제
    1-4 선택한 멤버 부담금액 추가
    1-5 전체 멤버에 n빵
2. 메뉴리스트
    2-1 메뉴 리스트 조회
    2-2 메뉴 리스트 추가
    2-3 메뉴 리스트에서 삭제
    2-4 랜덤메뉴 고르기 

*/



// ------------------------------------------------------------------------------------


int main(void){

    int cmd;
    memberList mem;
    menuList men;
    string todays;


    while(1){
        printInfo();
        cmd = getCommand();
        switch (cmd){
            case 1: //member list
            //@TODO. lets copy after complete this one in the run method
                cout << "\n -----Member List-----\n\n";
                mem.showMember();
                cout << endl;
                break;
            case 2: //get random menu
            //@TODO. lets copy after complete this one in the run method
                todays = men.getRandomMenu();
                if(todays == "null") cout << "\n[list is empty. please add some members.]\n\n";
                else{
                    cout << "\n\n - - - - - - - - - - - - - - - - - -\n";
                    cout << "\nHow about " << todays << " Today? :D\n";
                    cout << "\n - - - - - - - - - - - - - - - - - -\n\n";
                }
                break;
            case 3: //member
                mem.run();
                break;
            case 4: //menu
                men.run();
                break;
            case 0:
                cout << "\nHave a nice Babgo XD\n\n";
                return 0;
            default:
                cout << "\nCannot found the command :(\n\n";
                break;
        }
    }

}

// -------------------------------------------------------------------------------------
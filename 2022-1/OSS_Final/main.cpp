#include <iostream>
using namespace std;
#define SIZE 50

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
class member{
    string name;
    int cost;

    public:
    member(string newName);
    member(string newName, int initCost);

};

class memberList{
    member m[SIZE];
    int num;

    public:
    memberList();
    void showMember();
    void addMember(string newName);
    int deleteMember(string x);
    int addCostToSelectedMember(string name, int cost);
    void addCostToAllMember(int cost);

};

class menuList{
    string m[SIZE];
    int num;

    public:
    menuList();
    void showMenu();
    void addMenu(string newMenu);
    int deleteMenu(string x);
    string getRandomMenu();

};

void printInfo();
void printMemberInfo();
void printMenuInfo();


int main(void){

    int x;
    int y;
    bool flag = false;
    memberList mem;
    menuList men;
    string newM;
    int newC;


    while(1){
        printInfo();
        cin >> x;
        switch (x){
            case 1:
                flag = false;
                while(1){
                    printMemberInfo();
                    cin >> y;
                    switch (y){
                        case 1:
                            cout << "\n -----Member List-----\n";
                            mem.showMember();
                            cout << endl;
                            break;
                        case 2:
                            cout << "start adding member...\n member name:";
                            cin >> newM;
                            mem.addMember(newM);
                            cout << endl;
                            cout << "succedfully added!\n\n";
                            break;
                        case 3:
                            cout << "start deleteing member...\n member name:";
                            cin >> newM;
                            if(mem.deleteMember(newM)== 0){
                                cout << "Cannot find the name :(\n";
                            }else cout << "\nsuccedfully deleted!\n\n";
                            break;
                        case 4:
                            cout << "start adding cost to member...\n member name:";
                            cin >> newM;
                            cout << "cost:";
                            cin >> newC;
                            mem.addCostToSelectedMember(newM, newC);
                            cout << endl;
                            cout << "succedfully added!\n\n";
                            break;
                        case 0:
                            cout << "\nReturn to main page...\n";
                            flag = true;
                        default:
                            cout << "Cannot found the command :(\n";
                            break;
                        }
                    if(flag) break;
                }
                break;
            case 2:
                flag = false;
                while(1){
                    printMenuInfo();
                    cin >> y;
                    switch (y){
                        case 1:
                            
                            break;
                        case 2:
                            
                            break;
                        case 0:
                            cout << "\nReturn to main page...\n";
                            flag = true;
                        default:
                            cout << "Cannot found the command :(\n";
                            break;
                        }
                    if(flag) break;
                }
                break;
            case 0:
                cout << "Have a nice day :D\n";
                return 0;
            
            default:
                cout << "Cannot found the command :(\n";
                break;
        }

    }


}
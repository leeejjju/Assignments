#include <iostream>
#include <vector>
using namespace std;

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

    public:
    string name;
    int cost;
    member(string newName){
        name = newName;
        cost = 0;
    }
    member(string newName, int initCost){
        name = newName;
        cost = initCost;
    }
};

class memberList{
    vector<member> m;
    int num;
    int x;

    public:
    memberList(){
        m.clear();
        num = 0;
    }
    void printInfo();
    void run();
    void showMember();
    void addMember(string newName);
    int deleteMember(string x);
    int addCostToSelectedMember(string name, int cost);
    void addCostToAllMember(int cost);
};

class menuList{
    vector<string> m;
    int num;
    int x;

    public:
    menuList(){
        m.clear();
        num = 0;
    }
    void printInfo();
    void run();
    void showMenu();
    void addMenu(string newMenu);
    int deleteMenu(string x);
    string getRandomMenu();

};

void printInfo();


// ------------------------------------------------------------------------------------


int main(void){

    int cmd;
    memberList mem;
    menuList men;


    while(1){
        printInfo();
        cin >> cmd;
        switch (cmd){
            case 1: //member list
            //@TODO. lets copy after complete this one in the run method
                mem.showMember();
                break;
            case 2: //get random menu
            //@TODO. lets copy after complete this one in the run method
                cout << "\n\n - - - - - - - - - - - - - - - - - -\n";
                cout << "\nHow about " << men.getRandomMenu() << " Today? :D\n";
                cout << "\n - - - - - - - - - - - - - - - - - -\n\n";
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

// --------------------------------------------------------------------------------------

//print the main infomation. 
void printInfo(){
    //cout << "Hello World!!!\n plz input the command ^0^(1, 2, 0) >>";
    printf("\n[Welcome to BabgoToday!]\n\n");
    printf("1 : Show the member list\n2 : Get some random menu\n3 : Edit members\n4 : Edit menus\n0 : Exit\n>> ");
}

//-- -------------------------------------------------------------------------------------

//print the member information
void memberList :: printInfo(){
    cout << "\n~ member setting page ~\n\n";
    printf("1 : Show the member list\n2 : Add member\n3 : Delete member\n4 : Add cost to selected member\n5 : Add cost to all member\n0 : Exit\n>> ");
    return;
}

void memberList :: run(){
    string newM;
    int newC;

    while(1){
        printInfo();
        cin >> x;
        switch (x){
            case 1:
                cout << "\n -----Member List-----\n";
                showMember();
                cout << endl;
                break;
            case 2:
                cout << "start adding member...\n member name: ";
                cin >> newM;
                addMember(newM);
                cout << endl;
                cout << "succedfully added!\n\n";
                break;
            case 3:
                cout << "start deleteing member...\n member name: ";
                cin >> newM;
                if(deleteMember(newM)== 0){
                    cout << "Cannot find the name :(\n";
                }else cout << "\nsuccedfully deleted!\n\n";
                break;
            case 4:
                cout << "start adding cost to member...\n member name: ";
                cin >> newM;
                cout << "cost: ";
                try{
                    cin >> newC;
                }catch(int exception){
                    cout << "\nplease input the right vlaue :(\n\n";
                    break;
                }
                addCostToSelectedMember(newM, newC);
                cout << "\nsuccedfully reflected!\n\n";
                
                break;
            case 5:
                cout << "start adding cost to all member...\n whole cost:";
                cin >> newC;
                addCostToAllMember(newC);
                cout << "\nsuccedfully reflected!\n\n";
                break;
            case 0:
                cout << "\nReturn to main page...\n";
                return;
            default:
                cout << "Cannot found the command :(\n";
                break;
            }
    }

}

void memberList :: showMember(){
    cout << "#showMember\n";
    if(num == 0) cout << "[list is empty. please add some members.]\n\n";
    else for(int i = 0; i < num; i++) cout << m[i].name << " : " << m[i].cost << endl;
    
}

void memberList :: addMember(string newName){
    cout << "#addMember\n";
    member tmp(newName);
    m.push_back(tmp);
    num ++;

}

//return 1 if success, return 0 if faild.
int memberList :: deleteMember(string x){
    cout << "#deleteMember\n";
    int i = 0;

    if(num == 0){
        cout << "[error] list is empty.\n";
        return 0;
    }

    for(i = 0; ((i != num) && (m[i].name != x)); i++);

    if( i == num){
        cout << "[error] cannot found the name.\n";
        return 0;
    }else {
        m.erase(m.begin()+i);
        num -= 1;
    }


    return 1;

}

int memberList :: addCostToSelectedMember(string name, int cost){
    cout << "addCostToSelectedMember\n";
    return 0;
}

void memberList :: addCostToAllMember(int cost){
    cout << "addCostToAllMember\n";
}


// menu -------------------------------------------------------

void menuList :: printInfo(){
    cout << "\n~ menu setting page ~\n\n";
    printf("1 : Show the menu list\n2 : Add menu\n3 : Delete menu\n4 : Get some random menu\n0 : Exit\n>> ");
    return;

}

void menuList :: run(){
    string newM;

    while(1){
        printInfo();
        cin >> x;
        switch (x){
            case 1:
                cout << "\n -----Menu List-----\n";
                showMenu();
                cout << endl;
                break;
            case 2:
                cout << "start adding Menu...\n Menu name: ";
                cin >> newM;
                addMenu(newM);
                cout << endl;
                cout << "succedfully added!\n\n";
                break;
            case 3:
                cout << "start deleteing Menu...\n Menu name: ";
                cin >> newM;
                if(deleteMenu(newM)== 0){
                    cout << "Cannot find the name :(\n";
                }else cout << "\nsuccedfully deleted!\n\n";
                break;
            case 4:
                cout << "\n\n - - - - - - - - - - - - - - - - - -\n";
                cout << "\nHow about " << getRandomMenu() << " Today? :D\n";
                cout << "\n - - - - - - - - - - - - - - - - - -\n\n";
                break;
            case 0:
                cout << "\nReturn to main page...\n";
                return;
            default:
                cout << "Cannot found the command :(\n";
                break;
            }
    }
    

}

void menuList :: showMenu(){
    cout << "showMenu\n";
}

void menuList :: addMenu(string newMenu){
    cout << "addMenu\n";

}

int menuList :: deleteMenu(string x){
    cout << "deleteMenu\n";
    return 0;

}

string menuList :: getRandomMenu(){
    cout << "getRandomMenu\n";
    return "null";

}


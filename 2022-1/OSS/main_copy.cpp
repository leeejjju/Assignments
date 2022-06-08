#include <iostream>
#include <limits>
#include <vector>
#include <stdlib.h>
#include <time.h>

using std::string; using std::vector;
using std::cout; using std::endl;
using std::cin; using std::numeric_limits;

//OSS FINAL PROJECT
//BabgoToday



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
    int x;

    public:
    memberList(){
        m.clear();
    }
    void printInfo();
    void run();
    void showMember();
    int addMember(string newName);
    int deleteMember(string x);
    int addCostToSelectedMember(string name, int cost);
    int addCostToAllMember(int cost);
};


class menuList{
    vector<string> m;
    int x;

    public:
    menuList(){
        m.clear();
    }
    void printInfo();
    void run();
    void showMenu();
    int addMenu(string newMenu);
    int deleteMenu(string x);
    string getRandomMenu();

};

void printInfo();
int getCommand();



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



//print the main infomation. 
void printInfo(){
    //cout << "Hello World!!!\n plz input the command ^0^(1, 2, 0) >>";
    printf("\n[Welcome to BabgoToday!]\n\n");
    printf("1 : Show the member list\n2 : Get some random menu\n3 : Edit members\n4 : Edit menus\n0 : Exit\n");
}

//get valid int cmd
int getCommand(){
    int x;
    while (true) {
        cout << ">> ";
        if (cin >> x) {
            break;
        } else {
            cout << "Enter a valid integer command!\n";
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return x;
}



//member---------------------------------------------------------------------------------------

//print the member information
void memberList :: printInfo(){
    cout << "\n~ member setting page ~\n\n";
    printf("1 : Show the member list\n2 : Add member\n3 : Delete member\n4 : Add cost to selected member\n5 : Add cost to all member\n0 : Exit\n");
    return;
}

void memberList :: run(){
    string newM;
    int newC;

    while(1){
        printInfo();
        //cin >> x;
        x = getCommand();
        switch (x){
            case 1:
                cout << "\n -----Member List-----\n\n";
                showMember();
                cout << endl;
                break;
            case 2:
                cout << "start adding member...\n member name: ";
                cin >> newM;
                if(addMember(newM) != 0) cout << "\nsuccedfully added!\n\n";
                break;
            case 3:
                cout << "start deleteing member...\n member name: ";
                cin >> newM;
                if(deleteMember(newM) != 0) cout << "\nsuccedfully deleted!\n\n";
                break;
            case 4:
                cout << "start adding cost to member...\n member name: ";
                cin >> newM;
                while (true) {
                    cout << " cost: ";
                    if (cin >> newC) break;
                    else {
                        cout << "Enter a valid integer cost!\n";
                        cin.clear();
                        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                    }
                }
                if (addCostToSelectedMember(newM, newC) != 0) cout << "\nsuccedfully reflected!\n\n";
                
                break;
            case 5:
                cout << "start adding cost to all member...\n";

                while (true) {
                    cout << " whole cost: ";
                    if (cin >> newC) break;
                    else {
                        cout << "Enter a valid integer cost!\n";
                        cin.clear();
                        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                    }
                }



                cin >> newC;
                if(addCostToAllMember(newC) != 0) cout << "\nsuccedfully reflected!\n\n";
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
    //cout << "#showMember\n";
    if(m.empty()) cout << "[list is empty. please add some members.]\n\n";
    else for(int i = 0; i < m.size(); i++) cout << m[i].name << " : " << m[i].cost << endl;
    
}

int memberList :: addMember(string newName){
    //cout << "#addMember\n";

    int i = 0;
    for(i = 0; (i != m.size() && (m[i].name != newName)); i++);
    if( i < m.size()){
        cout << "[error] cannot used duplicate name.\n";
        return 0;
    }

    member tmp(newName);
    m.push_back(tmp);
    return 1;

}

//return 1 if success, return 0 if faild.
int memberList :: deleteMember(string x){
    //cout << "#deleteMember\n";
    int i = 0;

    if(m.empty()){
        cout << "[error] list is empty.\n";
        return 0;
    }

    for(i = 0; (i != m.size() && (m[i].name != x)); i++);

    if( i == m.size()){
        cout << "[error] cannot find the name.\n";
        return 0;
    }else m.erase(m.begin()+i);
    
    return 1;

}

int memberList :: addCostToSelectedMember(string name, int cost){
    //cout << "#addCostToSelectedMember\n";
    int i = 0;
    for(i = 0; (i != m.size() && (m[i].name != name)); i++);

    if( i == m.size()){
        cout << "[error] cannot find the name.\n";
        return 0;
    }else m[i].cost += cost;
    
    return 1;

    return 0;
}

int memberList :: addCostToAllMember(int cost){
    //cout << "#addCostToAllMember\n";
    if(m.empty()){
        cout << "[error] list is empty.\n";
        return 0;
    }
    float c = cost/m.size();
    for(int i = 0; i < m.size(); i++) m[i].cost += c;
    return 1;
}



// menu -------------------------------------------------------

void menuList :: printInfo(){
    cout << "\n~ menu setting page ~\n\n";
    printf("1 : Show the menu list\n2 : Add menu\n3 : Delete menu\n4 : Get some random menu\n0 : Exit\n");
    return;

}

void menuList :: run(){
    string newM;

    while(1){
        printInfo();
        //cin >> x;
        x = getCommand();
        switch (x){
            case 1:
                cout << "\n -----Menu List-----\n";
                showMenu();
                cout << endl;
                break;
            case 2:
                cout << "start adding Menu...\n Menu name: ";
                cin >> newM;
                if(addMenu(newM) != 0) cout << "\nsuccedfully added!\n\n";
                break;
            case 3:
                cout << "start deleteing Menu...\n Menu name: ";
                cin >> newM;
                if(deleteMenu(newM) != 0) cout << "\nsuccedfully deleted!\n\n";
                break;
            case 4:
                if(m.empty()) cout << "\n[list is empty. please add some members.]\n\n";
                else{
                    cout << "\n\n - - - - - - - - - - - - - - - - - -\n";
                    cout << "\nHow about " << getRandomMenu() << " Today? :D\n";
                    cout << "\n - - - - - - - - - - - - - - - - - -\n\n";
                }
                break;
            case 0:
                cout << "\nReturn to main page...\n";
                return;
            default:
                cout << "Cannot find the command :(\n";
                break;
        }
    }

}

void menuList :: showMenu(){
    //cout << "#showMenu\n";
    if(m.empty()) cout << "[list is empty. please add some members.]\n\n";
    else for(int i = 0; i < m.size(); i++) cout << m[i] << endl;
}

int menuList :: addMenu(string newMenu){
    //cout << "#addMenu\n";

    int i = 0;
    for(i = 0; (i != m.size() && (m[i] != newMenu)); i++);
    if(i < m.size()){
        cout << "[error] cannot used duplicate menu.\n";
        return 0;
    }

    m.push_back(newMenu);
    return 1;

}

int menuList :: deleteMenu(string x){
    //cout << "#deleteMenu\n";
    int i = 0;

    if(m.empty()){
        cout << "[error] list is empty.\n";
        return 0;
    }

    for(i = 0; (i != m.size() && (m[i] != x)); i++);

    if( i == m.size()){
        cout << "[error] cannot find the menu.\n";
        return 0;
    }else m.erase(m.begin()+i);
    
    return 1;

}

string menuList :: getRandomMenu(){
    //cout << "#getRandomMenu\n";

    if(m.empty()) return "null";

    srand(time(NULL));
    int ranNum = rand() % m.size();
    
    return m[ranNum];

}



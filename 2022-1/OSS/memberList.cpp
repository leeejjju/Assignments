#include <iostream>
#include <limits>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "memberList.h"
#include "header.h"

using std::string; using std::vector;
using std::cout; using std::endl;
using std::cin; using std::numeric_limits;



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

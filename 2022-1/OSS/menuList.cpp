#include <iostream>
#include <limits>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "menuList.h"
#include "header.h"

using std::string; using std::vector;
using std::cout; using std::endl;
using std::cin; using std::numeric_limits;

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



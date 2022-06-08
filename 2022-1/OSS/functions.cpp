#include <iostream>
#include <limits>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "header.h"

using std::string; using std::vector;
using std::cout; using std::endl;
using std::cin; using std::numeric_limits;




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

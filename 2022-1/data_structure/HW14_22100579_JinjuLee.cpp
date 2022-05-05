#include <iostream>
using namespace std;

//데이타구조 Programming Assignment 14
//22100579 이진주
/*Binary Search Tree 구현 예제

아래와 같은 형식의 Menu-driven program 으로

 {전화번호, 생일 외 정보 } 목록을 binary search tree로 구현

(내용과 세부 형식은 자유롭게 구현 할 것)

(Menu 예)

새로운 원소 추가
원소 조회
전체 목록 보기
종료
  명령 선택 : _     
*/


class bst_node{

    public:
    //data
    //{전화번호, 생일 외 정보 }
    string phoneNum;
    string name;
    string birthDay;
    string mayjor;

    //link
    bst_node* left;
    bst_node* right;
    
    void set_data(string newPhoneNum, string newName, string newBirthDay, string newMayjor){
        phoneNum = newPhoneNum;
        name = newName;
        birthDay = newBirthDay;
        mayjor = newMayjor;
    }

};

class bst_tree{
    bst_node* root;
    int size;

    public:
    bst_tree(){
        root = NULL;
        size = 0;
    }
    void insert_node(bst_node x); 
    void show_inorder();
    bst_node search(string key);

};



void showInfo();
void goToSelected(int key);

void addNewNode();
void showSelectedNode();
void showAllNodes();
void exitMenu();



int main(){

    bst_node temp;
    bst_tree t1;  
    int key; 

    while(1){
        showInfo();
        cin >> key;

        
        switch (key)
        {
        case 1:
            //addNewNode();
            if(true) printf("\nnew node succefully added!\n");
            else printf("\ncannot add the node :(\n");

            break;
        case 2:
            //showSelectedNode();
            if(true) printf("\nsuccefully found the node!\n");
            else printf("\ncannot find the node :(\n");
            break;
        case 3:
            //showAllNodes();
            if(true) printf("\nall the nodes succefully loaded!\n");
            else printf("\ntree is empyt :(\n");
            break;
        case 0:
            //exitMenu();
            cout << "\nsee you again ;D\n\n";
            return 0;
            break;
        
        default:
            cout << "\nCannot find the command :(\n\n";
            break;
        } 

    } 


    return 0;
}

/*
새로운 원소 추가
원소 조회
전체 목록 보기
종료
  명령 선택 : _ 
  */
void showInfo(){

    printf("\n--------MENU--------\n\n");
    printf("1: add new node\n");
    printf("2: search the node\n");
    printf("3: show all nodes\n");
    printf("0: exit\n");
    printf("\t\t command: ");


}

void goToSelected(int key){

}

void addNewNode(){

}
void showSelectedNode(){

}
void showAllNodes(){

}
void exitMenu(){

}
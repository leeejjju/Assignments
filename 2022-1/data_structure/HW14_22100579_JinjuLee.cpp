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


class node{

    public:
    //data
    //{전화번호, 생일 외 정보 }
    string phoneNum; //key
    string name;
    string birthDay;
    string mayjor;

    //link
    node* left;
    node* right;
    
    void set_data(string newPhoneNum, string newName, string newBirthDay, string newMayjor){
        phoneNum = newPhoneNum;
        name = newName;
        birthDay = newBirthDay;
        mayjor = newMayjor;
        left = NULL;
        right = NULL;
    }

};

class bst_tree{
    node* root;
    int size;

    public:
    bst_tree(){
        root = NULL;
        size = 0;
    }
    node search(string key);
    int insert_node(node x); //when failed, return 0
    //void delete_node(string key);
    void show_inorder();
    int getSize();
    bool isEmpty();

};

void inorder_traverse(node* p);

void showInfo();

void addNewNode(bst_tree *t1);
void showSelectedNode(bst_tree t1);
void showAllNodes(bst_tree t1);



int main(){

    node temp;
    bst_tree t1;  
    int key; 

    while(1){
        showInfo();
        cin >> key;

        
        switch (key)
        {
        case 1:
            addNewNode(&t1);
            break;
        case 2:
            showSelectedNode(t1);
            break;
        case 3:
            showAllNodes(t1);
            break;
        case 0:
            cout << "\nSee you again ;D\n\n";
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


void addNewNode(bst_tree *t1){
  string num, name, birth, major;
  
  cout << "\nstart adding new node...\nplease input the datas!\n\n";
  cout << "phone number(key): ";
  cin >> num;
  cout << "name: ";
  cin >> name;
  cout << "birth day: ";
  cin >> birth;
  cout << "major: ";
  cin >> major;
  
  node x;
  x.set_data(num, name, birth, major);
  if(t1->insert_node(x) == 0) cout << "please try again :(\n";
  else cout << "new node succefully added!\n\n";
  
}

void showSelectedNode(bst_tree t1){
  string key;
  
  cout << "input phone number(key): ";
  cin >> key;
  
  node rst = t1.search(key);
  if(rst.phoneNum == "null") cout << "please insert some data first :(\n";
  else{
    cout << "\nsuccefully found the node!\n";
    cout << rst.phoneNum << " : " << rst.name << " : " << rst.birthDay << " : " << rst.mayjor << endl;
  } 
  
}

void showAllNodes(bst_tree t1){
  t1.show_inorder();
}


//-----------

node bst_tree:: search(string key){
  node none;
  none.set_data("null", "null", "null", "null");
  if(isEmpty()){
    cout << "\n[error: tree is empty]\n";
    return none;
  } 

  node* t = root;

  while(1){
      if(t == NULL){
          cout << "\n[error: cannot find the node of the key]\n";
          return none;
      } 
      if(t->phoneNum == key) return *t;
      else if((t->phoneNum) > key) t = t->left;
      else t = t->right;
  }
  
}
int bst_tree:: insert_node(node x){
    
  node* tmp = new node;
  *tmp = x;
  tmp->left = NULL;
  tmp->right = NULL;
  
  if(isEmpty()){
    root = tmp;
    size++;
    return 1;
  }
  
  node* t = root;
  while(1){
      if(t->phoneNum == x.phoneNum){
        cout << "\n[error: dupplicated key value]\n";
        return 0;
      }else if(t->phoneNum > x.phoneNum){
        if(t->left == NULL){
          t->left = tmp;
          break;
        }else t = t->left;
      }else{
        if(t->right == NULL){
          t->right = tmp;
          break;
        }else t = t->right;
      }
  }
  
  size++;
  //cout << t->name << " is successfully added." << endl;
  //cout << "current size is " << size << endl;
  return 1;
  
  
}
//void delete_node(string key);
void bst_tree:: show_inorder(){
  cout << endl;
  inorder_traverse(root);
  cout << size << " nodes loaded.\n";
}

void inorder_traverse(node* p){
  //왼쪽, 본인, 오른쪽 순으로 traversal
  //linked list
  if(p == NULL) return;
  inorder_traverse(p->left);
  cout << p->phoneNum << " : " << p->name << " : " << p->birthDay << " : " << p->mayjor << endl;
  inorder_traverse(p->right);
}


int bst_tree:: getSize(){
  return size;
}

bool bst_tree:: isEmpty(){
  if(size > 0) return false;
  return true;
}
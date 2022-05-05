#include <iostream>
using namespace std;

//데이타구조 Programming Assignment 13
//22100579 이진주

/*Binary Search Tree 구현 예제
아래의 주어진  main 함수의 의도대로 동작하는 프로그램을 완성하시오.
(강의 내용 참조)
*/

class bst_node{

    public:
    //data
    string s_id;
    string name;
    double score;

    //link
    bst_node* left;
    bst_node* right;

    void set_data(string newID, string newName, double newScore){
        s_id = newID;
        name = newName;
        score = newScore;
        left = NULL;
        right = NULL;
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


int main(){

    bst_node temp;
    bst_tree t1;       

    temp.set_data("21900013", "Kim", 6.5);      
    t1.insert_node(temp);     
    temp.set_data("21900136", "Lee", 8.8);
    t1.insert_node(temp);
    temp.set_data("21900333", "Park", 9.2);
    t1.insert_node(temp);
    temp.set_data("21800442", "Choi", 7.1);
    t1.insert_node(temp);
    temp.set_data("21900375", "Ryu", 5.4);
    t1.insert_node(temp);
    temp.set_data("21700248", "Cho", 6.3);
    t1.insert_node(temp);

    cout << "\n\n Node List : inorder sequence \n";
    t1.show_inorder();

    string s_key = "21800442";
    temp = t1.search(s_key);

    cout << "\n -- " << s_key << "'s record ---" << endl;
    cout << " Student ID   : "<< temp.s_id << endl;
    cout << " Student Name : "<< temp.name << endl;
    cout << " Score        : " << temp.score << endl;
    
    return 0;
}

 


void bst_tree:: insert_node(bst_node x){


} 


void bst_tree:: show_inorder(){


}


bst_node bst_tree:: search(string key){

    
}


 
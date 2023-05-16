#include <iostream>
#include <string>
#define HSIZE 31
using namespace std;
/*
    알고리듬분석 HW1_ 22100579 이진주
    references:
    김호준교수님 데이타구조 강의 slide chapter28 page5-8
*/

class element{
    public:
    string name;
    int id; 
    string school;
    void set_data(string newName, int newID, string newSchool); //노드의 데이타 설정 
};

//min-priority queue by heap
class my_heap{

    public:
    element h[HSIZE];
    int csize; 

    my_heap();
    bool isFull();
    bool isEmpty();
    void printAll();

}pq;

//utility
void swap(element* a, element* b);//swap two element in array
int idCheck(string id); //validation check about ID

//for Menu-Driven view
void printMenu(); //print info about menu
int insertQueue(); //asks user’s name and score, then inserts element into queue.
int deleteQueue(); //removes and displays record of element with smallest score and rebuild queue.
int decreaseQueue(); //asks index of element and new score of element, then decreases key value of the element and place the element in proper position.
int PrintQueue(); //displays all elements in queue.

//requirements
void INSERT(element* S, element x);
element MINIMUM(element* S);
element EXTRACT_MIN(element* S);
void DECREASE_KEY(element* S, element x, int k);



int main(){

    printMenu();
    return 0;

}

// ----------------- utility func -----------------------

void swap(element* a, element* b){
    element tmp = *a;
    *a = *b;
    *b = tmp;
}

//return the int type valid ID. if not valid, return 0
int idCheck(string id){
    //4 digit (integer) / 0xxx is not valid 
    //User may enter any character such as “12 34”, “123o”, “12_34”, etc
    char confirm;
    bool flag = false;
    
    for(int i = 0; i < id.length(); i++){
        if(!isdigit(id[i]) || id[i] == ' '){
            id.erase(id.begin()+i);
            flag = true;
            i --;
        }
    }

    if(flag){
        while(1){
            cout << "[notice] continue with " << id << "?(Y/N) : ";
            cin >> confirm;
            getchar();
            if(confirm == 'N' || confirm == 'n') return 0;
            if(confirm == 'Y' || confirm == 'y') break;
            printf("[notice] wrong command\n");
        }
    }

    if((id.length() != 4) || id[0] == '0'){
        printf("[notice] ID must be 4 digit integer\n");
        return 0;
    }

    return stoi(id);

}

string trim(string s){
    if(s[0] == ' ') s.erase(s.begin());
    if(s[s.length()-1] == ' ') s.erase(s.end() -= 1);
    return s;
}

// ----------------- requirements func -----------------------


void INSERT(element* S, element x){
    if(pq.isFull()){
        cout << "[notice] heap is full.\n";
        return;
    }

    int k = ++pq.csize; 
    S[k] = x;

    while(1){
        if(k == 1) return;
        if(S[k].id < S[k/2].id){
            swap(&(S[k]), &(S[k/2]));
            k = k/2;
        }else return;
    }
}

element MINIMUM(element* S){
    return S[0];
}

element EXTRACT_MIN(element* S){
    if(pq.isEmpty()){
        cout << "[notice] heap is empty\n";
        element dumy;
        dumy.set_data("NONE", -1, "NONE");
        return dumy;
    }

    element tmp = S[1];
    S[1] = S[pq.csize--];
    int k = 1; 
    int c;

    while(1){
        if(k*2+1 <= pq.csize) c = (S[k*2].id < S[k*2+1].id)? (k*2): (k*2+1);
        else if(k*2 <= pq.csize) c = k*2;
        else return tmp;
        
        if(S[k].id > S[c].id) swap(&(S[k]), &(S[c]));
        else return tmp;
    }
    return tmp;
}

void DECREASE_KEY(element* S, int x, int k){
    
    S[x].id = k; //update element

    //reheaping
    int key = x; 
    while(1){
        if(key == 1) return;
        if(S[key].id < S[key/2].id){
            swap(&(S[key]), &(S[key/2]));
            key = key/2;
        }else return;
    }

}


// ----------------- class func -----------------------

my_heap:: my_heap(){
    csize = 0;
}

bool my_heap:: isFull(){
    if(csize >= HSIZE-1 ) return true;
    return false;
}

bool my_heap:: isEmpty(){
    if(csize == 0) return true;
    return false;
}

void my_heap::printAll(){

    for(int i = 1; i <= csize ; i++){
        cout << "[" << h[i].name << ", " << h[i].id  << ", " <<  h[i].school+ "] ";
    }
    cout.clear();

}

void element:: set_data(string newName, int newID, string newSchool){
    name = newName;
    id = newID;
    school = newSchool;
} 


// ----------------- Menu-Deiven func -----------------------


void printMenu(){

    char cmd;

    while (1){

        printf("\n*********** MENU ****************\nI : Insert new element into queue.\nD : Delete element with smallest key from queue.\nC : Decrease key of element in queue.\nP : Print out all elements in queue. \nQ : Quit\n\nChoose menu : ");
        cin >> cmd;
        getchar(); //remvoe enter from buffer

        switch (cmd){
        case 'I':
            insertQueue();
            break;
        case 'D':
            deleteQueue();
            break;
        case 'C':
            decreaseQueue();
            break;
        case 'P':
            PrintQueue();
            break;
        case 'Q':
            printf("Thank you. Bye!\n\n");
            return;
        default:
            printf("[notice] wrong command\n\n");
        }
    }
}

int insertQueue(){
    string name, shcool, inputID;
    int id;

    printf("Enter name of element: ");
    cin >> name;
    getchar();

    do{
       printf("Enter id of element: ");
       getline(cin, inputID);

    }while(!(id = idCheck(inputID)));
    
    printf("Enter shcool of element: ");
    cin >> shcool;

    element tmp;
    tmp.name = name;
    tmp.id = id;
    tmp.school = shcool;
    
    INSERT(pq.h, tmp);
    
    cout << "[" <<tmp.name << ", " << tmp.id << ", " << tmp.school << "] is inserted.\n\n";
    getchar(); //remove enter from buffer

}

int deleteQueue(){

    element tmp = EXTRACT_MIN(pq.h);
    cout << "[" <<tmp.name << ", " << tmp.id << ", " << tmp.school << "] is deleted.\n\n";

}

int decreaseQueue(){
    int index, id;
    string inputID;

    do{
       printf("Enter index of element: ");
       cin >> index;
       if(index <= pq.csize && index != 0) break;
       printf("[notice] wrong index\n");
    }while(1);

    getchar(); //remove enter from buffer

    do{
       printf("Enter id value: ");
       getline(cin, inputID);
    }while(!(id = idCheck(inputID)));

    DECREASE_KEY(pq.h, index , id); 
    
}

int PrintQueue(){
    pq.printAll();
    printf("\n");
} 

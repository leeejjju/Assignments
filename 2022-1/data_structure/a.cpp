#include <iostream>
using namespace std;
//#define JUMGUM printf("%d단계 점검\n", jum++);
#define JUMGUM jum++;


class node{

    public:
    //data
    string name; 
    double score;
    //link
    node* link;

    void set_data(string newName, double newScore){
        name = newName;
        score = newScore;
    }
};


class my_list{

    node* head; //첫 원소를 가리킬 node 포인터 타입
    node* tail; //마지막 원소를 가리킬 node 포인터 타입
    
    public:
    my_list(); //생성자, construnctor
    void add_to_head(node x); //head에 node 추가
    void add_to_tail(node x); //tail에 node 추가
    node delete_from_head(); //head에서 node 지우고 삭제된놈 반환   

    int num_nodes(); //현재 node의 갯수
    double score_sum(); //현재 node들의 점수의 합
    double get_score(string name); //입력된 name의 node의 점수 반환
    int remove_a_node(string name); //입력된 name의 node 삭제 

};



int main(){

   my_list a; //linked list 선언 
   node   tmp; //수행을 위한 node변수 
    int jum = 1;

    // head 위치로 2개의 원소 추가
    tmp.set_data("Kim", 83.5);
    a.add_to_head(tmp);
    tmp.set_data("Lee", 78.2);
    a.add_to_head(tmp);           

    cout << a.num_nodes() << " : " << a.score_sum() << "\n";  // 1단계 점검
    JUMGUM

    // tail 위치로 1개의 원소 추가
    tmp.set_data("Park", 91.3);   
    a.add_to_tail(tmp);

    cout << a.num_nodes() << " : " << a.score_sum() << "\n";  //2단계 점검
    JUMGUM

    // head 위치에서 원소 하나 삭제 
    tmp = a.delete_from_head();
    cout  << tmp.name << " is deleted.\n";   // 3단계 점검
    JUMGUM

    // tail과 head에 원소 하나씩 추가 
    tmp.set_data("Choi", 85.1);   
    a.add_to_tail(tmp);              
    tmp.set_data("Ryu", 94.3);   
    a.add_to_head(tmp);            

    cout << a.num_nodes()<< " : " << a.score_sum() << "\n"; // 4단계 점검
    cout << "Park’s score : " << a.get_score("Park")<< "\n";  
    JUMGUM

    if ( a.remove_a_node("Kim") == 1) cout << "Kim is deleted from the list. \n";     // 5단계 점검
    JUMGUM

    cout << a.num_nodes()<< " : " << a.score_sum() << "\n";  // 최종 점검       
    JUMGUM

    return 0;
  }


// ----------------------------------------------------------------------------

    //생성자, construnctor
    my_list:: my_list(){
        head = NULL;
        tail = NULL;

    } 

    //head에 node 추가
    void my_list:: add_to_head(node x){
        //1. 새 node공간 만들어서 2. 인자로 받은 데이터를 담아주고 3. 연결작업(첫 원소면 tail도)

        node* t = new node(); //공간 확보하고 데이터 이동 
        *t = x;

        t->link = head; //head가 가리키던 놈을 얘가 가리키게 바꿔주고
        head = t; //head는 얘를 가리키도록 

        if(tail == NULL) tail = t; //얘가 처음 들어온 친구라면 tail도 얘를 가리키도록 

    }

    //tail에 node 추가
    void my_list:: add_to_tail(node x){
        node* t = new node(); //공간 확보하고 데이터 이동
        *t = x;

        t->link = NULL; //연결작업. 마지막 원소이니 링크는 null과 연결해주고
        tail->link = t; //원래의 마지막놈이 얘를 가리키도록 조정하고
        tail = t; //tail도 얘를 가리키도록 

        if(head == NULL) head = t; //첫 원소라면 head도 얘를 가리키도록 

    }

    //head에서 node 지우고 삭제된놈 반환   
    node my_list:: delete_from_head(){
        node* t; //임시로 머시깽이 하기 위한 공간. 반환해야하고... 그러니까... 
        node temp; //공간 해제한 후에도 데이터 반환해야하니까 임시변수 

        t = head; //head가 가리키던놈을 t도 가리키게(어디를 free시킬지 알아야하니까)
        temp = *t; //해당 데이터도 복사해두고(리턴용)

        head = head->link; //head는 두번째 node(기존 head node가 link로 가리키던 그곳)를 가리키도록 조정
        delete(t); //이제 안쓰는 그곳 메모리 반환 

        return temp; //아까 복사해둔 data 반환 
    }

    //현재 node의 갯수
    int my_list:: num_nodes(){
        node* t; //i 역할. 반복문에 사용될 포인터 변수 
        int count = 0; //숫자셀거임! 

        for(t = head; t != NULL; t = t->link){ //head부터, link를 타고 이동하며, NULL을 만나기 이전까지 반복 
            count ++;
        }

        return count;

    }

    //현재 node들의 점수의 합
    double my_list:: score_sum(){
        node* t; //i 역할. 반복문에 사용될 포인터 변수 
        double sum = 0; //점수 누적할거임  

        for(t = head; t != NULL; t = t->link){ //head부터, link를 타고 이동하며, NULL을 만나기 이전까지 반복 
            sum += t->score;
        }

        return sum;

    }

    //입력된 name의 node의 점수 반환
    double my_list:: get_score(string name){

        

        node* t; //i 역할. 반복문에 사용될 포인터 변수 

        for(t = head; (t->name) != name; t = t->link){
          
        } //head부터, link를 타고 이동하며, name을 만나면 break

        return (t->score); //현시점(break된,)의 t의 score를 반환 

    }

    //입력된 name의 node 삭제, 삭제 성공했으면 1, 실패했으면 0 반환 
    int my_list:: remove_a_node(string name){

        node* t; //반복문용
        node* pre; //삭제할 그 친구의 직전 node를 알기 위한 변수 

        for(t = head; (t->name != name)&&(t != NULL); t = t->link){ //head부터, link를 타고 이동하며, name을 만나기 직전까지(name이 없다면 NULL 직전까지) 이하를 반복하며 만나고 break
            pre = t;
        }

        //break되고 여기까지 왔을 때, 성공적으로 name을 찾지 못했다면 t == NULL일 것임. 이때의 처리
        if(t == NULL){
            printf("cannot fint the name\n");
            return 0;
        }else{ //잘 찾으면? 현재 t는 name과 일치한 해당 node를, pre는 그 직전 node를 담고 있음을 유념하며
            pre->link = t->link; //node들이 끊어지지 않도록 직전 친구가 가리키던 주소를 t가 가리키던 주소와 연결 
            delete(t); //연결들 다 끊어졌으니 삭제~
            if(head == NULL) tail = NULL; //혹시 걔가 헤드였다면... 그래서 head가 비어버렸다면 tail도 비우기 
            return 1;
        }


    }
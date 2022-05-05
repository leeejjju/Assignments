#include <iostream>
using namespace std;
#define HSIZE 50

//데이타구조 Programming Assignment 11 
//22100579 이진주
/*

Heap 구현 예제: 
{성명, 점수}의 원소를 저장하는 heap 구현, 점수를 Key 값으로 고려
다음 main 함수의 의도에 따라 동작하는 프로그램을 완성하시오. 

<예상 출력 > //sorting된 순서대로 출력 
Park : 98
Ryu : 94
Kim : 88
Cho : 85
Lee : 77
Choi : 74
*/

class element{

    public:
    //data
    string name;
    double score; //key..?

    //method
    void set_data(string newName, int newScore); //노드의 데이타 설정 

};

class my_heap{
    element h[HSIZE]; //link list형식이 아닌 array형식..!이므로 root 포인터 이런거 필요 없나봄 와우
    int csize; //number of nodes

    public:
    my_heap(); //constuctor
    void insert_heap(element newNode); //적절한 위치로 node 삽입 
    int h_size(); //현재시점의 node갯수 반환 
    element delete_heap(); //최고값의..? node 삭제하고 반환 
    bool isFull();
    bool isEmpty();
    void swap(element* a, element* b); //둘이 자리바꾸는거 메서드로 처리하면 편하지 않으까? 아님말구 
};





int main(){

   my_heap   h1; //heap 선언
   element   temp; //임시저장용 노드 선언 

    //노드 데이터들을 heap에 넣기 
   temp.set_data("Kim", 88);
   h1.insert_heap(temp);

   temp.set_data("Lee", 77);
   h1.insert_heap(temp);

   temp.set_data("Park", 98);
   h1.insert_heap(temp);

   temp.set_data("Choi", 74);
   h1.insert_heap(temp);

   temp.set_data("Ryu", 94);
   h1.insert_heap(temp);

   temp.set_data("Cho", 85);
   h1.insert_heap(temp);

   while (h1.h_size() > 0) { //heap에 있는 node 정보들을 순차적으로 출력 
        temp = h1.delete_heap();
        cout << temp.name << " : " << temp.score << "\n";
   }

   return 0;

}



//constuctor
my_heap:: my_heap(){
    csize = 0;
} 

//적절한 위치로 node 삽입 
void my_heap:: insert_heap(element newNode){

    //cout << "new node added\n";

    if(isFull()){
        cout << "heap is full :(\n";
        return;
    }

    //일단 제일 끝 노드에 넣어주고, 이때 k는 csize
    int k = csize+1; //1번 인덱스부터 시작하고싶으니까 이래 처리하면 되려나? 본인 인덱스임 
    h[k] = newNode;
    csize ++; 

    //아니면... 끝없는 배틀이 시작된다... 부모한테 계속 도전장 내밀거임 (k번과 k/2번의 웅장한 싸움)
    while(1){
        if(k == 1) return; //루트까지 가면 걍 탈출 
        //본인이 더 크다? 부모랑 스왑합니당 k값도 조정해주고
        if(h[k].score > h[k/2].score){
            swap(&(h[k]), &(h[k/2]));
            k = k/2;
        }else return; //부모가 더 크다? 그자리에 만족하고 리턴. 
    }

} 

//현재시점의 node갯수 반환 
int my_heap:: h_size(){
    //cout << csize <<endl;
    return csize;
} 

//최고값의..? node 삭제하고 반환 
element my_heap:: delete_heap(){

    //cout << "node deleted\n";

    if(isEmpty()){
        cout << "heap is empty :(\n";
        element dumy;
        dumy.set_data("NONE", 0);
        return dumy;
    }


    //리턴용으로 root노드를 어따 보관하고
    element tmp = h[1];
    //삭제될 그곳의 친구를 root로 이동시키고
    h[1] = h[csize];
    //아래의 끝없는 도전을 받아들이기...
    int k = 1; //루트부터 제자리 찾아 내려가는 여정, #가보자고 
    int c; //챌린저...! 
    csize --; 

    while(1){
        
        //일단 (자식이 둘이면)자식들끼리 예선전을 벌여서 이긴놈만이 도전의 자격을 가짐
        if(k*2+1 < csize) c = (h[k*2].score > h[k*2+1].score)? (k*2): (k*2+1);
        //자식 하나 있으면 그놈을 도전자로 지정 
        else if(k*2 < csize) c = k*2;
        //더 도전할 자식 없으믄 그자리에 땅땅땅
        else return tmp;  
        
        //도전자 선정을 마쳤다면 비교ㄱㄱ, 본인이 작다? 스왑
        if(h[k].score < h[c].score) swap(&(h[k]), &(h[c]));
        //본인이 크다? 그자리가 천직인거임. 리턴.
        else return tmp;

    }
    return tmp;

} 

bool my_heap:: isFull(){
    if(csize >= HSIZE-1 ) return true;
    return false;
}

bool my_heap:: isEmpty(){
    if(csize == 0) return true;
    return false;
}


//둘이 자리바꾸는거 메서드로 처리하면 편하지 않으까? 아님말구 
void my_heap:: swap(element* a, element* b){

    element tmp = *a;
    *a = *b;
    *b = tmp;

} 


//노드의 데이타 설정 
void element:: set_data(string newName, int newScore){
    name = newName;
    score = newScore;
} 


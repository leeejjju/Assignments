#include <iostream>
#include <string>
using namespace std;

//데이타구조 HW04
//22100579 이진주
/*Infix expression을 Postfix expression으로 변환하는 프로그램을 작성하시오.
test case 예)
입력 :  a * (b + c)
출력 :  a b c + **/


class stack{ //DIY 스택스택... 
    private:
    char s[50]; //대충 50칸짜리 스택 공간
    int x; //가장 최근 들어간 녀석의 인덱스 


    public :
    void init(); //초기화
    void push(int a); //원소 밀어넣기
    char pop(); //원소 하나빼기
    char show(); //최상위 원소 하나 보여주기
    bool isEmpty(); //비었나 체크
    bool isFull(); //꽉찼나 체크

} s1 ;


int main(void){


    return 0;
}
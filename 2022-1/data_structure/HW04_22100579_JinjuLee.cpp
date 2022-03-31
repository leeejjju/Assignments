#include <iostream>
#include <string>
using namespace std;

//데이타구조 HW04
//22100579 이진주
/*Infix expression을 Postfix expression으로 변환하는 프로그램을 작성하시오.
test case 예)
입력 :  a * (b + c)
출력 :  a b c + **/


//선언
class mystack{
    private:
    char s[100]; //대충 백칸짜리 스택 공간 확보
    int top; //다음에 >>들어와야 할<< 공간의 인덱스!! 

    public:
    void init(); //초기화
    void push(int a); //하나 밀어넣기
    int pop(); //하나 빼내기
    int show(); //가장 최근에 들어간 놈을 (제거하지 않고)반환. 확인용. 
    bool stack_empty(); //비어있는지 체크
    bool stack_full(); //꽉차있는지 체크 
};

int calcPriority(char x); //오퍼레이터나 하여튼 이것저것 받아서 우선순위 반환 

int main(){

    mystack  s1; //스택 하나 만들고 
    int i; //반복문에 사용할 변수
    s1.init(); //스택 초기화
    s1.push('$');//하나 넣어두기 

    string myFormula; //수식 입력받을 공간 
    char x; //한놈씩 담을 머시기 

    //cout << "Enter your formula! >>";
    //cin >> myFormula;
    myFormula = "a+b*c"; //&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&임시로 지정해두겠음 테스트용 

    for (i = 0; i < 5; i++ ){ //스택에 수식 한자한자씩... 

    //cout << "수식 점검중... " << myFormula[i] << "\n";
      
      
        if(myFormula[i] == '('){
            s1.push( myFormula[i]); //여는괄호는 스택에 넣기 
        }else if(myFormula[i] == ')'){
            while(1){
                if (s1.show() == '(') { //여는괄호 나오면 
                    s1.pop(); //그놈 버리고
                    break; //루프 끗.
                }else {
                    cout << s1.pop(); //꺼내서 출력 
                }
            }
        }else if(myFormula[i] >= 'a' && myFormula[i] <= 'z'){
            cout << myFormula[i]; //피연산자는 그대로 출력
        }else{ //연산자는? 
            while(1){
                if(calcPriority(s1.show()) >= calcPriority(myFormula[i])){//최상위원소 우선순위가 본인보다 높은 한 
                    cout << s1.pop(); //꺼내서 출력 
                }else{//낮아지면?
                  cout << myFormula[i] << "는 스택에 들어갑니당\n";
                    s1.push(myFormula[i]); //스택에 넣고
                    break; //루프 종료 
                }
            }
        }
    }

    while (s1.show() != '$'){ //스택에 남은놈들을 하나씩 빼냄
      //cout << "여기까지오긴했니\n";
        x = s1.pop(); //변수 x에 한놈 담아서
        cout << x << endl ; //출력
    }

    return 0;

}




void mystack:: init(){
    top = 0;

} //초기화

void mystack:: push(int a){
    if(!stack_full()){ //꽉차있지 않다면 
        s[top] = a; //현재 대기중인 공간에 인자로 받은 원소 밀어넣기 
        top++; //대기인덱스 한칸 위로 
    }else{
        cout<<"stack is full :(\n"; //꽉찼서ㅠㅠ
    }

} //하나 밀어넣기

int mystack:: pop(){
    if(!stack_empty()){ //비어있지 않다면 
        top--; //대기인덱스 한칸 뒤로 물려서 젤 최근에 들어온놈을 가리키게 하고 
        return s[top]; //그놈 뱉기
    }else{
        cout<<"stack is empty :(\n"; //비엇서ㅠㅠ
    }

} //하나 뾱하고 빼기

int mystack:: show(){
    return s[top];

}//가장 최근의 놈 (제거하지 않고) 반환해서 알려주기


bool mystack:: stack_empty(){
    if(top == 0) return true;
    return false;
} //비어있는지 체크

bool mystack:: stack_full(){
    if(top == 100) return true;
    return false;
} //꽉차있는지 체크 

int calcPriority(char x){

    if(x == '+' || x == '-'){
        return 1;
    }else if(x == ')' || x == '$'){
        return 0;
    }else{
        return 2;
    }

} //오퍼레이터나 하여튼 이것저것 받아서 우선순위 반환 

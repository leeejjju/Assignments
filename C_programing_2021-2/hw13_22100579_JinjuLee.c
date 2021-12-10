// c프로그래밍 과제13
/*아래 표의 형식으로 저장되는 데이터에 대하여 (성명/학번/학년/중간고사/기말고사) 
다음 기능을 지원하는 프로그램을 menudriven 방식으로 작성하시오. 

<메뉴구성>
원하는 명령을 선택하시오.

	1. 데이터 추가
	2. 데이터 삭제
	3. 전체 현황 보기
	4. 데이터 조회
	5. 종료
	
	명령 선택:_
	
 <기능 설명>
1. 데이터 추가 : 한 학생에 대한 정보를 추가하는 과정, 초기 empty list에서 시작, 총
100명까지의 항목을 저장할 수 있도록 구현
2. 데이터 삭제 : 삭제를 원하는 학생을 지정(학번으로 지정)하여 목록에서 삭제, 해당
학번의 내용이 없으면 실패 처리(메시지 출력)
3. 전체 현황 보기 : 전체 목록 출력 및 요약 정보(총인원, 중간고사 평균, 기말고사 평균
등 출력), empty list이면 ‘현재 데이터 없음’ 메시지 출력
4. 데이터 조회 : 지정(학번으로)한 학생의 데이터 내용을 출력, 해당 학번의 내용이 없
으면 실패 처리(메시지 출력)
5. 종료 : 프로그램을 종료함
기타 추가 기능 및 인터페이스 설계는 자유롭게 창의적으로 작성할 것 */

//1. 학생정보 구조체 만들기... 
//2. 구조체를 원소로 갖는 배열..?
#include <stdio.h>
#include <string.h>

struct student{
	char name[20]; //이름  
	char number[10]; //학번 8자리 
	int grade; //학년(1,2,3,4) 
	float midJumsu; //중간고사 성적 
	float finJumsu; //기말고사 성적  
}list[100]; //100명까지 저장 가능한 리스트  

void addStudentData();
void removeStudentData(char num[]);
void printStudentData();
void searchStudentData(char num[]);

int count = 0; //현재까지 저장된 유효한 학생 수. 모든 함수에서 접근 가능하도록 글로벌로 선언.  
int i; //반복문에 사용될 변수. 모든 함수에서 접근 가능하도록 글로벌로 선언.   

int main(void){
	int command; //사용자에게 입력받아 해당 명령을 실행시킬 변수  
	char number[10]; //사용자에게 입력받아 필요한 함수에 파라미터로 전달될 학번 문자열  

	
	
	while(1){
		
		
		//인터페이스 출력  
		printf("\n\n- - - - - - - - - - - - - - - - - - - -\n");
		printf("\n원하는 명령을 선택하시오.\n\n");
		printf("	1. 데이터 추가\n	2. 데이터 삭제\n	3. 전체 현황 보기\n	4. 데이터 조회\n	5. 종료\n\n");
		printf("			명령 선택:");
		scanf("%d", &command);
		
		//유저에게 입력받은 커멘드에 따라 이하의 내용 실행  	
		if(command == 1){
			printf("\n데이터 추가를 시작합니다...\n\n");
			addStudentData();
			
		}else if(command == 2){
			printf("\n데이터 제거를 시작합니다...\n\n");
			printf("제거할 데이터의 학번을 입력해주세요:");
			scanf("%s", number);
			removeStudentData(number);
			
		}else if(command == 3){
			printf("\n전체 현황을 출력합니다...\n\n");
			printStudentData();
			
		}else if(command == 4){
			printf("\n데이터 조회를 시작합니다...\n\n");
			printf("조회할 데이터의 학번을 입력해주세요:");
			scanf("%s", number);
			searchStudentData(number);
			
		}else if(command == 5){
			printf("\n프로그램을 종료합니다...");
			break;
		}else{
			printf("올바른 명령어를 입력해주세요(1~5)");
		}
		
	} 
	
	printf("\n이용해주셔서 감사합니다 :-)"); 
	return 0;
} 

//함수 1. 데이터 추가
void addStudentData(){
	
	printf("%d번째 학생 정보를 추가합니다. \n\n", count+1);
	
	printf("학생 이름을 입력하세요:");
	scanf("%s", &list[count].name); 
	printf("학번을 입력하세요:");
	scanf("%s", &list[count].number); 
	printf("학년을 입력하세요:");
	scanf("%d", &list[count].grade); 
	printf("중간고사 성적을 입력하세요:");
	scanf("%f", &list[count].midJumsu); 
	printf("기말고사 성적을 입력하세요:");
	scanf("%f", &list[count].finJumsu); 
	
	count ++; //방금 한명 입력받았으니 학생수 증가  
	
	
}
	//한 학생에 대한 정보를 추가
	//총 100명까지 저장 가능하도록 구현 



//함수 2. 데이터 삭제
void removeStudentData(char num[]){
	int index = -1; //중복 인덱스를 찾지 못했을 떄를 판별할 초기값 설정  
	
	for(i = 0; i < count; i++){//리스트를 쭉 훑으며 일치하는 학번의 순번?  찾아 인덱스에 저장  
		if(strcmp(num, list[i].number) == 0){
			index = i;
			break;
		} 	
	}
	
	if(index == -1){ //중복 하나도 못찾고 여기까지 왔으면...(초기값에서 값 변화가 없다면) 
		printf("\n입력하신 학번의 학생이 데이터에 없습니다.\n");
		return;
		
	}else{
		for(i = index; i < count; i++){ //인덱스부분이 덮어지게 한칸씩 앞으로 땡기기... !
			strcpy(list[i].name, list[i+1].name);
			strcpy(list[i].number, list[i+1].number);
			list[i].grade = list[i+1].grade;
			list[i].midJumsu = list[i+1].midJumsu;
			list[i].finJumsu = list[i+1].finJumsu;			
		} 
		
		count --;//인제 한명 없어졌다는 뜻. 다음 입력은 중복으로 남은 마지막의 그놈을 덮으며 입력될 것임.  
		printf("\n성공적으로 제거했습니다.\n");
				
	}
	
}
	//학번으로 지정한 학생의 데이터를 목록에서 삭제. 
	//해당 학번의 내용이 없으면 실패처리(메세지 출력) 


//함수 3. 전체 현황 보기
void printStudentData(){
	float sumMid = 0, sumFin = 0; //중간기말 점수를 누적하여 더할 공간. 평균구하기용.  
	
	if(count == 0){
		printf("현재 데이터 없음\n");
		return;
	}

	//1. 전체 목록 출력하며 평균계산 위한 누적값 쌓기 
	printf("\n\n성명 / 학번 / 학년 / 중간고사 / 기말고사\n");
	for(i = 0; i < count; i++){
		printf("%s / %s / %d / %.2f / %.2f\n", list[i].name, list[i].number, list[i].grade, list[i].midJumsu, list[i].finJumsu);
		sumMid += list[i].midJumsu;
		sumFin += list[i].finJumsu;
		
	}
	//2. 요약정보 계산 마무리하여 출력 
	printf("\n총 인원은 %d명입니다.\n", count);
	printf("중간고사 평균 성적은 %.2f점, 기말고사 평균 성적은 %.2f점입니다.\n", sumMid/count, sumFin/count); 
	
	
	
}
	//전체 목록 출력 및 요약정보(총인원, 중간고사 평균, 기말고사 평균)출력.
	//빈 리스트면 '현재 데이터 없음' 메세지 출력  


//함수 4. 데이터 조회
void searchStudentData(char num[]){
	int index = -1; //중복 인덱스를 찾지 못했을 떄를 판별할 초기값 설정 
	
	for(i = 0; i < count; i++){//리스트를 쭉 훑으며 일치하는 학번의 순번?  찾아 인덱스에 저장  
		if(strcmp(num, list[i].number) == 0){
			index = i;
			break;
		} 	
	}
	
	if(index == -1){  //중복 하나도 못찾고 여기까지 왔으면...(초기값에서 값 변화가 없다면) 
		printf("\n입력하신 학번의 학생이 데이터에 없습니다.\n");
		return;
		
	}else{ //해당 인덱스의 구조체 정보 출력  
		printf("검색 결과:\n");
		printf("%s / %s / %d / %.2f / %.2f\n", list[index].name, list[index].number, list[index].grade, list[index].midJumsu, list[index].finJumsu);
	}	
	
}
	//학번으로 지정한 학생의 데이터 내용을 출력
	//해당 학번 내용이 없으면 실패 처리(메세지 출력) 

// 학번 : 22100579
// 이름 : 이진주
//나 이진주는 하나님과 사람 앞에서 이번 코딩 테스트를 정직하게 수행하고 있습니다.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char kname[2][10] = {"Grade", "P/F"}; // 평가방식 표현 문자열
// 이미 구현된 함수
int loadData(char names[50][30], int units[50], int kinds[50]); // 파일에서 과목 목록을 읽어온다.
void printAllClasses(char names[50][30], int units[50], int kinds[50], int size); // 전체 과목 목록을 출력한다.


// 구현해야 하는 함수
void selectMy5Classes(int my[5], int range); // 내 수강과목 5개 랜덤 등록하기
void printMyClasses(int my[5], char names[50][30], int units[50], int kinds[50]); // 내 수강과목 출력하기
void saveReport(int my[5], char myg[5][10], char names[50][30], int units[50], int kinds[50]); // 성적표 파일을 만들어 저장한다.


// 추가로 만든 함수가 있으면 여기에 넣을 것!
float getPoint(char g[10]);

int main(void) {

	int no;	// 작업번호 
	char cnames[50][30]; // 전체 과목이름 (최대 10개)
	int kinds[50]; // 전체 과목별 평가유형 (최대 10개, 1:Grade, 2:P/F)
	int units[50]={0}; // 전체 과목별 학점 수

	int myclass[5]; // 내 수강과목 목록 (최대 5과목)
	char mygrades[5][10]; // 내 수강과목별 취득 학점 (A+,A0,B+,B0,C+,C0,D+,D0,F,P)
	int myscores[5]; // 내 평점 평균

  //------------------------------------------------------------

	srand(time(0));
  
	int count = loadData(cnames, units, kinds);
	printf("%d개의 수강과목 정보를 읽었습니다.\n", count);
	printAllClasses(cnames, units, kinds, count);

	while(1){

		printf("\n[작업] 1.수강과목등록 2.학점입력 3.과목성적검색 4.성적표저장 0.종료\n");
		printf("작업 번호는? > ");
		scanf("%d", &no);

		if(no == 1){ 
			printf("1.수강과목등록\n");
			selectMy5Classes(myclass, count);
			printf("5개의 과목을 수강등록하였습니다.\n");
			printMyClasses(myclass, cnames, units, kinds);
		}
		else if(no == 2){
			printf("2.학점입력\n");
			for(int i=0; i<5; i++){
				int classno = myclass[i];
				printf("%d. %s [%d학점 - %s] ", i+1, cnames[classno], units[classno], kname[kinds[classno]-1]);
				if(kinds[classno]==1){
					printf("성적은? (A+,A0,B+,B0,C+,C0,D+,D0,F) > ");
					scanf("%s", mygrades[i]);
				}
				else{
					printf("성적은? (P,F) > ");
					scanf("%s", mygrades[i]);
				}
			}
		}
		else if(no == 3){
			printf("3.과목성적검색\n");
			printf("검색할 과목 이름은? > ");
			char str[30];
			scanf("%s", str);
			int count=0;
			for(int i=0; i<5; i++){
				int classno = myclass[i];
				if(strstr(cnames[classno], str)){
					printf("%s [%d학점] 성적 : %s\n", cnames[classno], units[classno], mygrades[i]);
					count++;
				}
			}
			printf("%d개 과목을 찾았습니다.\n", count);
		}
		else if(no == 4){
			printf("4.성적표저장\n");
			saveReport(myclass, mygrades,cnames, units, kinds);
			printf("\nreport.txt에 성적표를 저장했습니다.\n");
		}
    else break;
	}
	return 0;
}

//------------------------------------------------------------

int loadData(char names[50][30], int units[50], int kinds[50]){
	int count = 0;
	FILE* file;

	file=fopen("classes.txt", "r");
	while(!feof(file)){
		int r = fscanf(file, "%s %d %d", names[count], &units[count], &kinds[count]);
		if(r < 3) break;
		count++;
	}
	fclose(file);
	return count;
}

//------------------------------------------------------------

void printAllClasses(char names[50][30], int units[50], int kinds[50], int size){
	printf("전체 과목\n");
	for(int i=0; i<size; i++){
		printf("%d. %s [%d학점 - %s]\n",i+1, names[i], units[i], kname[kinds[i]-1]);
	}
}

/////////// 아래 함수는 직접 구현할 것! ////////////////

//내 수강과목 출력하기
void printMyClasses(int my[5], char names[50][30], int units[50], int kinds[50]){
  //0. 내 수강과목\n'' 출력 
  printf("내 수강과목\n");
  //1. 이하를 다섯번 반복...
  for(int i = 0; i < 5; i++){
    //1-1 (순서번호). (과목이름) [(학점수)학점 - (평가방식)]\n)
    printf("%d. %s [%d학점 - %s]\n", i+1, names[my[i]], units[my[i]], kname[kinds[my[i]]-1]);
  }
}
/*ex) 5개의 수강과목을 수강등록하였습니다.
내 수강과목
1. 과목이름 [n학점 - 평가방식]


}
//파라미터 : 내 수강과목번호배열, 전체과목이름배열, 전체과목학점수배열, 전체과목평가방식배열
//리턴값 : 없음
//하는 일 : 전체과목의 정보가 들어있는 배열 3개를 참조해서 내가 수강하는 5개 과목 정보를 출력한다.

/*
0. 내 수강과목\n'' 출력 
1. 이하를 다섯번 반복...
  1-1 (순서번호). (과목이름) [(학점수)학점 - (평가방식)]\n)
*/

/*ex) 5개의 수강과목을 수강등록하였습니다.
내 수강과목
1. 과목이름 [n학점 - 평가방식]
... */

//------------------------------------------------------------

//내 수강과목 5개 랜덤 등록하기
void selectMy5Classes(int my[5], int range){

  //0. count = 0, joong = 0;
  int count = 0, joong = 0; 
  //1. 이하를 무한반복... 
  while(1){
    //1-1 my배열에 rand함수를 사용해서 (특정 범위지정) 값을 하나 입력받습니다.
    my[count] = rand()%(range);
    //1-2 방금 입력받은 값이 역대 값들과 중복되는지를 체크(for))
    for(int i; i < count; i++){
      if(count != 0 && my[i] == my[count]){
        joong = 1;
        break;
      }
      //1-2-1 중복되면 joong = 1, break;
    }
    //1-3  만약 중복된 상태면(joong = 1) >> joong = 0;
    if(!joong){
      count++;
      joong = 0;

    }
      //1-3-2 중복이 아니면 joong=0 >> count++
    
    //1-4 카운트가 5 이상이면 return; 
    if(count >= 5) break;
  }
}
//파라미터 : 내 수강과목의 번호 5개를 저장할 배열, 전체 과목의 갯수
//리턴값 : 없음
//하는 일 : 전체 과목의 갯수에 따른 과목번호(0~갯수-1) 중에 중복되지 않는 5개의 번호를 임의로 골라서 my 배열에 넣는다.
/*
0. count = 0, joong = 0;
1. 이하를 무한반복... 
  1-1 my배열에 rand함수를 사용해서 (특정 범위지정) 값을 하나 입력받습니다.
  1-2 방금 입력받은 값이 역대 값들과 중복되는지를 체크(for))
    1-2-1 중복되면 joong = 1, break;
  1-3  만약 중복된 상태면(joong = 1) >> joong = 0;
    1-3-2 중복이 아니면 joong=0 >> count++
  
  1-4 카운트가 5 이상이면 return; 

*/

//------------------------------------------------------------

void saveReport(int my[5], char myg[5][10], char names[50][30], int units[50], int kinds[50]){

  //0. 전체학점 정수=0, 얻은학점 정수 =0, 그레이드학점 = 0, float 총점계산용 sum = 0, ave 
  int apoint = 0, point = 0, gpoint = 0;
  float sum = 0, ave;

  //1. 파일 핸들러 선언, 파일 쓰기모드로 열기
  FILE* file;
  file = fopen("report.txt", "w");

  //2. 파일에 내용 프린트
    //2-1 "성적표\n"
    fprintf(file, "성적표\n");

    //2-2 이하 5번 반복...
    for(int i = 0; i < 5; i++){
      //2-2-1 "(순서). (과목이름) [(학점수)학점 - (평가방식)] - (성적)"
      fprintf(file, "%d. %s [%d학점 - %s] - %s\n", i+1, names[my[i]], units[my[i]], kname[kinds[my[i]]-1], myg[i]);
      //2-2-2 전체학점 += (학점수)
      apoint += units[my[i]];
      //2-2-3 (myg 가 F가 아니라면 )얻은학점 +=(학점수)
      if(strcmp(myg[i], "F")){
        point += units[my[i]];
      }
      //2-2-4 (그레이드라면 )
      if(kinds[my[i]] == 1){
        //2-2-4-1 sum+= (등급에 따른)과목 점수 * (학점수)
        if(!strcmp(myg[i], "A+")){
          sum = sum + (4.5*units[my[i]]);
        }else if(!strcmp(myg[i], "A0")){
          sum = sum + (4.0*units[my[i]]);
        }else if(!strcmp(myg[i], "B+")){
          sum = sum + (3.5*units[my[i]]);
        }else if(!strcmp(myg[i], "B0")){
          sum = sum + (3.0*units[my[i]]);
        }else if(!strcmp(myg[i], "C+")){
          sum = sum + (2.5*units[my[i]]);
        }else if(!strcmp(myg[i], "C0")){
          sum = sum + (2.0*units[my[i]]);
        }else if(!strcmp(myg[i], "D+")){
          sum = sum +(1.5*units[my[i]]);
        }else if(!strcmp(myg[i], "D0")){
          sum = sum + (1.0*units[my[i]]);
        }
        //2-2-4-2 그레이드학점 += (학점수)
        gpoint += units[my[i]];
      }
    }

    //2-3 "취득 학점 : n / n"
    fprintf(file, "취득 학점 : %d / %d\n", point, apoint);
    //2-4 (ave값 입력) "평점 평균 : .2f" 
    if(gpoint == 0){
      ave = 0.0;
      //printf("평점평균빵점임!!");
    }else{
      ave = sum/gpoint;
      //printf("%d, %f", gpoint, sum);
    }
    fprintf(file, "평점 평균 : %.2f\n", ave);
  //3. 파일 닫기 
  fclose(file);
}
//파라미터 : 내수강과목번호배열, 내수강과목평점배열, 전체과목이름배열, 전체과목학점수배열, 전체과목평가방식배열
//리턴값 : 없음
//하는 일 : 전체과목의 정보가 들어있는 배열 3개를 참조해서 내가 수강하는 5개 과목의 번호, 평점을 사용하여 성적표를 만들어 report.txt 파일로 저장한다.

/*
0. 전체학점 정수=0, 얻은학점 정수 =0, 그레이드학점 = 0, float 총점계산용 sum = 0, ave 
1. 파일 핸들러 선언, 파일 쓰기모드로 열기
2. 파일에 내용 프린트
  2-1 "성적표\n"
  2-2 이하 5번 반복...
    2-2-1 "(순서). (과목이름) [(학점수)학점 - (평가방식)] - (성적)"
    2-2-2 전체학점 += (학점수)
    2-2-3 (myg 가 F가 아니라면 )얻은학점 +=(학점수)
    2-2-4 (그레이드라면 )
      2-2-4-1 sum+= (등급에 따른)과목 점수 * (학점수)
      2-2-4-2 그레이드학점 += (학점수)

  2-3 "취득 학점 : n / n"
  2-4 (ave값 입력) "평점 평균 : .2f" 
3. 파일 닫기  

*/

/*1. P/F 과목은 평점평균을 계산할 때 고려하지 않아도 됩니다. 
2. 그레이드 과목은 각 과목의 학점과 성적을 곱해서 다 더한 후 총 그레이드 학점으로 나눠 주시면 됩니다.

예시)
과목 1 (3학점)- Grade : A+
과목 2 (2학점)- P/F : P
과목 3 (3학점)- Grade : A
과목 4 (1학점)- Grade : F
과목 5 (2학점)- P/F : F
평점 평균 = (4.5 * 3 + 4.0 * 3 + 1.0 * 0) / (3+3+1) = 3.64
*/

/*ex) 성적표
1. 과목이름 [n학점 - 평가방식] - 성적 
...

취득 학점 : n / n
평점 평균 : .2f */

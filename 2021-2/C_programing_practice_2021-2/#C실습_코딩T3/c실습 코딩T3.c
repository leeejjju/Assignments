// 학번 : 22100579
// 이름 : 이진주
// 나 이진주는 하나님과 사람 앞에서 이번 코딩 테스트를 정직하게 수행하고 있습니다

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct st_class{
	int code;		// 과목코드
	char name[30]; 	// 과목이름
	int unit;		// 학점수
	int grading;	// 평가방식 (1:grade, 2:pass/fail)
};

char kname[2][10] = {"Grade", "P/F"}; // 평가방식 표현 문자열
int i, j;
// 이미 구현된 함수
int loadData(struct st_class* c[]); // 파일에서 수강편람 교과목 목록을 읽어온다.
void printAllClasses(struct st_class* c[], int csize); // 전체 수강편람 목록을 출력한다.

// 코드를 변경해야 하는 함수
int addNewClass(struct st_class* c[], int csize); // 수강편람에 새 과목을 추가한다.
void editClass(struct st_class* c[], int csize); // 수강편람 내 과목을 수정한다.
void findClasses(char* name, struct st_class* c[], int csize); // 수강편람에서 과목이름을 검색한다.

// 구현해야 하는 함수

int applyMyClasses(int my[], int msize, struct st_class* c[], int csize); // 수강 신청하기
void printMyClasses(int my[], int msize, struct st_class* c[], int csize); // 내 수강과목 출력하기
void saveMyClass(int my[], int msize, struct st_class* c[], int csize); // 내 수강과목 파일을 저장한다.
void saveAllClasses(struct st_class* c[], int csize); //수강편람 파일을 저장한다.
int deleteMyClass(int my[], int msize, struct st_class* c[], int csize);//수강과목 철회 


int main(void) {

	int no;	// 작업번호 
	struct st_class* classes[50]; // 수강편람 (최대 50개 교과목)

	int myclass[10]; // 내 수강과목 목록 (최대 10과목의 과목코드가 저장)
	int mycount = 0; // 내 수강과목 갯수

	srand(time(0));

	int count = loadData(classes);
	printf("%d개의 교과목 정보를 읽었습니다.\n", count);

	while(1){
		printf("\n[작업] 1.수강편람 2.과목추가 3.과목수정 4.과목검색 5.수강신청 6.내 수강과목 7.저장 8.수강철회 0.종료\n");
		printf("작업 번호는? > ");
		scanf("%d", &no);

		if(no == 1){ 
			printf(">> 1.수강편람 (총 %d과목)\n", count);
			printAllClasses(classes, count);
		}
		else if(no == 2){ 
			printf(">> 2.수강편람 과목추가\n");
			count = addNewClass(classes, count);
		}
		else if(no == 3){ 
			printf(">> 3.수강편람 과목수정\n");
			editClass(classes, count);
		}
		else if(no == 4){
			printf(">> 4.수강편람 검색\n");
			printf("검색할 과목 이름은? > ");
			char name[30];
			scanf("%s", name);
			findClasses(name, classes, count);
		}
		else if(no == 5){
			printf(">> 5.수강신청\n");
			mycount = applyMyClasses(myclass, mycount, classes, count);
			printf("%d과목을 수강신청하였습니다.\n", mycount);
		}
		else if(no == 6){
			printf(">> 6.내 수강과목\n");
			printMyClasses(myclass, mycount, classes, count);
		}
		else if(no == 7){
			printf(">> 7.저장\n");
			saveMyClass(myclass, mycount, classes, count);
			printf("\nmy_classes.txt에 내 수강과목을 저장했습니다.\n");
			saveAllClasses(classes, count);
			printf("\nclasses.txt에 수강편람을 저장했습니다.\n");
		}else if(no == 8){
	      printf(">>8. 수강철회\n");
	      mycount = deleteMyClass(myclass, mycount, classes, count);
	    }
		else break;
	}
	return 0;
}

//완성된 함수임
int loadData(struct st_class* c[]){
	int count = 0;

	FILE* file;

	file=fopen("classes.txt", "r");

	while(!feof(file)){
		c[count] = (struct st_class*)malloc(sizeof(struct st_class));
		int r = fscanf(file, "%d %s %d %d", &(c[count]->code),c[count]->name, &(c[count]->unit), &(c[count]->grading));
		if(r < 4) break;
		count++;
	}
	fclose(file);

	return count;
}

//완성된 함수임 
void printAllClasses(struct st_class* c[], int csize){

	for(i=0; i<csize; i++){
		printf("[%d] %s [%d학점 - %s]\n",c[i]->code, c[i]->name, c[i]->unit, kname[c[i]->grading-1]);
	}

}

//완성된 함수임
void saveAllClasses(struct st_class* c[], int csize){
	FILE* file;
	file = fopen("classes.txt", "w");
	for(i=0; i<csize; i++){
		fprintf(file, "%d %s %d %d\n",c[i]->code, c[i]->name, c[i]->unit, c[i]->grading);
	}
	fclose(file);	
}

//완성된 함수임
void findClasses(char* name, struct st_class* c[], int csize){
	int count = 0;

	printf("과목 검색 (검색어 : %s)\n", name);
	for(i=0; i<csize; i++){
		if(strstr(c[i]->name, name)){
			printf("[%d] %s [%d학점 - %s]\n",c[i]->code, c[i]->name, c[i]->unit, kname[c[i]->grading-1]);
			count++;
		}
	}
	printf("%d개 과목을 찾았습니다.\n", count);
}


/////////// 아래 함수는 미완성 부분을 완성시킬 것! ////////////////
int addNewClass(struct st_class* c[], int csize){
// 목표 : 동일한 코드의 교과목이 추가되지 않도록 변경하시오.
//수정해야 하는 내용 : 과목을 추가할 때에 이미 등록된 과목코드가 추가되지 않도록 코드를 수정하라.
	struct st_class* p = (struct st_class*)malloc(sizeof(struct st_class));
//0. joong =0;
  int joong = 0;


  //1. 이하를 무한반복(while(1))
  while(1){
    //1-1 일단 값을 입력받구요
    printf("과목코드 > ");
    scanf("%d", &(p->code));
    //1-2 중복검사for, 만약 중복 찾으면 >>중복있따!알려주고, 중복이라고 변수 변경 joong=1 break;
    for(i = 0; i < csize; i++){
      if(p->code == c[i]->code){
        printf("이미 등록된 과목코드입니다.\n");
        joong = 1;
        break;
      }
    }
    
    if(joong){
      joong = 0;
    }else{
      break;
    }
    //1-3 중복있었니?if 있었으면 >>joong = 0
      //없었으면 break;
  }

    //------------------------------------------
	printf("과목이름 > ");
	scanf("%s", p->name);
	printf("학점수 > ");
	scanf("%d", &(p->unit));
	printf("평가방식(1:Grade, 2: P/F) > ");
	scanf("%d", &(p->grading));

	c[csize] = p;
	return csize+1;
}
/*
0. joong =0;
1. 이하를 무한반복(while(1))
  1-1 일단 값을 입력받구요
  1-2 중복검사for, 만약 중복 찾으면 >>중복있따!알려주고, 중복이라고 변수 변경 joong=1 break;
  1-3 중복있었니?if 있었으면 >>joong = 0
    없었으면 break;

*/

void editClass(struct st_class* c[], int csize){
	struct st_class* p;
	int code;
  //0. 찾앗나변수 found = 0, index
  int found = 0, index;
  //1. 일단 입력받고
  printf("수정하려는 과목코드를 입력하세요 > ");
	scanf("%d", &code);

  //2. 중복검사? 찾기? for >>찾으면 찾았다고 변수변경 fouond = 1, 인덱스 저장  break
  for(i = 0; i < csize; i++){
    if(code == c[i]->code){
      found = 1;
      index = i;
      break;
    }
  }

  if(found){
    p = c[index];
  }else{
    printf("존재하지 않는 과목코드입니다.\n");
    return;
  }

  //3. if찾앗는지, 찾았으면 c[i]포인터를 p랑 연결해줍니당. 
    //3-2 못찾았으면? 못찾겟다 말하기, return.

// 이 부분에서 code 값으로 p포인터에 적당한 값을 찾아 넣어주는 코드를 완성하시오.
//수정해야 하는 내용 : 과목코드를 입력받은 후, 수정작업을 진행하기 위해 과목구조체 포인터의 값을 할당하는 과정을 코드에 반영하여 수정하라. 이 때, 과목코드가 존재하지 않는 경우도 적절하게 처리하라.
/*
0. 찾앗나변수 found = 0, index
1. 일단 입력받고
2. 중복검사? 찾기? for >>찾으면 찾았다고 변수변경 fouond = 1, 인덱스 저장  break
3. if찾앗는지, 찾았으면 c[i]포인터를 p랑 연결해줍니당. 
  3-2 못찾았으면? 못찾겟다 말하기, return.
*/

	printf("[%d] %s [%d학점 - %s]\n",p->code, p->name, p->unit, kname[p->grading-1]);
	printf("과목이름(수정) > ");
	scanf("%s", p->name);
	printf("학점수(수정) > ");
	scanf("%d", &(p->unit));
	printf("평가방식(수정)(1:Grade, 2: P/F) > ");
	scanf("%d", &(p->grading));
	
	printf("수정했습니다.\n");

}


/////////// 아래 함수는 직접 구현할 것! ////////////////

//내 수강과목 등록하기
int applyMyClasses(int my[], int msize, struct st_class* c[], int csize){

  //yes(계속할건가), joong =0, found=0, mycount = msize 
  int yes, joong = 0, found = 0, mycount = msize, code;
  //0. 이하를 무한반복... \

  while(1){
    //1. 이하를 무한반복...

    while(1){
      //1-1 입력받고
      printf("수강하려는 과목 코드를 입력하세요 >\n");
      scanf("%d", &code);
      //1-2 적절하게 받았나 확인
        //1-2-1 이미 신청한건지, 역대수강과목 중복검사
      for(i = 0; i < mycount; i++){
        if(code == my[i]){
          joong = 1;
          break;
        }
      }
        //1-2-2 존재하는코드인지. 역대수강편람 중복검사
      for(i = 0 ; i < csize; i++){
        if(code == c[i]->code){
          found = 1;
          break;
        }
      }

      //1-3 잘 받았으면 found=0하고 break, 아니면 (joong==1, found !=1)에러메세지 출력 (다음턴 위한 값 초기화도)
      if(joong){
        joong = 0;
        printf("이미 신청한 과목입니다.\n");
      }else if(found != 1){
        printf("과목코드가 잘못되었습니다.\n");
      }else{
        found = 0;
        my[mycount] = code;
        mycount ++;
        break;
      }
    }
    //2. 방금 입력받은거 my배열에 저장, mycount++
    //3. 계속 입력받을건지 물어보기. no하면 break. 

    printf("계속 입력하실까요?(1:예 2:아니요)) >\n");
    scanf("%d", &yes);
    if(yes == 2){
      break;
    }

  }
	return mycount;
}
//파라미터 : 내가 신청한 과목코드 배열, 내가 신청한 과목 갯수, 수강편람 구조체포인터 배열, 수강편람 과목 갯수
//리턴값 : 변경된 내 수강과목 갯수
//하는 일 : 과목코드를 입력받아 내 수강신청 과목을 추가로 등록하는 과정을 반복하다가 끝나면 최종 등록된 내 수강과목의 갯수를 리턴한다.
/*
yes(계속할건가), joong =0, found=0, mycount = msize 
0. 이하를 무한반복... \

  1. 이하를 무한반복...
    1-1 입력받고
    1-2 적절하게 받았나 확인
      1-2-1 이미 신청한건지, 역대수강과목 중복검사
      1-2-2 존재하는코드인지. 역대수강편람 중복검사
    1-3 잘 받았으면 found=0하고 break, 아니면 (joong==1, found !=1)에러메세지 출력 (다음턴 위한 값 초기화도)

  2. 방금 입력받은거 my배열에 저장, mycount++
  3. 계속 입력받을건지 물어보기. no하면 break. 

4. n과목을 수강신청하였습니다. 출력, return mycount

*/

//수강하려는 과목 코드를 입력하세요 >
//과목코드가 잘못되었습니다.
//이미 신청한 과목입니다. 

//계속 입력하실까요?(1:예 2:아니요)) >

//2과목을 수강신청하였습니다.


//내 수강과목 출력하기
void printMyClasses(int my[], int msize, struct st_class* c[], int csize){
  //0. sum=0; 
  int sum = 0;
  //1. mysize번 이하 반복for
  for(i = 0; i < msize; i++){

    //1-1 csize번 훑으며...(for)
    for(j = 0; j < csize; j++){
      //1-1-2 my[i]랑 코드가 일치하는 c의 정보 출력, 학점 누적더하기,break
      if(my[i] == c[j]->code){
        printf("%d. [%d] %s [%d학점 - %s]\n", i+1, c[j]->code, c[j]->name, c[j]->unit, kname[c[j]->grading-1]);
        sum += c[j]->unit;
        break;
      }
    }
  }
  //2. 총 수강학점 출력 
  printf("총 수강학점: %d학점 \n", sum);


}
//파라미터 : 내가 신청한 과목코드 배열, 내가 신청한 과목 갯수, 수강편람 구조체포인터 배열, 수강편람 과목 갯수
//리턴값 : 없음
//하는 일 : 나의 수강신청 과목의 모든 과목정보를 출력한다.

/*
0. sum=0; 
1. mysize번 이하 반복for
  1-1 csize번 훑으며...(for)
    1-1-2 my[i]랑 코드가 일치하는 c의 정보 출력, 학점 누적더하기,break
2. 총 수강학점 출력 
*/


// 1. [101] C프로그래밍 [3학점 - Grade]'''
//총 수강학점: 4학점 



//내 수강과목 파일로 저장하기
void saveMyClass(int my[], int msize, struct st_class* c[], int csize){

  //0. apoint, gpoint, ppoint =0=0=0
  int apoint = 0, gpoint = 0, ppoint = 0;

  //1. 파일핸들러 선언, 파일 열기 
  FILE* file;
  file = fopen("my_classes.txt", "w");

  //2. 파일에 쓰기
    //2-1 (*내 수강 과목)
    fprintf(file, "*내 수강 과목\n");
    //2-2 for문으로 misize만큼 이하 반복
  for(i = 0; i < msize; i++){
    //1-1 csize번 훑으며...(for)
    for(j = 0; j < csize; j++){
      //1-1-2 my[i]랑 코드가 일치하는 c의 정보 출력, 학점 누적더하기,break
      if(my[i] == c[j]->code){
        fprintf(file, "%d. [%d] %s [%d학점 - %s]\n", i+1, c[j]->code, c[j]->name, c[j]->unit, kname[c[j]->grading-1]);
        apoint += c[j]->unit;
        if(c[j]->grading == 1){
          gpoint +=c[j]->unit;
        }else{
          ppoint += c[j]->unit;
        }
        break;
      }
    }
  }
    
      //2-2-1 [101] C프로그래밍 [3학점 - Grade]'''출력
      //2-2-2 올포인트 누적

      //2-2-3 조건에 맞게 g포인트나 p포인트 누적
    //2-3 누적정보? 출력 
  fprintf(file, "총 수강 과목: %d과목, %d학점(Grade %d학점, P/F %d학점)\n", msize, apoint, gpoint, ppoint);

  //3. 파일 닫기
  fclose(file);

}
//파라미터 : 내가 신청한 과목코드 배열, 내가 신청한 과목 갯수, 수강편람 구조체포인터 배열, 수강편람 과목 갯수
//리턴값 : 없음
//하는 일 : 나의 수강신청 과목의 모든 과목정보를 my_classes.txt 파일로 저장한다.
//파일에 포함해야 하는 내용 : 내가 신청한 수강 과목 목록 (과목코드, 과목명, 학점수, 평가방식), 총 수강학점, 평가방식별 수강학점, 수강과목수 등

/*
0. apoint, gpoint, ppoint =0=0=0

1. 파일핸들러 선언, 파일 열기 

2. 파일에 쓰기
  2-1 (*내 수강 과목)
  2-2 for문으로 misize만큼 이하 반복
    2-2-1 [101] C프로그래밍 [3학점 - Grade]'''출력
    2-2-2 올포인트 누적
    2-2-3 조건에 맞게 g포인트나 p포인트 누적
  2-3 누적정보? 출력 

3. 파일 닫기
*/

/*내 수강 과목
1. [101] C프로그래밍 [3학점 - Grade]'''
총 수강 과목: 5과목, 12학점(Grade 11학점, P/F 1학점)
*/

//수강과목 철회 
int deleteMyClass(int my[], int msize, struct st_class* c[], int csize){
  int code, yes, found = 0, index;

  //1. 삭제하고싶은 과목 입력받기(코드)
  printf("수강철회할 과목 코드를 입력하세요\n");
  scanf("%d", &code);
    //1-1 수강중인 과목인지 찾기(for, found, index저장) >> 못찾으면 return msize
  for(i = 0; i < msize; i++){
    if(code == my[i]){
      found = 1;
      index = i;
      break;
    }
  }

  //2. 찾았으면, 과목 정보 출력
  if(found != 1){
    printf("수강중인 과목이 아닙니다.\n");
    return msize;
  }else{
    for( j = 0; j < csize; j++){
          //1-1-2 my[i]랑 코드가 일치하는 c의 정보 출력, 학점 누적더하기,break
      if(my[index] == c[j]->code){
        printf("%d. [%d] %s [%d학점 - %s]\n", j+1, c[j]->code, c[j]->name, c[j]->unit, kname[c[j]->grading-1]);
        break;
      }
    }
  }

  //3. 진짜 삭제할건지 물어보기(yes), no하면 return msize
  printf("정말로 수강철회 하시겠습니까?(yes: 1, no : 2)\n");
  scanf("%d", &yes);

  if(yes == 2){
    return msize;
  }

  //4. 삭제하기 
    //4-1 아까 저장한 index부터 시작하는 for문
    for(i = index; i < msize; i++){
      //4-1-1 my[index] = my[index+1];
      if(i <= msize-1){
        my[i] = my[i+1];
      }
    }
  printf("수강철회 되었습니다.\n");
  //5. 리턴 msize-1
  return msize-1;
}
/*
1. 삭제하고싶은 과목 입력받기(코드)
  1-1 수강중인 과목인지 찾기(for, found, index저장) >> 못찾으면 return msize
2. 찾았으면, 과목 정보 출력
3. 진짜 삭제할건지 물어보기(yes), no하면 return msize
4. 삭제하기 
  4-1 아까 저장한 index부터 시작하는 for문
    4-1-1 my[index] = my[index+1];
    4-1-2 index+1 = msize 가 되면 break 
5. 리턴 msize-1

*/

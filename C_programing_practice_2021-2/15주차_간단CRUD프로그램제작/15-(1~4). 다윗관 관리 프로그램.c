#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*다윗관이라고 불리는 가상의 생활관에는 외국인 학생들이 거주한다. 이 곳은 2층으로 되어 있으며, 1층에는 여학생, 2층에는 남학생이 거주하게 된다. 각 층마다 1호실부터 15호실까지 15개의 2인1실의 방이 있다.

이 프로그램은 다윗관에 거주하는 학생들의 정보를 관리한다. 관리하는 정보는 다음과 같다. 학생이름, 성별(F or M), 입학년도(2015~2018), 방호실(101~215), 벌점(0~10)

기본적으로 프로그램이 시작되면 members.txt로부터 40명의 관생정보를 읽어온 후 (완성 코드 제공), 5개의 메뉴를 선택하면서 필요한 기능이 수행된다.

[1] 목록 - 현재의 모든 관생 정보를 화면에 출력한다. --> 이 기능은 코드에 이미 구현되어 제공한다. [2] 호실변경 - 특정 학생의 호실을 변경한다. --> 이 기능은 코드에 일부만 구현되어 제공한다. [3] 벌점부여 - 특정 학생에게 벌점을 1점 부과한다. --> 이 기능은 직접 구현해야 한다. [4] 검색 - 이름의 일부(2글자이상)만으로 관생정보를 검색한다. --> 이 기능은 코드에 일부만 구현되어 제공한다. [5] 보고서 저장 - 현재의 다윗관 현황을 파일에 저장한다. --> 이 기능은 직접 구현해야 한다.

문제설명 : 보고서 저장 기능 구현하기
다음의 순서대로 보고서 파일에 텍스트를 저장하는 기능을 구현하라. 

1. 전체 관생수, 남녀 학생 수 
2. 호실 현황 (호실별 인원이 0명, 1명, 2명으로 구분) 
3. 학번별 현황 (입학년도가 2015에서 2018까지 4종류의 학생 수) 
4. 고벌점자 - 벌점이 7점 이상인 학생 숫자와 명단 
5. 관생 목록 - listMembers()함수의 내용 참고
*/

struct Record{		// 생활관생 관리 레코드
	char name[20];	// 성명				
	char fm;		// 성별 ('F' 여성, 'M' 남성)				
	int entry;		// 입학년도 (4자리 숫자)
	int room;		// 방 호실
	int point;		// 벌점
};

int loadMembers(struct Record* p[]);		// 목록파일 읽기
void listMembers(struct Record* p[], int n);	// 목록 출력(리스트)
void editRoom(struct Record* p[], int n);		// 호실 수정
void makePenalty(struct Record* p[], int n);	// 벌점 부여
void findMembers(struct Record* p[], int n);	// 검색 (이름)
void saveReport(struct Record* p[], int n);	// 보고서 저장

int main(){
	struct Record* members[100]; 	// 최대 100명까지 관리할 수 있는 포인터 배열
	int count;	// 현재등록된 관생 수
	int menu;	// 메뉴번호
	count = loadMembers(members);	// 시작 전에 파일로부터 관생 리스트를 모두 읽어온다.
	while(1)
	{
		printf("\n[1]목록 [2]호실변경 [3]벌점부여 [4]검색 [5]보고서 저장 [0]종료 >> ");
		scanf("%d",&menu);	// 메뉴를 읽음

		if(menu==1){
			listMembers(members, count);	// 목록 출력
		}
		else if(menu==2){
			editRoom(members, count);	// 호실 변경
		}
		else if(menu==3){
			makePenalty(members, count); // 벌점 부여
		}
		else if(menu==4){
			findMembers(members, count);	// 검색
		}
		else if(menu==5){
			saveReport(members, count);	// 보고서 저장
		}
		else {
			break;
		}
	}
}

int loadMembers(struct Record* p[]){
	FILE *file;
	int n=0;
	file = fopen("members.txt","rt");
	while(!feof(file)){
		p[n]=(struct Record*)malloc(sizeof(struct Record));
		fscanf(file,"%s %c %d %d %d",p[n]->name,&(p[n]->fm),&(p[n]->entry),&(p[n]->room),&(p[n]->point));
		n++;
	}
	fclose(file);
	printf("%d명이 저장된 파일을 읽었습니다.\n",n);
	return n;
}

void listMembers(struct Record * p[], int n){
	int i;
	printf("\n전체목록입니다.\n");
	printf("NO 이름 성별 학번 호실 벌점\n");
	
	for(i=0; i<n; i++){
		printf("%d %s [%c] %d %d %d\n", (i+1), p[i]->name, p[i]->fm, p[i]->entry, p[i]->room, p[i]->point);
	}
}

// 15-1 문제
void editRoom(struct Record* p[], int n){
	char name[20];
	struct Record* rp; // 수정할 레코드 구조체의 포인터값
	int i, found=0, newroom;
  int error, count; //문제가 있나없나/ 해당 방호실에 현 학생수 몇명?

	printf("호실 변경하려는 학생 이름은? >> ");
	scanf("%s", name);

	for(i=0;i<n;i++){
		if(strcmp(p[i]->name,name)==0){
			found=1;
			rp=p[i]; //이제부터 같은곳을 가리키는거임 
			break;
		}
	}

	if(found==1){
		printf("이름 성별 학번 호실 벌점\n");
		printf("%s [%c] %d %d %d\n", rp->name, rp->fm, rp->entry, rp->room, rp->point);

    while(1){
      error = 0;
      count = 0;
      printf("새로운 호실을 입력하시오. >> ");
      scanf("%d", &newroom); 

      if(!(newroom > 100 && newroom < 116)&&!(newroom > 200 && newroom < 216) ){
        printf("배정불가(호실 오류)\n");
        error = 1;
        continue;
      }

      if(rp->fm == 'M' && (newroom > 100 && newroom < 116)){
        printf("배정불가(층 오류)\n");
        error = 1;
        continue;
      }else if(rp->fm == 'F' && (newroom > 200 && newroom < 216)){
        printf("배정불가(층 오류)\n");
        error = 1;
        continue;
      }

      //방금 선택한 그 호실에 지금 학생 몇명 사는지... 
      for(i=0;i<n;i++){ 
        if(p[i]->room == newroom){
          count ++;
        }
      }

      if(count == 2){
        printf("배정불가(인원초과)\n");
        error = 1;
        continue;
      }

      if(error == 0){ //아무런 에러에도 안걸리면 탈출 
        break;
      }

    }

		rp->room = newroom;
		printf("수정완료!\n");
	}
	else{
		printf("없는 학생입니다.\n");
	}
}

// 15-2
void makePenalty(struct Record* p[], int n){
  char name[20];
	struct Record* rp; // 수정할 레코드 구조체의 포인터값
	int i, found=0;
  int yes; //벌점 부여할거냐 


  printf("벌점 부여할 학생 이름은? >> ");
  scanf("%s", name);

	for(i=0;i<n;i++){
		if(strcmp(p[i]->name,name)==0){
			found=1;
			rp=p[i]; //이제부터 같은곳을 가리키는거임 
			break;
		}
	}

  if(found == 1){

    printf("이름 성별 학번 호실 벌점\n%s [%c] %d %d %d\n", rp->name, rp->fm, rp->entry, rp->room, rp->point);
    printf("위 학생에게 벌점을 부여할까요? (YES 1, NO 0) >> ");
    scanf("%d", &yes);

    if(yes){
      rp->point ++;
      printf("%s 학생의 벌점은 %d점입니다.\n", rp->name, rp->point);

    }else{
      return;
    }

  }else{
    printf("없는 학생입니다.\n");
  }

}

// 15-3
void findMembers(struct Record * p[], int n){
	int i, count=0;
	char name[20];
	while(1){
		printf("검색하려는 학생 이름을 2글자 이상 입력하세요. >> ");
		scanf("%s", name);
		if(strlen(name) > 1) break;
	}

  printf("NO 이름 성별 학번 호실 벌점\n");

	for(i=0;i<n;i++){
		if(strstr(p[i]->name,name)!=0){
			printf("%d %s [%c] %d %d %d\n", i+1, p[i]->name, p[i]->fm, p[i]->entry, p[i]->room, p[i]->point); 
      count ++;
		}
	}

  printf("%d명 검색됨\n", count);

}


// 15-4
void saveReport(struct Record* p[], int n){
  int rooms[2][15] = {0};//각 호실에 있는 학생수
  int entry; //학번 
  int entryNum[4] = {0}; //15학번-18학번까지 학생수 
  int warn = 0, index[40]={0}; //고벌점자 학생수, 학생번호 
  
	FILE* file;
	file = fopen("report.txt","wt");


  fprintf(file, "다윗관 현황 보고서\n");
  fprintf(file, "1. 거주학생 수 : 40명 (남 20명, 여 20명)\n");

 	for(int i=0; i<n; i++){
		rooms[p[i]->room/100-1][p[i]->room%100-1] ++; //해당 룸 인원수+

    entry = p[i]->entry-2000; //학번 누적저장 
    if(entry == 15) entryNum[0] ++;
    if(entry == 16) entryNum[1] ++;
    if(entry == 17) entryNum[2] ++;
    if(entry == 18) entryNum[3] ++;

    if(p[i]->point >6){ //고벌점자인지 판단, 저장 
      index[warn] = i;
      warn++;
    }

	} 

  fprintf(file, "\n2. 호실 현황\n");
  fprintf(file, " 1) 공실 : ");
  for(int i=0; i<2; i++){
    for(int j = 0; j < 15; j++){
      if(rooms[i][j] == 0){
        fprintf(file, "%d%02d ", i+1, j+1);
      }
    }
	}

  fprintf(file, "\n 2) 1인실 : ");
  for(int i=0; i<2; i++){
    for(int j = 0; j < 15; j++){
      if(rooms[i][j] == 1){
        fprintf(file, "%d%02d ", i+1, j+1);
      }
    }
	}

  fprintf(file, "\n 3) 2인실 : 1");
  for(int i=0; i<2; i++){
    for(int j = 0; j < 15; j++){
      if(rooms[i][j] == 2){
        fprintf(file, "%d%02d ", i+1, j+1);
      }
    }
	}

  fprintf(file, "\n3. 학번별 현황\n");
  fprintf(file, " 1) 2015학번 : %d명\n", entryNum[0]);
  fprintf(file, " 2) 2016학번 : %d명\n", entryNum[1]);
  fprintf(file, " 3) 2018학번 : %d명\n", entryNum[2]);
  fprintf(file, " 4) 2019학번 : %d명\n", entryNum[3]);

  fprintf(file, "\n4. 고벌점자(7점 이상) : %d명\n", warn);
  for(int i = 0; i < warn; i++){
    fprintf(file, "%s(%d)", p[index[i]]->name, p[index[i]]->point);
  }
  
  fprintf(file, "\n\n5. 관생 목록\n");
	fprintf(file, "NO 이름 성별 학번 호실 벌점\n");
	
	for(int i=0; i<n; i++){
		fprintf(file, "%d %s [%c] %d %d %d\n", (i+1), p[i]->name, p[i]->fm, p[i]->entry, p[i]->room, p[i]->point);
	}

	fclose(file);
  printf("저장되었습니다.\n");
}	
/*1. 전체 관생수, 남녀 학생 수 
2. 호실 현황 (호실별 인원이 0명, 1명, 2명으로 구분) 
3. 학번별 현황 (입학년도가 2015에서 2018까지 4종류의 학생 수) 
4. 고벌점자 - 벌점이 7점 이상인 학생 숫자와 명단 
5. 관생 목록 - listMembers()함수의 내용 참고*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*어떤 호텔에 3종류의 객실 여러 개가 준비되어 있다. 이 객실들을 예약하는 프로그램을 제작하라.

* 이미 구현된 기능
1. 객실상태 기초정보 읽어오기 - loadCards()
"rooms.txt"로부터 객실번호, 등급, 수용최대인원 정보를 관리카드에 가져온다.
2. 모든 객실상태 출력하기 - listCards()
현재 등록된 모든 객실정보를 출력한다.

* 구현해야 하는 기능
3. 객실 예약하기 - makeReserve()
예약자 이름과 예약 인원, 원하는 객실 번호를 입력받아 이에 맞는 객실에 예약할 수 있도록 카드 정보를 수정한다.
4. 객실 예약 취소하기 - cancelReserve()
예약자 이름을 입력받아 해당 객실의 예약을 취소한다.
5. 객실 검색 - findCards()
고객 이름을 입력받아 해당 고객이 예약한 정보를 출력한다.
객실 번호를 입력받아 해당 객실의 상황을 출력한다.
6. 객실관리 보고서 저장하기 - saveReport()
현재의 객실상황을 roomsReport.txt 파일에 저장한다. 
7. 빈 객실 찾기 - findRoom()
객실 등급, 수용 인원에 따라 예약이 가능한 객실의 정보를 찾아 출력한다.
8. 객실 추가하기 - addCards()
객실 정비 등의 이유로 누락되었던 객실을 관리카드에 새로 추가한다.

>>>객실 추가 기능을 구현하라

새로운 객실번호를 입력받는다.
이 객실번호가 이미 등록되어 있거나, 이전 객실번호와 연속적으로 연결되는 번호가 아닌 경우에는 오류 메시지를 출력하고 다시 입력받도록 한다.
객실 등급과 수용인원을 입력받아 새로 추가한다.
*/

char GRADE[3][10]={"Deluxe", "Luxury", "Suite"}; // 객실등급 명칭 

struct st_card{		// 객실 관리 카드 레코드
	int no;		// 객실번호 (3자리 숫자)
	int grade; // 객실 등급 (1:deluxe, 2:luxury, 3:suite)
	int capa;		// 수용최대인원 (2~10명)
	char name[20];	// 예약자 성명				
	int person;		// 예약 인원
};

int loadCards(struct st_card* p[]);		// 객실정보 읽기
void listCards(struct st_card* p[], int n);	// 객실 목록 출력
void makeReserve(struct st_card* p[], int n);		// 객실 예약
void cancelReserve(struct st_card* p[], int n);	// 예약 취소
void findCards(struct st_card* p[], int n);	// 객실 검색
void saveReport(struct st_card* p[], int n);	// 보고서 저장
void findRoom(struct st_card* p[], int n);	// 빈 객실 찾기
int addCards(struct st_card* p[], int n);	// 객실 추가 

int main(){
	struct st_card* cards[50]; 	// 최대 50개의 객실을 관리할 수 있는 구조체 포인터 배열
	int count;	// 현재 등록된 카드 수
	int menu;	// 메뉴번호
	count = loadCards(cards);	// 시작 전에 파일로부터 객실 리스트를 모두 읽어온다.
	while(1)
	{
		// 메뉴 출력
		printf("\n[1]객실목록 [2]예약 [3]예약취소 [4]검색 [5]저장 [6]빈객실찾기 [7]객실추가 [0]종료 >> ");
		scanf("%d",&menu);	// 메뉴를 읽음

		if(menu==1){
			listCards(cards, count);	// 객실 목록 출력
		}
		else if(menu==2){
			makeReserve(cards, count);	// 예약하기
		}
		else if(menu==3){
			cancelReserve(cards, count); // 예약 취소
		}
		else if(menu==4){
			findCards(cards, count);	// 검색
		}
		else if(menu==5){
			saveReport(cards, count);	// 보고서 저장
		}
		else if(menu==6){
			findRoom(cards, count);	// 빈 객실 찾기
		}
		else if(menu==7){
			count = addCards(cards, count);	// 객실 추가
		}
		else {
			break;
		}
	}
}

int loadCards(struct st_card* p[]){
	FILE *file;
	int n=0;
	file = fopen("rooms.txt","r");
	while(!feof(file)){
		p[n]=(struct st_card*)malloc(sizeof(struct st_card));
		int result = fscanf(file,"%d %d %d",&(p[n]->no),&(p[n]->grade),&(p[n]->capa));
		if (result < 1) break;
		n++;
	}
	fclose(file);
	printf("%d개의 객실 정보를 읽었습니다.\n",n);
	return n;
}

void listCards(struct st_card * p[], int n){
	int i;
	printf("\n전체 객실 목록입니다.\n");
	printf("객실번호 / 등급 / 최대인원 / 예약상황\n");
	
	for(i=0; i<n; i++){
		printf("%d호 / %s / %d명 / ", p[i]->no, GRADE[p[i]->grade-1], p[i]->capa);
		if(p[i]->person > 0)
			printf("예약 : %s %d명\n",p[i]->name, p[i]->person);
		else
			printf("예약없음\n");
	}
}

// 15-5
void makeReserve(struct st_card* p[], int n){
	char name[20];
	struct st_card* rp; // 예약할 카드레코드 구조체의 포인터값
	int i, roomno, newperson;
  int error, index = -1; //문제있는지, 방금부른 객실번호의 인덱스

	printf("예약하실 고객 이름은? >> ");
	scanf("%s", name);
	printf("예약 인원수를 입력하시오. >> ");
	scanf("%d", &newperson); 

  while(1){
    error = 0;
    printf("예약하실 객실 번호는? >> ");
    scanf("%d", &roomno);

    for(i=0;i<n;i++){ //있는 번호면 인덱스는 뭔지(없으면 초기값인 -1)
      if(p[i]->no==roomno){
        index = i;
        break;
      }
    }

    if(index == -1){
      printf("예약불가(객실번호 오류)\n");
      error = 1;
      continue;
    }


    if(p[index]->person != 0){
      printf("예약불가(예약된 객실)\n");
      error = 1;
      continue;
    }

    if(newperson > p[index]->capa){
      printf("예약불가(인원 초과)\n");
      error = 1;
      continue;
    }

    if(error == 0){
      break;
    }

  }
	
	for(i=0;i<n;i++){
		if(p[i]->no==roomno){
			rp=p[i];
			break;
		}
	}

	rp->person = newperson;
	strcpy(rp->name, name);
	printf("예약완료!\n");
}


// 15-6
void cancelReserve(struct st_card* p[], int n){
  char name[20];
	struct st_card* rp; // 예약취소할 카드레코드 구조체의 포인터값
	int i, roomno, found = 0;;
  int yes; //진짜 취소할건지 

  printf("예약 취소하실 객실 번호는? >> ");
  scanf("%d", &roomno);

  for(i=0;i<n;i++){
		if(p[i]->no==roomno){
			rp=p[i];
      if(rp->person != 0){
        found = 1;
      }
			break;
		}
	}

  if(found == 1){

    printf("객실번호 / 등급 / 예약자 / 예약인원\n");
    printf("%d호 / %s / %s / %d명\n", rp->no, GRADE[rp->grade-1],rp->name, rp->person);

    printf("위 예약을 취소할까요? (YES 1, NO 0) >> ");
    scanf("%d", &yes);

    if(yes){
      rp->person = 0;
      strcpy(rp->name,"\0");
      printf("취소했습니다.\n");
      return;
    }

  }else{
    printf("예약된 객실이 아닙니다.\n");
  }


}


// 15-7
void findCards(struct st_card * p[], int n){
  char name[20];
  int count = 0;

  while(1){
    printf("검색하려는 고객 이름을 2글자 이상 입력하세요. >> ");
    scanf("%s", name);

    if(strlen(name) > 1){
      break;
    }else{
      printf("두 글자 이상 입력하세요\n");
    }

  }

  printf("객실번호 / 등급 / 예약자 / 예약인원 / 최대인원\n");

  for(int i=0;i<n;i++){
		if(strstr(p[i]->name, name) != 0){
			printf("%d호 / %6s / %s / %d명 / %d명\n", p[i]->no, GRADE[p[i]->grade-1],p[i]->name, p[i]->person, p[i]->capa);
			count ++;
		}
	}

  printf("%d명 검색됨\n", count);

}


// 15-8
void saveReport(struct st_card* p[], int n){
  int rooms[3] = {0}, checkInRooms[3] = {0}, checkInPpl[3] = {0}, blankPpl[3] = {0};//객실 수, 예약객실수, 예약고객, 남은수용인원/ 등급별 0,1,2


  for(int i=0; i<n; i++){ //싹 한번 훑으며 필요한 정보 누적 
    rooms[p[i]->grade-1]++; //해당 등급 객실수 ++
    
    if(p[i]->person != 0){ //예약되어있으면 
      checkInRooms[p[i]->grade-1] ++; //해당 등급 예약객실수 ++
      checkInPpl[p[i]->grade-1] += p[i]->person; //해당 등급 예약고객++
    }else{//아니면 
      blankPpl[p[i]->grade-1] += p[i]->capa; //수용가능인원++
    }
		
	}


  FILE* file;
  file = fopen("rooms_report.txt", "w");

  fprintf(file, "객실 현황 보고서\n");
  for(int i = 0; i < 3; i ++){
    fprintf(file, "\n객실등급 : %s\n", GRADE[i]);
    fprintf(file, "1. 객실 수 : 총 %d실 중 %d실 예약 중\n", rooms[i], checkInRooms[i]);
    fprintf(file, "2. 예약 고객 : 총 %d명\n", checkInPpl[i]);
    fprintf(file, "3. 남은 최대수용 고객 : 총 %d명\n", blankPpl[i]);

  }

  fprintf(file, "\n객실 예약 목록\nn");
	fprintf(file,"객실번호 / 등급 / 최대인원 / 예약상황\n");
	
	for(int i=0; i<n; i++){
		fprintf(file,"%d호 / %s / %d명 / ", p[i]->no, GRADE[p[i]->grade-1], p[i]->capa);
		if(p[i]->person > 0)
			fprintf(file,"예약 : %s %d명\n",p[i]->name, p[i]->person);
		else
			fprintf(file,"예약없음\n");
	}

  fprintf(file, "예약 인원 합계 : %d명", (checkInPpl[0]+checkInPpl[1]+checkInPpl[2]));

  fclose(file);
  printf("저장되었습니다.\n");

}	

//15-9
void findRoom(struct st_card* p[], int n){
  int person, grade;//투숙인원수 
  int count = 0; //투숙가능 객실 수 

  printf("투숙 인원수는? >> ");
  scanf("%d", &person);

  printf("원하시는 객실 등급은? (Deluxe 1, Luxury 2. Suite 3, 무관 0) >> ");
  scanf("%d", &grade);

  printf("객실번호 / 등급 / 최대인원\n");

  for(int i=0; i<n; i++){ //싹 한번 훑으며 조건 부합하면 출력 

    if(p[i]->capa >= person){

      if(p[i]->grade == grade || (grade == 0)){

        if(p[i]->person == 0){
          printf("%d호 / %s / %d명\n", p[i]->no, GRADE[p[i]->grade-1], p[i]->capa);
          count++;
        }
      }
    }
  }
  printf("총 %d개의 객실이 예약 가능합니다.\n", count);
}

/*int no;		// 객실번호 (3자리 숫자)
	int grade; // 객실 등급 (1:deluxe, 2:luxury, 3:suite)
	int capa;		// 수용최대인원 (2~10명)
	char name[20];	// 예약자 성명				
	int person;		// 예약 인원*/
// 15-10
int addCards(struct st_card* p[], int n){
  p[n] = malloc(sizeof(struct st_card));
  int joong, yeon;

  while(1){
    joong = 0;
    yeon = 0;
    printf("추가할 객실번호는? >> ");
    scanf("%d", &p[n]->no);

    for(int i=0; i<n; i++){ //싹 한번 훑으며 중복검사 
      if(p[i]->no == p[n]->no){
        joong = 1;
      }
      if((p[i]->no +1 == p[n]->no) || (p[i]->no -1 == p[n]->no)){
        yeon = 1;
      }

    }

      if(joong){
        printf("이미 등록된 객실번호입니다.\n");
      }else if(!yeon){
        printf("연속적인 객실번호가 아닙니다.\n");
      }else{
        break;
      }

  }

  printf("객실등급(Deluxe 1, Luxury 2. Suite 3)과 최대인원을 입력하세요 >> ");
  scanf("%d %d", &p[n]->grade, &p[n]->capa);

  printf("객실을 추가하였습니다.\n");




	return n+1;
}
/*새로운 객실번호를 입력받는다.
이 객실번호가 이미 등록되어 있거나, 이전 객실번호와 연속적으로 연결되는 번호가 아닌 경우에는 오류 메시지를 출력하고 다시 입력받도록 한다.
객실 등급과 수용인원을 입력받아 새로 추가한다.*/


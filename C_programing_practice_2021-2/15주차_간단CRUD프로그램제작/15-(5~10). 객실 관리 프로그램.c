#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*� ȣ�ڿ� 3������ ���� ���� ���� �غ�Ǿ� �ִ�. �� ���ǵ��� �����ϴ� ���α׷��� �����϶�.

* �̹� ������ ���
1. ���ǻ��� �������� �о���� - loadCards()
"rooms.txt"�κ��� ���ǹ�ȣ, ���, �����ִ��ο� ������ ����ī�忡 �����´�.
2. ��� ���ǻ��� ����ϱ� - listCards()
���� ��ϵ� ��� ���������� ����Ѵ�.

* �����ؾ� �ϴ� ���
3. ���� �����ϱ� - makeReserve()
������ �̸��� ���� �ο�, ���ϴ� ���� ��ȣ�� �Է¹޾� �̿� �´� ���ǿ� ������ �� �ֵ��� ī�� ������ �����Ѵ�.
4. ���� ���� ����ϱ� - cancelReserve()
������ �̸��� �Է¹޾� �ش� ������ ������ ����Ѵ�.
5. ���� �˻� - findCards()
�� �̸��� �Է¹޾� �ش� ���� ������ ������ ����Ѵ�.
���� ��ȣ�� �Է¹޾� �ش� ������ ��Ȳ�� ����Ѵ�.
6. ���ǰ��� ���� �����ϱ� - saveReport()
������ ���ǻ�Ȳ�� roomsReport.txt ���Ͽ� �����Ѵ�. 
7. �� ���� ã�� - findRoom()
���� ���, ���� �ο��� ���� ������ ������ ������ ������ ã�� ����Ѵ�.
8. ���� �߰��ϱ� - addCards()
���� ���� ���� ������ �����Ǿ��� ������ ����ī�忡 ���� �߰��Ѵ�.

>>>���� �߰� ����� �����϶�

���ο� ���ǹ�ȣ�� �Է¹޴´�.
�� ���ǹ�ȣ�� �̹� ��ϵǾ� �ְų�, ���� ���ǹ�ȣ�� ���������� ����Ǵ� ��ȣ�� �ƴ� ��쿡�� ���� �޽����� ����ϰ� �ٽ� �Է¹޵��� �Ѵ�.
���� ��ް� �����ο��� �Է¹޾� ���� �߰��Ѵ�.
*/

char GRADE[3][10]={"Deluxe", "Luxury", "Suite"}; // ���ǵ�� ��Ī 

struct st_card{		// ���� ���� ī�� ���ڵ�
	int no;		// ���ǹ�ȣ (3�ڸ� ����)
	int grade; // ���� ��� (1:deluxe, 2:luxury, 3:suite)
	int capa;		// �����ִ��ο� (2~10��)
	char name[20];	// ������ ����				
	int person;		// ���� �ο�
};

int loadCards(struct st_card* p[]);		// �������� �б�
void listCards(struct st_card* p[], int n);	// ���� ��� ���
void makeReserve(struct st_card* p[], int n);		// ���� ����
void cancelReserve(struct st_card* p[], int n);	// ���� ���
void findCards(struct st_card* p[], int n);	// ���� �˻�
void saveReport(struct st_card* p[], int n);	// ���� ����
void findRoom(struct st_card* p[], int n);	// �� ���� ã��
int addCards(struct st_card* p[], int n);	// ���� �߰� 

int main(){
	struct st_card* cards[50]; 	// �ִ� 50���� ������ ������ �� �ִ� ����ü ������ �迭
	int count;	// ���� ��ϵ� ī�� ��
	int menu;	// �޴���ȣ
	count = loadCards(cards);	// ���� ���� ���Ϸκ��� ���� ����Ʈ�� ��� �о�´�.
	while(1)
	{
		// �޴� ���
		printf("\n[1]���Ǹ�� [2]���� [3]������� [4]�˻� [5]���� [6]�󰴽�ã�� [7]�����߰� [0]���� >> ");
		scanf("%d",&menu);	// �޴��� ����

		if(menu==1){
			listCards(cards, count);	// ���� ��� ���
		}
		else if(menu==2){
			makeReserve(cards, count);	// �����ϱ�
		}
		else if(menu==3){
			cancelReserve(cards, count); // ���� ���
		}
		else if(menu==4){
			findCards(cards, count);	// �˻�
		}
		else if(menu==5){
			saveReport(cards, count);	// ���� ����
		}
		else if(menu==6){
			findRoom(cards, count);	// �� ���� ã��
		}
		else if(menu==7){
			count = addCards(cards, count);	// ���� �߰�
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
	printf("%d���� ���� ������ �о����ϴ�.\n",n);
	return n;
}

void listCards(struct st_card * p[], int n){
	int i;
	printf("\n��ü ���� ����Դϴ�.\n");
	printf("���ǹ�ȣ / ��� / �ִ��ο� / �����Ȳ\n");
	
	for(i=0; i<n; i++){
		printf("%dȣ / %s / %d�� / ", p[i]->no, GRADE[p[i]->grade-1], p[i]->capa);
		if(p[i]->person > 0)
			printf("���� : %s %d��\n",p[i]->name, p[i]->person);
		else
			printf("�������\n");
	}
}

// 15-5
void makeReserve(struct st_card* p[], int n){
	char name[20];
	struct st_card* rp; // ������ ī�巹�ڵ� ����ü�� �����Ͱ�
	int i, roomno, newperson;
  int error, index = -1; //�����ִ���, ��ݺθ� ���ǹ�ȣ�� �ε���

	printf("�����Ͻ� �� �̸���? >> ");
	scanf("%s", name);
	printf("���� �ο����� �Է��Ͻÿ�. >> ");
	scanf("%d", &newperson); 

  while(1){
    error = 0;
    printf("�����Ͻ� ���� ��ȣ��? >> ");
    scanf("%d", &roomno);

    for(i=0;i<n;i++){ //�ִ� ��ȣ�� �ε����� ����(������ �ʱⰪ�� -1)
      if(p[i]->no==roomno){
        index = i;
        break;
      }
    }

    if(index == -1){
      printf("����Ұ�(���ǹ�ȣ ����)\n");
      error = 1;
      continue;
    }


    if(p[index]->person != 0){
      printf("����Ұ�(����� ����)\n");
      error = 1;
      continue;
    }

    if(newperson > p[index]->capa){
      printf("����Ұ�(�ο� �ʰ�)\n");
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
	printf("����Ϸ�!\n");
}


// 15-6
void cancelReserve(struct st_card* p[], int n){
  char name[20];
	struct st_card* rp; // ��������� ī�巹�ڵ� ����ü�� �����Ͱ�
	int i, roomno, found = 0;;
  int yes; //��¥ ����Ұ��� 

  printf("���� ����Ͻ� ���� ��ȣ��? >> ");
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

    printf("���ǹ�ȣ / ��� / ������ / �����ο�\n");
    printf("%dȣ / %s / %s / %d��\n", rp->no, GRADE[rp->grade-1],rp->name, rp->person);

    printf("�� ������ ����ұ��? (YES 1, NO 0) >> ");
    scanf("%d", &yes);

    if(yes){
      rp->person = 0;
      strcpy(rp->name,"\0");
      printf("����߽��ϴ�.\n");
      return;
    }

  }else{
    printf("����� ������ �ƴմϴ�.\n");
  }


}


// 15-7
void findCards(struct st_card * p[], int n){
  char name[20];
  int count = 0;

  while(1){
    printf("�˻��Ϸ��� �� �̸��� 2���� �̻� �Է��ϼ���. >> ");
    scanf("%s", name);

    if(strlen(name) > 1){
      break;
    }else{
      printf("�� ���� �̻� �Է��ϼ���\n");
    }

  }

  printf("���ǹ�ȣ / ��� / ������ / �����ο� / �ִ��ο�\n");

  for(int i=0;i<n;i++){
		if(strstr(p[i]->name, name) != 0){
			printf("%dȣ / %6s / %s / %d�� / %d��\n", p[i]->no, GRADE[p[i]->grade-1],p[i]->name, p[i]->person, p[i]->capa);
			count ++;
		}
	}

  printf("%d�� �˻���\n", count);

}


// 15-8
void saveReport(struct st_card* p[], int n){
  int rooms[3] = {0}, checkInRooms[3] = {0}, checkInPpl[3] = {0}, blankPpl[3] = {0};//���� ��, ���ఴ�Ǽ�, �����, ���������ο�/ ��޺� 0,1,2


  for(int i=0; i<n; i++){ //�� �ѹ� ������ �ʿ��� ���� ���� 
    rooms[p[i]->grade-1]++; //�ش� ��� ���Ǽ� ++
    
    if(p[i]->person != 0){ //����Ǿ������� 
      checkInRooms[p[i]->grade-1] ++; //�ش� ��� ���ఴ�Ǽ� ++
      checkInPpl[p[i]->grade-1] += p[i]->person; //�ش� ��� �����++
    }else{//�ƴϸ� 
      blankPpl[p[i]->grade-1] += p[i]->capa; //���밡���ο�++
    }
		
	}


  FILE* file;
  file = fopen("rooms_report.txt", "w");

  fprintf(file, "���� ��Ȳ ����\n");
  for(int i = 0; i < 3; i ++){
    fprintf(file, "\n���ǵ�� : %s\n", GRADE[i]);
    fprintf(file, "1. ���� �� : �� %d�� �� %d�� ���� ��\n", rooms[i], checkInRooms[i]);
    fprintf(file, "2. ���� �� : �� %d��\n", checkInPpl[i]);
    fprintf(file, "3. ���� �ִ���� �� : �� %d��\n", blankPpl[i]);

  }

  fprintf(file, "\n���� ���� ���\nn");
	fprintf(file,"���ǹ�ȣ / ��� / �ִ��ο� / �����Ȳ\n");
	
	for(int i=0; i<n; i++){
		fprintf(file,"%dȣ / %s / %d�� / ", p[i]->no, GRADE[p[i]->grade-1], p[i]->capa);
		if(p[i]->person > 0)
			fprintf(file,"���� : %s %d��\n",p[i]->name, p[i]->person);
		else
			fprintf(file,"�������\n");
	}

  fprintf(file, "���� �ο� �հ� : %d��", (checkInPpl[0]+checkInPpl[1]+checkInPpl[2]));

  fclose(file);
  printf("����Ǿ����ϴ�.\n");

}	

//15-9
void findRoom(struct st_card* p[], int n){
  int person, grade;//�����ο��� 
  int count = 0; //�������� ���� �� 

  printf("���� �ο�����? >> ");
  scanf("%d", &person);

  printf("���Ͻô� ���� �����? (Deluxe 1, Luxury 2. Suite 3, ���� 0) >> ");
  scanf("%d", &grade);

  printf("���ǹ�ȣ / ��� / �ִ��ο�\n");

  for(int i=0; i<n; i++){ //�� �ѹ� ������ ���� �����ϸ� ��� 

    if(p[i]->capa >= person){

      if(p[i]->grade == grade || (grade == 0)){

        if(p[i]->person == 0){
          printf("%dȣ / %s / %d��\n", p[i]->no, GRADE[p[i]->grade-1], p[i]->capa);
          count++;
        }
      }
    }
  }
  printf("�� %d���� ������ ���� �����մϴ�.\n", count);
}

/*int no;		// ���ǹ�ȣ (3�ڸ� ����)
	int grade; // ���� ��� (1:deluxe, 2:luxury, 3:suite)
	int capa;		// �����ִ��ο� (2~10��)
	char name[20];	// ������ ����				
	int person;		// ���� �ο�*/
// 15-10
int addCards(struct st_card* p[], int n){
  p[n] = malloc(sizeof(struct st_card));
  int joong, yeon;

  while(1){
    joong = 0;
    yeon = 0;
    printf("�߰��� ���ǹ�ȣ��? >> ");
    scanf("%d", &p[n]->no);

    for(int i=0; i<n; i++){ //�� �ѹ� ������ �ߺ��˻� 
      if(p[i]->no == p[n]->no){
        joong = 1;
      }
      if((p[i]->no +1 == p[n]->no) || (p[i]->no -1 == p[n]->no)){
        yeon = 1;
      }

    }

      if(joong){
        printf("�̹� ��ϵ� ���ǹ�ȣ�Դϴ�.\n");
      }else if(!yeon){
        printf("�������� ���ǹ�ȣ�� �ƴմϴ�.\n");
      }else{
        break;
      }

  }

  printf("���ǵ��(Deluxe 1, Luxury 2. Suite 3)�� �ִ��ο��� �Է��ϼ��� >> ");
  scanf("%d %d", &p[n]->grade, &p[n]->capa);

  printf("������ �߰��Ͽ����ϴ�.\n");




	return n+1;
}
/*���ο� ���ǹ�ȣ�� �Է¹޴´�.
�� ���ǹ�ȣ�� �̹� ��ϵǾ� �ְų�, ���� ���ǹ�ȣ�� ���������� ����Ǵ� ��ȣ�� �ƴ� ��쿡�� ���� �޽����� ����ϰ� �ٽ� �Է¹޵��� �Ѵ�.
���� ��ް� �����ο��� �Է¹޾� ���� �߰��Ѵ�.*/


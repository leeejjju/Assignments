#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*�������̶�� �Ҹ��� ������ ��Ȱ������ �ܱ��� �л����� �����Ѵ�. �� ���� 2������ �Ǿ� ������, 1������ ���л�, 2������ ���л��� �����ϰ� �ȴ�. �� ������ 1ȣ�Ǻ��� 15ȣ�Ǳ��� 15���� 2��1���� ���� �ִ�.

�� ���α׷��� �������� �����ϴ� �л����� ������ �����Ѵ�. �����ϴ� ������ ������ ����. �л��̸�, ����(F or M), ���г⵵(2015~2018), ��ȣ��(101~215), ����(0~10)

�⺻������ ���α׷��� ���۵Ǹ� members.txt�κ��� 40���� ���������� �о�� �� (�ϼ� �ڵ� ����), 5���� �޴��� �����ϸ鼭 �ʿ��� ����� ����ȴ�.

[1] ��� - ������ ��� ���� ������ ȭ�鿡 ����Ѵ�. --> �� ����� �ڵ忡 �̹� �����Ǿ� �����Ѵ�. [2] ȣ�Ǻ��� - Ư�� �л��� ȣ���� �����Ѵ�. --> �� ����� �ڵ忡 �Ϻθ� �����Ǿ� �����Ѵ�. [3] �����ο� - Ư�� �л����� ������ 1�� �ΰ��Ѵ�. --> �� ����� ���� �����ؾ� �Ѵ�. [4] �˻� - �̸��� �Ϻ�(2�����̻�)������ ���������� �˻��Ѵ�. --> �� ����� �ڵ忡 �Ϻθ� �����Ǿ� �����Ѵ�. [5] ���� ���� - ������ ������ ��Ȳ�� ���Ͽ� �����Ѵ�. --> �� ����� ���� �����ؾ� �Ѵ�.

�������� : ���� ���� ��� �����ϱ�
������ ������� ���� ���Ͽ� �ؽ�Ʈ�� �����ϴ� ����� �����϶�. 

1. ��ü ������, ���� �л� �� 
2. ȣ�� ��Ȳ (ȣ�Ǻ� �ο��� 0��, 1��, 2������ ����) 
3. �й��� ��Ȳ (���г⵵�� 2015���� 2018���� 4������ �л� ��) 
4. ������� - ������ 7�� �̻��� �л� ���ڿ� ��� 
5. ���� ��� - listMembers()�Լ��� ���� ����
*/

struct Record{		// ��Ȱ���� ���� ���ڵ�
	char name[20];	// ����				
	char fm;		// ���� ('F' ����, 'M' ����)				
	int entry;		// ���г⵵ (4�ڸ� ����)
	int room;		// �� ȣ��
	int point;		// ����
};

int loadMembers(struct Record* p[]);		// ������� �б�
void listMembers(struct Record* p[], int n);	// ��� ���(����Ʈ)
void editRoom(struct Record* p[], int n);		// ȣ�� ����
void makePenalty(struct Record* p[], int n);	// ���� �ο�
void findMembers(struct Record* p[], int n);	// �˻� (�̸�)
void saveReport(struct Record* p[], int n);	// ���� ����

int main(){
	struct Record* members[100]; 	// �ִ� 100����� ������ �� �ִ� ������ �迭
	int count;	// �����ϵ� ���� ��
	int menu;	// �޴���ȣ
	count = loadMembers(members);	// ���� ���� ���Ϸκ��� ���� ����Ʈ�� ��� �о�´�.
	while(1)
	{
		printf("\n[1]��� [2]ȣ�Ǻ��� [3]�����ο� [4]�˻� [5]���� ���� [0]���� >> ");
		scanf("%d",&menu);	// �޴��� ����

		if(menu==1){
			listMembers(members, count);	// ��� ���
		}
		else if(menu==2){
			editRoom(members, count);	// ȣ�� ����
		}
		else if(menu==3){
			makePenalty(members, count); // ���� �ο�
		}
		else if(menu==4){
			findMembers(members, count);	// �˻�
		}
		else if(menu==5){
			saveReport(members, count);	// ���� ����
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
	printf("%d���� ����� ������ �о����ϴ�.\n",n);
	return n;
}

void listMembers(struct Record * p[], int n){
	int i;
	printf("\n��ü����Դϴ�.\n");
	printf("NO �̸� ���� �й� ȣ�� ����\n");
	
	for(i=0; i<n; i++){
		printf("%d %s [%c] %d %d %d\n", (i+1), p[i]->name, p[i]->fm, p[i]->entry, p[i]->room, p[i]->point);
	}
}

// 15-1 ����
void editRoom(struct Record* p[], int n){
	char name[20];
	struct Record* rp; // ������ ���ڵ� ����ü�� �����Ͱ�
	int i, found=0, newroom;
  int error, count; //������ �ֳ�����/ �ش� ��ȣ�ǿ� �� �л��� ���?

	printf("ȣ�� �����Ϸ��� �л� �̸���? >> ");
	scanf("%s", name);

	for(i=0;i<n;i++){
		if(strcmp(p[i]->name,name)==0){
			found=1;
			rp=p[i]; //�������� �������� ����Ű�°��� 
			break;
		}
	}

	if(found==1){
		printf("�̸� ���� �й� ȣ�� ����\n");
		printf("%s [%c] %d %d %d\n", rp->name, rp->fm, rp->entry, rp->room, rp->point);

    while(1){
      error = 0;
      count = 0;
      printf("���ο� ȣ���� �Է��Ͻÿ�. >> ");
      scanf("%d", &newroom); 

      if(!(newroom > 100 && newroom < 116)&&!(newroom > 200 && newroom < 216) ){
        printf("�����Ұ�(ȣ�� ����)\n");
        error = 1;
        continue;
      }

      if(rp->fm == 'M' && (newroom > 100 && newroom < 116)){
        printf("�����Ұ�(�� ����)\n");
        error = 1;
        continue;
      }else if(rp->fm == 'F' && (newroom > 200 && newroom < 216)){
        printf("�����Ұ�(�� ����)\n");
        error = 1;
        continue;
      }

      //��� ������ �� ȣ�ǿ� ���� �л� ��� �����... 
      for(i=0;i<n;i++){ 
        if(p[i]->room == newroom){
          count ++;
        }
      }

      if(count == 2){
        printf("�����Ұ�(�ο��ʰ�)\n");
        error = 1;
        continue;
      }

      if(error == 0){ //�ƹ��� �������� �Ȱɸ��� Ż�� 
        break;
      }

    }

		rp->room = newroom;
		printf("�����Ϸ�!\n");
	}
	else{
		printf("���� �л��Դϴ�.\n");
	}
}

// 15-2
void makePenalty(struct Record* p[], int n){
  char name[20];
	struct Record* rp; // ������ ���ڵ� ����ü�� �����Ͱ�
	int i, found=0;
  int yes; //���� �ο��Ұų� 


  printf("���� �ο��� �л� �̸���? >> ");
  scanf("%s", name);

	for(i=0;i<n;i++){
		if(strcmp(p[i]->name,name)==0){
			found=1;
			rp=p[i]; //�������� �������� ����Ű�°��� 
			break;
		}
	}

  if(found == 1){

    printf("�̸� ���� �й� ȣ�� ����\n%s [%c] %d %d %d\n", rp->name, rp->fm, rp->entry, rp->room, rp->point);
    printf("�� �л����� ������ �ο��ұ��? (YES 1, NO 0) >> ");
    scanf("%d", &yes);

    if(yes){
      rp->point ++;
      printf("%s �л��� ������ %d���Դϴ�.\n", rp->name, rp->point);

    }else{
      return;
    }

  }else{
    printf("���� �л��Դϴ�.\n");
  }

}

// 15-3
void findMembers(struct Record * p[], int n){
	int i, count=0;
	char name[20];
	while(1){
		printf("�˻��Ϸ��� �л� �̸��� 2���� �̻� �Է��ϼ���. >> ");
		scanf("%s", name);
		if(strlen(name) > 1) break;
	}

  printf("NO �̸� ���� �й� ȣ�� ����\n");

	for(i=0;i<n;i++){
		if(strstr(p[i]->name,name)!=0){
			printf("%d %s [%c] %d %d %d\n", i+1, p[i]->name, p[i]->fm, p[i]->entry, p[i]->room, p[i]->point); 
      count ++;
		}
	}

  printf("%d�� �˻���\n", count);

}


// 15-4
void saveReport(struct Record* p[], int n){
  int rooms[2][15] = {0};//�� ȣ�ǿ� �ִ� �л���
  int entry; //�й� 
  int entryNum[4] = {0}; //15�й�-18�й����� �л��� 
  int warn = 0, index[40]={0}; //������� �л���, �л���ȣ 
  
	FILE* file;
	file = fopen("report.txt","wt");


  fprintf(file, "������ ��Ȳ ����\n");
  fprintf(file, "1. �����л� �� : 40�� (�� 20��, �� 20��)\n");

 	for(int i=0; i<n; i++){
		rooms[p[i]->room/100-1][p[i]->room%100-1] ++; //�ش� �� �ο���+

    entry = p[i]->entry-2000; //�й� �������� 
    if(entry == 15) entryNum[0] ++;
    if(entry == 16) entryNum[1] ++;
    if(entry == 17) entryNum[2] ++;
    if(entry == 18) entryNum[3] ++;

    if(p[i]->point >6){ //����������� �Ǵ�, ���� 
      index[warn] = i;
      warn++;
    }

	} 

  fprintf(file, "\n2. ȣ�� ��Ȳ\n");
  fprintf(file, " 1) ���� : ");
  for(int i=0; i<2; i++){
    for(int j = 0; j < 15; j++){
      if(rooms[i][j] == 0){
        fprintf(file, "%d%02d ", i+1, j+1);
      }
    }
	}

  fprintf(file, "\n 2) 1�ν� : ");
  for(int i=0; i<2; i++){
    for(int j = 0; j < 15; j++){
      if(rooms[i][j] == 1){
        fprintf(file, "%d%02d ", i+1, j+1);
      }
    }
	}

  fprintf(file, "\n 3) 2�ν� : 1");
  for(int i=0; i<2; i++){
    for(int j = 0; j < 15; j++){
      if(rooms[i][j] == 2){
        fprintf(file, "%d%02d ", i+1, j+1);
      }
    }
	}

  fprintf(file, "\n3. �й��� ��Ȳ\n");
  fprintf(file, " 1) 2015�й� : %d��\n", entryNum[0]);
  fprintf(file, " 2) 2016�й� : %d��\n", entryNum[1]);
  fprintf(file, " 3) 2018�й� : %d��\n", entryNum[2]);
  fprintf(file, " 4) 2019�й� : %d��\n", entryNum[3]);

  fprintf(file, "\n4. �������(7�� �̻�) : %d��\n", warn);
  for(int i = 0; i < warn; i++){
    fprintf(file, "%s(%d)", p[index[i]]->name, p[index[i]]->point);
  }
  
  fprintf(file, "\n\n5. ���� ���\n");
	fprintf(file, "NO �̸� ���� �й� ȣ�� ����\n");
	
	for(int i=0; i<n; i++){
		fprintf(file, "%d %s [%c] %d %d %d\n", (i+1), p[i]->name, p[i]->fm, p[i]->entry, p[i]->room, p[i]->point);
	}

	fclose(file);
  printf("����Ǿ����ϴ�.\n");
}	
/*1. ��ü ������, ���� �л� �� 
2. ȣ�� ��Ȳ (ȣ�Ǻ� �ο��� 0��, 1��, 2������ ����) 
3. �й��� ��Ȳ (���г⵵�� 2015���� 2018���� 4������ �л� ��) 
4. ������� - ������ 7�� �̻��� �л� ���ڿ� ��� 
5. ���� ��� - listMembers()�Լ��� ���� ����*/


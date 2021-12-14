// �й� : 22100579
// �̸� : ������
//�� �����ִ� �ϳ��԰� ��� �տ��� �̹� �ڵ� �׽�Ʈ�� �����ϰ� �����ϰ� �ֽ��ϴ�.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char kname[2][10] = {"Grade", "P/F"}; // �򰡹�� ǥ�� ���ڿ�
// �̹� ������ �Լ�
int loadData(char names[50][30], int units[50], int kinds[50]); // ���Ͽ��� ���� ����� �о�´�.
void printAllClasses(char names[50][30], int units[50], int kinds[50], int size); // ��ü ���� ����� ����Ѵ�.


// �����ؾ� �ϴ� �Լ�
void selectMy5Classes(int my[5], int range); // �� �������� 5�� ���� ����ϱ�
void printMyClasses(int my[5], char names[50][30], int units[50], int kinds[50]); // �� �������� ����ϱ�
void saveReport(int my[5], char myg[5][10], char names[50][30], int units[50], int kinds[50]); // ����ǥ ������ ����� �����Ѵ�.


// �߰��� ���� �Լ��� ������ ���⿡ ���� ��!
float getPoint(char g[10]);

int main(void) {

	int no;	// �۾���ȣ 
	char cnames[50][30]; // ��ü �����̸� (�ִ� 10��)
	int kinds[50]; // ��ü ���� ������ (�ִ� 10��, 1:Grade, 2:P/F)
	int units[50]={0}; // ��ü ���� ���� ��

	int myclass[5]; // �� �������� ��� (�ִ� 5����)
	char mygrades[5][10]; // �� �������� ��� ���� (A+,A0,B+,B0,C+,C0,D+,D0,F,P)
	int myscores[5]; // �� ���� ���

  //------------------------------------------------------------

	srand(time(0));
  
	int count = loadData(cnames, units, kinds);
	printf("%d���� �������� ������ �о����ϴ�.\n", count);
	printAllClasses(cnames, units, kinds, count);

	while(1){

		printf("\n[�۾�] 1.���������� 2.�����Է� 3.�������˻� 4.����ǥ���� 0.����\n");
		printf("�۾� ��ȣ��? > ");
		scanf("%d", &no);

		if(no == 1){ 
			printf("1.����������\n");
			selectMy5Classes(myclass, count);
			printf("5���� ������ ��������Ͽ����ϴ�.\n");
			printMyClasses(myclass, cnames, units, kinds);
		}
		else if(no == 2){
			printf("2.�����Է�\n");
			for(int i=0; i<5; i++){
				int classno = myclass[i];
				printf("%d. %s [%d���� - %s] ", i+1, cnames[classno], units[classno], kname[kinds[classno]-1]);
				if(kinds[classno]==1){
					printf("������? (A+,A0,B+,B0,C+,C0,D+,D0,F) > ");
					scanf("%s", mygrades[i]);
				}
				else{
					printf("������? (P,F) > ");
					scanf("%s", mygrades[i]);
				}
			}
		}
		else if(no == 3){
			printf("3.�������˻�\n");
			printf("�˻��� ���� �̸���? > ");
			char str[30];
			scanf("%s", str);
			int count=0;
			for(int i=0; i<5; i++){
				int classno = myclass[i];
				if(strstr(cnames[classno], str)){
					printf("%s [%d����] ���� : %s\n", cnames[classno], units[classno], mygrades[i]);
					count++;
				}
			}
			printf("%d�� ������ ã�ҽ��ϴ�.\n", count);
		}
		else if(no == 4){
			printf("4.����ǥ����\n");
			saveReport(myclass, mygrades,cnames, units, kinds);
			printf("\nreport.txt�� ����ǥ�� �����߽��ϴ�.\n");
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
	printf("��ü ����\n");
	for(int i=0; i<size; i++){
		printf("%d. %s [%d���� - %s]\n",i+1, names[i], units[i], kname[kinds[i]-1]);
	}
}

/////////// �Ʒ� �Լ��� ���� ������ ��! ////////////////

//�� �������� ����ϱ�
void printMyClasses(int my[5], char names[50][30], int units[50], int kinds[50]){
  //0. �� ��������\n'' ��� 
  printf("�� ��������\n");
  //1. ���ϸ� �ټ��� �ݺ�...
  for(int i = 0; i < 5; i++){
    //1-1 (������ȣ). (�����̸�) [(������)���� - (�򰡹��)]\n)
    printf("%d. %s [%d���� - %s]\n", i+1, names[my[i]], units[my[i]], kname[kinds[my[i]]-1]);
  }
}
/*ex) 5���� ���������� ��������Ͽ����ϴ�.
�� ��������
1. �����̸� [n���� - �򰡹��]


}
//�Ķ���� : �� ���������ȣ�迭, ��ü�����̸��迭, ��ü�����������迭, ��ü�����򰡹�Ĺ迭
//���ϰ� : ����
//�ϴ� �� : ��ü������ ������ ����ִ� �迭 3���� �����ؼ� ���� �����ϴ� 5�� ���� ������ ����Ѵ�.

/*
0. �� ��������\n'' ��� 
1. ���ϸ� �ټ��� �ݺ�...
  1-1 (������ȣ). (�����̸�) [(������)���� - (�򰡹��)]\n)
*/

/*ex) 5���� ���������� ��������Ͽ����ϴ�.
�� ��������
1. �����̸� [n���� - �򰡹��]
... */

//------------------------------------------------------------

//�� �������� 5�� ���� ����ϱ�
void selectMy5Classes(int my[5], int range){

  //0. count = 0, joong = 0;
  int count = 0, joong = 0; 
  //1. ���ϸ� ���ѹݺ�... 
  while(1){
    //1-1 my�迭�� rand�Լ��� ����ؼ� (Ư�� ��������) ���� �ϳ� �Է¹޽��ϴ�.
    my[count] = rand()%(range);
    //1-2 ��� �Է¹��� ���� ���� ����� �ߺ��Ǵ����� üũ(for))
    for(int i; i < count; i++){
      if(count != 0 && my[i] == my[count]){
        joong = 1;
        break;
      }
      //1-2-1 �ߺ��Ǹ� joong = 1, break;
    }
    //1-3  ���� �ߺ��� ���¸�(joong = 1) >> joong = 0;
    if(!joong){
      count++;
      joong = 0;

    }
      //1-3-2 �ߺ��� �ƴϸ� joong=0 >> count++
    
    //1-4 ī��Ʈ�� 5 �̻��̸� return; 
    if(count >= 5) break;
  }
}
//�Ķ���� : �� ���������� ��ȣ 5���� ������ �迭, ��ü ������ ����
//���ϰ� : ����
//�ϴ� �� : ��ü ������ ������ ���� �����ȣ(0~����-1) �߿� �ߺ����� �ʴ� 5���� ��ȣ�� ���Ƿ� ��� my �迭�� �ִ´�.
/*
0. count = 0, joong = 0;
1. ���ϸ� ���ѹݺ�... 
  1-1 my�迭�� rand�Լ��� ����ؼ� (Ư�� ��������) ���� �ϳ� �Է¹޽��ϴ�.
  1-2 ��� �Է¹��� ���� ���� ����� �ߺ��Ǵ����� üũ(for))
    1-2-1 �ߺ��Ǹ� joong = 1, break;
  1-3  ���� �ߺ��� ���¸�(joong = 1) >> joong = 0;
    1-3-2 �ߺ��� �ƴϸ� joong=0 >> count++
  
  1-4 ī��Ʈ�� 5 �̻��̸� return; 

*/

//------------------------------------------------------------

void saveReport(int my[5], char myg[5][10], char names[50][30], int units[50], int kinds[50]){

  //0. ��ü���� ����=0, �������� ���� =0, �׷��̵����� = 0, float �������� sum = 0, ave 
  int apoint = 0, point = 0, gpoint = 0;
  float sum = 0, ave;

  //1. ���� �ڵ鷯 ����, ���� ������� ����
  FILE* file;
  file = fopen("report.txt", "w");

  //2. ���Ͽ� ���� ����Ʈ
    //2-1 "����ǥ\n"
    fprintf(file, "����ǥ\n");

    //2-2 ���� 5�� �ݺ�...
    for(int i = 0; i < 5; i++){
      //2-2-1 "(����). (�����̸�) [(������)���� - (�򰡹��)] - (����)"
      fprintf(file, "%d. %s [%d���� - %s] - %s\n", i+1, names[my[i]], units[my[i]], kname[kinds[my[i]]-1], myg[i]);
      //2-2-2 ��ü���� += (������)
      apoint += units[my[i]];
      //2-2-3 (myg �� F�� �ƴ϶�� )�������� +=(������)
      if(strcmp(myg[i], "F")){
        point += units[my[i]];
      }
      //2-2-4 (�׷��̵��� )
      if(kinds[my[i]] == 1){
        //2-2-4-1 sum+= (��޿� ����)���� ���� * (������)
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
        //2-2-4-2 �׷��̵����� += (������)
        gpoint += units[my[i]];
      }
    }

    //2-3 "��� ���� : n / n"
    fprintf(file, "��� ���� : %d / %d\n", point, apoint);
    //2-4 (ave�� �Է�) "���� ��� : .2f" 
    if(gpoint == 0){
      ave = 0.0;
      //printf("������ջ�����!!");
    }else{
      ave = sum/gpoint;
      //printf("%d, %f", gpoint, sum);
    }
    fprintf(file, "���� ��� : %.2f\n", ave);
  //3. ���� �ݱ� 
  fclose(file);
}
//�Ķ���� : �����������ȣ�迭, ���������������迭, ��ü�����̸��迭, ��ü�����������迭, ��ü�����򰡹�Ĺ迭
//���ϰ� : ����
//�ϴ� �� : ��ü������ ������ ����ִ� �迭 3���� �����ؼ� ���� �����ϴ� 5�� ������ ��ȣ, ������ ����Ͽ� ����ǥ�� ����� report.txt ���Ϸ� �����Ѵ�.

/*
0. ��ü���� ����=0, �������� ���� =0, �׷��̵����� = 0, float �������� sum = 0, ave 
1. ���� �ڵ鷯 ����, ���� ������� ����
2. ���Ͽ� ���� ����Ʈ
  2-1 "����ǥ\n"
  2-2 ���� 5�� �ݺ�...
    2-2-1 "(����). (�����̸�) [(������)���� - (�򰡹��)] - (����)"
    2-2-2 ��ü���� += (������)
    2-2-3 (myg �� F�� �ƴ϶�� )�������� +=(������)
    2-2-4 (�׷��̵��� )
      2-2-4-1 sum+= (��޿� ����)���� ���� * (������)
      2-2-4-2 �׷��̵����� += (������)

  2-3 "��� ���� : n / n"
  2-4 (ave�� �Է�) "���� ��� : .2f" 
3. ���� �ݱ�  

*/

/*1. P/F ������ ��������� ����� �� ������� �ʾƵ� �˴ϴ�. 
2. �׷��̵� ������ �� ������ ������ ������ ���ؼ� �� ���� �� �� �׷��̵� �������� ���� �ֽø� �˴ϴ�.

����)
���� 1 (3����)- Grade : A+
���� 2 (2����)- P/F : P
���� 3 (3����)- Grade : A
���� 4 (1����)- Grade : F
���� 5 (2����)- P/F : F
���� ��� = (4.5 * 3 + 4.0 * 3 + 1.0 * 0) / (3+3+1) = 3.64
*/

/*ex) ����ǥ
1. �����̸� [n���� - �򰡹��] - ���� 
...

��� ���� : n / n
���� ��� : .2f */

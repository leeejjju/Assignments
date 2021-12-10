#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*�л� 5���� ����, ����, ���� ������ 50~100 ������ ������ ���Ƿ� ����� ������ �Ŀ�, ���� �׸���� ����Ͽ� ����϶�.

��, ������ main() �Լ� �ڵ带 �������� �Լ� ���븸 �ۼ��϶�.*/


void evalClass(int j[5][3], int i, int* s, float* a);
void evalStudent(int j[5][3], int i, int* s, float* a, char* g);

int main(void) {
  int jumsu[5][3];        // 5���� 3���� ������ �����ϰ� �ִ� 2���� �迭 
  char classname[3][20]={"����","����","����"};
  int sum = 0;                //���������
  float avg;              // ��������
  char grade;             // ��������
  int i, j;               // �ݺ����� ���� ����

  srand(time(0)); 
  for(i=0;i<5;i++)
    for(j=0;j<3;j++)
      jumsu[i][j] = rand()%50+51;

  printf("5���� �л� ������ �����Ǿ����ϴ�.\n"); 
  for(i=0;i<5;i++){
    printf("%d�� �л� : ",i+1); 
    for(j=0;j<3;j++){
      printf("%s %d", classname[j], jumsu[i][j]); 
      if(j<2) printf(", ");
      else printf("\n");
    } 
  }

  printf("1) �� ���� ������ �������\n"); 
  for(i=0;i<3;i++){
    evalClass(jumsu, i, &sum, &avg);
    printf("%s ������ ������ %d ����� %.1f\n",classname[i],sum,avg);
    sum = 0;
  }

  printf("2) �� �л��� ������ �������, ��տ� ���� ���\n"); 
  for(i=0;i<5;i++){
    evalStudent(jumsu, i, &sum, &avg, &grade);
    printf("%d�� �л��� ������ %d ����� %.1f(��� %c)\n",i+1,sum,avg,grade); 
    sum = 0;
  }
  
  return 0; 
}


void evalClass(int j[5][3], int i, int* s, float* a){
  int k;
  for(k = 0; k < 5; k++){
     *s += j[k][i];
  }
  *a = *s / 5;
}
//�Ķ���� : �����迭(j)�� �����ȣ(i=0,1,2), ������ ������ �����ͺ���(s), ����� ������ �����ͺ���(a)
//���೻�� : �����迭�� �����ȣ�� �޾Ƽ�, ������ ����� ����� ������ ������ ����Ͽ� ������



void evalStudent(int j[5][3], int i, int* s, float* a, char* g){
  int k;
  for(k = 0; k < 3; k++){
     *s += j[i][k];
  }
  *a = *s / 3;

  if(*a >= 90){
    *g = 'A';
  }else if(*a >= 80){
    *g = 'B';
  }else if(*a >= 70){
    *g = 'C';
  }else if(*a >= 60){
    *g = 'D';
  }else{
    *g = 'F';
  }

}

//�Ķ���� : �����迭(j)�� �л���ȣ(i=0,1,2,3,4),������ ������ �����ͺ���(s), ����� ������ �����ͺ���(a), ����� ������ �����ͺ���(g)
//���೻�� : �����迭�� �����ȣ�� �޾Ƽ�, ������ ���, ����� ����� ������ ������ ����Ͽ� ������


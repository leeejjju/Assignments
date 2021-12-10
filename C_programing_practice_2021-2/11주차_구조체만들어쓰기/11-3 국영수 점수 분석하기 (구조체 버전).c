#include <stdio.h>
/*����ü �迭�� ����Ͽ�, ����Ÿ ���Ϸκ��� �л� 5���� ����, ����, ���� ������ �Է¹޾� ���� �׸���� ����Ͽ� ����϶�.
1) �� ���� ������ ��� ����
2) �� �л��� ������ �������, ��տ� ���� ��� ����� ������ ���� �������� �����϶�.
��� 90�̻� : A
��� 80�̻� ~ 90�̸� : B
��� 70�̻� ~ 80�̸� : C
��� 60�̻� ~ 70�̸� : D
��� 60�̸� : F*/

/*
1. ���Ϸκ��� ������ �Է¹޾� ����ü�� ����, �������� 
  1-1 ���� ����
  1-2 ���� 5ȸ ����
    1-2-1 ���Ͽ��� ���� �о ����ü�� ����
    1-2-2 �Լ� ȣ���Ͽ� ������ ���, ��� ����ü�� ����
2. �Լ� ȣ���Ͽ� ���� ���� ������ ����
3. ���� ���, �л��� ��� ����ϱ� 

*/

struct st_jumsu{
  int kor, eng, mat;
  int sum;
  float avg;
  char grade;
};

void sumClass(struct st_jumsu p[], int* sum, float* avg, int i);
void evalStudent(struct st_jumsu* p);

int main(void) {
  struct st_jumsu p[5];

  FILE* data;
  data = fopen("data.txt", "r");

  for(int i=0; i<5; i++){
    fscanf(data, "%d %d %d", &p[i].kor, &p[i].eng, &p[i].mat);
    evalStudent(p+i);
  }

  //�̰��� �ڵ� �ۼ� 

  for(int i = 0; i < 5; i++){
    printf("%d�� �л� : ���� %d, ���� %d, ���� %d\n", i+1, p[i].kor, p[i].eng, p[i].mat);
  }

  int sum;
  float avg;
  char subject[3][10] = {"����", "����","����"};

  printf("1) �� ���� ������ �������\n");
  for(int i=0; i<3; i++){
    sumClass(p, &sum, &avg, i);
    printf("%s ������ ������ %d ����� %.1f\n", subject[i], sum, avg);
  }

  printf("2) �� �л��� ������ �������, ��տ� ���� ���\n");
  for(int i = 0; i < 5; i++){
    printf("%d�� �л��� ������ %d ����� %.1f(��� %c)\n", i+1, p[i].sum, p[i].avg, p[i].grade);
  }
  
  return 0;
}


void sumClass(struct st_jumsu p[], int* sum, float* avg, int i){
  int n = 0;

  for(int j = 0; j < 5; j++){
    if(i == 0){
      n += p[j].kor;
    }else if(i == 1){
      n += p[j].eng;
    }else if(i == 2){
      n += p[j].mat;
    }
  }
  *sum = n;

  float a = (float)n/5.00;
  *avg = a;

}
// �Ķ���� : p : ����ü �迭, sum : ���� ���� ������, avg : ��� ���� ������, i : 0,1,2 (������ ����) 
// ���ϰ� : ����
// ���೻�� : ����ü �迭 ���� �ش� ����(i)�� ��� ������ ������ ����� ����Ͽ� ������ ������ ���� ���� ����

void evalStudent(struct st_jumsu* p){
  float n = 0;

  n += p->kor;
  n += p->eng;
  n += p->mat;
  p->sum = n;

  n = (float)n / 3.0;
  p->avg = n;

  if(n < 60){
    p->grade = 'F';
  }else if(n < 70){
    p->grade = 'D';
  }else if(n < 80){
    p->grade = 'C';
  }else if(n < 90){
    p->grade = 'B';
  }else{
    p->grade = 'A';
  }

}
// �Ķ���� : ����ü ������
// ���ϰ� : ����
// ���೻�� : �л��� ���� ����ü �����͸� �޾� ������ ���, ��� ����Ͽ� ����

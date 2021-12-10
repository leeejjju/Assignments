#include <stdio.h>
#include <stdlib.h>
/*����ü�� ����Ͽ�, ����, ����, ���� ������ �Է¹޾� ������ ��� ����, ����� ����Ͽ� ����϶�.

��, ����ü ������ �������� ����, ����ü �����͸� �����Ͽ� �������� �޸𸮸� �Ҵ�޵��� �϶�.

����� ������ ���� �������� �����϶�.
��� 90�̻� : A
��� 80�̻� ~ 90�̸� : B
��� 70�̻� ~ 80�̸� : C
��� 60�̻� ~ 70�̸� : D
��� 60�̸� : F*/

struct st_jumsu{
 int kor, eng, mat;
 int sum;
 float avg;
 char grade;
};

struct st_jumsu* getScore();
void evalScore(struct st_jumsu* p);


//������ �ڵ�, main() ���� ����
int main(){
	struct st_jumsu* score = getScore();
	evalScore(score);
	printf("�л��� ������ %d ����� %.1f (��� %c)\n",score->sum, score->avg, score->grade);
	return 0;
}

struct st_jumsu* getScore(){

  struct st_jumsu* p;
  p = malloc(sizeof(struct st_jumsu));

  printf("���� ����? > ");
  scanf("%d", &p->kor);
  printf("���� ����? > ");
  scanf("%d", &p->eng);
  printf("���� ����? > ");
  scanf("%d", &p->mat);

  return p;
}
// ���೻�� : ���� ����ü�� �����޸��Ҵ�ް� �л��� ����, ����, ���� ������ �Է¹޾� ����ü �����͸� ������

void evalScore(struct st_jumsu* p){
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
// ���೻�� : ����ü �����͸� �޾� �л��� ������ ���, ��� ����Ͽ� ����

#include <stdio.h>
#include <stdlib.h>
/*����ü�� ����Ͽ�, 5���� ����, ����, ���� ������ �Է¹޾� ���� ����, ��� �� �л��� ������ ��� ����, ����� ����Ͽ� ����϶�.
������ �Է��ϴ� ������ �Լ��� ���� �������� �޸𸮸� �Ҵ�޾� �����ϵ��� �϶�.
�� �л��� ������ ���, ��� ����� �Լ��� �����Ͽ� �����ϵ��� �϶�.

����� ������ ���� �������� �����϶�.
��� 90�̻� : A
��� 80�̻� ~ 90�̸� : B
��� 70�̻� ~ 80�̸� : C
��� 60�̻� ~ 70�̸� : D
��� 60�̸� : F

������ �ڵ� main() ��������*/

struct st_jumsu{
    int kor, eng, mat;
    int sum;
    float avg;
    char grade;
};

struct st_jumsu* getJumsu();
void evalScore(struct st_jumsu* p);

int main()
{
    struct st_jumsu* jumsu[5]; // 5���� ���� ����� ������ �迭 
    for(int i=0;i<5;i++){
        printf("%d�� �л�\n", i+1);
        jumsu[i] = getJumsu();
		    evalScore(jumsu[i]);
    }

    for(int i = 0; i < 5; i++){
      printf("%d�� �л��� ������ %d ����� %.1f(��� %c)\n", i+1,jumsu[i]->sum, jumsu[i]->avg, jumsu[i]->grade);
    }
    return 0;
}

struct st_jumsu* getJumsu(){
  struct st_jumsu* p;
  p = malloc(sizeof(struct st_jumsu));

  printf("����, ����, ���� ������ �Է��Ͻÿ�. > ");
  scanf("%d %d %d", &p->kor, &p->eng, &p->mat);

  return p;
}
// ���೻�� : �������� �޸𸮸� �Ҵ���� ����ü ���� ����, ����, ���� ������ �Է¹޾� �����ϰ� �� ����ü�� �����͸� ������

void evalScore(struct st_jumsu* p){

  p->sum = p->kor + p->eng + p->mat;
  p->avg = p->sum / 3.0;

  if(p->avg < 60){
    p->grade = 'F';
  }else if(p->avg < 70){
    p->grade = 'D';
  }else if(p->avg < 80){
    p->grade = 'C';
  }else if(p->avg < 90){
    p->grade = 'B';
  }else{
    p->grade = 'A';
  }

}
// �Ķ���� : ����ü ������
// ���ϰ� : ����
// ���೻�� : ����ü �����͸� �޾� �л��� ������ ���, ��� ����Ͽ� ����

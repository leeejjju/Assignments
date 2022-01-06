#include <stdio.h>
#include <stdlib.h>
/*������ ���Ϸκ��� �л����� ����, ����, ���� ������ �Է¹޾� ���� �׸���� ����Ͽ� ����϶�.
1) �� ���� ������ ��� ����
2) �� �л��� ������ �������, ��տ� ���� ���

���Ϸκ��� ������ �о�ͼ� ����� ������ ������ �Լ��� ���� �������� �޸𸮸� �Ҵ�޾� �����϶�.
�л��� ������ ���, ��� ������Լ��� �����Ͽ� ����϶�.
���� ������ ��� ����� �Լ��� �����Ͽ� ����϶�.

����� ������ ���� �������� �����϶�.
��� 90�̻� : A
��� 80�̻� ~ 90�̸� : B
��� 70�̻� ~ 80�̸� : C
��� 60�̻� ~ 70�̸� : D
��� 60�̸� : F

������ �ҽ� main() ���� ����*/

struct st_jumsu{
    int kor, eng, mat;
    int sum;
    float avg;
    char grade;
};

int loadJumsu(struct st_jumsu* p[], char* filename);
void evalScore(struct st_jumsu* p);
void evalClass(struct st_jumsu* p[], int sum[], float avg[],int count);

int main()
{
    struct st_jumsu* jumsu[10]; 	// �ִ� 10���� ���� ����� ������ �迭 
    int count; // ���� ����
    int classsum[3]; 			// ���� ����
    float classavg[3]; 			// ���� ���
    char classname[3][20]={"����","����","����"};
    count = loadJumsu(jumsu, "data.txt");
    for(int i=0;i<count;i++)
        evalScore(jumsu[i]);
    evalClass(jumsu, classsum, classavg, count);
    printf("1) �� ���� ������ �������\n");
    for(int i=0;i<3;i++)
        printf("%s ������ ������ %d ����� %.1f\n", classname[i],classsum[i], classavg[i]);
    printf("2) �� �л��� ������ �������, ��տ� ���� ���\n");
    for(int i=0;i<5;i++)
        printf("%d�� �л��� ������ %d ����� %.1f(��� %c)\n", i+1,jumsu[i]->sum, jumsu[i]->avg, jumsu[i]->grade);
    return 0;
}

int loadJumsu(struct st_jumsu* p[], char* filename){
  int count = 0;

  FILE* file;
  file = fopen(filename, "r");

  while(!feof(file)){
    p[count] = malloc(sizeof(struct st_jumsu));
    int r = fscanf(file, "%d %d %d", &p[count]->kor,  &p[count]->eng,  &p[count]->mat);
    if(r < 3){
      break;
    }else{
      count++;
    }
  }

  fclose(file);
  printf("%d���� ������ �о����ϴ�.\n", count);
  return count;
}
// �Ķ���� : ��������� ������ ����ü ������ �迭, ���������� �̸�
// ���ϰ� : ���� ���� �迭
// ���೻�� : ������ �����鼭 ���� ����ü�� ���� �޸� �Ҵ��� ���� ����� ����, ����, ���� ������ �Է¹޾� ������ ��, ���� ��������� ������ ������

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
// �Ķ���� : �л��� ���� ����ü ������
// ���ϰ� : ����
// ���೻�� : ����ü �����͸� �޾� �л��� ������ ���, ��� ����Ͽ� ����

void evalClass(struct st_jumsu* p[], int sum[], float avg[], int count){

  sum[0] = sum[1] =sum[2] =0;

  for(int i = 0; i < count; i++){
    sum[0] += p[i]->kor;
    sum[1] += p[i]->eng;
    sum[2] += p[i]->mat;
  }
  
  for(int i = 0; i < 3; i++){
    avg[i] = sum[i]/count;
  }
  
}
// �Ķ���� : �������(����ü ������ �迭), ���� ���� �迭, ���� ��� �迭, �л��� 
// ���ϰ� : ����
// ���೻�� : ��������� �޾� 3���� ���� ������ ����� ����Ͽ� �����Ѵ�.

#include<stdio.h>
#include<stdlib.h>
#include <time.h>
/*�л� 5���� ����, ����, ���� ������ 50~100 ������ ������ ���Ƿ� ����� ������ �Ŀ�, ���� �׸���� ����Ͽ� ����϶�.

1) �� ���� ������ ��� ����

2) �� �л��� ������ �������, ��տ� ���� ���

����� ������ ���� �������� �����϶�.

��� 90�̻� : A

��� 80�̻� ~ 90�̸� : B

��� 70�̻� ~ 80�̸� : C

��� 60�̻� ~ 70�̸� : D

��� 60�̸� : F*/

int main(void){
  int jumsu[5][3];            // 5���� 3���� ������ �����ϰ� �ִ� 2���� �迭 
  char classname[3][20]={"����","����","����"};
  int sum_student[5] = {0};         // �л��� ����
  float average_student[5];   // �л��� ���
  char grade[5];              // �л��� ��� 
  int sum_class[3] = {0};           // ���� ����
  float average_class[3];     // ���� ���
  int i, j; //�󺹹� ������ ���� ���� 

  srand(time(0)); //�õ� �ʱ�ȭ 

  //��� ��� 

  printf("5���� �л� ������ �����Ǿ����ϴ�.\n");
  for(i = 0; i <5; i++){
    printf("%d�� �л� : ", i+1);

    for(j = 0; j < 3; j++){//�� �л��� ���� ���� �� �迭�� ����(����-����-���� �� )
      jumsu[i][j] = 50+ rand()%50+1;
      sum_class[j] += jumsu[i][j];
      sum_student[i] += jumsu[i][j];
    }

    printf("���� %d, ���� %d, ���� %d\n", jumsu[i][0], jumsu[i][1], jumsu[i][2]);
  }

  printf("1) �� ���� ������ �������\n");
  for(i = 0; i < 3; i++){
    average_class[i] = sum_class[i] / 5;
    printf("%s ������ ������ %d ����� %.1f\n", classname[i], sum_class[i], average_class[i]);
  }


  printf("2) �� �л��� ������ �������, ��տ� ���� ���\n");
  for(i = 0; i < 5; i++){

    average_student[i] = sum_student[i] / 3;

    if(average_student[i] >= 90){
      grade[i] = 'A';
    }else if(average_student[i] >= 80){
      grade[i] = 'B';
    }else if(average_student[i] >= 70){
      grade[i] = 'C';
    }else if(average_student[i] >= 60){
      grade[i] = 'D';
    }else{
      grade[i] = 'F';
    }

    printf("%d�� �л��� ������ %d ����� %.1f(��� %c)\n", i+1, sum_student[i], average_student[i], grade[i]);
  }


  return 0;
}

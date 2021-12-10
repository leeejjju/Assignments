#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*�л� 5���� ����, ����, ���� ������ 50~100 ������ ������ ���Ƿ� ����� ������ �Ŀ�, ���� �׸���� ����Ͽ� ����϶�.

1) �� ���� ������ ��� ����

2) �� �л��� ������ �������, ��տ� ���� ���

����� ������ ���� �������� �����϶�. ��� 90�̻� : A

��� 80�̻� ~ 90�̸� : B

��� 70�̻� ~ 80�̸� : C

��� 60�̻� ~ 70�̸� : D ��� 60�̸� : F

������ ���� �Լ��� ����� ����϶�  ...*/

int classsum(int s[5][3], int classnum){ //���� ����

  int i, j;
  int sum = 0;
  for(i = 0; i < 5; i++){
     sum += s[i][classnum];
  }
  return sum;
}
// �Ķ���� : �����迭(s)�� �����ȣ(0,1,2) 
// ���ϰ� : �ش� ������ ����

int studentsum(int s[5][3], int stunum){ //�л��� ����

  int i, j;
  int sum = 0;
  for(i = 0; i < 3; i++){
     sum += s[stunum][i];
  }
  return sum;
}
// �Ķ���� : �����迭(s)�� �л���ȣ(0,1,2,3,4) 
// ���ϰ� : �ش� �л��� ����

char studentgrade(int s[5][3], int stunum){//�л��� ���
  char grade;
  int ave;
  ave = studentsum(s, stunum) / 3;

  if(ave >= 90){
    grade = 'A';
  }else if(ave >= 80){
    grade = 'B';
  }else if(ave >= 70){
    grade = 'C';
  }else if(ave >= 60){
    grade = 'D';
  }else{
    grade = 'F';
  }

  return grade;
} 
// �Ķ���� : �����迭(s)�� �л���ȣ(0,1,2,3,4) 
// ���ϰ� : �ش� �л��� ��� ('A','B','C','D','F')


int main(void){
  int jumsu[5][3];            // 5���� 3���� ������ �����ϰ� �ִ� 2���� �迭 
  char classname[3][20]={"����","����","����"};
  float ave;     //��տ����� ���� ���� 
  int i, j;

  
  srand(time(0)); //�õ� �ʱ�ȭ 

  //���� ���� ���� 
  printf("5���� �л� ������ �����Ǿ����ϴ�.\n");
  for(i = 0; i <5; i++){
    printf("%d�� �л� : ", i+1);
    
    for(j = 0; j < 3; j++){//�� �л��� ���� ���� �� �迭�� ����(����-����-���� �� )
      jumsu[i][j] = 50+ rand()%50+1;
    }
    
    printf("���� %d, ���� %d, ���� %d\n", jumsu[i][0], jumsu[i][1], jumsu[i][2]);
  }


  //��� ��� 
  printf("1) �� ���� ������ �������\n");
  for(i = 0; i < 3; i++){
    ave = classsum(jumsu, i) / 5;
    printf("%s ������ ������ %d ����� %.1f\n", classname[i], classsum(jumsu, i), ave);
  }

  printf("2) �� �л��� ������ �������, ��տ� ���� ���\n");
  for(i = 0; i < 5; i++){
    ave = studentsum(jumsu, i)/3;
    printf("%d�� �л��� ������ %d ����� %.1f(��� %c)\n", i+1, studentsum(jumsu, i), ave, studentgrade(jumsu, i));
  }


  return 0;
}

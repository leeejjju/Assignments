#include <stdio.h>

int main(void) {
  
  int jumsu[5][3] = {0, };            // 5���� 3���� ������ �����ϰ� �ִ� 2���� �迭 
  int sum_student[5] = {0, };         // �л��� ����
  float average_student[5];   // �л��� ���
  char grade[5];              // �л��� ��� 
  int sum_class[3] = {0, };           // ���� ����
  float average_class[3];     // ���� ���
  int i, j;                   // �ݺ����� ���� ���� 

  for(i = 0; i < 5; i++){ //�л��� ���� �Է¹ް� ���� ����, ��յ�� ���� 
    printf("%d�� �л� ����, ����, ���� ����? ", i+1 );
    scanf("%d %d %d", &jumsu[i][0], &jumsu[i][1], &jumsu[i][2]);

    sum_student[i] = jumsu[i][0] + jumsu[i][1] + jumsu[i][2]; //�л��� ���� 
    sum_class[0] += jumsu[i][0]; //���� ���� 
    sum_class[1] += jumsu[i][1]; //���� ���� 
    sum_class[2] += jumsu[i][2]; //���� ���� 

    for(j = 0; j < 3; j++){ //��տ� ���� ��� 
      if( sum_student[i]/3 >= 90){
       grade[i] = 'A';
     }else if(sum_student[i]/3 >= 80){
        grade[i] = 'B';
      }else if(sum_student[i]/3 >= 70){
        grade[i] = 'C';
      }else if(sum_student[i]/3 >= 60){
        grade[i] = 'D';
      }else{
        grade[i] = 'F';
      }
    }
  }
  
  printf("1) �� ���� ������ �������\n");
  printf("���� ������ ������ %d ����� %.1f\n", sum_class[0], sum_class[0]/5.0 );
  printf("���� ������ ������ %d ����� %.1f\n", sum_class[1], sum_class[1]/5.0);
  printf("���� ������ ������ %d ����� %.1f\n", sum_class[2], sum_class[2]/5.0);


  printf("2) �� �л��� ������ �������, ��տ� ���� ���\n");

  for(i = 0; i < 5; i++){
    printf("%d�� �л��� ������ %d ����� %.1f(��� %c)\n", i+1, sum_student[i], sum_student[i]/3.0, grade[i]);
  }
  


  return 0;
}

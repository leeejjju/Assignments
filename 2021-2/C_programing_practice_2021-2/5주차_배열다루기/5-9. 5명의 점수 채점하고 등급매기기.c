#include <stdio.h> 
/*
������ ���� 5���� �л��鿡�� 10������ ���� �Է¹޾�, �̸� ä���Ͽ� ����� �ű�� �۾��� �ϴ� ���α׷��� �ۼ��϶�. �л����� 10������ ����� �Է¹��� �Ŀ�, �� ��޺� �л� �̸��� �ο����� ����϶�.

��, 10������ ������ �̸� �ڵ忡 ���õ� �״�� ����϶�.

����� ������ ���� �����Ѵ�.

1st : 9~10���� ���� ���

2nd : 7~8���� ���� ���

Fail : 6���� ���Ϸ� ���� ���
*/

int main(void) {
  int i,j; // �ݺ����� ���� ����
  int jumsu = 0; // ���� ���� ����
  int count = 0; // �ο��� ���� ����
  char names[5][20]={"James", "David", "Simon", "Peter", "Jason"}; // �л� �̸� 
  int sheet[5][10]; // �л��� ��ȳ���
  int answer[10]={1,2,3,4,1,2,3,4,3,2}; // �������
  int grade[5] = {3}; // �л��� ��� 

  for(i=0;i<5;i++){
    printf("Enter %s's sheet >> ", names[i]); 
    for(j=0;j<10;j++)
      scanf("%d", &sheet[i][j]); //i��°�л��Ǵ��10���Է�
  }

  // �� �κп� �ڵ带 �ۼ��� ��!


 for(i=0;i<5;i++){ 
    
    for(j=0;j<10;j++){ //ä���ϱ� 
      if(answer[j] == sheet[i][j]){
        jumsu ++;// ���������� ���� ���� 
      }
    }

    if(jumsu > 8){ //����Ǻ�, �迭�� �ش� �л��� �ε��� ���� 
      grade[i] = 0;//1���

    }else if(jumsu > 6){
      grade[i] = 1;//2���

    }else{
      grade[i] = 2;//����...
    }

    jumsu = 0;//���� �ʱ�ȭ 

  }


  printf("\nGrade result\n");//������ 

  for(i = 0; i < 3; i++){ 

    if(i == 0){
      printf("1st : ");
    }else if(i == 1){
      printf("2nd : ");
    }else{
      printf("Fail : ");
    }

    for(j = 0; j < 5; j++){
      if(grade[j] == i){
        printf("%s ", names[j]);
        count++;
      }
    }

    printf("(%d)\n", count);
    count = 0;

  }

  

  return 0; 
}



#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*
1���� 100 ������ ������ ���ڸ� ���� �Ŀ� ����ڷ� �Ͽ��� �� ���ڸ� ���ߵ��� �϶�. ����ڰ� ������ ���ں��� ū ������ ���� �������� �˷��ָ鼭 �� �� ���� ���߾����� ����϶�.
*/

int main(void){
  int answer;       // ��ǻ�Ͱ� ����� �� 1���� 100������ ������ ����
  int number_try;   // ����ڰ� ������ ����
  int count = 0;        // ����ڰ� ���߷��� �õ��� Ƚ�� 

  srand(time(0));
  answer = rand()%100+1; //1~100 ���� ������ ���ڷ� ���� ���� 

  while(1){
    printf("1���� 100������ ���� �ϳ��� ���纸���� "); //��� �Է¹ޱ�
    scanf("%d", &number_try);


    if(answer < number_try){
      printf("�� �� ���� ���Դϴ�.\n");
      count++;
    }else if(answer > number_try){
      printf("�� �� ū ���Դϴ�.\n");
      count++;
    }else{
      break;
    }
  }

  printf("%d ������ ���ڸ� ���߼̽��ϴ�.", count);

  return 0;
}

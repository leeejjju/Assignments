#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*������ ���� ����ڿ� ��ǻ�Ͱ� ������������ �ϴ� ���α׷��� ������.

1) �������� ����(1), ����(2), ��(3) �� �߿� �ϳ��� �����.
2) ����ڿ��� ����(1), ����(2), ��(3) �߿� �ϳ��� ���ڷ� �Է¹޴´�.
3) ����ڰ� �Է��� �Ͱ� ��ǻ�Ͱ� ����� �� ���� ���Ͽ�

��ǻ�Ͱ� �̱��, "��ǻ�� ��!"
����ڰ� �̱��, "����� ��!"
����, "���~" ���� ����Ѵ�.

4) ����ڰ� 0�� �Է��� ������ �� 1)���� 3)�� ��� �ݺ��ϴٰ�, ������ �׵��� ��ǻ�Ϳ� ����ڰ� �̱� Ƚ���� �� Ƚ��, ��� Ƚ���� ����϶�.*/


int main(void) {
  
  int com_finger;   // ��ǻ�Ͱ� �� ����(1), ����(2), ��(3)
  int my_finger;    // ����ڰ� �� ����(1), ����(2), ��(3)
  int score[2][3] = {0};  // ��� Ƚ�� (1�� : ��ǻ���� ��, ��, ��, 2�� : ������� ��, ��, ��)
  int i, j;         // �ݺ����� ���� ����


  while(1){

    srand(time(0));
    com_finger = rand()%3+1;

    printf("����(1), ����(2), ��(3)�� �Է��ϼ���.");
    scanf("%d", &my_finger);

    if(my_finger == 0){
      break;
    }

    if(my_finger > 3 || my_finger < 1){
      printf("�ùٸ� ���ڸ� �Է��ϼ���\n");
    }else{

      if(com_finger == 1){
        printf("��ǻ��: ���� ");
        if(my_finger == 1){
            printf("���~\n");
            score[0][1] ++;
            score[1][1] ++;
        }else if(my_finger == 2){
            printf("-> ����� ��!\n");
            score[0][2] ++;
            score[1][0] ++;
        }else{
            printf("-> ��ǻ�� ��!\n");
            score[0][0] ++;
            score[1][2] ++;
        }  
      }else if(com_finger == 2){
        printf("��ǻ��: ���� ");
        if(my_finger == 2){
            printf("���~\n");
            score[0][1] ++;
            score[1][1] ++;
        }else if(my_finger == 3){
            printf("-> ����� ��!\n");
            score[0][2] ++;
            score[1][0] ++;
        }else{
            printf("-> ��ǻ�� ��!\n");
            score[0][0] ++;
            score[1][2] ++;
        }
      }else{
        printf("��ǻ��: �� ");
        if(my_finger == 3){
            printf("���~\n");
            score[0][1] ++;
            score[1][1] ++;
        }else if(my_finger == 1){
            printf("-> ����� ��!\n");
            score[0][2] ++;
            score[1][0] ++;
        }else{
            printf("-> ��ǻ�� ��!\n");
            score[0][0] ++;
            score[1][2] ++;
        }
      }
    }
  }

   printf("��ǻ��: �̱� Ƚ�� %dȸ, �� Ƚ�� %dȸ, ��� Ƚ�� %dȸ\n", score[0][0], score[0][2], score[0][1]);
   printf("�����: �̱� Ƚ�� %dȸ, �� Ƚ�� %dȸ, ��� Ƚ�� %dȸ", score[1][0], score[1][2], score[1][1]);


  return 0;
}

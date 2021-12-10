#include <stdio.h>
#include <string.h>
/*������ ����(data.txt)�κ��� ������ �о� ��ü �ؽ�Ʈ ���Ͽ� ���Ե� �ҹ���, �빮���� ��, ��ĭ�� ���� ���϶�.

1. ���� ����
2. ���Ϸκ��� ���پ� �о����...
  2-1 ���ο� �ش� ���� ���
  2-2 �ش� ������ ���ڿ��� ���ھ� �˻��ϸ�...
    2-2-1 �빮�ڸ� �빮��ī��Ʈ ����
    2-2-2 �ҹ��ڸ� �ҹ���ī��Ʈ ����
    2-2-3 ��ĭ�̸� ��ĭī��Ʈ ����
3. �м� ��� ��� 
*/


int main(void) {
  int countUp = 0; //�빮�� �� 
  int countLow = 0; //�ҹ��� ��
  int countSpace = 0; //��ĭ ��
  char line[100];

  //1. ���� ����
  FILE* file;
  file = fopen("data.txt", "r");

  //2. ���Ϸκ��� ���پ� �о����...
  while(!feof(file)){
    //2-1 ���ο� �ش� ���� ���
    fgets(line, 100,file);

    //2-2 �ش� ������ ���ڿ��� ���ھ� �˻��ϸ�...
    for(int i = 0; i < strlen(line); i++){

      //2-2-1 �빮�ڸ� �빮��ī��Ʈ ����
      if(line[i] >= 'A' && line[i] <= 'Z'){
        countUp ++;
      }else if(line[i] >= 'a' && line[i] <= 'z'){ //2-2-2 �ҹ��ڸ� �ҹ���ī��Ʈ ����
        countLow ++;
      }else if(line[i] == ' '){//2-2-3 ��ĭ�̸� ��ĭī��Ʈ ����
        countSpace ++;
      }
    }
  }
  //3. �м� ��� ��� 
  printf(">> �빮�� : %d��, �ҹ��� : %d��, ���� : %d��", countUp, countLow, countSpace);
  
  return 0;
}

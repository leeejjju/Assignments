#include <stdio.h>
#include <string.h>
/*�� ������ �Է¹��� �Ŀ� �� ���� �� ���� �� �ܾ�� �� ���̸� ���϶�.

�̸� ���� ������ ��Ÿ���� ����(char* Ÿ��)�� �����Ͽ� �� ������ �̷�� �ִ� �ܾ�� �� ���� �� �ܾ ã��, �� �ܾ��� ù���ں��� ���۵Ǵ� ���ڿ��� �����ϴ� �Լ��� ����� ����϶�.*/


char* findLongestWord(char* str);

int main(void) {

  char line[100];     // �Է¹��� ���� 
  printf("���� �Է� > ");
  fgets(line, 100, stdin); 
  line[strlen(line)-1]='\0'; //���� ����

  // �̰��� �ڵ带 �ۼ��϶�
  //��,.... 

  printf("��� > %s �߿� ���� �� �ܾ�� ", line);

  int count = 0; //���� �� �ܾ� ���ڼ� �� ���� 
  while(findLongestWord(line)[count] != ' ' && findLongestWord(line)[count] != '\0'){ //���� �� �ܾ� ��� 
    printf("%c",findLongestWord(line)[count] );
    count ++;
  }

  printf(", ���� %d�Դϴ�.",  count);


  

  return 0;
}

char* findLongestWord(char* str){
  int count = 0; //�� �ܾ��� ���ڼ��� ���ϴ�...
  int maxLen = 0, maxINdex = 0; //���� �� ���̿�... �׳� �ܾ��� ������ġ�� �����մϴ�... 
  int i; //�ݺ���... 
  //char max[100] = {'\0'}; //���� �� ���̷� �����ϴ� ���ڿ�... 

  for(i = 0; i < strlen(str); i++){
    if(str[i] != ' '){ //���Ⱑ �ƴ϶��, �� �ܾ� �߰��϶��� 
      count++; //������ ���ڼ����� 
    }else{ //���⸦ ������ 
      if(maxLen < count){ //���ݲ� �� ���ڼ��� �ִ����� �Ǻ� 
        maxLen = count; //�ִ��.. ���ο� �Žñ� ���� �Ӹ�ǰ� 
        maxINdex = (i - count); //�׳��� ��ġ�� ���� 
      }
      count = 0;  //�۰� �����ܾ� ���� ���ؼ� ī��Ʈ �ʱ�ȭ 
    }
  }

  return &str[maxINdex];
}
//�Ķ���� : ��ü ���� (str)
//���ϰ� : ���� ��ܾ�� ���۵Ǵ� ����
//���೻�� : ���� �߿��� ���� �� �ܾ ���۵Ǵ� ��ġ�� ���ڿ�


#include <stdio.h>
#include <string.h>
/*������ �ϳ� �Է¹��� �Ŀ�, �� ���� �ӿ��� white space ������ ������ ����.

��, �־��� �Լ��� �ݵ�� recursion�� ����Ͽ� ������ ��, ����� ��. main() ��������!*/

int rSpaces(char* str);

int main(void) {
	char line[100];
	printf("Enter a string > ");
	fgets(line, 100, stdin);
	printf("spaces : %d\n", rSpaces(line));
	return 0;
}

//----------------

int rSpaces(char* str){

  if(strlen(str) == 1){
    return 0;

  }else{
    if(str[0] == ' '){
      //printf("3\n");
      return 1 + rSpaces(&str[1]);
    }else{
      //printf("4\n");
      return rSpaces(&str[1]);
    }
  }
}
//�Ķ���� : ������ ����� �ϴ� ���ڿ��� ���� ������
//���ϰ� : �� �����ͷκ��� ���ڿ��� ������ ����ִ� ���� ���� ����

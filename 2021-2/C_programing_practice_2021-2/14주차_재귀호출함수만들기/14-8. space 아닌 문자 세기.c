#include <stdio.h>
#include <string.h>
/*������ �ϳ� �Է¹��� �Ŀ�, �� ���� �ӿ��� white space�� �ƴ� ������ ������ ����.
��, �־��� �Լ��� �ݵ�� ����Լ��� ������ ��, ����� ��. 
main() ��������!*/

int rStrlen(char* str);

int main(void) {
	char line[100];
	printf("Enter a string > ");
	fgets(line, 100, stdin);
	printf("length : %d\n", rStrlen(line));
	return 0;
}

//------------------���ķθ� ���� ����


int rStrlen(char* str){

  if(strlen(str) == 1){
    /*if(str[0] != ' '){
      printf("1\n");
      return 1;
    }else{
      printf("2\n");
      return 0;
    }*/
    return 0;

  }else{
    if(str[0] != ' '){
      //printf("3\n");
      return 1 + rStrlen(&str[1]);
    }else{
      //printf("4\n");
      return rStrlen(&str[1]);
    }
  }

}
//�Ķ���� : ������ ����� �ϴ� ���ڿ��� ���� ������
//���ϰ� : �� �����ͷκ��� ���ڿ��� ������ ����ִ� �������� ���� ����
//��Ʈ: ���ڿ��� ���� ������ ���� ���� �ٷ� �ں��� �����ϴ� ���ڿ��� ���� ������ �� ��, 1�� ���Ѵ�.

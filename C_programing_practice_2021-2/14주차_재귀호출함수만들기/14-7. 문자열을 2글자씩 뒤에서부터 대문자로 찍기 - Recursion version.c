#include <stdio.h>
#include <string.h>
/*������ ���� ���ڿ��� �� �� �Է¹��� �Ŀ� �ش� ���ڿ��� 2���ھ� �ڿ������� �빮�ڷ� ��� ���α׷��� �ϼ��϶�.

��, ¦������ ���ڿ��� ��쿡�� �� ������ 2�� ���ڸ� ���� ���� ��� �ǰ�, Ȧ������ ���ڿ��� ��쿡�� �� �������� 1�� ���ڸ� ���� ���� ��� �� ���̴�. ��, ���ĺ� ���ڴ� �ݵ�� �빮�ڷ� �ٲ㼭 ���� �Ѵ�.

��, main()�� �����Ұ��ϸ�, rPrint() �Լ��� �ݵ�� ����Լ��� �����ؾ� �Ѵ�.*/

void rPrint(char* str);
void changeUpper(char* str);

int main(void) {
	char str[80];
	printf("Enter a string >>");

	fgets(str, 80, stdin);
	str[strlen(str)-1]='\0';
  
  changeUpper(str);
	rPrint(str);

	return 0;
}

//--------------------------------------------------------
void changeUpper(char* str){
  for(int i = 0 ; i < strlen(str); i++){
    if(str[i] >= 'a' && str[i] <= 'z'){
      str[i] -= 32;
    }
  }
}
//�빮������ �Ǻ��ϰ� �빮�ڷ� �ٲ��ֱ� 




void rPrint(char* str){

  if(strlen(str) <= 2){
    printf("%s", str);
    return; 
  }else{
    rPrint(&str[2]);
    printf("%c%c", str[0], str[1]);
  }
}
//�Ķ���� : ���ڿ� (���ڿ��� ù���� �ּ�)
//���೻�� : ���� �Է¹��� ���ڿ��� ���̰� 2 ������ ��� �ٷ� ����Ѵ�. �� ���� ��쿡�� 3��° ���ں��� �����ϴ� ���ڿ��� �Ķ���ͷ� rPrint()�� ȣ���� ��, ó�� 2���ڸ� ����Ѵ�.

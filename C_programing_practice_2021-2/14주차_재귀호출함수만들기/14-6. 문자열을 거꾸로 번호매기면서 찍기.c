#include <stdio.h>
#include <string.h>
/*������ ���� ���ڿ��� �� �� �Է¹��� �Ŀ� �ش� ���ڿ��� �Ųٷ� ��ȣ �Ű� ��� ���α׷��� �ϼ��϶�.

��, rPrint() �Լ��� �ݵ�� ����Լ��� �����ؾ� �Ѵ�.
void rPrint(char* str, int n);
�Ķ���� : ���ڿ� str, ������(���ڿ��� ������ ���� �ǹ�) n
���ڿ��� ������ ���ڸ� ����Ű�� �����Ϳ� �������� �Ķ���ͷ� �޴´�.
rPrint()�� �̿��� �ش� ���� ������ ���ڿ��� ���� �۾� ���� �Ŀ�, �ش� ���ڸ� ��ȣ�� �Բ� ����Ѵ�.*/


void rPrint(char* str, int n);

int main(void) {
	char str[80];
	printf("Enter a string >> ");
	fgets(str, 80, stdin);
	str[strlen(str)-1]='\0';
	rPrint(str, strlen(str));
	return 0;
}

void rPrint(char* str, int n){
  static int count = 1;
  if(n == 0){
    printf("%2d. %c", count, str[n-1]);
    return;
  }else{
    printf("%2d. %c\n", count, str[n-1]);
    count += 1;
    rPrint(str, n-1);
    //////////////ī��Ʈ�� �� �� �����ұ�??
  }
}
//�Ķ���� : ���ڿ� str, ������(���ڿ��� ������ ���� �ǹ�) n
//���ڿ��� ������ ���ڸ� ����Ű�� �����Ϳ� �������� �Ķ���ͷ� �޴´�.
//rPrint()�� �̿��� �ش� ���� ������ ���ڿ��� ���� �۾� ���� �Ŀ�, �ش� ���ڸ� ��ȣ�� �Բ� ����Ѵ�.

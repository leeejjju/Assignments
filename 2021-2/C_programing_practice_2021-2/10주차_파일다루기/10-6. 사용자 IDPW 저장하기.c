#include <stdio.h>
#include <string.h>
/*10���� ����� ����(ID, PW)�� �Է¹޾� ����ϰ� �ؽ�Ʈ����(user.txt)�� �����ϴ� ���α׷��� �ۼ��϶�.*/

/*
1. ����� ���� �Է¹޾� �迭�� ����
2. �Է¹��� �迭 ���Ͽ� �ۼ� 
3. ���� �б�� �ۼ��� ���� ��� 
*/

int main(void) {
	char userid[10][20];
	char userpw[10][20];
  char line[100] = {0,};
  char preLine[100] = "hehe";

  //1. ����� ���� �Է¹޾� �迭�� ����
  for(int i = 0; i < 10; i++){
    printf("%d��° ��� ID Password? ", i+1);
    scanf("%s %s", userid[i], userpw[i]);
  }
  //2. �Է¹��� �迭 ���Ͽ� �ۼ�
  FILE* file;
  file = fopen("userData.txt", "w");

  fprintf(file, "��ϵ� ����� ���\n");
  fprintf(file, "No ID Password\n");

  for(int i = 0; i < 10; i++){
    fprintf(file, "%d %s %s\n", i+1, userid[i], userpw[i]);
  }
  fclose(file);

  printf("\n");

  //3. ���� �б�� �ۼ��� ���� ��� 
  file = fopen("userData.txt", "r");
  int count = 0;

  while(!feof(file)){
    if(count > 11){
      break;
    }
    fgets(line, 100, file); //������ �޾ƿ���(���ͱ���..)
    printf("%s", line); //�� ���� ����ϰ�... 
    count ++;
  }

  fclose(file);

  printf("\nuser.txt�� ������");


	return 0;
}

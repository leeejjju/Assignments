#include <stdio.h>
#include <string.h>
/*name.txt ���Ͽ� ������ �к��̸��� �������� �����ִ�. �� ������ �о �к� ��ü ������ ���� �̸��� �� �̸��� ���� ª�� �̸��� �������� ����϶�.

1. ���� ����
2. ������ ���������� ���پ�...
  2-1 ������ �� ���� line�� ���
  2-2 line�� ����(sizeof)�� max�Ǻ�... max���ڿ� ����
  2-3 lnie�� ���̷� min�Ǻ�... min���ڿ� ����
3. ���� �� ���ڿ��� ª�� ���ڿ� ��� 

*/

int main(void) {
  char line[200] = {0};
  char maxLine[200] = {0}, minLine[200] = {0};
  int max = 0, min = 999999, count = 0;

  //1. ���� ����
  FILE* file;
  file = fopen("name.txt", "r");

  //2. ������ ���������� ���پ�...

  while(!feof(file)){
    //2-1 ������ �� ���� line�� ���
    fgets(line, 200, file);
    line[strlen(line)-1] = '\0';
    //printf("line %d is %s, size of line is %d\n", count+1, line, (unsigned)strlen(line));

    //2-2 line�� ����(sizeof)�� max�Ǻ�... max���ڿ� ����
    if(max < strlen(line)){
      max = strlen(line);
      strcpy(maxLine, line);
      //printf(" $$$now maxLine is %s$$$ \n\n", maxLine);
    }
    //2-3 lnie�� ���̷� min�Ǻ�... min���ڿ� ����
    if(min > strlen(line)){
      min = strlen(line);
      strcpy(minLine, line);
      //printf(" $$$now minLine is %s$$$ \n\n", minLine);
    }
    count ++;
  }

  //3. ���� �� ���ڿ��� ª�� ���ڿ� ��� 
  printf("Count : %d\n", count);
  printf("Longest name : %s\n", maxLine);
  printf("Shortest name : %s", minLine);


  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*����������(data.txt)�κ��� �ؽ�Ʈ ���Ϸκ��� ���̰� �ٸ� ���� ���� ������ �о�ͼ� �� �� ���� �� ����� ª�� ������ ��ȣ�� ������ ����϶�.

��, ������ �����ϴ� ���ڿ��� �����ͷ� �����Ͽ� �޸𸮸� �������� �Ҵ�޵��� �϶�. (ch12_03.c �����ҽ��� �����϶�.)*/

int main(void) {
  char* pstr[20]; // ������ ����� �ִ� 20���� ������ ���� ������ �迭 
  char* longest;  // ���� �� ������ ����Ű�� ������
  char* shoetest;	// ���� ª�� ������ ����Ű�� ������
  int max = 0, min = 99999999;
  int maxIndex, minIndex;
  int count = 0;

  FILE* file;
  file = fopen("data.txt", "r");

  while(!feof(file)){
    pstr[count] = malloc(sizeof(char)*200); //count��° �����Ϳ� 200�ڱ��� ���� ���ڿ� �ּ� ������ 
    fgets(pstr[count], 200, file); //�۰� �ű�ٰ� ���� �о ����
    if(pstr[count][strlen(pstr[count])-1] == '\n'){
      pstr[count][strlen(pstr[count])-1] = '\0';//�������� ���� �����
    }

    //max�Ǻ�... max���ڿ�, �ε��� ����
    if(max < strlen(pstr[count])){
      max = strlen(pstr[count]);
      longest = pstr[count];
      maxIndex = count+1;
    }
    //min�Ǻ�... min���ڿ�, �ε��� ����
    if(min > strlen(pstr[count])){
      min = strlen(pstr[count]);
      shoetest = pstr[count];
      minIndex = count+1;
    }
  
    count++;
  }
  fclose(file);

  printf("%d lines read.\n", count);
  printf("Longest #%d - %s\n", maxIndex, longest);
  printf("Shortest #%d - %s\n", minIndex, shoetest);



  return 0;
}

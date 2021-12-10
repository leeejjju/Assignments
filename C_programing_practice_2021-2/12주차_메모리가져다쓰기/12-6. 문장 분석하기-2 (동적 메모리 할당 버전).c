#include<stdio.h>
#include <stdlib.h>
#include <string.h>

/*12-5 ������ ��� �ҽ��� ������� ����������(data.txt)�κ��� �ؽ�Ʈ ���Ϸκ��� ���̰� �ٸ� ���� ���� ������ �о�ͼ� �� ���忡 ���ؼ� ������ ������ ����Ͽ� ������ ��ȣ�� ������ ����϶�.

��, ������ �����ϴ� ���ڿ��� �����ͷ� �����Ͽ� �޸𸮸� �������� �Ҵ�޵��� �϶�. (ch12_03.c �����ҽ��� �����϶�.)

��, ���� �� ������ ������ ���� �۾��� ������ ���� �Լ��� �����Ͽ� ����϶�.*/

int countVowels(char* str);


int main(void){
  char* pstr[20]; // ������ ����� �ִ� 20���� ������ ���� ������ �迭 
  int count = 0;

  FILE* file;
  file = fopen("data.txt", "r");

  while(!feof(file)){
    pstr[count] = malloc(sizeof(char)*200); //count��° �����Ϳ� 200�ڱ��� ���� ���ڿ� �ּ� ������ 
    fgets(pstr[count], 200, file); //�۰� �ű�ٰ� ���� �о ����
    if(pstr[count][strlen(pstr[count])-1] == '\n'){
      pstr[count][strlen(pstr[count])-1] = '\0';//�������� ���� �����
    }
    if(strlen(pstr[count]) != 0){
      count++;
    }
  }
  fclose(file);

  printf("%d lines read.\n", count);
  for(int i = 0; i < count; i++){ //��� 
    printf("#%d - %s [%d]\n", i+1, pstr[i], countVowels(pstr[i]));
  }

  return 0;
}

int countVowels(char* str){
  int countVowels = 0;
  char Vowels[10] = {'a','e','i','o','u','A','E','I','O','U'};

  for(int i = 0; i < strlen(str); i++){
    for(int j = 0; j < 10; j++){
      if(str[i] == Vowels [j]){
        countVowels++;
      }
    }
  }

  return countVowels;
}
// ���ϰ� : str ���ڿ� ���� ����ִ� ������ ���� (���� ���� : a,e,i,o,u,A,E,I,O,U)

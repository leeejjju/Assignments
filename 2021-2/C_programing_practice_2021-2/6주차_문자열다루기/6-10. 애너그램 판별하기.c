#include <stdio.h>
#include <string.h>

/*���ڿ� s1, s2 2���� �Է¹޾� �� �� ���ڿ��� anagram���� �Ǻ��϶�.

anagram�̶� �ΰ��� ���ڿ� �� �� ���ĺ��� ������ ������ŭ ���Ե� ���� ���Ѵ�.

�̶�, ���ĺ��� �ҹ��ڸ� �Էµȴٰ� �����ϸ�, ���ĺ� ���� ���ڵ��� �����Ѵ�.*/

int main(void){
  char str1[100], str2[100]; //�Է¹��� ���ڿ� 
  int alphacount1[26]={0}, alphacount2[26]={0}; //���ڿ� �� ���ĺ� ���� ����... 
  int i, j, same = 1;

  
  printf("String 1 > ");
  fgets(str1, 100, stdin);
  printf("String 2 > ");
  fgets(str2, 100, stdin);

  for(i = 0; i < strlen(str1); i++){ //���ڿ� �� ���ĺ� �� ����1 
    for(j = 97; j < 123; j++){
      if( str1[i] ==j){
        alphacount1[j-97] ++;
        break;
      }  
    }
  }

  for(i = 0; i < strlen(str2); i++){ //���ڿ� �� ���ĺ� �� ����1 
    for(j = 97; j < 123; j++){
      if( str2[i] ==j){
        alphacount2[j-97] ++;
        break;
      }  
    }
  }


  for(i = 0; i < 26; i++){ //���԰����� �ϳ��� �ٸ��� same = 0
    if(alphacount1[i] != alphacount2[i]){
      same = 0;
    }
  }

  if(same){
    printf("Anagram!");
  }else{
    printf("Not anagram!");
  }


}

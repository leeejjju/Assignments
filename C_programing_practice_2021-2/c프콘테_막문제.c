/*
C������ ���������� �� �� �Ծ��� �������� 3������ �ذ��ϰ� ������. �̰� �ذ� �� �ڵ� - �����ذ��� ]
1. ������ 22100579
2. �� �����ִ� �� ������ Ǯ��µ��� �ϳ��԰� ��� �տ��� �����ϰ� ���Ͽ����� �����մϴ�.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*�ҹ��ڷ� �̷��� ���� �ܾ �Է¹��� ��, �� �ܾ ��ȣȭ�� �ܾ��, �ٽ� ��ȣȭ�� �ܾ ����Ͻÿ�.

��, main() �Լ� ������ �������� ����, 2���� �Լ��� �����Ͽ� �ϼ��� ��.
*/


char ref[26]="@BCD#FGH%JKLMN$PQRST&VWXYZ"; // ��ȣȭ ���� ���ڿ�
char* encode(char* str);	// ��ȣȭ�� ���ڿ� �����
char* decode(char* str);	// ��ȣ�� Ǭ ���ڿ� �����
int i, j;

int main(void) {	// ���� ����
	char str[100]; // ���� �ܾ�
	char* encoded; // ��ȣȭ�� �ܾ�
	char* decoded; // ��ȣȭ�� �ܾ�

	printf("Enter a word.\n");
	scanf("%s", str);

	encoded = encode(str);
	decoded = decode(encoded);

	printf("Encoded string > %s\n", encoded);
	printf("Decoded string > %s\n", decoded);

	return 0;
}

//----------------------------------------------------

char* encode(char* str){
  int num, len;
  for(i = 0; i < strlen(str); i++){
    if(str[i] >= 'a' && str[i] <= 'z'){ //�ҹ��ڸ�  
      num = 97;
    }else if(str[i] >= 'A' && str[i] <= 'Z'){//�빮�ڸ� 
      num = 65;
    }

    len = ((int)str[i]-num)+strlen(str);

    while(1){ //���۷��� �ε��� �ȿ� ������ ���� 
      if(len < 26) break;
      len -= 26;
    }
    str[i] = ref[len];
    
  }

  return str;
}
/*��ȣȭ ��Ģ

char ref[26]="@BCD#FGH%JKLMN$PQRST&VWXYZ";
�ܾ� ������ ���ڵ��� ���� ���ĺ� ����(0~25) + �ܾ���̸� ���ؼ� �� ��ġ�� ��ȣȭ ���� ���ڷ� ��ü�Ѵ�.
���� ��� "abc" ��� �ܾ�� 3�����̹Ƿ�, ��ȣȭ ���� ���ڿ��� 3�� �ε������� �����ϰ� �Ǿ� "D#F"�� ��ü�ȴ�.
���� ���ڿ��� ��� �ݺ��Ǿ� ����ȴٰ� �����϶�.
*/

char* decode(char* str){

  char* strr = malloc(sizeof(char)*100);
  strcpy(strr, str);
  int index;
  for(i = 0; i < strlen(strr); i++){
    for(j = 0; j < 26; j++){
      if(ref[j] == strr[i]){
        index = j;
        break;
      }
    }
    
    index -= strlen(strr);
	if(index < 0) index +=26;
      

    strr[i] = (char)(index + 97);
  }
  
  return strr;
}
/*��ȣȭ ��Ģ

char ref[26]="@BCD#FGH%JKLMN$PQRST&VWXYZ";
��ȣȭ�� �ܾ� ������ ���ڵ鿡 ���� ��ȣȭ ���� ���ڿ��� ��ġ�� ã�Ƴ� ��, �� ��ġ���� �ܾ���̸�ŭ �� ��ġ���� �ش�Ǵ� ���ĺ� �ҹ��ڷ� ��ü�Ѵ�.
���� ��� "D#F" ��� �ܾ�� ��ȣȭ ���� ���ڿ��� 3,4,5��° ����������, �ܾ��� ���� 3��ŭ ����, 0,1,2��° ���ڰ� �ȴ�. �̿� ���� ���ĺ� �ҹ��� �� 0,1,2��°�� �ش��ϴ� "abc"�� ��ü�ȴ�.
���� ���ڿ��� ��� �ݺ��Ǿ� ����ȴٰ� �����϶�.*/

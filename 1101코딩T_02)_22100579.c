/*1101�ڵ�T_02)_22100579
2. ���� ������ ���������� �־����� �� �̵� �� ���� �󵵰� ���� ���� ã�� ���α׷��� �ۼ��Ͻÿ�.
(���� ���� ���� �������̸� ù��°�� �߰ߵ� ���� ��� )
*/
#include <stdio.h>
#include <string.h>

int main(void){
  int size;
  int i, j, max = 0, max_index;

  printf("size: ");
  scanf("%d", &size);

  int num[size], count[size];

  printf("input: ");
  for(i = 0; i < size; i++){ //�Է¹ް� ī��Ʈ 1�� �ʱ�ȭ... 
    scanf("%d", &num[i]);
    count[i] = 1;
  }

  for(i = 0; i < size; i++){
    for(j = i+1; j < size; j++){
      if(num[i] == num[j]){
        count[i] ++;
        break;
      }
    }
  }

  for(i = 0; i < size; i++){
    if(max < count[i]){
      max = count[i];
      max_index = i;
    }
  }

  printf("%d", num[max_index]);



  return 0;
}


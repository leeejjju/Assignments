#include <stdio.h>

int main(void) {

  int size;     // �Է¹��� ����
  int i, j;       // �ݺ��� ����� ���� ���� 

  printf("size? >> ");
  scanf("%d", &size);

  for(i = 0; i < size*2 - 1; i++){

    if(i < size){
      for(j = 0; j <(i + 1) ; j++){
      printf("*");
      }
      for(j = 0; j <(size - (i + 1))*2 ; j++){
      printf(" ");
      }
      for(j = 0; j <(i + 1) ; j++){
      printf("*");
      }
    }else{

      for(j = 0; j <size - (i - size + 1) ; j++){
      printf("*");
      }
      for(j = 0; j <(i - size + 1)*2 ; j++){
      printf(" ");
      }
      for(j = 0; j <size - (i - size + 1) ; j++){
      printf("*");
      }  
    } 

      printf("\n"); 
  }


  return 0;
}

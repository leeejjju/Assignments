#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	
  int bingo[5][5]={0}; // 5*5 ��Ʈ����
  int i, j, k = 0;
  int num;
  int yeokdae[100] = {100}; //�ߺ��˻�� 
  int count = 0, joongbok = 0; //���° �Է¹ް��ִ���, �ߺ��� �����ߴ���  

  while(1){

    printf("Enter a number(1~25) > ");
    scanf("%d", &num);

    if(num > 25){
      printf("EXIT!");
      break;
    }

    yeokdae[k] = num;
    k++;
    count ++;

    for(i = 1; i < count-1; i++){ //�ߺ��˻� 
      if(num == yeokdae[i]){
        joongbok = 1;
      }
    } 
    
    
    if(joongbok == 1){
      printf("�ߺ�!\n");
    }else{
      for(i = 1; i <= 5; i++){ //�Է¹��� ��ġ�� 1 �ִ� �ݺ��� 
        if(num <= 5){//ù�� 
          bingo[i-1][num-1] = 1; //1�� �� �־��ֱ�
          break; 
        }else if(num >= i*5){ //�ش� �ٿ� ����   
           num -= (i-1)*5; //�ش��� �� ĭ ã�ư��� 
          bingo[i-1][num-1] = 1; //1�� �� �־��ֱ� 
        }
      }
    }

    joongbok = 0;

  }


  printf("\n��Ʈ������ ������ ������ �����ϴ�.\n");
  for( i = 0; i < 5 ; i++){
    printf("---------------------\n|");
    for(j = 0; j < 5; j++){
      printf(" %d |", bingo[i][j]);

    }
    printf("\n");

  }
  printf("---------------------");

	return 0;
}

#include <stdio.h>

int main(void) {

  int size;     // 입력받은 높이
  int i, j;       // 반복문 사용을 위한 변수 

  printf("size? > ");
  scanf("%d", &size);

  for(i = 0; i < size; i++){
    for(j = 0; j <size - (i + 1) ; j++){
      printf(" ");
    }

    if(size%2 == 0){ //짝수 
      if(i == size/2){
      for(j = 0 ; j< size+1; j++){
      printf("*");
    }
    }else if(i == 0){
      printf("*");
      
    }else{
      printf("*");

      for(j=0 ; j< i*2 -1; j++){
      printf(" ");
      }

      printf("*");

    }

    }else{ //홀수 
      if(i == size/2){
      for(j = 0 ; j< size; j++){
      printf("*");
    }
    }else if(i == 0){
      printf("*");
      
    }else{
      printf("*");

      for(j=0 ; j< i*2 -1; j++){
      printf(" ");
      }

      printf("*");

    }

    }
    
    
    printf("\n");
  }


  return 0;
}

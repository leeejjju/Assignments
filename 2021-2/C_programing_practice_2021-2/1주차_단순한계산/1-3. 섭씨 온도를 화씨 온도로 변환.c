#include <stdio.h>

int main(void) {
  float c_degree; // ¼·¾¾ ¿Âµµ 
  float f_degree; // È­¾¾ ¿Âµµ 

  printf("¼·¾¾ ¿Âµµ¸¦ ÀÔ·ÂÇÏ½Ã¿À. ");
  scanf("%f", &c_degree);
  f_degree = c_degree * 1.8 + 32;
  printf("È­¾¾ ¿Âµµ´Â %.1fµµ ÀÔ´Ï´Ù.", f_degree);

 
  return 0;
}

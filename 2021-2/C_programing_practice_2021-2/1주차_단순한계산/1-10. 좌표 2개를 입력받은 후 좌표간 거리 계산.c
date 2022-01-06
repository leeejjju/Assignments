#include <stdio.h>
#include <math.h>

int main(void) {
  float x1, x2;   // xÁÂÇ¥ °ª
  float y1, y2;   // yÁÂÇ¥ °ª 

  printf("Ã¹¹øÂ° ÁÂÇ¥ÀÇ x°ª? ");
  scanf("%f", &x1);
  printf("Ã¹¹øÂ° ÁÂÇ¥ÀÇ y°ª? ");
  scanf("%f", &y1);
  printf("µÎ¹øÂ° ÁÂÇ¥ÀÇ x°ª? ");
  scanf("%f", &x2);
  printf("µÎ¹øÂ° ÁÂÇ¥ÀÇ y°ª? ");
  scanf("%f", &y2);


  printf("µÎ ÁÂÇ¥ »çÀÌÀÇ °Å¸®´Â %.1f", sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));


  return 0;
}

#include <stdio.h>

int main(void) {

  float m2_area;     // 면적 (제곱미터)  
  float pyung_area;  // 면적 (평수) 

  printf("m2_area? ");
  scanf("%f", &m2_area);

  pyung_area = m2_area / 3.305;

  printf("pyung_area is %.1f.", pyung_area);


  return 0;
}

#include <stdio.h>

int main(void) {
  int days;     // �Է¹��� �� �� 
  int hours;    // ȯ���� �ð� 
  int minutes;  // ȯ���� �� 
  int seconds;  // ȯ���� �� 
  printf("Days? ");
  scanf("%d", &days);

  hours = days * 24;
  minutes = hours * 60;
  seconds = minutes * 60;
  
  printf("%d days is %d hours.\n", days, hours);
  printf("%d days is %d minutes.\n", days, minutes);
  printf("%d days is %d seconds.", days, seconds);

  return 0;
}

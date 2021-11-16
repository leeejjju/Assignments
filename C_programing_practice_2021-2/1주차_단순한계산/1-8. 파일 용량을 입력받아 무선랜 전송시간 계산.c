#include <stdio.h>

int main(void) {
  int megabytes; // 용량(메가바이트 단위) 
  float seconds; // 전송시간 (소숫점 3자리까지 표시)

  printf("File size in megabytes? ");
  scanf("%d", &megabytes);

  seconds = (megabytes * 1024.000 * 1024.000 * 8.000) / 100000000.000;

  printf("It takes %.3f seconds in 100Mbps Wireless LAN.", seconds);


  return 0;
}

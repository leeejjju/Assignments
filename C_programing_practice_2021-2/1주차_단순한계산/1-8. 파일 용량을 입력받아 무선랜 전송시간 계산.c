#include <stdio.h>

int main(void) {
  int megabytes; // �뷮(�ް�����Ʈ ����) 
  float seconds; // ���۽ð� (�Ҽ��� 3�ڸ����� ǥ��)

  printf("File size in megabytes? ");
  scanf("%d", &megabytes);

  seconds = (megabytes * 1024.000 * 1024.000 * 8.000) / 100000000.000;

  printf("It takes %.3f seconds in 100Mbps Wireless LAN.", seconds);


  return 0;
}

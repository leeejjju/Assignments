#include <stdio.h>

int main(void) {
  int mode; // ��¸��(1: Ȧ����, 2: ¦����) 
  int i, j; // �ݺ��� ����� ���� ���� 
  int count = 0; //�ٹٲ� �Ǻ��� ���� ���� 
  printf("�������� ��¸��(1: Ȧ����, 2: ¦����)�� �Է��ϼ���. ");
  scanf("%d", &mode);

  if (mode == 2){ //¦���϶��� mode���� 0���� ����(���ǹ� ���Ŀ� ����ϱ� ���� )
    mode = 0;
  }

  for(i = 2; i <= 9; i++){
    if(i%2 == mode){ //mode�� ���� Ȧ¦�Ǻ� 
      for(j = 1; j <= 9; j++){
        printf("%d X %d = %2d    ", i, j, i*j);
        count ++;
        if(count == 3){ //���� ����ϸ� �ٹٲ� 
          printf("\n");
          count = 0; //�׸��� ī��Ʈ �ʱ�ȭ 
        }
      }
      printf("\n");
    }
  }

  return 0;
}

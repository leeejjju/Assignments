#include <stdio.h>

int main(void) {
  int mode; // ��¸��(1: Ȧ����, 2: ¦����) 
  int i, j, yeol; // �ݺ��� ����� ���� ���� 
  int count = 0; //�ٹٲ� �Ǻ��� ���� ���� 
  printf("�������� ��¸��(1: Ȧ����, 2: ¦����)�� �Է��ϼ���. ");
  scanf("%d", &mode);
  printf("�� �ٿ� ����� ������ �Է��ϼ���. ");
  scanf("%d", &yeol);

  if (mode == 2){ //¦���϶��� mode���� 0���� ����(���ǹ� ���Ŀ� ����ϱ� ���� )
    mode = 0;
  }

  for(i = 2; i <= 9; i++){ //�� ���� ���� 
    if(i%2 == mode){ //mode�� ���� Ȧ¦�Ǻ� 
      for(j = 1; j <= 9; j++){
       printf("%d X %d = %2d  ", i, j, i*j);
       count ++;
       if(count == yeol){ //yeol�� ����ϸ� �ٹٲ� 
        printf("\n");
        count = 0; //�׸��� ī��Ʈ �ʱ�ȭ 
       }
      }
      printf("\n");
      if(yeol >= 5 && yeol < 9){
        printf("\n"); //�׽�Ʈ���̽� �̷��ַ���...
      }
      count = 0;
    }
  }

  return 0;
}

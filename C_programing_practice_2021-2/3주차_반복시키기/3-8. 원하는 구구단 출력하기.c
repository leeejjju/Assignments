#include <stdio.h>

int main(void) {
  int dan;    // ����Ϸ��� �������� �� �� 
  int i;      // �ݺ����� ���� ���� 
  int test = 0; //�ùٸ� ���� �ԷµǾ����� �Ǵ� 



  while(test == 0){
    printf("����ϰ� ���� �������� �� ��?(2~9) ");
    scanf("%d", &dan);

   if(dan < 2 || dan > 9){
     printf("�߸� �Է��Ͽ����ϴ�.\n");
   }else{
      test = 1;
      for(i = 1; i <= 9; i++){
        printf("%d x %d = %d\n", dan, i, dan*i);
       }
      }
  }

  

  return 0;
}

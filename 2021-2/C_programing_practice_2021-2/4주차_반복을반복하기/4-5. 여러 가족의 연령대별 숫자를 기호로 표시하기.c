#include <stdio.h>

int main(void) {
  int family;                                // �� ����  
  int children, adult, senior;               // ���� �� ����, �, ���� ��
  int all_children=0, all_adult=0, all_senior=0;   // ����, �, ������ �հ�
  int i, j;                                  // �ݺ��� ����� ���� ���� 

  printf("��ü ��������? "); //������ �� �Է¹ޱ� 
  scanf("%d", &family);

  for(i = 0; i < family; i++){ //��ü��������ŭ ������������ �� ���� 
    printf("%d�� ������ ����, �, ������ ���ڴ�? ", i + 1);
    scanf("%d %d %d", &children, &adult, &senior);

    for(j = 0; j < children; j++){ //���� ����ŭ @��� 
      printf("@");
      all_children += 1;
    }

    if(children != 0){
    printf(" ");
    }

    for(j = 0; j < adult; j++){ //� ����ŭ # ���
      printf("#");
      all_adult += 1;
    }

    if(adult != 0){
    printf(" ");
    }

    for(j = 0; j < senior; j++){ // ���� ����ŭ $��� 
      printf("$");
      all_senior += 1;
    }

    printf("\n");

  }


  printf("��� �������� ���ڴ� ������ �����ϴ�.\n");

  for(i = 0; i < all_children; i++){
      printf("@");
    }
    if(all_children != 0){
    printf(" ");
    }
    for(i = 0; i < all_adult; i++){
      printf("#");
    }
    if(all_adult != 0){
    printf(" ");
    }
    for(i = 0; i < all_senior; i++){
      printf("$");
    }

  return 0;
}

#include <stdio.h>

int main(void) {
  float input_degree; // �Է¹��� �µ� 

  printf("degree? ");
  scanf("%f", &input_degree);

  if(input_degree >= 80){
    printf("���� ���Դϴ�.");
  }else if(input_degree >= 40){
    printf("�¼� �Դϴ�.");
  }else if(input_degree >= 25){
    printf("�̿¼� �Դϴ�.");
  }else if(input_degree >= 0){
    printf("�ü� �Դϴ�. ");
  }else{
    printf("�߸��Է��ϼ̽��ϴ�.");
  }
  return 0;
}

#include <stdio.h>

int main(void) {

  float m2_area;      // ���� (��������) 
  float pyung_area;   // ���� (���) 

  

  printf("����Ʈ�� �о� ����(��������)�� �Է��Ͻÿ�. ");
  scanf("%f", &m2_area);
 
  pyung_area = m2_area / 3.305;

  printf("����Ʈ�� ������ %.1f �Դϴ�.\n", pyung_area);
  
  if(pyung_area >= 50){
    printf("���� ����Ʈ �Դϴ�.");
  }else if(pyung_area >= 30){
    printf("���� ����Ʈ �Դϴ�.");
  }else if(pyung_area >= 15){
    printf("�߼��� ����Ʈ �Դϴ�.");
  }else{
    printf("���� ����Ʈ �Դϴ�.");
  }
  return 0;
}

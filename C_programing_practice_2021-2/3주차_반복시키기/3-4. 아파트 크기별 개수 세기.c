#include <stdio.h>

int main(void) {
  float m2_area;        // ���� (��������)
  float pyung_area;     // ���� (���) 
  int count1 = 0;           // ���� ����Ʈ ���� 
  int count2 = 0;           // �߼��� ����Ʈ ����
  int count3 = 0;           // ���� ����Ʈ ���� 
  int count4 = 0;           // ���� ����Ʈ ���� 
  int i = 0;


  while(i<10){
    printf("����Ʈ�� �о� ����(��������)�� �Է��Ͻÿ�. ");
    scanf("%f", &m2_area);

    pyung_area = m2_area / 3.305;

    printf("--> �� ����Ʈ�� ������ %.1f �Դϴ�.\n", pyung_area);

    if(pyung_area >= 50){
      count4 ++;
    }else if(pyung_area >= 30){
      count3 ++;
    }else if(pyung_area >= 15){
      count2 ++;
    }else{
      count1 ++;
    }
    i++;
  }
  


  printf("\"���� ����Ʈ\"�� ������ %d �Դϴ�.\n", count1);
  printf("\"�߼��� ����Ʈ\"�� ������ %d �Դϴ�.\n", count2);
  printf("\"���� ����Ʈ\"�� ������ %d �Դϴ�.\n", count3);
  printf("\"���� ����Ʈ\"�� ������ %d �Դϴ�.\n", count4);

  return 0;
}

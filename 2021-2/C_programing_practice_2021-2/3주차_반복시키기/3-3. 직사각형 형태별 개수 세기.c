#include <stdio.h>

int main(void) {
  int width, height; // ����ũ��, ����ũ��
  int count1 = 0; // "���簢��"�� ����
  int count2 = 0; // "������ ���簢��"�� ���� 
  int count3 = 0; // "������ ���簢��"�� ���� 


  do{
    printf("���簢���� ���� ũ��� ���� ũ�⸦ �Է��Ͻÿ�. : ");
    scanf("%d %d", &width, &height);

    if(width <= 0 || height <= 0){
      break;
    }
    

    if(width == height){
      count1 ++;
    }else if(width > height){
      count2 ++;
    }else{
      count3 ++;
    }
  }
  while(width > 0 && height > 0);


  printf("\"���簢��\"�� ������ %d �Դϴ�.\n", count1);
  printf("\"������ ���簢��\"�� ������ %d �Դϴ�.\n", count2);
  printf("\"������ ���簢��\"�� ������ %d�Դϴ�.\n", count3);


  return 0;
}

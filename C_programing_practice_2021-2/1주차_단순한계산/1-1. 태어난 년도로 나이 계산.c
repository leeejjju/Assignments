#include <stdio.h>

int main(void) {
  int birth_year; // �¾ �⵵ 
  int age; // ����

  //������� �Է� �ȳ��޽��� ���
  printf("Birth year? ");
  //����ڰ� �¾ �⵵ �Է¹޾� birth_year�� ����
  scanf("%d", &birth_year);
  //�Էµ� birth_year�� �̿��Ͽ� ���� ���, age�� ����
  age = 2021 - birth_year + 1;
  //age ��� 
  printf("%d", age);


  return 0;
}

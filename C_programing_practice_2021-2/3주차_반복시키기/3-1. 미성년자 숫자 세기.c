#include <stdio.h>
/*������ �� ������ �Է¹��� ��, �� �ο� �� ��ŭ �¾ �⵵�� �Է¹����鼭, ���̸� ����Ͽ� �̼����ڰ� ��� �� ������ ��� �϶�.

��, ���� = ���س⵵ ? �¾ �⵵ + 1 �� ����ϰ� ���̰� 20�� �̸��� ���, �̼����ڷ� �����Ѵ�.*/

int main(void) {
  int count_all;      // ���� �ο���
  int count_young = 0;    // �̼������� ��
  int birth_year;     // �¾ �⵵
  int age;            // ����
  int i;              // �ݺ����� ���� ���� 

  printf("���� �ο���? ");
  scanf("%d", &count_all);

  for(i = 0; i < count_all ; i++){
    printf("Birth year? ");
    scanf("%d", &birth_year);
    age = 2021 - birth_year + 1;
    if(age < 20){
      count_young ++;
    }
  }

  printf("������ �� �̼����ڴ� ��� %d���Դϴ�.", count_young);
  
  return 0;
}

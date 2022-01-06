#include <stdio.h>
#include <stdlib.h>
/*�� ���� �Լ��������� Ű�� ������ �����͸� �Է¹޾� �񸸵� �����͸� �ϼ��Ͽ� ����϶�.
�񸸵� ��ġ = ü��(kg) / (����(m)�� ����) ���� ����Ѵ�.
�� ��, ������ ���� ������ ȯ���ؾ� ���� ���� �϶�.

�񸸵� ��ġ�� ���� �񸸵� ����
18.5 �̸� : ��ü��
18.5 ~ 23 �̸� : ����ü��
23~25�̸� : ��ü��
25�̻� : ��

��, main������ ������ ���� ����ü �����͸��� ����ϰ�, addBmi()�� ���� �޸𸮰� �Ҵ�ǵ��� �ؾ� �Ѵ�.
main() �ڵ�� �̹� �����Ǵ� �������� �� ��!
*/

struct st_bmi{
  int height, weight; // Ű(cm), ������(kg)
  float bmi; // �񸸵�
  int bmi_index; // 1,2,3,4 --> ���� ��ü��, ����, ��ü��, ��
};

struct st_bmi* addBmi();
void evalBmi(struct st_bmi* p);

int main(void) {
  struct st_bmi* one;
	char bmi_string[4][20]={"��ü��","����","��ü��","��"};

	one = addBmi();

	printf("Ű: %d ", one->height);
	printf("������: %d ", one->weight);
	printf("�񸸵�: %.1f ", one->bmi);    
    printf("������� : %s\n", bmi_string[one->bmi_index-1]);
	return 0;
}

//-------------------------------------------------

struct st_bmi* addBmi(){
  struct st_bmi* p = (struct st_bmi*)malloc(sizeof(struct st_bmi));
  printf("Ű�� �����Ը� �Է��Ͻÿ� > ");
  scanf("%d %d", &(p->height), &(p->weight));
  evalBmi(p);
  return p;
}
// �Ķ���� : ����
// ���ϰ� : �޸� �Ҵ�޾� Ű, ������, �񸸵�, �񸸵������ ����� ����ü ������

void evalBmi(struct st_bmi* p){
  p->bmi = (p->weight)/((p->height)*(p->height)*0.01*0.01);
  if(p->bmi < 18.5){
    p->bmi_index = 1;
  }else if(p->bmi < 23){
    p->bmi_index = 2;
  }else if(p->bmi < 25){
    p->bmi_index = 3;
  }else{
    p->bmi_index = 4;
  }
	
}
// �Ķ���� : �񸸵� ����ü ������
// ���ϰ� : ����
// ���೻�� : �����ͷ� Ű, �����Ը� ������ �񸸵�, �񸸵������ ����


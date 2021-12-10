#include <stdio.h>
/*����ü�� ����Ͽ� ������ ���Ϸκ��� 5���� ����(cm����)�� ü��(kg����)�� �Է¹޾� �� �߿��� ���� ����� ���ڸ� �ľ��Ͽ� ����϶�.

��, �񸸿��δ� ���� �񸸵� ��ġ�� 25�̻��� ��쿡 "��"���� �Ǵ��Ѵ�.
�񸸵� ��ġ = ü��(kg) / (����(m)�� ����) ���� ����Ѵ�.

�񸸵�������� �����ϴ� �Լ��� �ۼ��Ͽ� ����� ��.*/

struct st_bmi{
    int height, weight; // Ű(cm), ������(kg)
    float bmi; // �񸸵�
    int bmi_index; // 1,2,3,4
};

float evalbmi(int h, int w);

int main(void){
  struct st_bmi man;
  int r, i = 0, count = 0;

  FILE* file;
  file = fopen("data.txt", "r");

  while(!feof(file)){

    r = fscanf(file, "%d %d", &man.height, &man.weight);
    if(r == 2){
      printf("%d��° ����� ����(cm)�� ü��(kg) : %d %d\n", i+1, man.height, man.weight);
      i++;
    }else{
      break;
    }
    man.bmi = evalbmi(man.height, man.weight);
    if(man.bmi >= 25){
      count ++;
    }

  }
  printf("���� ����� %d���Դϴ�.", count);

  return 0;
}

float evalbmi(int h, int w){
  float bmi;
  bmi = w/(h*h*0.01*0.01);
  return bmi;
}
//�Ķ���� : h : ����(cm ����), w : ü��(kg ����)
//���ϰ� : �񸸵�
//���೻�� : �Ķ���ͷ� ���� ����, ü���� ������ �񸸵��� ����Ͽ� ����


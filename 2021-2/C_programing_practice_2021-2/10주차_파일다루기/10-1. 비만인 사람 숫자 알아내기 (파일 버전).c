#include <stdio.h>
/*������ ���Ϸκ��� 5���� ����(cm����)�� ü��(kg����)�� �Է¹޾� �� �߿��� ���� ����� ���ڸ� �ľ��Ͽ� ����϶�. ��, �񸸿��δ� ���� �񸸵� ��ġ�� 25 �̻��� ��쿡 "��"���� �Ǵ��Ѵ�.

�񸸵� ��ġ = ü��(kg) / (����(m)�� ����) ���� ����Ѵ�.

�񸸵� ��� ����� �����ϴ� �Լ��� �ۼ��Ͽ� ����� ��.*/
float evalBmi(int h, int w);

int main(void) {
  float height, weight, bmi;
  int count=0;
  // �� ���� �ڵ带 �ۼ��϶�.
  FILE* file; //�����ڵ鷯 �������� 
  file = fopen("data.txt", "r"); //�б���� ���� ����

  for(int i = 0; i < 5; i++){
    fscanf(file, "%f", &height);
    fscanf(file, "%f", &weight);

    printf("%d��° ����� ����(cm)�� ü��(kg): %.0f %.0f\n", i+1, height, weight);

    if(evalBmi(height, weight) >= 25){
      count ++;
    }
  }

  fclose(file); //���� �ݱ�


  printf("���� ����� %d���Դϴ�.\n", count); 
  return 0;
}

float evalBmi(int h, int w){
  float mh = h*0.01;
  float bmi = w /(mh* mh);
  
  return bmi;
}

//�Ķ���� : h : ����(cm ����), w : ü��(kg ����)
//���ϰ� : �񸸵�
//���೻�� : �Ķ���ͷ� ���� ����, ü���� ������ �񸸵��� ����Ͽ� ������.

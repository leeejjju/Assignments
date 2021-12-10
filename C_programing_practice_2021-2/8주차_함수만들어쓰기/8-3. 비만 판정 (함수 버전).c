#include <stdio.h>
#include <string.h>
#include <math.h>
/*10���� ����(cm����)�� ü��(kg����)�� �Է¹����鼭 askBiman() �Լ��� ���� �̵��� �񸸵��� ����ϰ� ���� ���ؿ� ���� �񸸿��θ� �����Ͽ� ����϶�.

�񸸵� ��ġ = ü��(kg) / (����(m)�� ����) ���� ����Ѵ�.
�� ��, ������ ���� ������ ȯ���ؾ� ���� ���� �϶�.

�񸸵� ��ġ�� ���� �񸸵� ����

18.5 �̸� : ��ü��
18.5 ~ 23 �̸� : ����ü��
23~25�̸� : ��ü��
25~30�̸� : �浵��
30�̻� : ����

int askBiman(int height, int weight);
�Ķ����) height : ����(cm), weight : ü��(kg)
���೻��) �񸸵� ��� �� ������� ����
���ϰ�) ��ü�� 0, ����ü�� 1, ��ü�� 2, �浵�� 3, ���� 4*/

int askBiman(height, weight){
  float bmi = weight / pow(height * 0.01, 2); //�񸸵� ���� ���� bmi 
  int bimando; //�񸸵� ���� 

  if(bmi < 18.5){ //��ü��
    bimando = 0;
  }else if(bmi < 23){ //����ü��
    bimando = 1;
  }else if(bmi < 25){ //��ü��
    bimando = 2;
  }else if(bmi < 30){ //�浵��
    bimando = 3;
  }else{ //���� 
    bimando = 4;
  }

  return bimando;

}

int main(void) {
  int height, weight; // ����(cm), ü��(kg)
  int i; //�ݺ����� ���� ���� 
  char bimando [5][100] = {"��ü��", "����", "��ü��", "�浵��", "����"};

  for(i = 0; i < 10; i++){
    printf("%d��° ��� ����� ü��? ", i+1);
    scanf("%d %d", &height, &weight);
    if(height < 0 || weight < 0){
      printf("�߸� �Է��ϼ̽��ϴ�.\n");
    }else{
      printf("%s\n", bimando[askBiman(height, weight)]);
    }

  }


  
  return 0;
}

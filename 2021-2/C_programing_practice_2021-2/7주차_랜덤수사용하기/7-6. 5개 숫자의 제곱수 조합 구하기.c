#include <stdio.h>
#include <math.h>
// pow() �Լ� Ȱ��

/*2���� 9������ ���� 5���� �Է¹޾� �迭�� ������ ��, �� 5���� ���ڵ� �� ������ 2���� ���� a�� b�� �����Ͽ� a^b�� ���� ����Ͽ� �� �߿��� ���� ū ���� ���� ���� ���� ���� �� �ִ� ��츦 ã�Ƴ���. ��� �� ������ �Լ� pow()�� ����϶�. ���� ��� 2, 3, 4, 5, 6�� �Է��� ��쿡�� ���� ���� ���� 2^3�̰�, ���� ū ���� 5^6�� �ȴ�.*/

int main(void) {
  int number[5];        // �Է¹��� 5���� ����
  int pow_value[5][5];  // ������ �� �� a, b�� ���� �� �ִ� a^b�� �� ��
  int max, min;         // �ִ񰪰� �ּڰ�
  int max_a = 0, max_b = 0;     // �ִ��� ����� ���� ����� a�� b�� ��
  int min_a = 9999, min_b = 9999;     // �ּڰ��� ����� ���� ����� a�� b�� ��
  int i, j, k;             // �ݺ����� ���� ���� 
  int max_index, min_index; //���� ���Ұ� ���ϱ� ���� �ε��� 

  printf("2���� 9 ������ ���� 5���� �Է� \n"); //�Է¹ޱ� 
  for(i = 0; i < 5; i++){
    scanf("%d", &number[i]);
  }

  //�����ϰ� �Ǿյΰ� �ǵڵΰ��� ����
  //�ƴϸ� �ִ밪 �ι����ִ밪 �ּҰ� �ι�°�ּҰ� ������ ���ϱ�... 

  for(i = 0; i < 5; i++){ //�ִ� �ּҰ��� �� �ε��� ���� 
    if(max_b < number[i]){
      max_b = number[i];
      max_index = i;
    }
    if(min_a > number[i]){
      min_a = number[i];
      min_index = i;
    }
  }

  for(i = 0; i < 5; i++){ //���� ���Ұ��� ���ϱ�(�ִ��ּ� �ε��� �����ϰ� �� )
    if(i != max_index && max_a < number[i]){
      max_a = number[i];
    }
    if(i != min_index && min_b > number[i]){
      min_b = number[i];
    }
  }

//�ִ��������� �ּ������� ��� 
  max = (pow(max_a, max_b) > pow(max_b, max_a)) ? pow(max_a, max_b) : pow(max_b, max_a); 
  min = (pow(min_a, min_b) < pow(min_b, min_a)) ? pow(min_a, min_b) : pow(min_b, min_a);

  printf("�Է��Ͻ� 5���� ���� �������� �����...\n");
  if(max == pow(max_a, max_b)){
    printf("���� ū ���� %d�� %d���� %d�Դϴ�.\n", max_a, max_b, max);
  }else{
    printf("���� ū ���� %d�� %d���� %d�Դϴ�.\n", max_b, max_a, max);
  }

  if(min == pow(min_b, min_a)){
    printf("���� ���� ���� %d�� %d���� %d�Դϴ�.", min_b, min_a, min);
  }else{
    printf("���� ���� ���� %d�� %d���� %d�Դϴ�.", min_a, min_b, min);
  }


  return 0;
}

#include <stdio.h>
#include <stdlib.h>
/*�� ���� �Լ��������� Ű�� ������ �����͸� ���Ϸκ��� �Է¹޾� �񸸵� �����͸� �ϼ��Ͽ� ����϶�. ������ �Լ��� ������ ����.
�񸸵� ��ġ = ü��(kg) / (����(m)�� ����) ���� ����Ѵ�. �� ��, ������ ���� ������ ȯ���ؾ� ���� ���� �϶�. 

�񸸵� ��ġ�� ���� �񸸵� ����
18.5 �̸� : ��ü��
18.5 ~ 23 �̸� : ����ü��
23~25�̸� : ��ü��
25�̻� : ��

��, main������ ������ ���� ����ü ������ �迭���� ����ϰ�, load_bmi()�� ���� �޸𸮸� �Ҵ�޵��� �Ѵ�.*/


struct st_bmi{
    int height, weight; 		// Ű(cm), ������(kg)
    float bmi; 				// �񸸵�
    int bmi_index; 			// 1,2,3,4 --> ���� ��ü��, ����, ��ü��, ��
};

int loadBmi(struct st_bmi* list[], char* filename);
void evalBmi(struct st_bmi* p);

int main(void) {
	struct st_bmi* bmilist[50];  // �ִ� 50���� �񸸵� ������
	char bmi_string[4][20]={"��ü��","����","��ü��","��"};
	int count = loadBmi(bmilist, "data.txt");
	// �̰��� �ڵ� �ۼ�!

  printf("%d���� �����͸� �о����ϴ�.\n", count);
  for(int i = 0; i < count; i++){
    evalBmi(bmilist[i]);
    printf("%d�� ��. Ű: %d ������: %d �񸸵�: %.1f ������� : %s\n", i+1, bmilist[i]->height, bmilist[i]->weight, bmilist[i]->bmi, bmi_string[bmilist[i]->bmi_index-1]);
  }
	return 0;
}

int loadBmi(struct st_bmi* list[], char* filename){
  int count = 0;

  FILE* file;
  file = fopen(filename, "r");

  while(!feof(file)){
    list[count] = malloc(sizeof(struct st_bmi));
    int r = fscanf(file, "%d %d", &list[count]->height, &list[count]->weight);
    if(r < 2){
      break;
    }else{
      count++;
    }
  }

  fclose(file);
  return count;
}
// �Ķ���� : ���� �����̸� 
// ���ϰ� : ���� ����ü ������ ��Ʈ�� ����
// ���೻�� : ���Ϸκ��� Ű�� �������� �����͸� �о� list ������ �迭�� ���� �޸𸮸� �Ҵ��Ͽ� Ű, ������, �񸸵�, �񸸵������ ����� ����ü �����Ͱ� ����ǵ��� �� ��, �ϼ��� ������ ������ ����

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

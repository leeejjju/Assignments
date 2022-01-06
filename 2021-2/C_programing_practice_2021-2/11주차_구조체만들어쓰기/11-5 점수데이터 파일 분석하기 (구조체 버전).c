#include <stdio.h>
#include <string.h>
/*����ü�� ����ؼ� ����������(data.txt)�κ��� �̸�, C, Java, Python ���������� �о�鿩 �� ����� ������ ����, ��� �� �� ������ ��հ� ���� ���� ������ ���� ����� �̸�, ������ ����϶�.

���ǻ���- ���Ͽ��� �о�� ���� �̸� Ƚ���� ������ �� ��. (�ִ� 20���� ����)- ������ �д� fscanf()�� ����� �����͸� �о����� Ȯ���ؼ� ������ ������ �� �ֵ��� ó���� ��.*/

/*
1. ���Ͽ��� ���� �о ����ü �迭�� ���� 
  1-1 ���� ����
  1-2 ���ϳ�����... 
    1-2-1 ���� �о� �ν���Ʈ ������ ����
    1-2-2 �о ���������� �˸����� ����ü�� ����, ī��Ʈ ����
2. �о ���� ���, ���� �������� 
  2-1 ī��Ʈ��ŭ ���Ϲݺ�...
    2-1-1 ���
    2-1-2 ���� �������� ����
3. ���� ���, �ְ����л��� ���� ��� (�Լ�:�ְ����л��� �ε��� �����ϴ³����� )
  3-1 ������, �Ķ���ʹ� �Լ����ؼ�. 
*/

struct st_score{
  char name[10]; // �̸� 
  int jumsu[3];  // ���� (C, Java, Python)
  int sum;  // ����
  float avg;  //  ��� 
};

int findBestOne(struct st_score s[20], int sub, int count);


int main(void) {

  struct st_score s[20]; //�л����� ������ ����ü 
  int count = 0; //��ȿ�� �л������� ����ü �ε���
  int sumSub[3] = {0, 0, 0}; //���� ����. ���ʷ� c java py  

//1. ���Ͽ��� ���� �о ����ü �迭�� ���� 
  //1-1 ���� ����
  FILE *file;
  file = fopen("data.txt", "r");
  //1-2 ���ϳ�����... 
  while(!feof(file)){
    //  1-2-1 ���� �о� �ν���Ʈ ������ ����
    char n[10];
    int j0, j1, j2;

    int r = fscanf(file, "%s %d %d %d", n, &j0, &j1, &j2);
      //1-2-2 �о ���������� �˸����� ����ü�� ����, ī��Ʈ ����
    if(r == 4){
      strcpy(s[count].name,n);
      s[count].jumsu[0] = j0;
      s[count].jumsu[1] = j1;
      s[count].jumsu[2] = j2;

      s[count].sum = 0;
      s[count].sum += j0;
      s[count].sum += j1;
      s[count].sum += j2;

      s[count].avg = (float)s[count].sum/3.0;

      count++;
    }
  }
//2. �о ���� ���, ���� �������� 
  //2-1 ī��Ʈ��ŭ ���Ϲݺ�...
  printf("%d records read.\n", count);
  for(int i = 0; i < count; i++){
    //2-1-1 ���
    printf("%-7s %d  %d  %d  %d  %.1f\n", s[i].name,s[i].jumsu[0],s[i].jumsu[1],s[i].jumsu[2],s[i].sum,s[i].avg);
    //2-1-2 ���� �������� ����
    
    sumSub[0] += s[i].jumsu[0];
    sumSub[1] += s[i].jumsu[1];
    sumSub[2] += s[i].jumsu[2];
  
  }
//3. ���� ���, �ְ����л��� ���� ���. (�Լ�:�ְ����л��� �ε��� �����ϴ³����� )
  //3-1 ������, �Ķ���ʹ� �Լ����ؼ�. 



  printf("C - average : %.1f, Top : %s (%d)\n", (float)sumSub[0]/count, s[findBestOne(s, 0, count)].name, s[findBestOne(s, 0, count)].jumsu[0]);
  printf("Java - average : %.1f, Top : %s (%d)\n", (float)sumSub[1]/count, s[findBestOne(s, 1, count)].name, s[findBestOne(s, 1, count)].jumsu[1]);
  printf("Python - average : %.1f, Top : %s (%d)\n", (float)sumSub[2]/count, s[findBestOne(s, 2, count)].name, s[findBestOne(s, 2, count)].jumsu[2]);

  return 0;
}

int findBestOne(struct st_score s[20], int sub, int count){
  int max = 0, maxIndex = 0;

  for(int i = 0; i < count; i++){
    if(s[i].jumsu[sub] > max){
      max = s[i].jumsu[sub];
      maxIndex = i;
    }
  }

  return maxIndex;
}
//����ü �迭�� �����ȣ, �л����� �޾Ƽ� �ְ������� ���� �л��� �ε��� ���� 

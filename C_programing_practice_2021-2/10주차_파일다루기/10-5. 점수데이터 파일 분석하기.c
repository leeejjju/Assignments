#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
/*����������(data.txt)�κ��� �̸�, C, Java, Python ���������� �о�鿩 �� ����� ������ ����, ��� �� �� ������ ��հ� ���� ���� ������ ���� ����� �̸�, ������ ����϶�.

* ���ǻ��� *

���Ͽ��� �о�� ���� �̸� Ƚ���� ������ �� ��. (�ִ� 20���� ����)
������ �д� fscanf()�� ����� �����͸� �о����� Ȯ���ؼ� ������ ������ �� �ֵ��� ó���� ��.
�ʿ��� �Լ��� ������ ���� ����� ����� ��!
*/

/*
1. ���Ͽ��� ���� �о�ͼ� �迭�� �����ϰ�+��������
  1-1 ���� ����
  1-2 ������ ���������...
    1-2-1 ���ڿ�, ����, ����, ������ �о��, �ӽ�����
    1-2-2 4���� �� �о�鿩������ ��迭�� �ӽ����� ���� 
    1-2-3 �ΰ��� ���� ����
    1-2-4 ���� ���� ����
2. ����� �迭 ���
3. ���� �������� ��� 
*/

int findBestOne(int score[3][20], int subNum, int count);

int main(void) {
  char subName[3][20] = {"C", "Java", "Python"}; //�����
  char name[20][20] = {0,}; //�л��̸�(�ִ�20��)
  int score[3][20]; //�л�����(�ִ�20��)
  int stuSum[20] = {0,}; //�л�������(�ִ�20��)
  int subSum[3] = {0,}; //��������
  int count = 0; //��ȿ�� �л��� (20�̳�������...)


//printf("���Ӿ���̺�\n");

//1. ���Ͽ��� ���� �о�ͼ� �迭�� �����ϰ�+��������
  //1-1 ���� ����
  FILE* file;
  file = fopen("data.txt", "r");
  
  //1-2 ������ ���������...
  while(!feof(file)){
    char n[20]; //�ӽ������ �л��̸�
    int s[3];//�ӽ������ �л�����
    int r; //����� �� ���Գ� Ȯ�ο� 
    //1-2-1 ���ڿ�, ����, ����, ������ �о��, �ӽ�����
    r = fscanf(file, "%s %d %d %d", n, &s[0], &s[1], &s[2]);
    //1-2-2 4���� �� �о�鿩������ ��迭�� �ӽ����� ����, �ΰ��� ���� ����, ���� ���� ����
    if(r == 4){ //���ǹ��� ���� ��� �������� 
      strcpy(name[count], n); //�ӽ������ ���� �𿡴ٰ� ī�� 
      for(int i = 0; i < 3; i++){
        score[i][count] = s[i];
        subSum[i] += s[i];
      }
      stuSum[count] = s[0] + s[1] + s[2];
      count++;
    }
  }
  //1-3 ���� �ݱ� 
  fclose(file);


printf("%d records read.\n", count);

//2. ����� �迭 ���
for(int i = 0; i < count; i++){
  printf("%-6s  %d  %d  %d  %d  %.1f\n", name[i], score[0][i], score[1][i], score[2][i], stuSum[i], stuSum[i]/3.0);
}

//3. ���� �������� ��� 
for(int i = 0; i < 3; i++){
  printf("%s - average : %.1f, Top : %s (%d)\n", subName[i], (float)subSum[i]/count, name[findBestOne(score, i, count)], score[i][findBestOne(score, i, count)]);
}
  return 0;
}

int findBestOne(int score[3][20], int subNum, int count){
  int max = 0;
  int maxIndex = 0;

  for(int i = 0; i < count; i++){
    if(max < score[subNum][i]){
      max = score[subNum][i];
      maxIndex = i;
    }
  }

  return maxIndex;
}
///���� �ֵ������� �ε��� ����
//�޴°�... �����迭 score, ����������� ��ȣ subNum, ������� count 

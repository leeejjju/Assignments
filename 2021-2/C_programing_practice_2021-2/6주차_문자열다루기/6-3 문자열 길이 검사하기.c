#include <stdio.h>
#include <string.h>
/*������ �ҽ� �ڵ忡 �־��� 13���� �к��̸� �� ���� �� �Ͱ� ���� ª�� ���� ã�Ƴ��� ����϶�.*/

int main(void) {
  char names[13][100]={"Global Leadership School","International Studies, Languages and Literature","Management and Economics","Law","Counseling Psychology and Social Welfare", "Communication Arts","Spatial Environment System Engineering", "Mechanical and Control Engineering", "Contents Convergence Design","Life Science","Computer Science and Electrical Engineering", "Global Entrepreneurship and ICT","Creative Convergence Education"};
  char maxStr[100], minStr[100]; //���� ��Ͱ� ª�� ���� ������ �迭
  int i; //�ݺ��� ����� ���� ���� 

  strcpy(maxStr, names[0]); //�迭�� ù������ �ʱⰪ ���� 
  strcpy(minStr, names[0]);
  

  for(i = 0; i < 13; i++){ //�ִ��ּұ��� �˻�, ���� 
    if(strlen(names[i]) > strlen(maxStr)){
      strcpy(maxStr, names[i]); //max�� �ش� �迭 ���� 
    }
    if(strlen(names[i]) < strlen(minStr)){
      strcpy(minStr, names[i]); //min�� �ش� �迭 ���� 
    }
  }
  

  printf("���� �� �к� �̸��� %s\n", maxStr);
  printf("���� ª�� �к� �̸��� %s �Դϴ�.", minStr);




  return 0;
}

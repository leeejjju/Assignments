#include <stdio.h>

int main(void) {
  
  int monthdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};;        // 1~12���� �� �� 
  int month, day;           // �Է¹��� ��, ��
  int day_count = 0;            // 1�� �� �� ��
  int i;                    // �ݺ����� ���� ���� 

  printf("Month? ");
  scanf("%d", &month);
  printf("Day? ");
  scanf("%d", &day);

  if(month <= 12 && day <= monthdays[month-1]){
    for(i = 0; i < month -1; i++){ //�Է��� ���� �������� ���� ��� ���ϱ�
    day_count += monthdays[i];
    }
  day_count += day; //�� �� �����ֱ� 
  printf("�� ��¥�� 1�� �� %d��° ���� �ش�", day_count);
  }else{
    printf("�߸� �Է��ϼ̽��ϴ�.");
  }
  

  return 0;
}

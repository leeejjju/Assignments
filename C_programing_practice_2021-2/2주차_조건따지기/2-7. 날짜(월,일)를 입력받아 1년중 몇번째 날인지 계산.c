#include <stdio.h>

int main(void) {
  int month, day;   // ��, ��
  int day_count = 0;    // 1�� �� �� �� 
  int i;

  printf("Month? ");
  scanf("%d", &month);
  printf("Day? ");
  scanf("%d", &day);
  
  //�� ���� �´� ������ �� �� ���ϱ� 
  for(i = 2; i <= month ; i++){
    if(i-1 == 2){
      day_count += 28;
    }else if((i-1) % 2 == 0){//¦���϶�
      if(i-1 > 6){
        day_count += 30; 
      }else{
        day_count += 31;      
      }
    }else{ //Ȧ���϶� 
      if(i-1 > 6){
        day_count += 31;     
      }else{
        day_count += 30;  
      }
    }
  }

  day_count += day + 1;
  
  //�߸��� �� �Է½� �����޼��� ���� 
  if(month > 12 || day > 31){
    printf("�߸� �Է��ϼ̽��ϴ�.");
  }else{
    if( month == 2){
      if(day > 28){
        printf("�߸� �Է��ϼ̽��ϴ�.");
      }else{
        printf("�� ��¥�� 1�� �� %d��° ���� �ش�˴ϴ�.", day_count);
      }
    }else if((month%2 == 0 && month > 7)||(month%2 != 0 && month < 7)){
      if(day > 30){
        printf("�߸� �Է��ϼ̽��ϴ�.");
      }else{
        printf("�� ��¥�� 1�� �� %d��° ���� �ش�˴ϴ�.", day_count);
      }
    }else{
      printf("�� ��¥�� 1�� �� %d��° ���� �ش�˴ϴ�.", day_count);
    }
  }






 // printf("�� ��¥�� 1�� �� %d��° ���� �ش�˴ϴ�.", day_count);
  return 0;
}

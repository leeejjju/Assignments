#include <stdio.h>

  int main(void) {

  int birth_year;       // �Է¹��� �¾ �⵵
  int year[100];        // �� ������� ���� (�ִ� 100��) 
  int count_person = 0;     // �Էµ� �ο� ��
  int count_baby = 0;       // ���� ��
  int count_child = 0;      // ��� ��
  int count_youth = 0;      // û�ҳ� ��
  int count_young = 0;      // û�� ��
  int count_adult = 0;      // �߳� ��
  int count_old = 0;        // ��� ��
  int i = 1;                // �ݺ���, �ε����� ���� ���� 

  while(1){ 
  
  printf("%d��° ����� �¾ �⵵�� �Է��Ͻÿ�. ", i);
  scanf("%d", &birth_year);

  if(birth_year > 2021){
    break;
  }

  year[i] = 2021 - birth_year + 1; //�� ����� ���� ���� 

  if(year[i] >= 60){ //���̿� ���� ���ɴ� ī��Ʈ ���� 
    count_old ++;
  }else if(year[i] >= 30){
    count_adult ++;
  }else if(year[i] >= 20){
    count_young ++;
  }else if(year[i] >= 13){
    count_youth ++;
  }else if(year[i] >= 7){
    count_child ++;
  }else{
    count_baby ++;
  }

  i++; //�ε��� ���� 
  count_person ++; //���α��� ���� 

  
  }


  for( i = 1; i < count_person+1; i++ ){ //����� ���� ��� 
    printf("%d��° ����� ���̴� %d�Դϴ�.\n", i, year[i] );
  }

  printf("���ƴ� %d���Դϴ�.\n", count_baby);
  printf("��̴� %d���Դϴ�.\n", count_child);
  printf("û�ҳ��� %d���Դϴ�.\n", count_youth);
  printf("û���� %d���Դϴ�.\n", count_young);
  printf("�߳��� %d���Դϴ�.\n", count_adult);
  printf("����� %d���Դϴ�.", count_old);



  return 0;
}

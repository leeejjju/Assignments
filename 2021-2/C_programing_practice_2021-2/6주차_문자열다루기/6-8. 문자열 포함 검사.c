#include <stdio.h>
#include <string.h>
/*�ڵ� ���� ������ ���� 13���� �к� �̸��� �־����� ����, 3���� �̻��� �ܾ �ϳ� �Է¹��� ��, �� �ܾ ���� �ϴ� �к� �̸��� ��� ã�Ƴ� �� �к� �̸��� �� ������ ����϶�.*/

int main(void) {

  char names[13][100]={"Global Leadership School",
  "International Studies, Languages and Literature",
  "Management and Economics",
  "Law",
  "Counseling Psychology and Social Welfare",
  "Communication Arts",
  "Spatial Environment System Engineering",
  "Mechanical and Control Engineering",
  "Contents Convergence Design",
  "Life Science",
  "Computer Science and Electrical Engineering",
  "Global Entrepreneurship and ICT",
  "Creative Convergence Education"};
  char word[100]; //�Է¹��� �˻� �ܾ� 
  char same[13][100]; //�˻���� ��ġ�ϴ� ������ ����, ������ ���� 
  int count = 0; //��ġ�ϴ� ���� ��
  int i; //�ݺ��� ����� ���� ���� 


  printf("Input >> ");
  scanf("%s", word);

  for(i = 0; i < 13; i++){ //�˻���� ��ġ �˻� 
    if(strstr(names[i], word)){
      strcpy(same[count], names[i]);
      count++;
    }
  }

  if(strlen(word) < 3){
    printf("3���� �̻� �Է����ּ���.");
  }else{
    printf("Matching : \n");
    if(count != 0){
      for(i = 0; i < count; i++){ //����� ��ġ ���� ����� ��� 
        printf("[%s]\n", same[i] );
      }
    }
    printf("%d major found", count);
  }

  return 0;
}


#include <stdio.h>
/*����ü�� �̿��Ͽ� ���簢�� 2���� �»����� ��ǥ��(x, y)�� �������� ��ǥ��(x, y)�� �Է¹��� �Ŀ� 2���� ���簢���� �����ǥ �󿡼� ��ġ�� �κ��� �ִ����� ���θ� ����϶�.
��, 2���� ���簢���� ��ġ�� ���� �˻��ϴ� ���� �Լ��� ������ ����� ����϶�.*/

struct rectangle{ 
  int x1, y1; // �»��� ��ǥ�� (���� �� �𼭸�) 
  int x2, y2; // ������ ��ǥ�� (���� �Ʒ� �𼭸�) 
}; 

int check_overlap(struct rectangle r1, struct rectangle r2); 

int main(void) {
  struct rectangle r1, r2;

  printf("ù ��° ���簢�� �»��� ��ǥ��(x, y)? ");
  scanf("%d %d", &r1.x1, &r1.y1);
  printf("ù ��° ���簢�� ������ ��ǥ��(x, y)? ");
  scanf("%d %d", &r1.x2, &r1.y2);
  printf("�� ��° ���簢�� �»��� ��ǥ��(x, y)? ");
  scanf("%d %d", &r2.x1, &r2.y1);
  printf("�� ��° ���簢�� ������ ��ǥ��(x, y)? ");
  scanf("%d %d", &r2.x2, &r2.y2);

  if(check_overlap(r1, r2) == 0){
    printf("�� ���簢���� ��ġ�� �ʽ��ϴ�.");
  }else{
    printf("�� ���簢���� ��Ĩ�ϴ�.");
  }

  return 0;
}

int check_overlap(struct rectangle r1, struct rectangle r2){


  if((r2.y2 >= r1.y1)||(r2.y1 <= r1.y2)){
    return 0;
  }else if((r2.x1 >= r1.x2)||(r2.x2 <= r1.x1)){
    return 0;
  }else{
    return 1;
  }


}
 // ��ġ�� 1����, �ƴϸ� 0����

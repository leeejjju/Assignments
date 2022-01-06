#include <stdio.h>
#include <stdlib.h>
/*����ü�� �̿��Ͽ� ���簢�� 2���� �»����� ��ǥ��(x, y)�� �������� ��ǥ��(x, y)�� �Է¹��� �Ŀ� 2���� ���簢���� �����ǥ �󿡼� ��ġ�� �κ��� �ִ����� ���θ� ����϶�.

��, �� ���簢���� �»����� �������� ��ǥ�� �Է¹޴� �Լ��� �����Ͽ� ����϶�. �� �Լ����� ���� �޸𸮸� �Ҵ��ϴ� �۾��� ����Ǿ�� �Ѵ�.

���� 2���� ���簢���� ��ġ���� �˻��ϴ� ���� �Լ��� ������ ����� ����϶�.*/

struct rectangle{ 
 int x1, y1; 		// �»��� ��ǥ�� (���� �� �𼭸�) 
 int x2, y2; 		// ������ ��ǥ�� (���� �Ʒ� �𼭸�) 
}; 

struct rectangle* getPoints();	// ����ü �޸𸮸� �Ҵ�޾� ��ǥ�� �Է¹��� �� �ּҰ� ����

int checkOverlap(struct rectangle* r1, struct rectangle* r2); // ��ġ�� 1����, �ƴϸ� 0����

//main() �Լ��� �ڵ�� ������ ����. (���� ����!)
int main(){
	struct rectangle* rect1;  	// ù ��° ���簢���� ���� ����ü ������
	struct rectangle* rect2;  	// ù ��° ���簢���� ���� ����ü ������
	printf("���簢�� #1\n");
	rect1 = getPoints();
	printf("���簢�� #2\n");
	rect2 = getPoints();
	if (checkOverlap(rect1, rect2)) 
		printf("�� ���簢���� ��Ĩ�ϴ�.\n");
	else
		printf("�� ���簢���� ��ġ�� �ʽ��ϴ�.\n");
	return 0;
}

struct rectangle* getPoints(){
  struct rectangle* p;
  p = malloc(sizeof(struct rectangle));
  printf("�»��� ��ǥ��(x, y)? ");
  scanf("%d %d", &p->x1, &p->y1);
  printf("������ ��ǥ��(x, y)? ");
  scanf("%d %d", &p->x2, &p->y2);
  return p;
}
// ����ü �޸𸮸� �Ҵ�޾� ��ǥ�� �Է¹��� �� �ּҰ� ����

int checkOverlap(struct rectangle* r1, struct rectangle* r2){
  if((r2->y2 >= r1->y1)||(r2->y1 <= r1->y2)){
    return 0;
  }else if((r2->x1 >= r1->x2)||(r2->x2 <= r1->x1)){
    return 0;
  }else{
    return 1;
  }
}
// ��ġ�� 1����, �ƴϸ� 0����



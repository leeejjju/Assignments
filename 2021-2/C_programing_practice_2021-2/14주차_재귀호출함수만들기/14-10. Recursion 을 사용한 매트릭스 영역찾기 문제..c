#include <stdio.h>
void markArea(int p[5][5], int z[5][5], int xpos, int ypos, int area, int value);
void printMatrix(int p[5][5]); // 5*5 ��Ʈ������ ������ ����ϴ� �Լ� 

/*
5*5 ũ���� ��Ʈ������ ǥ�������� ������ �־����� ����, �� ���Ͼȿ� ���� �ٸ� �������� ������ �� �ִ� ������ ��� ����� ã�Ƴ��� ǥ���϶�.

��, ���ϰ��� 0�� ���� ������� �����ϸ�, ��/��/��/�쿡 ������ ĭ�� ���� ���� ����ִ� ��쿡�� ���� �������� �����Ѵ�.

��, ���ϰ��� ������ ������ ĭ�� �ƴ� ��� �ٸ� �������� �ν��Ͽ��� �Ѵ�.

�־��� �����Լ� �� printMatrix()�Լ��� ���� ���� �״�� ����ϰ�, markArea()�Լ��� �����ϵ�, �ݵ�� ����Լ��� �����϶�.

1. picture.txt ������ �о� 5*5 ��Ʈ������ picture�� ä��� ����Ѵ�.
2. ������ ũ���� zone ��Ʈ������ �غ��Ѵ�.(�ʱⰪ 0)
3. picture ��Ʈ������ ù��° ĭ���� �����Ͽ� markArea�� ���� ������ ������ ã���鼭 zone ��Ʈ������ ������ȣ�� ä���.
4. picture ��Ʈ������ ������ Ȯ���ߴٸ� ��ģ ��
5. ������ ������ zone ��Ʈ������ ������ ����Ѵ�.*/

int main(void) {
  int picture[5][5]={0}; // ���� ���� 
  int zone[5][5] = {0};  // ����ǥ�ÿ� ����
	int row = 5, col = 5;      // ����, ���� ũ��
	int area = 0;            // ������ȣ

  //���Ϸκ��� �о�� picture �迭 ä��� 
  FILE *fp = fopen("picture.txt", "rt"); 
  for(int i= 0; i < row; i++){
    for(int j= 0; j < col; j++)
      fscanf(fp, "%d", &picture[i][j]);
  }
  fclose(fp);

  //picture �迭�� ä���� �ʾ� ��� 
	printMatrix(picture);

  //zone�迭�� picture���, ������ ��ġ ���� �������� ä��� 
  for(int i=0; i < row; i++){
    for(int j=0; j < col; j++){
    	if(picture[i][j] != 0 && zone[i][j]==0){ 
      // ���� ���ϰ��� 0�� �ƴϰ�, ���� ����üũ�� �ȵ� ���
      	area++; // ���ο� ���� ����
				int value = picture[i][j]; // ���ϰ�
        //printf("���ϰ� %d��(��) area %d�� ä��ڽ��ϴ�\n", value, area);
      	markArea(picture, zone, i, j, area, value); 
        //�� ĭ���κ��� ���� ���ϰ��� ��� ������ ã�� ��ũ�϶�.
      }
    }
  }
  
  //zone�迭�� ä���� ��� ��� 
	printf("\n%d areas found.\n\n", area);
	printMatrix(zone);
}  

//---------------------------------------------------------------

void printMatrix(int p[5][5]){
  for(int i=0; i < 5; i++){
    for(int j=0; j < 5; j++){
      printf("%d ", p[i][j]);
    }
    printf("\n");
  }	
}

//---------------------------------------------------------------

void markArea(int p[5][5], int z[5][5], int xpos, int ypos, int area, int value){

  if(xpos < 0 || xpos > 4) return;
  if(ypos < 0 || ypos > 4) return;
  if(z[xpos][ypos] != 0) return;
  if(p[xpos][ypos] != value) return;
  if(p[xpos][ypos] == 0) return;

  //printf("��� [%d][%d]���ٰ� area %d������� �ѽ��ѽ�\n", xpos, ypos, area);

  //�� ��� ������..�丮���� ���ߴٸ� 
  z[xpos][ypos] = area; //zone�� ��ũ���ְ�
  //�����¿� ����
  markArea(p, z, xpos-1, ypos, area, value);
  markArea(p, z, xpos+1, ypos, area, value);
  markArea(p, z, xpos, ypos-1, area, value);
  markArea(p, z, xpos, ypos+1, area, value);

}
//���೻�� : ������Ʈ����(p)�� xpos, ypos ĭ���κ��� ����Ͽ� ����� �����鼭, value���� ��ġ�ϴ� ĭ�� ���� ������Ʈ����(z)�� ���� ��ġ ĭ�� ������ȣ(area)�� �ִ´�.

//return���� 
  //1. ���ο� xȤ�� y�� ������ ���
  //2. z���� �ش� ĭ�� �̹� ��ũ��
  //3. ���ο� p���� ���� value�� �ٸ� 
  //4. ���ο� p���� ���� 0��(�ٴ���)
  //5. ���� �� ��찡 �ƴ϶�� ���ο� ��ġ�� ���� ��濡 �Լ� ���� 




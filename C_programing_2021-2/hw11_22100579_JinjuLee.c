/*����11) MAGIC SQUARE ��� ���α׷�

������ ũ���� magic square ���

�Է� : magic square size (1���� ū Ȧ�� ��)
��� : ������ ũ���� magic square
*/

#include <stdio.h>

int main(void){
	int size = 0; //�Է¹��� ������   
	int i = 0, j = 0; //�ݺ����� ���� ����  
	int a , b; //������ �� ��ġ�� ��Ÿ�� ����  
	
	
	while(!(size%2 == 1 && size > 1)){
		printf("magic square�� ũ�⸦ �Է����ּ���(1���� ū Ȧ�� ��) : ");
		scanf("%d", &size);
	}
	
	int array[size+1][size+1]; //magic square�� �Է��� �迭 ����(��������)  	
		
	for(i = 0; i < size+1; i++){ // �迭 �ʱ�ȭ(��ĭ �÷���)  
		for(j = 0; j < size+1; j++){
			if(i == size || j == size){ //�����Ʒ��� ���鿡�� ������ �ֱ�  
				array[i][j] = -1;
			}else{
				array[i][j] = 0;
			}
		}
	}
	
	
	a = size-1; //������ �ּ��� �������� ����(�� ���� ���), ���۰�(1) �ֱ�  
	b = size/2;
	array[a][b] = 1; 

	
	for(i = 0; i < size*size-1; i++){ //�������� �� �ֱ� 
	 
		a++, b++; //���� �Ʒ�ĭ���� �̵�
		
		if(array[a][b] == 0){ //����ִ� ĭ�� ���  
			array[a][b] = i+2; // �ش� ��ġ�� �� �ֱ�  
		}else if(array[a][b] > 0){//�ٸ� ���� ä�������� ���  
			a--; //���� ��ĭ �̵� �� �� �ֱ� 
			array[a][b] = i+2; 
		}else{//���� ���� ���(�ش� ������ ������ ������� ��) 
			if(a == size && b == size){ //���� ���ϴ��� ���  
				a = 0, b = 0; //ùĭ���� �̵� �� �� �ֱ�  
				array[a][b] = i+2;
			}else if(a == size){ //���� ����� ���  
				a = 0; //�ֻ������ �̵� �� �� �ֱ�  
				array[a][b] = i+2;
			}else{ //���� ����� ���  
				b = 0; //���� ������ �̵� �� �� �ֱ�  
				array[a][b] = i+2;
			}
		}	
	}
	
	printf("\n\n[%d * %d magic square]\n\n", size, size);
	
	for(i = 0; i < size; i++){ //������ ���  
		for(j = 0; j < size; j++){
			printf(" %d ", array[i][j]);
		}
		printf("\n\n");
	}

	
	//what is this....  
	
	
	return 0;
}
 

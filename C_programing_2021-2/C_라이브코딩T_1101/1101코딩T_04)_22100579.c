/*1101�ڵ�T_04)_22100579
4. � �־��� ������ ��¥�� ������ ���° ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.
(�� 2���� ��¥���� 28�Ϸ� ������ �� )
*/
#include <stdio.h>

int main(void){
	
	int month, day;
	int i, sum = 0; //����� ���� ���غ����� �մϴ�...  
	
	printf("��¥�� �Է��ϼ���(M D) : ");
	scanf("%d %d", &month, &day);
	

	if(month != 1){
		for(i = 1; i < month; i++){ //���� �ش��ϴ� �ϼ��� ���ϴ� �ݺ���  
			if(i == 2){  
				sum += 28;
			}else if((i == 4 || i == 6) || (i == 9 || i == 11)){ //30��¥�� ����  
				sum += 30;
			}else{
				sum += 31;
			}
		}	
	}

	sum += day;	
	printf("%d", sum);	
	
	return 0;
}
   

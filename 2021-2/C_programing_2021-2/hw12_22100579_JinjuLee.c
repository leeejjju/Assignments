/*����12) �Է¹��� ���� �޷� ����ϱ�
������ ��, �� (�� �� �� �Է�)�� ���� �޷��� ����ϴ� program�� �ۼ��Ͻÿ�.
*/
 
#include <stdio.h>

int main(void){
	int year, month, yoil, numOfDays;
	int i, sum = 0, count = 0;
	
	printf("�⵵�� ���� �Է��ϼ��� (Y M) : ");
	scanf("%d %d", &year, &month);
	
	i = year - 1900;
	
	while(1){ //�⵵�� �ش��ϴ� �ϼ��� ���ϴ� �ݺ��� 
		
		if(i == 0){ //���� Ż�� ����  
			break;
		}
		
		if((i%4 == 0 && i%100 != 100)|| i%400 == 0){ //�����ǵ�, ������ ��  
			sum += 366;
		}else{ //����� ��  
			sum += 365;
		}		
		
		i --;	
	}
	
	if(month != 1){
		for(i = 1; i < month; i++){ //���� �ش��ϴ� �ϼ��� ���ϴ� �ݺ���  
			if(i == 2){ //�� �����ǵ�...  
				if((i%4 == 0 && i%100 != 100)|| i%400 == 0){ //�����ǵ�, ������ ��  
					sum += 29;
					numOfDays = 29;
				}else{ //����� ��  
					sum += 28;
					numOfDays = 28;
				}
			}else if((i == 4 || i == 6 ) || ( i == 9 || i == 11)){ //30��¥�� ����  
				sum += 30;
				numOfDays = 30;
			}else{
				sum += 31;
				numOfDays = 31;
			}
		}	
	}
	
	sum += 1; //1���� �����ϹǷ�  
	yoil = sum % 7;
	
	
	int days[numOfDays];
	for(i = 0; i<numOfDays; i++){ //�迭�� ��¥ �� �����ϱ�  
		days[i] = i+1;
	}
	
	count = yoil + 1; //���Ͽ� ���� ī��Ʈ�� �ʱⰪ ����(1~7) 
	
	printf("Sun    Mon    Tue    Wed    Thu   Fri    Sat\n");
	
	for(i = 0; i < yoil; i++){
		printf("       ");
	}
	
	i = 0;
	
	while(1){ //�޷��� �� �� 
	
		if(i > numOfDays - 1){ //Ż������  
			break;
		} 
		
		printf("%2d     ", days[i]); 
			
		if(count%7 == 0){ //�ٹٲ�   
			printf("\n");	
		}	
		
		count ++;
		i ++;		
	} 

	
	return 0;
}

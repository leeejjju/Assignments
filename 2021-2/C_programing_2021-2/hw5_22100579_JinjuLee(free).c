//C�ǽ� ����5

//� �־��� ����(y�� m�� d�� ���� ���� ���ϴ� ���α׷�
// ����� ����  2020 9 15 >> 2020 9 16/ 2019 2 28 >> 2019 3 1 

#include <stdio.h>

int main(void){
	
	int year, month, day;
	int endDay; //�� ���� ������ ������ ����  
	
	printf("�� �� ���� �Է����ּ��� : ");
	scanf("%d %d %d", &year, &month, &day);
	
	
	if( month == 12 && day== 31 ){ //�����ϰ�� �⵵ ����  
		year += 1;
		month = 1;
		day = 1;
		
		printf("\n������ : ");
		printf("%d %d %d", year, month, day);
		
	}else{
		if( month == 2){ //2���� ���  
			if(year%4 == 0 && year%100 != 100){ //�����Ǻ� 
				endDay = 29;
			}else{
				if(year%400 == 0){
					endDay = 29;
				}
				endDay = 28;
			}
		}else if((month%2 == 0 && month < 7)||(month%2 != 0 && month >= 7)){ //30�ϱ����� ���  
			endDay = 30;
		}else{ //���� Ȧ���϶�  
			endDay = 31;
		}
	
		if( day == endDay){ //������ ���  
			month += 1;
			day = 1;
			printf("\n������ : ");
			printf("%d %d %d", year, month, day);
			
		}else{
			if(day > endDay || month > 12){
				printf("�߸� �Է��ϼ̽��ϴ�.");
			}else{
				day += 1;
				printf("\n������ : ");
				printf("%d %d %d", year, month, day);
			}
	
		}
		
	}
	
	return 0;
}

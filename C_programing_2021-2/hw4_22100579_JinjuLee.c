//C�ǽ� ����4

//� �־��� ����(y�� m�� d�� ���� ���� ���ϴ� ���α׷�
// ����� ����  2020 9 15 >> 2020 9 16/ 2019 2 28 >> 2019 3 1 

#include <stdio.h>

int main(void){
	
	int year, month, day;
	int endDay; //�� ���� ������ ������ ����  
	
	printf("�� �� ���� �Է����ּ��� : ");
	scanf("%d %d %d", &year, &month, &day);
	
	
	switch (month){ //�� ���� ���������� ������  
		
		case 2 :  if(year%4 == 0 && year%100 != 100){ //�����Ǻ� 
					  endDay = 29;
				  }else{
					  if(year%400 == 0){
						  endDay = 29;
					  }
				  	  endDay = 28;
			  	  }
				  break;
			
		case 4 :
		case 6 :
		case 9 :
		case 11 : endDay = 30;
				  break;
		
		default : endDay = 31;
				  break;
	}
	
	
	if( month == 12 && day== 31 ){ //�����ϰ�� �⵵ ����  
		year += 1;
		month = 1;
		day = 1;
		
		printf("\n������ : ");
		printf("%d %d %d", year, month, day);
		
	}else{
		
		if( day == endDay){ //������ ���  
			month += 1;
			day = 1;
			printf("\n������ : ");
			printf("%d %d %d", year, month, day);
	
		}else{ 
			if(day > endDay || month > 12){ //�ٸ��� ���� ��¥�� �Է½�  
				printf("�߸� �Է��ϼ̽��ϴ�.");
			}else{ //�ùٸ� ��¥�� �Է½� ��¥�� +1  
				day += 1;
				printf("\n������ : ");
				printf("%d %d %d", year, month, day);
			}	
			
		}		
		
	}	
	return 0;
}

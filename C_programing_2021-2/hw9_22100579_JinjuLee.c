/*����9) �޷� ��� ���α׷�  
� ��(month)�� 1���� ����(0 ? 6)�� ��¥���� �Է����� �޾�, 
�޷��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

��)  �Է�
     1���� ���� : ( 0: Sun,  1:Mon, 2:Tue, 3:Wed, 4:Thu, 5:Fri, 6:Sat) :  3
     Number of days :  31
<���>
    Sun    Mon    Tue    Wed    Thu   Fri    Sat
                           1      2      3      4
      5      6       7        8      9     10     11
     12     13     14       15     16     17     18
     19     20     21       22     23     24     25
     26     27     28       29     30     31
      
     */
     
#include <stdio.h>

int main(void){
	
	int yoil, numOfDays;
	int i, count;
	
	printf("1���� ���� : ( 0: Sun,  1:Mon, 2:Tue, 3:Wed, 4:Thu, 5:Fri, 6:Sat) :  ");
	scanf("%d", &yoil);
	
	printf("Number of days :  ");
	scanf("%d", &numOfDays);
	
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

/*��???12) ??��????? ��??? ��?��? ??��?????
?????? ��?, ?? (��? ?? ��? ??��?)?? ��??? ��?��??? ??��???��? program?? ??????��???.
*/
 
#include <stdio.h>

int main(void){
	int year, month, yoil, numOfDays;
	int i, sum = 0, count = 0;
	
	printf("��????? ��??? ??��??????? (Y M) : ");
	scanf("%d %d", &year, &month);
	
	i = year - 1900;
	
	while(1){ //��????? ??��???��? ????��? ��???��? ?????? 
		
		if(i == 0){ //��??? ???? ??��?  
			break;
		}
		
		if((i%4 == 0 && i%100 != 100)|| i%400 == 0){ //??��?????, ??��??? ?��  
			sum += 366;
		}else{ //??��??? ??  
			sum += 365;
		}		
		
		i --;	
	}
	
	if(month != 1){
		for(i = 1; i < month; i++){ //???? ??��???��? ????��? ��???��? ??????  
			if(i == 2){ //?? ??��?????...  
				if((i%4 == 0 && i%100 != 100)|| i%400 == 0){ //??��?????, ??��??? ?��  
					sum += 29;
					numOfDays = 29;
				}else{ //??��??? ??  
					sum += 28;
					numOfDays = 28;
				}
			}else if((i == 4 || i == 6 ) || ( i == 9 || i == 11)){ //30????��? ????  
				sum += 30;
				numOfDays = 30;
			}else{
				sum += 31;
				numOfDays = 31;
			}
		}	
	}
	
	sum += 1; //1???? ???��????��?  
	yoil = sum % 7;
	
	
	int days[numOfDays];
	for(i = 0; i<numOfDays; i++){ //???��?? ��??? ��? ????????  
		days[i] = i+1;
	}
	
	count = yoil + 1; //?????? ??��? ???????? ????��? ?��?��(1~7) 
	
	printf("Sun    Mon    Tue    Wed    Thu   Fri    Sat\n");
	
	for(i = 0; i < yoil; i++){
		printf("       ");
	}
	
	i = 0;
	
	while(1){ //��?��??? ?? ?? 
	
		if(i > numOfDays - 1){ //??????��?  
			break;
		} 
		
		printf("%2d     ", days[i]); 
			
		if(count%7 == 0){ //????��?   
			printf("\n");	
		}	
		
		count ++;
		i ++;		
	} 

	
	return 0;
}

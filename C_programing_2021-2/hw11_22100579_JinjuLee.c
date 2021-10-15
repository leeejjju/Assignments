/*과제11) MAGIC SQUARE 출력 프로그램

지정한 크기의 magic square 출력

입력 : magic square size (1보다 큰 홀수 값)
출력 : 지정한 크기의 magic square
*/

#include <stdio.h>

int main(void){
	int size = 0; //입력받을 사이즈   
	int i = 0, j = 0; //반복문을 위한 변수  
	int a , b; //마방진 내 위치를 나타낼 변수  
	
	
	while(!(size%2 == 1 && size > 1)){
		printf("magic square의 크기를 입력해주세요(1보다 큰 홀수 값) : ");
		scanf("%d", &size);
	}
	
	int array[size+1][size+1]; //magic square를 입력할 배열 선언(여백포함)  	
		
	for(i = 0; i < size+1; i++){ // 배열 초기화(한칸 늘려서)  
		for(j = 0; j < size+1; j++){
			if(i == size || j == size){ //우측아래측 여백에는 음수값 넣기  
				array[i][j] = -1;
			}else{
				array[i][j] = 0;
			}
		}
	}
	
	
	a = size-1; //마방진 주소의 시작지점 설정(맨 밑줄 가운데), 시작값(1) 넣기  
	b = size/2;
	array[a][b] = 1; 

	
	for(i = 0; i < size*size-1; i++){ //마방진에 값 넣기 
	 
		a++, b++; //우측 아래칸으로 이동
		
		if(array[a][b] == 0){ //비어있는 칸일 경우  
			array[a][b] = i+2; // 해당 위치에 값 넣기  
		}else if(array[a][b] > 0){//다른 값이 채워져있을 경우  
			a--; //위로 한칸 이동 후 값 넣기 
			array[a][b] = i+2; 
		}else{//영역 밖일 경우(해당 공간에 음수가 들어있을 떄) 
			if(a == size && b == size){ //우측 최하단일 경우  
				a = 0, b = 0; //첫칸으로 이동 후 값 넣기  
				array[a][b] = i+2;
			}else if(a == size){ //행을 벗어났을 경우  
				a = 0; //최상단으로 이동 후 값 넣기  
				array[a][b] = i+2;
			}else{ //열을 벗어났을 경우  
				b = 0; //좌측 끝으로 이동 후 값 넣기  
				array[a][b] = i+2;
			}
		}	
	}
	
	printf("\n\n[%d * %d magic square]\n\n", size, size);
	
	for(i = 0; i < size; i++){ //마방진 출력  
		for(j = 0; j < size; j++){
			printf(" %d ", array[i][j]);
		}
		printf("\n\n");
	}

	
	//what is this....  
	
	
	return 0;
}
 

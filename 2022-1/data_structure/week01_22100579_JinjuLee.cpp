#include <iostream>
using namespace std;

//데이타구조 1주차2 과제 


void my_sort(int list[], int num); //리스트를 받아와 정렬함
void swap(int* a, int* b); //두개의 정수를 교체  


int main(){
	
	int list[10] = {23, 11, 15, 8, 17, 33, 7, 14, 19, 21};
	int i;
	
	my_sort(list, 10); //배열 list의 원소 10개를 sort하는 함수 
	for(i = 0; i < 10; i++){ //화면상에 결과 출력  
		cout << list[i] << "\n";
	}
	
	return 0;
}


void my_sort(int list[], int num){
	int i, j;
	int temp;
	
	//bubble sort
	for(i = 0; i < num; i++){ 
		for(j = 0; j < num-i; j++){ //max를 깎아나가며  
			if(j+1 < num-i && list[j] > list[j+1]){
				swap(&list[j], &list[j+1]);
			}
		}
	}
	
	/*
	//selection sort
	int min = 0; //최소값의 인덱스 
	
	for(i = 0; i < num; i++){ 
		min = i;
		for(j = i; j < num; j++){ //min을 채워나가며  
			if(list[j] < list[min]) min = j;
		}
		swap(list[i], list[min]);
	}
	*/
}

void swap(int* a, int* b){
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}



// c���α׷��� ����2
// �� ���� ������ �Է� �޾�, �ִ밪, �ּҰ� �� ��հ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

#include <stdio.h>

int main(void){

    int fst, snd, trd;
    int max, min;
	float ave;
    int i;

    scanf("%d %d %d", &fst, &snd, &trd);
    
    max = fst;
    min = fst;
    ave = fst;
    
    if(fst > snd){ //�ִ밪 ã��  
    	if(fst > trd){
    		max = fst;
		}else{
			max = trd;
		}
	}else if(snd > trd){
		max = snd;
	}else{
		max = trd;
	}
	
	if(fst < snd){ //�ּҰ� ã��  
    	if(fst < trd){
    		min = fst;
		}else{
			min = trd;
		}
	}else if(snd < trd){
		min = snd;
	}else{
		min = trd;
	}
    
    ave = (fst + snd + trd) / 3.0 ; //��հ� ���ϱ�

    printf("�ְ��� %d, �ּڰ��� %d, ����� %f�Դϴ�.", max, min, ave ); //����� ����մϴ� 

    return 0;
}

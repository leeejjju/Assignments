// c���α׷��� ����2
// �� ���� ������ �Է� �޾�, �ִ밪, �ּҰ� �� ��հ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

#include <stdio.h>
#include <limits.h>

int main(void){

    int array[3];
    int max = INT_MIN, min = INT_MAX, sum = 0;
    int i;

    scanf("%d %d %d", &array[0], &array[1], &array[2]); //�迭�� ������� �Է��� ���ڸ� ���� 

    for(i = 0; i < 3; i++){ //�ִ밪�� max�� �����մϴ� 
        if(max < array[i]){
            max = array[i];
        }
    }

    for(i = 0; i < 3; i++){ //�ּҰ��� min�� �����մϴ�
        if(min > array[i]){
            min = array[i];
        }
    }

    for(i = 0; i < 3; i++){ //�� ���� ���� ��ġ�� ����ϴ�
        sum += array[i];
    }

    printf("�ְ��� %d, �ּڰ��� %d, ����� %d�Դϴ�.", max, min, sum/3 ); //����� ����մϴ� 

    return 0;
}

// c���α׷��� ����1 
// //����(Celsius) �µ��� ȭ��(Fahrenheit) �µ��� ��ȯ�ϴ� ���α׷��� �ۼ� �Ͻÿ�.
// �Է� : ���� �µ��� ��
// ��� : �Է� ���� ���� ȭ�� �µ� ��
//�� =�� * 1.8000+ 32.00

#include <stdio.h>

int main(void){
    float cel, fah ;
    printf("���� �µ��� �Է��ϼ��� : ");
    scanf("%f", &cel );
    fah =(cel * 1.800) + 32.00;

    printf("%f ��", fah);


    return 0;
}

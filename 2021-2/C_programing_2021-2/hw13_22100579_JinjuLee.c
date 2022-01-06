// c���α׷��� ����13
/*�Ʒ� ǥ�� �������� ����Ǵ� �����Ϳ� ���Ͽ� (����/�й�/�г�/�߰����/�⸻���) 
���� ����� �����ϴ� ���α׷��� menudriven ������� �ۼ��Ͻÿ�. 

<�޴�����>
���ϴ� ����� �����Ͻÿ�.

	1. ������ �߰�
	2. ������ ����
	3. ��ü ��Ȳ ����
	4. ������ ��ȸ
	5. ����
	
	��� ����:_
	
 <��� ����>
1. ������ �߰� : �� �л��� ���� ������ �߰��ϴ� ����, �ʱ� empty list���� ����, ��
100������� �׸��� ������ �� �ֵ��� ����
2. ������ ���� : ������ ���ϴ� �л��� ����(�й����� ����)�Ͽ� ��Ͽ��� ����, �ش�
�й��� ������ ������ ���� ó��(�޽��� ���)
3. ��ü ��Ȳ ���� : ��ü ��� ��� �� ��� ����(���ο�, �߰���� ���, �⸻��� ���
�� ���), empty list�̸� ������ ������ ������ �޽��� ���
4. ������ ��ȸ : ����(�й�����)�� �л��� ������ ������ ���, �ش� �й��� ������ ��
���� ���� ó��(�޽��� ���)
5. ���� : ���α׷��� ������
��Ÿ �߰� ��� �� �������̽� ����� �����Ӱ� â�������� �ۼ��� �� */

//1. �л����� ����ü �����... 
//2. ����ü�� ���ҷ� ���� �迭..?
#include <stdio.h>
#include <string.h>

struct student{
	char name[20]; //�̸�  
	char number[10]; //�й� 8�ڸ� 
	int grade; //�г�(1,2,3,4) 
	float midJumsu; //�߰���� ���� 
	float finJumsu; //�⸻��� ����  
}list[100]; //100����� ���� ������ ����Ʈ  

void addStudentData();
void removeStudentData(char num[]);
void printStudentData();
void searchStudentData(char num[]);

int count = 0; //������� ����� ��ȿ�� �л� ��. ��� �Լ����� ���� �����ϵ��� �۷ι��� ����.  
int i; //�ݺ����� ���� ����. ��� �Լ����� ���� �����ϵ��� �۷ι��� ����.   

int main(void){
	int command; //����ڿ��� �Է¹޾� �ش� ����� �����ų ����  
	char number[10]; //����ڿ��� �Է¹޾� �ʿ��� �Լ��� �Ķ���ͷ� ���޵� �й� ���ڿ�  

	
	
	while(1){
		
		
		//�������̽� ���  
		printf("\n\n- - - - - - - - - - - - - - - - - - - -\n");
		printf("\n���ϴ� ����� �����Ͻÿ�.\n\n");
		printf("	1. ������ �߰�\n	2. ������ ����\n	3. ��ü ��Ȳ ����\n	4. ������ ��ȸ\n	5. ����\n\n");
		printf("			��� ����:");
		scanf("%d", &command);
		
		//�������� �Է¹��� Ŀ��忡 ���� ������ ���� ����  	
		if(command == 1){
			printf("\n������ �߰��� �����մϴ�...\n\n");
			addStudentData();
			
		}else if(command == 2){
			printf("\n������ ���Ÿ� �����մϴ�...\n\n");
			printf("������ �������� �й��� �Է����ּ���:");
			scanf("%s", number);
			removeStudentData(number);
			
		}else if(command == 3){
			printf("\n��ü ��Ȳ�� ����մϴ�...\n\n");
			printStudentData();
			
		}else if(command == 4){
			printf("\n������ ��ȸ�� �����մϴ�...\n\n");
			printf("��ȸ�� �������� �й��� �Է����ּ���:");
			scanf("%s", number);
			searchStudentData(number);
			
		}else if(command == 5){
			printf("\n���α׷��� �����մϴ�...");
			break;
		}else{
			printf("�ùٸ� ��ɾ �Է����ּ���(1~5)");
		}
		
	} 
	
	printf("\n�̿����ּż� �����մϴ� :-)"); 
	return 0;
} 

//�Լ� 1. ������ �߰�
void addStudentData(){
	
	printf("%d��° �л� ������ �߰��մϴ�. \n\n", count+1);
	
	printf("�л� �̸��� �Է��ϼ���:");
	scanf("%s", &list[count].name); 
	printf("�й��� �Է��ϼ���:");
	scanf("%s", &list[count].number); 
	printf("�г��� �Է��ϼ���:");
	scanf("%d", &list[count].grade); 
	printf("�߰���� ������ �Է��ϼ���:");
	scanf("%f", &list[count].midJumsu); 
	printf("�⸻��� ������ �Է��ϼ���:");
	scanf("%f", &list[count].finJumsu); 
	
	count ++; //��� �Ѹ� �Է¹޾����� �л��� ����  
	
	
}
	//�� �л��� ���� ������ �߰�
	//�� 100����� ���� �����ϵ��� ���� 



//�Լ� 2. ������ ����
void removeStudentData(char num[]){
	int index = -1; //�ߺ� �ε����� ã�� ������ ���� �Ǻ��� �ʱⰪ ����  
	
	for(i = 0; i < count; i++){//����Ʈ�� �� ������ ��ġ�ϴ� �й��� ����?  ã�� �ε����� ����  
		if(strcmp(num, list[i].number) == 0){
			index = i;
			break;
		} 	
	}
	
	if(index == -1){ //�ߺ� �ϳ��� ��ã�� ������� ������...(�ʱⰪ���� �� ��ȭ�� ���ٸ�) 
		printf("\n�Է��Ͻ� �й��� �л��� �����Ϳ� �����ϴ�.\n");
		return;
		
	}else{
		for(i = index; i < count; i++){ //�ε����κ��� �������� ��ĭ�� ������ �����... !
			strcpy(list[i].name, list[i+1].name);
			strcpy(list[i].number, list[i+1].number);
			list[i].grade = list[i+1].grade;
			list[i].midJumsu = list[i+1].midJumsu;
			list[i].finJumsu = list[i+1].finJumsu;			
		} 
		
		count --;//���� �Ѹ� �������ٴ� ��. ���� �Է��� �ߺ����� ���� �������� �׳��� ������ �Էµ� ����.  
		printf("\n���������� �����߽��ϴ�.\n");
				
	}
	
}
	//�й����� ������ �л��� �����͸� ��Ͽ��� ����. 
	//�ش� �й��� ������ ������ ����ó��(�޼��� ���) 


//�Լ� 3. ��ü ��Ȳ ����
void printStudentData(){
	float sumMid = 0, sumFin = 0; //�߰��⸻ ������ �����Ͽ� ���� ����. ��ձ��ϱ��.  
	
	if(count == 0){
		printf("���� ������ ����\n");
		return;
	}

	//1. ��ü ��� ����ϸ� ��հ�� ���� ������ �ױ� 
	printf("\n\n���� / �й� / �г� / �߰���� / �⸻���\n");
	for(i = 0; i < count; i++){
		printf("%s / %s / %d / %.2f / %.2f\n", list[i].name, list[i].number, list[i].grade, list[i].midJumsu, list[i].finJumsu);
		sumMid += list[i].midJumsu;
		sumFin += list[i].finJumsu;
		
	}
	//2. ������� ��� �������Ͽ� ��� 
	printf("\n�� �ο��� %d���Դϴ�.\n", count);
	printf("�߰���� ��� ������ %.2f��, �⸻��� ��� ������ %.2f���Դϴ�.\n", sumMid/count, sumFin/count); 
	
	
	
}
	//��ü ��� ��� �� �������(���ο�, �߰���� ���, �⸻��� ���)���.
	//�� ����Ʈ�� '���� ������ ����' �޼��� ���  


//�Լ� 4. ������ ��ȸ
void searchStudentData(char num[]){
	int index = -1; //�ߺ� �ε����� ã�� ������ ���� �Ǻ��� �ʱⰪ ���� 
	
	for(i = 0; i < count; i++){//����Ʈ�� �� ������ ��ġ�ϴ� �й��� ����?  ã�� �ε����� ����  
		if(strcmp(num, list[i].number) == 0){
			index = i;
			break;
		} 	
	}
	
	if(index == -1){  //�ߺ� �ϳ��� ��ã�� ������� ������...(�ʱⰪ���� �� ��ȭ�� ���ٸ�) 
		printf("\n�Է��Ͻ� �й��� �л��� �����Ϳ� �����ϴ�.\n");
		return;
		
	}else{ //�ش� �ε����� ����ü ���� ���  
		printf("�˻� ���:\n");
		printf("%s / %s / %d / %.2f / %.2f\n", list[index].name, list[index].number, list[index].grade, list[index].midJumsu, list[index].finJumsu);
	}	
	
}
	//�й����� ������ �л��� ������ ������ ���
	//�ش� �й� ������ ������ ���� ó��(�޼��� ���) 

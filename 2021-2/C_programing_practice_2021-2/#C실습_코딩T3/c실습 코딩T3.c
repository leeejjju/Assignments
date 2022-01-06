// �й� : 22100579
// �̸� : ������
// �� �����ִ� �ϳ��԰� ��� �տ��� �̹� �ڵ� �׽�Ʈ�� �����ϰ� �����ϰ� �ֽ��ϴ�

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct st_class{
	int code;		// �����ڵ�
	char name[30]; 	// �����̸�
	int unit;		// ������
	int grading;	// �򰡹�� (1:grade, 2:pass/fail)
};

char kname[2][10] = {"Grade", "P/F"}; // �򰡹�� ǥ�� ���ڿ�
int i, j;
// �̹� ������ �Լ�
int loadData(struct st_class* c[]); // ���Ͽ��� ������� ������ ����� �о�´�.
void printAllClasses(struct st_class* c[], int csize); // ��ü ������� ����� ����Ѵ�.

// �ڵ带 �����ؾ� �ϴ� �Լ�
int addNewClass(struct st_class* c[], int csize); // ��������� �� ������ �߰��Ѵ�.
void editClass(struct st_class* c[], int csize); // ������� �� ������ �����Ѵ�.
void findClasses(char* name, struct st_class* c[], int csize); // ����������� �����̸��� �˻��Ѵ�.

// �����ؾ� �ϴ� �Լ�

int applyMyClasses(int my[], int msize, struct st_class* c[], int csize); // ���� ��û�ϱ�
void printMyClasses(int my[], int msize, struct st_class* c[], int csize); // �� �������� ����ϱ�
void saveMyClass(int my[], int msize, struct st_class* c[], int csize); // �� �������� ������ �����Ѵ�.
void saveAllClasses(struct st_class* c[], int csize); //������� ������ �����Ѵ�.
int deleteMyClass(int my[], int msize, struct st_class* c[], int csize);//�������� öȸ 


int main(void) {

	int no;	// �۾���ȣ 
	struct st_class* classes[50]; // ������� (�ִ� 50�� ������)

	int myclass[10]; // �� �������� ��� (�ִ� 10������ �����ڵ尡 ����)
	int mycount = 0; // �� �������� ����

	srand(time(0));

	int count = loadData(classes);
	printf("%d���� ������ ������ �о����ϴ�.\n", count);

	while(1){
		printf("\n[�۾�] 1.������� 2.�����߰� 3.������� 4.����˻� 5.������û 6.�� �������� 7.���� 8.����öȸ 0.����\n");
		printf("�۾� ��ȣ��? > ");
		scanf("%d", &no);

		if(no == 1){ 
			printf(">> 1.������� (�� %d����)\n", count);
			printAllClasses(classes, count);
		}
		else if(no == 2){ 
			printf(">> 2.������� �����߰�\n");
			count = addNewClass(classes, count);
		}
		else if(no == 3){ 
			printf(">> 3.������� �������\n");
			editClass(classes, count);
		}
		else if(no == 4){
			printf(">> 4.������� �˻�\n");
			printf("�˻��� ���� �̸���? > ");
			char name[30];
			scanf("%s", name);
			findClasses(name, classes, count);
		}
		else if(no == 5){
			printf(">> 5.������û\n");
			mycount = applyMyClasses(myclass, mycount, classes, count);
			printf("%d������ ������û�Ͽ����ϴ�.\n", mycount);
		}
		else if(no == 6){
			printf(">> 6.�� ��������\n");
			printMyClasses(myclass, mycount, classes, count);
		}
		else if(no == 7){
			printf(">> 7.����\n");
			saveMyClass(myclass, mycount, classes, count);
			printf("\nmy_classes.txt�� �� ���������� �����߽��ϴ�.\n");
			saveAllClasses(classes, count);
			printf("\nclasses.txt�� ��������� �����߽��ϴ�.\n");
		}else if(no == 8){
	      printf(">>8. ����öȸ\n");
	      mycount = deleteMyClass(myclass, mycount, classes, count);
	    }
		else break;
	}
	return 0;
}

//�ϼ��� �Լ���
int loadData(struct st_class* c[]){
	int count = 0;

	FILE* file;

	file=fopen("classes.txt", "r");

	while(!feof(file)){
		c[count] = (struct st_class*)malloc(sizeof(struct st_class));
		int r = fscanf(file, "%d %s %d %d", &(c[count]->code),c[count]->name, &(c[count]->unit), &(c[count]->grading));
		if(r < 4) break;
		count++;
	}
	fclose(file);

	return count;
}

//�ϼ��� �Լ��� 
void printAllClasses(struct st_class* c[], int csize){

	for(i=0; i<csize; i++){
		printf("[%d] %s [%d���� - %s]\n",c[i]->code, c[i]->name, c[i]->unit, kname[c[i]->grading-1]);
	}

}

//�ϼ��� �Լ���
void saveAllClasses(struct st_class* c[], int csize){
	FILE* file;
	file = fopen("classes.txt", "w");
	for(i=0; i<csize; i++){
		fprintf(file, "%d %s %d %d\n",c[i]->code, c[i]->name, c[i]->unit, c[i]->grading);
	}
	fclose(file);	
}

//�ϼ��� �Լ���
void findClasses(char* name, struct st_class* c[], int csize){
	int count = 0;

	printf("���� �˻� (�˻��� : %s)\n", name);
	for(i=0; i<csize; i++){
		if(strstr(c[i]->name, name)){
			printf("[%d] %s [%d���� - %s]\n",c[i]->code, c[i]->name, c[i]->unit, kname[c[i]->grading-1]);
			count++;
		}
	}
	printf("%d�� ������ ã�ҽ��ϴ�.\n", count);
}


/////////// �Ʒ� �Լ��� �̿ϼ� �κ��� �ϼ���ų ��! ////////////////
int addNewClass(struct st_class* c[], int csize){
// ��ǥ : ������ �ڵ��� �������� �߰����� �ʵ��� �����Ͻÿ�.
//�����ؾ� �ϴ� ���� : ������ �߰��� ���� �̹� ��ϵ� �����ڵ尡 �߰����� �ʵ��� �ڵ带 �����϶�.
	struct st_class* p = (struct st_class*)malloc(sizeof(struct st_class));
//0. joong =0;
  int joong = 0;


  //1. ���ϸ� ���ѹݺ�(while(1))
  while(1){
    //1-1 �ϴ� ���� �Է¹ޱ���
    printf("�����ڵ� > ");
    scanf("%d", &(p->code));
    //1-2 �ߺ��˻�for, ���� �ߺ� ã���� >>�ߺ��ֵ�!�˷��ְ�, �ߺ��̶�� ���� ���� joong=1 break;
    for(i = 0; i < csize; i++){
      if(p->code == c[i]->code){
        printf("�̹� ��ϵ� �����ڵ��Դϴ�.\n");
        joong = 1;
        break;
      }
    }
    
    if(joong){
      joong = 0;
    }else{
      break;
    }
    //1-3 �ߺ��־���?if �־����� >>joong = 0
      //�������� break;
  }

    //------------------------------------------
	printf("�����̸� > ");
	scanf("%s", p->name);
	printf("������ > ");
	scanf("%d", &(p->unit));
	printf("�򰡹��(1:Grade, 2: P/F) > ");
	scanf("%d", &(p->grading));

	c[csize] = p;
	return csize+1;
}
/*
0. joong =0;
1. ���ϸ� ���ѹݺ�(while(1))
  1-1 �ϴ� ���� �Է¹ޱ���
  1-2 �ߺ��˻�for, ���� �ߺ� ã���� >>�ߺ��ֵ�!�˷��ְ�, �ߺ��̶�� ���� ���� joong=1 break;
  1-3 �ߺ��־���?if �־����� >>joong = 0
    �������� break;

*/

void editClass(struct st_class* c[], int csize){
	struct st_class* p;
	int code;
  //0. ã�ѳ����� found = 0, index
  int found = 0, index;
  //1. �ϴ� �Է¹ް�
  printf("�����Ϸ��� �����ڵ带 �Է��ϼ��� > ");
	scanf("%d", &code);

  //2. �ߺ��˻�? ã��? for >>ã���� ã�Ҵٰ� �������� fouond = 1, �ε��� ����  break
  for(i = 0; i < csize; i++){
    if(code == c[i]->code){
      found = 1;
      index = i;
      break;
    }
  }

  if(found){
    p = c[index];
  }else{
    printf("�������� �ʴ� �����ڵ��Դϴ�.\n");
    return;
  }

  //3. ifã�Ѵ���, ã������ c[i]�����͸� p�� �������ݴϴ�. 
    //3-2 ��ã������? ��ã�ٴ� ���ϱ�, return.

// �� �κп��� code ������ p�����Ϳ� ������ ���� ã�� �־��ִ� �ڵ带 �ϼ��Ͻÿ�.
//�����ؾ� �ϴ� ���� : �����ڵ带 �Է¹��� ��, �����۾��� �����ϱ� ���� ������ü �������� ���� �Ҵ��ϴ� ������ �ڵ忡 �ݿ��Ͽ� �����϶�. �� ��, �����ڵ尡 �������� �ʴ� ��쵵 �����ϰ� ó���϶�.
/*
0. ã�ѳ����� found = 0, index
1. �ϴ� �Է¹ް�
2. �ߺ��˻�? ã��? for >>ã���� ã�Ҵٰ� �������� fouond = 1, �ε��� ����  break
3. ifã�Ѵ���, ã������ c[i]�����͸� p�� �������ݴϴ�. 
  3-2 ��ã������? ��ã�ٴ� ���ϱ�, return.
*/

	printf("[%d] %s [%d���� - %s]\n",p->code, p->name, p->unit, kname[p->grading-1]);
	printf("�����̸�(����) > ");
	scanf("%s", p->name);
	printf("������(����) > ");
	scanf("%d", &(p->unit));
	printf("�򰡹��(����)(1:Grade, 2: P/F) > ");
	scanf("%d", &(p->grading));
	
	printf("�����߽��ϴ�.\n");

}


/////////// �Ʒ� �Լ��� ���� ������ ��! ////////////////

//�� �������� ����ϱ�
int applyMyClasses(int my[], int msize, struct st_class* c[], int csize){

  //yes(����Ұǰ�), joong =0, found=0, mycount = msize 
  int yes, joong = 0, found = 0, mycount = msize, code;
  //0. ���ϸ� ���ѹݺ�... \

  while(1){
    //1. ���ϸ� ���ѹݺ�...

    while(1){
      //1-1 �Է¹ް�
      printf("�����Ϸ��� ���� �ڵ带 �Է��ϼ��� >\n");
      scanf("%d", &code);
      //1-2 �����ϰ� �޾ҳ� Ȯ��
        //1-2-1 �̹� ��û�Ѱ���, ����������� �ߺ��˻�
      for(i = 0; i < mycount; i++){
        if(code == my[i]){
          joong = 1;
          break;
        }
      }
        //1-2-2 �����ϴ��ڵ�����. ���������� �ߺ��˻�
      for(i = 0 ; i < csize; i++){
        if(code == c[i]->code){
          found = 1;
          break;
        }
      }

      //1-3 �� �޾����� found=0�ϰ� break, �ƴϸ� (joong==1, found !=1)�����޼��� ��� (������ ���� �� �ʱ�ȭ��)
      if(joong){
        joong = 0;
        printf("�̹� ��û�� �����Դϴ�.\n");
      }else if(found != 1){
        printf("�����ڵ尡 �߸��Ǿ����ϴ�.\n");
      }else{
        found = 0;
        my[mycount] = code;
        mycount ++;
        break;
      }
    }
    //2. ��� �Է¹����� my�迭�� ����, mycount++
    //3. ��� �Է¹������� �����. no�ϸ� break. 

    printf("��� �Է��ϽǱ��?(1:�� 2:�ƴϿ�)) >\n");
    scanf("%d", &yes);
    if(yes == 2){
      break;
    }

  }
	return mycount;
}
//�Ķ���� : ���� ��û�� �����ڵ� �迭, ���� ��û�� ���� ����, ������� ����ü������ �迭, ������� ���� ����
//���ϰ� : ����� �� �������� ����
//�ϴ� �� : �����ڵ带 �Է¹޾� �� ������û ������ �߰��� ����ϴ� ������ �ݺ��ϴٰ� ������ ���� ��ϵ� �� ���������� ������ �����Ѵ�.
/*
yes(����Ұǰ�), joong =0, found=0, mycount = msize 
0. ���ϸ� ���ѹݺ�... \

  1. ���ϸ� ���ѹݺ�...
    1-1 �Է¹ް�
    1-2 �����ϰ� �޾ҳ� Ȯ��
      1-2-1 �̹� ��û�Ѱ���, ����������� �ߺ��˻�
      1-2-2 �����ϴ��ڵ�����. ���������� �ߺ��˻�
    1-3 �� �޾����� found=0�ϰ� break, �ƴϸ� (joong==1, found !=1)�����޼��� ��� (������ ���� �� �ʱ�ȭ��)

  2. ��� �Է¹����� my�迭�� ����, mycount++
  3. ��� �Է¹������� �����. no�ϸ� break. 

4. n������ ������û�Ͽ����ϴ�. ���, return mycount

*/

//�����Ϸ��� ���� �ڵ带 �Է��ϼ��� >
//�����ڵ尡 �߸��Ǿ����ϴ�.
//�̹� ��û�� �����Դϴ�. 

//��� �Է��ϽǱ��?(1:�� 2:�ƴϿ�)) >

//2������ ������û�Ͽ����ϴ�.


//�� �������� ����ϱ�
void printMyClasses(int my[], int msize, struct st_class* c[], int csize){
  //0. sum=0; 
  int sum = 0;
  //1. mysize�� ���� �ݺ�for
  for(i = 0; i < msize; i++){

    //1-1 csize�� ������...(for)
    for(j = 0; j < csize; j++){
      //1-1-2 my[i]�� �ڵ尡 ��ġ�ϴ� c�� ���� ���, ���� �������ϱ�,break
      if(my[i] == c[j]->code){
        printf("%d. [%d] %s [%d���� - %s]\n", i+1, c[j]->code, c[j]->name, c[j]->unit, kname[c[j]->grading-1]);
        sum += c[j]->unit;
        break;
      }
    }
  }
  //2. �� �������� ��� 
  printf("�� ��������: %d���� \n", sum);


}
//�Ķ���� : ���� ��û�� �����ڵ� �迭, ���� ��û�� ���� ����, ������� ����ü������ �迭, ������� ���� ����
//���ϰ� : ����
//�ϴ� �� : ���� ������û ������ ��� ���������� ����Ѵ�.

/*
0. sum=0; 
1. mysize�� ���� �ݺ�for
  1-1 csize�� ������...(for)
    1-1-2 my[i]�� �ڵ尡 ��ġ�ϴ� c�� ���� ���, ���� �������ϱ�,break
2. �� �������� ��� 
*/


// 1. [101] C���α׷��� [3���� - Grade]'''
//�� ��������: 4���� 



//�� �������� ���Ϸ� �����ϱ�
void saveMyClass(int my[], int msize, struct st_class* c[], int csize){

  //0. apoint, gpoint, ppoint =0=0=0
  int apoint = 0, gpoint = 0, ppoint = 0;

  //1. �����ڵ鷯 ����, ���� ���� 
  FILE* file;
  file = fopen("my_classes.txt", "w");

  //2. ���Ͽ� ����
    //2-1 (*�� ���� ����)
    fprintf(file, "*�� ���� ����\n");
    //2-2 for������ misize��ŭ ���� �ݺ�
  for(i = 0; i < msize; i++){
    //1-1 csize�� ������...(for)
    for(j = 0; j < csize; j++){
      //1-1-2 my[i]�� �ڵ尡 ��ġ�ϴ� c�� ���� ���, ���� �������ϱ�,break
      if(my[i] == c[j]->code){
        fprintf(file, "%d. [%d] %s [%d���� - %s]\n", i+1, c[j]->code, c[j]->name, c[j]->unit, kname[c[j]->grading-1]);
        apoint += c[j]->unit;
        if(c[j]->grading == 1){
          gpoint +=c[j]->unit;
        }else{
          ppoint += c[j]->unit;
        }
        break;
      }
    }
  }
    
      //2-2-1 [101] C���α׷��� [3���� - Grade]'''���
      //2-2-2 ������Ʈ ����

      //2-2-3 ���ǿ� �°� g����Ʈ�� p����Ʈ ����
    //2-3 ��������? ��� 
  fprintf(file, "�� ���� ����: %d����, %d����(Grade %d����, P/F %d����)\n", msize, apoint, gpoint, ppoint);

  //3. ���� �ݱ�
  fclose(file);

}
//�Ķ���� : ���� ��û�� �����ڵ� �迭, ���� ��û�� ���� ����, ������� ����ü������ �迭, ������� ���� ����
//���ϰ� : ����
//�ϴ� �� : ���� ������û ������ ��� ���������� my_classes.txt ���Ϸ� �����Ѵ�.
//���Ͽ� �����ؾ� �ϴ� ���� : ���� ��û�� ���� ���� ��� (�����ڵ�, �����, ������, �򰡹��), �� ��������, �򰡹�ĺ� ��������, ��������� ��

/*
0. apoint, gpoint, ppoint =0=0=0

1. �����ڵ鷯 ����, ���� ���� 

2. ���Ͽ� ����
  2-1 (*�� ���� ����)
  2-2 for������ misize��ŭ ���� �ݺ�
    2-2-1 [101] C���α׷��� [3���� - Grade]'''���
    2-2-2 ������Ʈ ����
    2-2-3 ���ǿ� �°� g����Ʈ�� p����Ʈ ����
  2-3 ��������? ��� 

3. ���� �ݱ�
*/

/*�� ���� ����
1. [101] C���α׷��� [3���� - Grade]'''
�� ���� ����: 5����, 12����(Grade 11����, P/F 1����)
*/

//�������� öȸ 
int deleteMyClass(int my[], int msize, struct st_class* c[], int csize){
  int code, yes, found = 0, index;

  //1. �����ϰ���� ���� �Է¹ޱ�(�ڵ�)
  printf("����öȸ�� ���� �ڵ带 �Է��ϼ���\n");
  scanf("%d", &code);
    //1-1 �������� �������� ã��(for, found, index����) >> ��ã���� return msize
  for(i = 0; i < msize; i++){
    if(code == my[i]){
      found = 1;
      index = i;
      break;
    }
  }

  //2. ã������, ���� ���� ���
  if(found != 1){
    printf("�������� ������ �ƴմϴ�.\n");
    return msize;
  }else{
    for( j = 0; j < csize; j++){
          //1-1-2 my[i]�� �ڵ尡 ��ġ�ϴ� c�� ���� ���, ���� �������ϱ�,break
      if(my[index] == c[j]->code){
        printf("%d. [%d] %s [%d���� - %s]\n", j+1, c[j]->code, c[j]->name, c[j]->unit, kname[c[j]->grading-1]);
        break;
      }
    }
  }

  //3. ��¥ �����Ұ��� �����(yes), no�ϸ� return msize
  printf("������ ����öȸ �Ͻðڽ��ϱ�?(yes: 1, no : 2)\n");
  scanf("%d", &yes);

  if(yes == 2){
    return msize;
  }

  //4. �����ϱ� 
    //4-1 �Ʊ� ������ index���� �����ϴ� for��
    for(i = index; i < msize; i++){
      //4-1-1 my[index] = my[index+1];
      if(i <= msize-1){
        my[i] = my[i+1];
      }
    }
  printf("����öȸ �Ǿ����ϴ�.\n");
  //5. ���� msize-1
  return msize-1;
}
/*
1. �����ϰ���� ���� �Է¹ޱ�(�ڵ�)
  1-1 �������� �������� ã��(for, found, index����) >> ��ã���� return msize
2. ã������, ���� ���� ���
3. ��¥ �����Ұ��� �����(yes), no�ϸ� return msize
4. �����ϱ� 
  4-1 �Ʊ� ������ index���� �����ϴ� for��
    4-1-1 my[index] = my[index+1];
    4-1-2 index+1 = msize �� �Ǹ� break 
5. ���� msize-1

*/

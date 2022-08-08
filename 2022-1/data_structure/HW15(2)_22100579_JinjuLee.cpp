#include <iostream>
using namespace std;

//soroting 설명을 위해 int배열에 맞추어 간단화 시킴. 

//swap two records
void swap(int* a, int* b){
      int tmp = *a;
      *a = *b;
      *b = tmp;
}

//show the list
void show_thelist(int s[], int n){
      for(int i = 0; i < n; i++){
            cout << s[i] << " ";
      }
      cout << endl;
}


//insertion sort
void insertion_sort(int arry[], int n){
      int tmp;
      int index = 1;

      for(int i = 1; i < n ; i++){ //start index
            index = i;
            tmp = arry[index];
            while(index > 0 && (tmp < arry[index-1])){
                  arry[index] = arry[index-1];
                  index --;
            }
            arry[index] = tmp;
      }

}

//selection sort
void selection_sort(int arry[], int n){

      for(int i = 0; i < n; i++){ //start index
            //find min value
            int* min = &arry[i];
            for(int j = i+1; j < n; j++){ 
                  if(*min > arry[j]) min = &arry[j];
            }
            swap(arry[i], *min);
      }
}

//bubble sort
void bubble_sort(int arry[], int n){

      for(int i = n; i >= 0 ; i--){ //range
            for(int j = 1; j < i; j++){ //sorting circles range
                  if(arry[j-1] > arry[j]){
                        swap(arry[j-1], arry[j]);
                  } 
            }
      }
}

//quick sort
void quick_sort(int arry[], int left, int right){

      if(left >= right) return; //return if size of list is under 1
      int pivot = arry[left]; //set the pivot as first record
      int i = left, j = right+1; //index for compare

      do{
            do{ i++; }while((i <= right) && (arry[i] < pivot)); //go forward till found bigger value then pivot
            do{ j--; }while((j >= left) && (arry[j] > pivot)); //go backward till found less value then pivot
            if(i < j) swap(arry[i], arry[j]); //swap swap

      }while(i < j);
      
      swap(arry[j], arry[left]); //swap pivot and middle value
      quick_sort(arry, left, j-1); //recursivly call
      quick_sort(arry, j+1, right);

}


//adjust the heap(customized, about the heap starts from index 0.)
/*
parent = (k-1)/2 
left child = 2*k + 1 
right child = 2*k + 2
*/
void adjust(int arry[], int k, int n){

      int child;
      int tmp;

      tmp = arry[k]; //save the root record
      child = 2*k + 1; //init child

      while(child <= n){
            //select bigger child to compare with parent
            if((child < n) && (arry[child] < arry[child+1])) child ++;
            //compare root and child
            if(tmp > arry[child]) break; //작으면 거기로 결정. 거기가 어딘데? 현재 child의 부모위치. 
            else{
                  arry[(child-1)/2] = arry[child]; //끌어올리고 내려가. child를 부모위치로 승격시키고 다음 도전자 선정. 
                  child = child*2 + 1 ;
            }
      }
      arry[(child-1)/2] = tmp;
}

//heap sort
void heap_sort(int arry[], int n){

      int i;
      int size = n-1;
      //init heap
      for(i = (size-1)/2; i >= 0; i--){
            adjust(arry, i, size);
      }

      //sorting
      for(int i = size-1; i >= 0; i--){
            swap(arry[0], arry[i+1]);
            adjust(arry, 0, i);
      }

}

void merge(int a[], int b[], int n1, int n2, int n3, int n4){

      int i = n1, j = n3, k = n1, t;
      //merge (a to b)
      while((i <= n2) && (j <= n4)){
            if(a[i] <= a[j]) {
                  b[k++] = a[i++];
            }else {
                  b[k++] = a[j++];
            }
      }
      //move remain records at a to b
      if(i > n2){
            for(t = j; t <= n4; t++){
                  b[t] = a[t]; 
            }
      }else{
            for(t = i; t <= n2; t++){
                  b[k+t-i] = a[t];
            } 
      }
}

void merge_pass(int a[], int b[], int n, int s){
      int i, j;

      for(i = 0; i < (n - 2*s + 1); i += 2*s){
            merge(a, b, i, i+s-1, i+s, i+2*s-1);
      } 
      //if the lenth of remain list is bigger than s, merge others. 
      if(i+s <= n){
            merge(a, b, i, i+s-1, i+s, n);
      }else{ //if not, just copy b to a 
            for(j = i; j <= n; j++){
                  b[j] = a[j]; 
            }
      } 
}

//merge sort
void merge_sort(int arry[], int n){

      int size = 1;
      int b[n];

      while(size < n){
            merge_pass(arry, b, n-1, size);
            size = size* 2;
            merge_pass(b, arry, n-1, size);
            size = size* 2;
      }
}




int main(){
      int s_list[10] = { 5, 6, 2, 8, 9, 1, 7, 4, 3, 0};
      int    n = 10;

      //insertion_sort(s_list, n);
      //bubble_sort(s_list, n);
      //selection_sort(s_list, n);

      //quick_sort(s_list, 0, n-1);
      //heap_sort(s_list, n); 
      merge_sort(s_list, n);
      

      cout << "\n< The result of the sorting >" << endl;
      show_thelist(s_list, n);

      return 0;
      

}
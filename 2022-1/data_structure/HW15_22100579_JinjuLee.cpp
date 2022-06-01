#include <iostream>
using namespace std;

//데이타구조 Programming Assignment 15
//22100579 이진주

//6개의 sort algorithm을 적용한 function 구현
//아래의 main() 함수가 동작하도록 구성하시오. 

class s_record{
      //data
      string s_id;
      string name;
      double score;

      public:
      s_record(){};
      s_record(string nID, string nName, double nScore){ //constructor
            s_id = nID;
            name = nName;
            score = nScore;
      }
      string getID()
      {return s_id;}
      string getName()
      {return name;}
      double getScore()
      {return score;}
};


//6 sorting methods
void insertion_sort(s_record s[], int n);
void bubble_sort(s_record s[], int n);
void selection_sort(s_record s[], int n);
void quick_sort(s_record s[], int left, int right);
void merge_sort(s_record s[], int n);
void heap_sort(s_record s[], int n);

void swap(s_record* a, s_record* b); //swap two records
void show_thelist(s_record s[], int n); //show the list


int main(){
      s_record s_list[12] = { 
            {"21900013", "Kim ", 6.5}, {"21900136", "Lee ", 8.8 }, {"21900333", "Park", 9.2 }, 
            { "21800442", "Choi", 7.1}, {"21900375", "Ryu ", 5.4  }, {"21700248", "Cho ", 6.3 },
            { "21700302", "Jung", 8.3}, {"21800255", "Han ", 6.9  }, {"21800369", "Kang", 6.3 },
            { "21900401", "Yang", 9.1}, {"21800123", "Moon", 8.1  }, {"21700678", "Seo ", 7.9 } 
      };
      int    n = 12;

      //insertion_sort(s_list, n);
      //bubble_sort(s_list, n);
      selection_sort(s_list, n);

      //quick_sort(s_list, 0, n-1);
      //merge_sort(s_list, n);
      //heap_sort(s_list, n); 

      cout << "\n< The result of the sorting >" << endl;
      show_thelist(s_list, n);

      return 0;
      

}


//6 sorting methods
//insertion sort
void insertion_sort(s_record s[], int n){
      s_record tmp;
      int index = 1;

      for(int i = 1; i < n ; i++){ //start index
            index = i;
            tmp = s[index];
            while(index > 0 && (tmp.getID() < s[index-1].getID())){
                  s[index] = s[index-1];
                  index --;
            }
            s[index] = tmp;
      }

}

//bubble sort
void bubble_sort(s_record s[], int n){

      for(int i = n; i >= 0 ; i--){ //range
            for(int j = 1; j < i; j++){ //sorting circles range
                  if(s[j-1].getID() > s[j].getID()){
                        swap(s[j-1], s[j]);
                  } 
            }
      }

}

//selection sort
void selection_sort(s_record s[], int n){

      for(int i = 0; i < n; i++){ //start index
            //find min value
            s_record* min = &s[i];
            for(int j = i+1; j < n; j++){ 
                  if(min->getID() > s[j].getID()) min = &s[j];
            }

            swap(s[i], *min);
            //cout << i+1 <<"st min value is " << s[i].getID() << ", " <<  s[i].getName() << endl;
      }
}


//quick sort
void quick_sort(s_record s[], int left, int right){
      

}

void merge_sort(s_record s[], int n){

}

void heap_sort(s_record s[], int n){

}


//swap two records
void swap(s_record* a, s_record* b){
      s_record tmp = *a;
      *a = *b;
      *b = tmp;
}

//show the list
void show_thelist(s_record s[], int n){
      for(int i = 0; i < n; i++){
            cout << s[i].getID() << " : " << s[i].getName() << " : " << s[i].getScore() << endl;
      }
      cout << endl;
}


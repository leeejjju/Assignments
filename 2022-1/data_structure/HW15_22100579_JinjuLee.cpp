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
      s_record(string nID, string nName, double nScore){ //constructor
            s_id = nID;
            name = nName;
            score = nScore;
      }
};


//6 sorting methods
void insertion_sort(s_record s[], int n);
void bubble_sort(s_record s[], int n);
void selection_sort(s_record s[], int n);
void quick_sort(s_record s[], int n);
void merge_sort(s_record s[], int n);
void heap_sort(s_record s[], int n);

void show_thelist(s_record s[], int n); //show the list


int main(){
      s_record s_list[12] = { {"21900013", "Kim ", 6.5}, {"21900136", "Lee ", 8.8 }, {"21900333", "Park", 9.2 }, 
                  { "21800442", "Choi", 7.1}, {"21900375", "Ryu ", 5.4  }, {"21700248", "Cho ", 6.3 },
                  { "21700302", "Jung", 8.3}, {"21800255", "Han ", 6.9  }, {"21800369", "Kang", 6.3 },
                  { "21900401", "Yang", 9.1}, {"21800123", "Moon", 8.1  }, {"21700678", "Seo ", 7.9 } };
      int    n = 12;

      //insertion_sort(s_list, n);
      bubble_sort(s_list, n);
      //selection_sort(s_list, n);

      //quick_sort(s_list, 0, n-1);
      //merge_sort(s_list, n);
      //heap_sort(s_list, n); 

      cout << "< The result of the sorting >" << endl;
      show_thelist(s_list, n);

      return 0;
      

}


//6 sorting methods
void insertion_sort(s_record s[], int n){

}

void bubble_sort(s_record s[], int n){

}

void selection_sort(s_record s[], int n){

}

void quick_sort(s_record s[], int n){

}

void merge_sort(s_record s[], int n){

}

void heap_sort(s_record s[], int n){

}


//show the list
void show_thelist(s_record s[], int n){
      
}
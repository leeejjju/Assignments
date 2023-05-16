#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>
#include <chrono> 

/*
ref: 
강의 slide: knapsack. page12-29
공식 reference: https://cplusplus.com/reference/algorithm/
Blog: https://notepad96.tistory.com/40
Hyperscale AI ChatGPT
*/

// #define DEBUG
using namespace std;
using namespace std::chrono;

struct item{
    int value;
    int weight;
    float valuePerWeight;
};

//structor for problem. 
struct problem{
    int maxCapacity = 0;
    vector<item> items;
} Q;

//for branch and bound
struct node{
    long long benefit;
    long long weight;
    double bound;
    int itemIndex;
};

//for debug, show the values of Q
void showQ(){
    printf("value: ");
    // for(int i = 0; i < Q.value.size(); i++) printf("%d ", Q.value.at(i));
    for(int i = 0; i < Q.items.size(); i++) printf("%d ", Q.items.at(i).value);
    printf("\nweight: ");
    for(int i = 0; i < Q.items.size(); i++) printf("%d ", Q.items.at(i).weight);
    printf("\nvalue per weight: ");
    for(int i = 0; i < Q.items.size(); i++) printf("%.1f ", Q.items.at(i).valuePerWeight);
    printf("\n");
}

//for sorting value per weight
int descItem(struct item a, struct item b){
    return (a.valuePerWeight > b.valuePerWeight);
}

//for find max among nodes
bool ascNode(struct node a, struct node b) { 
    return a.bound < b.bound; 
}

//generate Random benefit value Vs and weight Ws with number of item n(input) and save in input structor q.
int generateRandomValues(int n) {
    Q.maxCapacity = n * 25;
    Q.items.clear();
    
    srand(100);// Seed random number generator 
    for(int i = 0; i < n; i++){
        struct item t;
        t.value = rand() % 500 + 1; // Benefit between 1 and 500
        t.weight = rand() % 100 + 1; // Weight between 1 and 100
        t.valuePerWeight = (float)t.value / (float)t.weight;
        Q.items.push_back(t);
    }

    #ifdef DEBUG
    showQ();
    #endif

    return n;
}

//display the result in a good format
void printFormat(string s, int n, double t, long long m){
    printf("%-20s | %5d   :      %10.3lf    /  %15lld\n", s.c_str(), n, t, m);
}

//recursive brute force function by charGPT
int BF(int capacity, int currentIndex) {
    // Base case: if there are no more items or the capacity is 0
    if (currentIndex == Q.items.size() || capacity == 0) {
        return 0;
    }

    // If the weight of the current item is greater than the remaining capacity,
    // skip the current item and move on to the next item
    if (Q.items.at(currentIndex).weight > capacity) {
        return BF(capacity, currentIndex + 1);
    }

    // Return the maximum of two cases: 
    // 1. The current item is included in the knapsack
    // 2. The current item is excluded from the knapsack
    return max(Q.items.at(currentIndex).value + BF(capacity - Q.items.at(currentIndex).weight, currentIndex + 1),
               BF(capacity, currentIndex + 1));
}

//brute force method, from chatGPT
void bruteForce(int n){
    auto start = high_resolution_clock::now();// for measure running time of func
    long long maxBenefit = BF(Q.maxCapacity, 0);

    auto duration = duration_cast<milliseconds>(high_resolution_clock::now() - start);
    printFormat("Brute Force", n, duration.count(), maxBenefit);
}


//greedy method
void greedy(int n){
    auto start = high_resolution_clock::now();// for measure running time of func
    long long maxBenefit = 0;

    sort(Q.items.begin(), Q.items.end(), descItem);

    //following greedy, solve the problem
    for(int i = 0; i < n; i++){
        if(Q.items.at(i).weight <= Q.maxCapacity){
            maxBenefit += Q.items.at(i).value;
            Q.maxCapacity -= Q.items.at(i).weight;
        }else{
            maxBenefit += Q.items.at(i).valuePerWeight * Q.maxCapacity;
            break;
        }
    }

    auto duration = duration_cast<milliseconds>(high_resolution_clock::now() - start);
    printFormat("Greedy", n, duration.count(), maxBenefit);
}


void dynamicProgramming(int n){
    auto start = high_resolution_clock::now();// for measure running time of func
    vector<vector<long long>> DP;
    DP.resize(2,vector<long long>(Q.maxCapacity+1));

    for(int k = 1; k <= n; k++){
        for(int w = 1; w <= Q.maxCapacity; w++){
            //k가 짝수면 0번 인덱스, 홀수면 1번 인덱스가 현재값. (k-1)%2
            if(Q.items.at(k-1).weight <= w){//if k can be part of solution
                DP[(k%2)][w] = max(Q.items.at(k-1).value + DP[!(k%2)][w - Q.items.at(k-1).weight], DP[!(k%2)][w]);
                // DP[k][w] = max(Q.items.at(k-1).value + DP[k-1][w - Q.items.at(k-1).weight], DP[k-1][w]);
            }else DP[(k%2)][w] = DP[!(k%2)][w];
        }
        #ifdef DEBUG
        if(!(k%100)) printf("DP[%d][%d] = %ld\n", k, Q.maxCapacity, DP[(k%2)][Q.maxCapacity]);
        #endif
    }
    DP.shrink_to_fit(); //save the memory... idk if it works
    
    long long maxBenefit =  DP[(n%2)][Q.maxCapacity];

    #ifdef DEBUG
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            printf("%d ", DP[i][j]); 
        }
        printf("\n");
    }
    #endif
    
    auto duration = duration_cast<milliseconds>(high_resolution_clock::now() - start);
    printFormat("Dynamic Programming", n, duration.count(), maxBenefit);
}



/*
TODO implement branch and bound
node로 만들어야 할 것 같기는 한데. benefit, weight, bound로 구성된. 이건 item이랑은 별개의 개념이니까. (현재까지의 배낭 상태 같은...)
어케 그래프를 구현하냐...?의 문제같음. 냅다 다 공간을 할당해주기엔... 가망 없는 애들을 실시간 컷 하는 branch and bound의 이점을 못 살리는 꼴이고
그때그때 생성하는건가? 현재 살아있는 node들 중 bound가 가장 큰 놈에서 확장해나가면서?
그럼 node에 가망(?)같은 var을 추가해야겠다. 일단 고려 조건이 되는 노드는 항상 leaf노드들이고... 그니까 자식을 낳는 순간 부모노드는 disable되는거임. 
가망 var을 false처리하는 것 보다는 벡터에 넣고 빼는게 나으려나. 그럼 식별을 위한 index도 있는게 나으려나...? 
어느 item에 대한건지 index도 포함해야할 듯. 

Algorithm
루트노드를 vector에 넣고
while문으로 돌려서, 
현재 vector에 아무것도 없으면 탈출. 남은 item이 없어도 탈출..? 
vector에 있는애들의 bound들을 비교해서 가망있는 애들 중 최대값을 택해서 새끼치기. 
방금 새끼친 부모도 vector에서 뱉고 자식들의 bound 계산하기. 
노가망도 vector에서 뱉어내기.

struct node{
    long long benefit;
    long long weight;
    double bound;
    int itemIndex;
};

*/


void setNode(struct node* n, long long v, long long w, int index){
    //set from parameter
    n->benefit = v;
    n->weight = w;
    n->itemIndex = index;

    //calculate bound
    n->bound = v;
    int i = index+1; //from the next item... 
    int space = Q.maxCapacity - w; //availabe capacity now
    //fill the tot_weight
    while(i < Q.items.size() && space >= Q.items[i].weight){
        space -= Q.items[i].weight;
        n->bound += Q.items[i].value;
        i++;
    }
    //fill the remain capacity in bound, fractally
    if(i < Q.items.size()) n->bound += (double)Q.items[i].valuePerWeight * space;
}


//Branch and bound by chatGPT, and modified some error
void branchAndBound(int n){
    auto start = high_resolution_clock::now();// for measure running time of func
    long long maxBenefit = 0;
    int tmp = 0;


    vector<node> BB;
    sort(Q.items.begin(), Q.items.end(), descItem); //sorting
    #ifdef DEBUG
    showQ();
    #endif

    node root = {0, 0, 0, -1};
    BB.push_back(root);

    while(!BB.empty()){

        sort(BB.begin(), BB.end(), ascNode);
        node parent = BB.back(); //get 1st bound node... 
        BB.pop_back();

        #ifdef DEBUG
        printf("%d. [Branch and Bound] choosen node : benefit: %ld, weight: %ld, bound : %.1f, index: %d\n", tmp++, parent.benefit,parent.weight, parent.bound, parent.itemIndex );
        #endif

        //leaf node라면 자식생성과정 skip
        if(parent.itemIndex == n - 1) continue;
        
        //자식 생성하기 
        int nextIndex = parent.itemIndex + 1;
        long long v1 = parent.benefit + Q.items[nextIndex].value;
        long long w1 = parent.weight + Q.items[nextIndex].weight;
        
        node left, right;

        setNode(&left, v1, w1, nextIndex);//좌측 baby... nextIndex의 item을 넣었을 경우. 
        setNode(&right, parent.benefit, parent.weight, nextIndex);//우측 baby... nextIndex의 item을 안 넣었을 경우. 
        
        if(left.weight <= Q.maxCapacity && left.benefit > maxBenefit) maxBenefit = left.benefit;
        if(left.bound > maxBenefit && left.weight <= Q.maxCapacity) BB.push_back(left);
        if(right.bound > maxBenefit && right.weight <= Q.maxCapacity) BB.push_back(right);


    }

    #ifdef DEBUG
    printf("[Branch and bound] case %d, all done.\n", n);
    #endif
    
    auto duration = duration_cast<milliseconds>(high_resolution_clock::now() - start);
    printFormat("Branch and Bound", n, duration.count(), maxBenefit);
}



void printResult(){

    printf("\n        method       |   item  : time(milliseconds) / maximum benefit value\n");
    printf("----------------------------------------------------------------------------\n");
    // bruteForce(generateRandomValues(10));
    bruteForce(generateRandomValues(11));
    bruteForce(generateRandomValues(21));
    bruteForce(generateRandomValues(31)); 
    printf("----------------------------------------------------------------------------\n");
    greedy(generateRandomValues(10));
    greedy(generateRandomValues(100));
    greedy(generateRandomValues(1000));
    greedy(generateRandomValues(10000));
    printf("----------------------------------------------------------------------------\n");
    dynamicProgramming(generateRandomValues(10));
    dynamicProgramming(generateRandomValues(100));
    dynamicProgramming(generateRandomValues(1000));
    dynamicProgramming(generateRandomValues(10000)); 
    printf("----------------------------------------------------------------------------\n");
    branchAndBound(generateRandomValues(10));
    branchAndBound(generateRandomValues(100));
    branchAndBound(generateRandomValues(1000));
    branchAndBound(generateRandomValues(10000));
    printf("----------------------------------------------------------------------------\n\n");

}


int main() {

    //there is problem Q.
    printResult();



}

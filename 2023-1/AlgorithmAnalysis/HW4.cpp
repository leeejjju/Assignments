#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>
#include <chrono> 

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
    int numOfItem;
    int maxCapacity = 0;
    vector<item> items;
    // vector<int> value = {};
    // vector<int> weight = {};
    // vector<float> valuePerWeight = {};
} Q;

//for debug, show the values of Q
void showQ(){
    printf("value: ");
    // for(int i = 0; i < Q.value.size(); i++) printf("%d ", Q.value.at(i));
    for(int i = 0; i < Q.items.size(); i++) printf("%d ", Q.items.at(i).value);
    printf("\nweight: ");
    for(int i = 0; i < Q.items.size(); i++) printf("%d ", Q.items.at(i).weight);
    printf("\value per weight: ");
    for(int i = 0; i < Q.items.size(); i++) printf("%.1f ", Q.items.at(i).valuePerWeight);
    printf("\n");
}

//for sorting value per weight
int desc(struct item a, struct item b){
    return (a.valuePerWeight > b.valuePerWeight);
}

//generate Random benefit value Vs and weight Ws with number of item n(input) and save in input structor q.
int generateRandomValues(int n) {
    Q.numOfItem = n;
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
    if (currentIndex == Q.numOfItem || capacity == 0) {
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

//bruth force method, from chatGPT
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

    sort(Q.items.begin(), Q.items.end(), desc);

    //following greedy, solve the problem
    int remainCapacity = Q.maxCapacity;
    int index = 0;
    while(1){
        if(remainCapacity <= 0 || index >= n) break;
        if(Q.items.at(index).weight > 0){//see the most valuable
            //printf("fill %.1f from %d g, remain capacity is %d\n", valuePerWeight.at(index).first, valuePerWeight.at(index).second, remainCapacity-1);
            maxBenefit += Q.items.at(index).valuePerWeight; //get 1g
            Q.items.at(index).weight--; //remove from avaliable
            remainCapacity--; //reduce remain capacity
        }else{ //if most valuable one is run out,
            index++; //see the next most valuable
        }
    }

    auto duration = duration_cast<milliseconds>(high_resolution_clock::now() - start);
    printFormat("Greedy", n, duration.count(), maxBenefit);
}

void dynamicProgramming(int n){
    auto start = high_resolution_clock::now();// for measure running time of func
    vector<vector<long long>> DP;
    DP.resize(n+1,vector<long long>(Q.maxCapacity+1));

    //for(int i = 0; i <= n; i++) for(int j = 0; j <= Q.maxCapacity; j++) DP[i][j] = 0; //clear DP
    
    for(int k = 1; k <= n; k++){
        for(int w = 1; w <= Q.maxCapacity; w++){
            if(Q.items.at(k-1).weight <= w){//if k can be part of solution
                DP[k][w] = max(Q.items.at(k-1).value + DP[k-1][w - Q.items.at(k-1).weight], DP[k-1][w]);
            }else DP[k][w] = DP[k-1][w];
        }
    }
    DP.shrink_to_fit(); //save the memory... idk if it works
    
    long long maxBenefit =  DP[n][Q.maxCapacity];

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



void branchAndBound(int n){
    auto start = high_resolution_clock::now();// for measure running time of func
    long long maxBenefit = 0;

    
    auto duration = duration_cast<milliseconds>(high_resolution_clock::now() - start);
    printFormat("Branch and Bound", n, duration.count(), maxBenefit);
}

/*
TODO implement branch and bound
BFS탐색... 예제 있나? 
node로 만들어야 할 것 같기는 한데. benefit, weight, bound로 구성된. 이건 item이랑은 별개의 개념이니까. (현재까지의 배낭 상태 같은...)
어케 그래프를 구현하냐...?의 문제같음. 냅다 다 공간을 할당해주기엔... 가망 없는 애들을 실시간 컷 하는 branch and bound의 이점을 못 살리는 꼴이고
그때그때 생성하는건가? 현재 살아있는 node들 중 bound가 가장 큰 놈에서 확장해나가면서?
그럼 node에 가망(?)같은 var을 추가해야겠다. 일단 고려 조건이 되는 노드는 항상 leaf노드들이고... 그니까 자식을 낳는 순간 부모노드는 disable되는거임. 
가망 var을 false처리하는 것 보다는 벡터에 넣고 빼는게 나으려나. 

*/




void printResult(){

    printf("\n        method       |   item  : time(milliseconds) / maximum benefit value\n");
    printf("----------------------------------------------------------------------------\n");
    bruteForce(generateRandomValues(10));
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
    // dynamicProgramming(generateRandomValues(10000)); //std::bad_alloc
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
    // branchAndBound(generateRandomValues(10));
    
}

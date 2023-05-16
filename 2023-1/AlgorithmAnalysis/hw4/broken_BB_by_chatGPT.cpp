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
bool descNode(struct node a, struct node b) { 
    return a.bound > b.bound; 
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
        t.weight = rand() % 50 + 1; // Weight between 1 and 100
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


void setBB(struct node* n, long long v, long long w, int index){
    n->benefit = v;
    n->weight = w;
    n->itemIndex = index;
    n->bound = v;
    int i = index+1;
    int space = Q.maxCapacity - w;
    while(i < Q.numOfItem && space >= Q.items[i].weight){
        space -= Q.items[i].weight;
        n->bound += Q.items[i].value;
        i++;
    }
    if(i < Q.numOfItem) n->bound += (double)Q.items[i].valuePerWeight * space;
}

void branchAndBound(int n){
    auto start = high_resolution_clock::now();// for measure running time of func
    long long maxBenefit = 0;

    vector<node> BB;
    sort(Q.items.begin(), Q.items.end(), descItem); //sorting
    #ifdef DEBUG
    showQ();
    #endif

    node root = {0, 0, 0, -1};
    BB.push_back(root);

    while(!BB.empty()){
        node parent = BB.back();
        BB.pop_back();

        if(parent.itemIndex == Q.numOfItem - 1) continue;

        int nextIndex = parent.itemIndex + 1;
        long long v1 = parent.benefit + Q.items[nextIndex].value;
        long long w1 = parent.weight + Q.items[nextIndex].weight;
        node left = {v1, w1, 0, nextIndex};
        setBB(&left, v1, w1, nextIndex);

        if(left.weight <= Q.maxCapacity && left.benefit > maxBenefit){
            maxBenefit = left.benefit;
        }

        if(left.bound > maxBenefit){
            BB.push_back(left);
        }

        node right = {parent.benefit, parent.weight, 0, nextIndex};
        setBB(&right, parent.benefit, parent.weight, nextIndex);

        if(right.bound > maxBenefit){
            BB.push_back(right);
        }
    }

    #ifdef DEBUG
    printf("[Branch and bound] case %d, all done.\n", n);
    #endif
    
    auto duration = duration_cast<milliseconds>(high_resolution_clock::now() - start);
    printFormat("Branch and Bound", n, duration.count(), maxBenefit);
}


int main(){
    // branchAndBound(generateRandomValues(10));
    int a = (1>2)?10 : 20;
}
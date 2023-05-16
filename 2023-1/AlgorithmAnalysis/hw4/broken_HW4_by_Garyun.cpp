#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <queue>

//from Garyun
#define ARRSIZE 10000

using namespace std;

struct Item {
    int weight;
    int value;
    double ratio;
};

int random_weight();
int random_benefit();
void initialize_weight_benefit(vector<vector<int>>& weight_benefit, int num);
bool compare(const vector<int>& a, const vector<int>& b);
int bruteForce(int num);
int knapsack = 0;
float greedy(int num);
int dp(int num);
void initialize_Item(vector<Item>& items, vector<vector<int>>& weight_benefit, int num);
int branch_bound(int num);
double get_bound(vector<Item> items, int current_weight, int current_value);

auto start_time = chrono::high_resolution_clock::now();
auto end_time = chrono::high_resolution_clock::now();
auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

bool cmp(Item a, Item b) {
    return a.ratio < b.ratio;
}

void mil2mic(long long mil){
    cout << mil/1000 << "." << mil%1000/10;
}

int main() {
    long temp_result;
    int result_greedy;
    int result_dp;
    int result_bb;
    long long mictime[3];
    temp_result = bruteForce(11);
    cout << "[1] Brute force" << endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << "| Number of Items |  Processing time in milliseconds / Maximum benefit value \t|" << endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << "|       11        |\t\t\t\t"; mil2mic(duration.count()); cout<<" / " << temp_result << "\t\t\t|"<< endl;
    temp_result = bruteForce(21);
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << "|       21        |\t\t\t\t"; mil2mic(duration.count()); cout<<" / " << temp_result << "\t\t\t|"<< endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    //temp_result = bruteForce(31);
    cout << "|       31        |\t\t\t\t"; mil2mic(duration.count()); cout<<" / " << temp_result << "\t\t\t|"<< endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << endl;
    result_greedy = greedy(10);
    mictime[0] = duration.count();
    result_dp = dp(10);
    mictime[1] = duration.count();
    result_bb = branch_bound(10);
    mictime[2] = duration.count();
    cout << "[2]Greedy / D.P. / B.&B." << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
    cout << "|    Number of    |  Processing time in milliseconds / Maximum benefit value \t\t|" << endl;
    cout << "|                 |---------------------------------------------------------------------|" << endl;
    cout << "|      Items      |      Greedy       \t|        D.P.       \t|       B.&B.      \t|" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
    cout << "|       10        |\t";mil2mic(mictime[0]);cout<<"/"<<result_greedy<<"\t|\t";  mil2mic(mictime[1]);cout<<"/"<<result_dp<<"\t|\t";  mil2mic(mictime[2]);cout<<"/"<<result_bb<<"\t|"<<endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
    result_greedy = greedy(100);
    mictime[0] = duration.count();
    result_dp = dp(100);
    mictime[1] = duration.count();
    result_bb = branch_bound(100);
    mictime[2] = duration.count();
    cout << "|       100       |\t";mil2mic(mictime[0]);cout<<"/"<<result_greedy<<"\t|\t";  mil2mic(mictime[1]);cout<<"/"<<result_dp<<"\t|\t";  mil2mic(mictime[2]);cout<<"/"<<result_bb<<"\t|"<<endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
    result_greedy = greedy(1000);
    mictime[0] = duration.count();
    result_dp = dp(1000);
    mictime[1] = duration.count();
    result_bb = branch_bound(1000);
    mictime[2] = duration.count();
    cout << "|       1000      |\t";mil2mic(mictime[0]);cout<<"/"<<result_greedy<<"\t|\t";  mil2mic(mictime[1]);cout<<"/"<<result_dp<<"\t|\t";  mil2mic(mictime[2]);cout<<"/"<<result_bb<<"\t|"<<endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
    result_greedy = greedy(10000);
    mictime[0] = duration.count();
    result_dp = dp(10000);
    mictime[1] = duration.count();
    result_bb = branch_bound(10000);
    mictime[2] = duration.count();
    cout << "|       10000     |\t";mil2mic(mictime[0]);cout<<"/"<<result_greedy<<"|\t";  mil2mic(mictime[1]);cout<<"/"<<result_dp<<"|\t";  mil2mic(mictime[2]);cout<<"/"<<result_bb<<"\t|"<<endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
    return 0;
}

int random_weight() {
    int random_value = rand() % 50 + 1;
    return random_value;
}

int random_benefit() {
    int random_value = rand() % 500 + 1;
    return random_value;
}

void initialize_weight_benefit(vector<vector<int>>& weight_benefit, int num) {
    srand(100);
    for (int i = 0; i < num; i++) {
        weight_benefit[i][0] = random_weight();
        weight_benefit[i][1] = random_benefit();
    }
}

bool compare(const vector<int>& a, const vector<int>& b) {
    double ratio_a = static_cast<double>(a[1]) / static_cast<double>(a[0]);
    double ratio_b = static_cast<double>(b[1]) / static_cast<double>(b[0]);
    return ratio_a > ratio_b;
}

int bruteForce(int num){
    start_time = chrono::high_resolution_clock::now();
    vector<vector<int>> weight_benefit(num, vector<int>(2, 0));
    initialize_weight_benefit(weight_benefit, num);
    sort(weight_benefit.begin(), weight_benefit.end(), compare);

    knapsack = 25 * num;
    int max_benefit = 0;
    for(unsigned long long i = 0; i < ((unsigned long long)1 << num); i++){
        int current_weight = 0;
        int current_benefit = 0;
        for(int j = 0; j < num; j++){
            if(i & ((unsigned long long)1 << j)){
                current_weight += weight_benefit[j][0];
                current_benefit += weight_benefit[j][1];
            }
        }
        if(current_weight < knapsack && current_benefit > max_benefit)
            max_benefit = current_benefit;
    }
    end_time = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    return max_benefit;
}

float greedy(int num){
    start_time = chrono::high_resolution_clock::now();
    vector<vector<int>> weight_benefit(num, vector<int>(2, 0));
    initialize_weight_benefit(weight_benefit, num);
    sort(weight_benefit.begin(), weight_benefit.end(), compare);
    knapsack = 25 * num;
    float max_benefit = 0;
    int current_weight = 0;
    for(int i = 0; i < num; i++){
        if(current_weight + weight_benefit[i][0] > knapsack){
            int remain = knapsack - current_weight;
            max_benefit += (weight_benefit[i][0]/(float)weight_benefit[i][1]) * remain;
            break;
        }
        else{
            current_weight += weight_benefit[i][0];
            max_benefit += weight_benefit[i][1];
        }
    }
    end_time = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    return max_benefit;
}


int dp(int num){
    start_time = chrono::high_resolution_clock::now();
    vector<vector<int>> weight_benefit(num, vector<int>(2, 0));
    initialize_weight_benefit(weight_benefit, num);
    sort(weight_benefit.begin(), weight_benefit.end(), compare);
    knapsack = num * 25;
    int wn_hist[knapsack+1][2];
    for(int i=0;i<=knapsack; i++){
        for(int j=0;j<2; j++){
            wn_hist[i][j] = 0;
        }
    }

    for(int i=1; i<=num; i++){
        for(int w=0; w<= knapsack; w++){
            if(weight_benefit[i-1][0] > w){
                wn_hist[w][i%2] = wn_hist[w][(i-1)%2];
            }
            else{
                wn_hist[w][i%2] = wn_hist[w][(i-1)%2] > (wn_hist[w-weight_benefit[i-1][0]][(i-1)%2] + weight_benefit[i-1][1])
                                ? wn_hist[w][(i-1)%2] : wn_hist[w-weight_benefit[i-1][0]][(i-1)%2] + weight_benefit[i-1][1];
            }
        }
    }
    end_time = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    return wn_hist[knapsack][num%2];
}

void initialize_Item(vector<Item>& items, vector<vector<int>>& weight_benefit, int num){
    for(int i=0; i<num; i++){
        items[i].weight = weight_benefit[i][0];
        items[i].value = weight_benefit[i][1];
        items[i].ratio = items[i].value/(double)items[i].weight;
    }
}

int branch_bound(int num){
    start_time = chrono::high_resolution_clock::now();
    knapsack = num * 25;
    vector<vector<int>> weight_benefit(num, vector<int>(2, 0));
    initialize_weight_benefit(weight_benefit, num);
    vector<Item> items(num);
    initialize_Item(items,weight_benefit,num);
    sort(items.begin(),items.end(),cmp);

    int max_value = 0;
    int current_weight = 0;
    int current_value = 0;

    priority_queue<pair<double, pair<int, int>>> pq;
    double bound = get_bound(items, current_weight, current_value);
    pq.push(make_pair(bound, make_pair(current_weight, current_value)));

    while (!pq.empty()) {
        bound = pq.top().first;
        current_weight = pq.top().second.first;
        current_value = pq.top().second.second;
        pq.pop();

        if (current_weight > knapsack) continue;

        if (bound <= max_value) continue;

        if(max_value < current_value) max_value = current_value;

        if (items.empty()) {
            continue;
        }

        Item next_item = items.back();
        items.pop_back();
        double lbound = get_bound(items, current_weight+next_item.weight, current_value+next_item.value);//선택
        pq.push(make_pair(lbound, make_pair(current_weight+next_item.weight, current_value+next_item.value)));
        double rbound = get_bound(items, current_weight, current_value);//미선택
        pq.push(make_pair(rbound, make_pair(current_weight, current_value)));
        
    }
    end_time = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    return max_value;
}

double get_bound(vector<Item> items, int current_weight, int current_value) {
    int bound = current_value;
    int weight_sum = current_weight;
    for(int i=items.size()-1;i>=0;i--){
        if (weight_sum + items[i].weight <= knapsack) {
            bound += items[i].value;
            weight_sum += items[i].weight;
        } else {
            double fraction = double(knapsack-weight_sum) / (double)items[i].weight;
            bound += fraction * items[i].value;
            break;
        }
    }

    return bound;
}
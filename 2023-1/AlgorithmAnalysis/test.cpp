#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Struct for problem
struct problem{
    int numOfItem;
    int maxCapacity = 0;
    vector<int> value;
    vector<int> weight;
} Q;

// Utility function to find upper bound
int upper_bound_knapsack(int current_weight, int current_value, int remaining_capacity, vector<pair<float, int>>& value_per_weight_sorted) {
    int upper_bound = current_value;
    int i = 0;
    int remaining_weight = remaining_capacity;
    while (remaining_weight > 0 && i < Q.numOfItem) {
        int item_index = value_per_weight_sorted[i].second;
        if (remaining_weight >= Q.weight[item_index]) {
            remaining_weight -= Q.weight[item_index];
            upper_bound += Q.value[item_index];
        }
        else {
            upper_bound += remaining_weight * value_per_weight_sorted[i].first;
            remaining_weight = 0;
        }
        i++;
    }
    return upper_bound;
}


// Utility function to solve branch and bound
int branch_and_bound_knapsack_helper(int current_weight, int current_value, int remaining_capacity, vector<bool> selected_items) {
    if (remaining_capacity == 0 || selected_items.size() == Q.numOfItem) {
        return current_value;
    }
    int upper_bound = upper_bound_knapsack(current_weight, current_value, remaining_capacity); // calling upper_bound_knapsack() function
    if (upper_bound <= current_value) {
        return current_value;
    }
    int best_value = current_value;
    for (int i = 0; i < Q.numOfItem; i++) {
        if (!selected_items[i] && remaining_capacity >= Q.weight[i]) {
            selected_items[i] = true;
            int value = branch_and_bound_knapsack_helper(current_weight + Q.weight[i], current_value + Q.value[i], remaining_capacity - Q.weight[i], selected_items);
            best_value = max(best_value, value);
            selected_items[i] = false;
        }
    }
    return best_value;
}





// Function to solve knapsack problem using branch and bound
void branch_and_bound_knapsack() {
    auto start = high_resolution_clock::now(); // Measure running time of function
    long long maxBenefit = 0;
    vector<bool> selected_items(Q.numOfItem, false);
    maxBenefit = branch_and_bound_knapsack_helper(0, 0, Q.maxCapacity, selected_items);
    auto duration = duration_cast<milliseconds>(high_resolution_clock::now() - start);
    cout << "Branch and Bound - " << Q.numOfItem << " items: " << maxBenefit << " (in " << duration.count() << " ms)" << endl;
}

int main() {
    // Example usage
    Q.numOfItem = 5;
    Q.maxCapacity = 10;
    Q.value = {10, 20, 30, 40, 50};
    Q.weight = {1, 2, 3, 4, 5};
    branch_and_bound_knapsack();
    return 0;
}

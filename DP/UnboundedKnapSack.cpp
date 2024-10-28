#include<bits/stdc++.h>
using namespace std;

int unboundedKnapsack(vector<int>& profits, vector<int>& weights, int capacity, int currIndex) { // Time O(2^(n+c))
    // Base case
    if(capacity<=0 || profits.empty() || weights.size() != profits.size() || currIndex >= profits.size()) {
        return 0;
    }
    // Recursive call after choosing the item at currIndex
    int currProfit = 0;
    if(weights[currIndex] <= capacity) {
        currProfit = profits[currIndex] + unboundedKnapsack(profits, weights, capacity - weights[currIndex], currIndex);
    }

    // Recursive call after excluding the item at currIndex
    int currProfitMinumItem = unboundedKnapsack(profits, weights, capacity, currIndex + 1);

    return max(currProfit, currProfitMinumItem);
}

// Time O(N*C)
int unboundedKnapsackMemo(vector<int>& profits, vector<int>& weights, int capacity, int currIndex, vector<vector<int>>& dp) {
    // Base check
    if(capacity <= 0 || profits.empty() || weights.size() != profits.size() || currIndex >= profits.size()) {
        return 0;
    }

    if(dp[currIndex][capacity] != -1) {
        return dp[currIndex][capacity];
    }

    int currprofit = 0;
    if(weights[currIndex] <= capacity) {
        currprofit = profits[currIndex] + unboundedKnapsackMemo(profits, weights, capacity - weights[currIndex], currIndex, dp);
    }

    int currProfitsMinusItem = unboundedKnapsackMemo(profits, weights, capacity, currIndex + 1, dp);
    dp[currIndex][capacity] = max(currprofit, currProfitsMinusItem);

    return dp[currIndex][capacity];
}

int unboundedKnapsackBottomUp(vector<int>& profits, vector<int>& weights, int capacity) { // Time O(N*C)
    if(capacity <= 0 || profits.empty() || weights.size() != profits.size())
        return 0;

    int n = profits.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    for(int i = 0; i < n; i++)
        dp[i][0] = 0;

    for(int i = 0; i < n; i++) {
        for(int c = 1; c <= capacity; c++) {
            int currProfit = 0;
            int currProfitMinusIndex = 0;

            if(weights[i] <= c)  // check wt before proceding  
                currProfit = profits[i] + dp[i][c-weights[i]];

            if(i > 0)  
                currProfitMinusIndex = dp[i-1][c];
            dp[i][c] = max(currProfit, currProfitMinusIndex); 
        }
    }
    return dp[n-1][capacity];
}

int solveKnapsack(vector<int>& profits, vector<int>& weights, int capacity) {
    return unboundedKnapsackBottomUp(profits, weights, capacity);
}

int main() {
    vector<int> profits = {15, 50, 60, 90};
    vector<int> weights = {1, 3, 4, 5};
    int capacity = 8;

    cout << "Total knapsack profit: ---> " << solveKnapsack(profits, weights, capacity) << endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

class Solution { // Brute force - TLE
public:
    int minCost(vector<int>& cost, int n) {
        if(n < 0) return 0;
        if(n == 0 || n == 1) return cost[n];

        return cost[n] + min(minCost(cost, n -1), minCost(cost, n - 2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return minCost(cost, n);    
    }
};

class Solution { // Top Down DP
public: 
    int minCost(vector<int> cost, int n, vector<int>& dp) {
        if(n < 0) return 0;
        if(n == 0 || n == 1) return cost[n];

        if(dp[n] != 0) return dp[n];

        dp[n] = cost[n] + min(minCost(cost, n - 1, dp), minCost(cost, n - 2, dp));
    } 
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);
        return minCost(cost, n, dp);
    }
};

class Solution { // TLE 
public:
    vector<int> dp;

    int minCost(vector<int>& cost, int n) {
        if (n < 0)
            return 0;
        if (n == 0 || n == 1)
            return cost[n];
        if (dp[n] != 0)
            return dp[n];

        dp[n] = cost[n] + min(minCost(cost, n - 1), minCost(cost, n - 2));
        return dp[n];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp = vector<int>(n, 0);
        return min(minCost(cost, n - 1), minCost(cost, n - 2));
    }
};

class Solution { // Best Solution
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            if (i < 2)
                dp[i] = cost[i];
            else
                dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[n - 1], dp[n - 2]);
    }
};
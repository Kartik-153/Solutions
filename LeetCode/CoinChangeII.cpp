#include<bits/stdc++.h>
using namespace std;

class Solution1 { // Show TLE
public:
    int change(int amount, vector<int>& coins) {
        return deno(coins, amount, 0);
    }

private:
    int deno(vector<int>& coins, int amount, int currIndex) {
        if (amount == 0)
            return 1;
        if (coins.size() == 0 || currIndex >= coins.size()) {
            return 0;
        }

        int currSum = 0;
        if (coins[currIndex] <= amount) {
            currSum = deno(coins, amount - coins[currIndex], currIndex);
        }

        int currSumAtNextItem = deno(coins, amount, currIndex + 1);

        return currSum + currSumAtNextItem;
    }
};


class Solution2 {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        return cntChangeRecursive(coins, amount, 0, dp);
    }

private:
    int cntChangeRecursive(vector<int>& coins, int total, int currIndex, vector<vector<int>>& dp) {
        if(total == 0) return 1;
        if(currIndex >= coins.size()) return 0;

        if(dp[currIndex][total] != -1) return dp[currIndex][total];

        int currSum = 0;

        if(coins[currIndex] <= total) {
            currSum = cntChangeRecursive(coins, total - coins[currIndex], currIndex, dp);
        }

        int sumAtNextIndex = cntChangeRecursive(coins, total, currIndex+1, dp);

        dp[currIndex][total] = currIndex + sumAtNextIndex;
        return dp[currIndex][total];
    }
};

class Solution3 {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));

        for(int i = 0; i < n; i++) dp[i][0] = 1;

        for(int i = 0; i < n; i++) {
            for(int t = 1; t <= amount; t++) {
                if(i > 0) dp[i][t] = dp[i-1][t];
                if(t >= coins[i]) dp[i][t] += dp[i][t-coins[i]];
            }
        }

        return dp[n-1][amount];
    }
};
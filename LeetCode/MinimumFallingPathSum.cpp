#include <bits/stdc++.h>
using namespace std;

class Solution { // Brute force - TLE
public:
    int minFallingPathSum(vector<vector<int>>& M) {
        int n = M.size();
        int minSum = INT_MAX;
        for (int col = 0; col < n; col++) {
            minSum = min(minSum, dfs(M, 0, col));
        }
        return minSum;
    }

private:
    int dfs(vector<vector<int>>& M, int row, int col) {
        int n = M.size();
        if (col < 0 || col >= n) return INT_MAX;
        if (row == n - 1) return M[row][col];
        int down = dfs(M, row + 1, col);
        int left = dfs(M, row + 1, col - 1);
        int right = dfs(M, row + 1, col + 1);
        return M[row][col] + min({down, left, right});
    }
};

class Solution { // Memo - TLE
public:
    int minFallingPathSum(vector<vector<int>>& M) {
        int n = M.size();
        int minSum = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int col = 0; col < n; col++) {
            minSum = min(minSum, memo(M, 0, col, dp));
        }
        return minSum;
    }

private:
    int memo(vector<vector<int>>& M, int row, int col,
             vector<vector<int>>& dp) {
        int n = M.size();
        if (col < 0 || col >= n) return dp[row][col];
        if (row == n - 1) return M[row][col];
        if (dp[row][col] != -1) return dp[row][col];
        int down = memo(M, row + 1, col, dp);
        int left = memo(M, row + 1, col - 1, dp);
        int right = memo(M, row + 1, col + 1, dp);
        return dp[row][col] = M[row][col] + min({down, left, right});
    }
};

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp = matrix;

        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col < n; col++) {
                int down = dp[row + 1][col];
                int left = (col > 0) ? dp[row + 1][col - 1] : INT_MAX;
                int right = (col < n - 1) ? dp[row + 1][col + 1] : INT_MAX;
                dp[row][col] += min({down, left, right});
            }
        }
        return *min_element(dp[0].begin(), dp[0].end());
    }
};
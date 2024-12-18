#include<bits/stdc++.h>
using namespace std;

class Solution {  // Bottom - up
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m - 1][n - 1] = grid[m - 1][n - 1];

        for (int col = n - 2; col >= 0; --col) {
            dp[m - 1][col] = grid[m - 1][col] + dp[m - 1][col + 1];
        }

        for (int row = m - 2; row >= 0; --row) {
            dp[row][n - 1] = grid[row][n - 1] + dp[row + 1][n - 1];
        }

        for (int row = m - 2; row >= 0; --row) {
            for (int col = n - 2; col >= 0; --col) {
                dp[row][col] =
                    grid[row][col] + min(dp[row + 1][col], dp[row][col + 1]);
            }
        }
        return dp[0][0];
    }
};

class Solution { // Brute force - TLE
public:
    int minPathSum(vector<vector<int>>& grid) { return recursion(grid, 0, 0); }
    
private:
    int recursion(vector<vector<int>>& grid, int row, int col) {
        int m = grid.size();
        int n = grid[0].size();
        if (row == m - 1 && col == n - 1) {
            return grid[row][col];
        }
        if (row >= m || col >= n) {
            return INT_MAX;
        }
        int right = recursion(grid, row, col + 1);
        int down = recursion(grid, row + 1, col);
        return grid[row][col] + min(right, down);
    }
};

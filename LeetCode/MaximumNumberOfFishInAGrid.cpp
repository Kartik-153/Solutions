#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int numFish = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0 && !visited[i][j]) {
                    numFish = max(numFish, dfs(grid, visited, i, j));
                }
            }
        }
        return numFish;
    }

private:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, 
            int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
            grid[i][j] == 0 || visited[i][j]) {
            return 0;
        }
        visited[i][j] = true;
        return grid[i][j] + dfs(grid, visited, i - 1, j) +
               dfs(grid, visited, i + 1, j) +
               dfs(grid, visited, i, j - 1) +
               dfs(grid, visited, i, j + 1);
    }
};

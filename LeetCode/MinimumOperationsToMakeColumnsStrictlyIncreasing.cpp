#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size();    
        int n = grid[0].size(); 
        int op = 0;

        for (int j = 0; j < n; j++) {
            for (int i = 1; i < m; i++) {
                if (grid[i][j] <= grid[i - 1][j]) {
                    int inc = grid[i - 1][j] - grid[i][j] + 1;
                    op += inc;
                    grid[i][j] += inc; 
                }
            }
        }
        return op;
    }
};
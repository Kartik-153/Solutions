#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        if (m == 0)
            return;

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')
                DFS(board, i, 0, m, n);

            if (board[i][n - 1] == 'O')
                DFS(board, i, n - 1, m, n);
        }

        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O')
                DFS(board, 0, i, m, n);

            if (board[m - 1][i] == 'O')
                DFS(board, m - 1, i, m, n);
        }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
    }

    void DFS(vector<vector<char>>& v, int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n || v[i][j] != 'O') {
            return;
        }
        v[i][j] = '#';
        DFS(v, i - 1, j, m, n);
        DFS(v, i + 1, j, m, n);
        DFS(v, i, j - 1, m, n);
        DFS(v, i, j + 1, m, n);
    }
};

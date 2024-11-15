#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int len = board.size();
        reverse(board.begin(), board.end());

        auto intToPos = [&](int square) {
            int r = (square - 1) / len;
            int c = (square - 1) % len;
            if(r % 2 == 1) {
                c = len - 1 - c;
            }
            return make_pair(r, c);
        };

        queue<pair<int, int>> q;
        q.push({1, 0});
        unordered_set<int> visit;

        while(!q.empty()) {
            auto [square, moves] = q.front();
            q.pop();

            for(int i = 1; i <= 6; i++) {
                int nextSquare = square + i;
                auto [r, c] = intToPos(nextSquare);

                if(board[r][c] != -1) {
                    nextSquare = board[r][c];
                }

                if (nextSquare == len * len) {
                    return moves + 1;
                }
                
                if (visit.find(nextSquare) == visit.end()) {
                    visit.insert(nextSquare);
                    q.push({nextSquare, moves + 1});
                }
            }
        }
        return -1;
    }
};
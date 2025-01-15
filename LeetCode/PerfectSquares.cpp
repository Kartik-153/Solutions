#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        if (n <= 0) return 0;
        vector<int> perfectSquares;
        vector<int> cntPerfectSquares(n);
        for (int i = 1; i * i <= n; i++) {
            perfectSquares.push_back(i * i);
            cntPerfectSquares[i * i - 1] = 1;
        }
        if (perfectSquares.back() == n) return 1;
        queue<int> Q;
        for (auto& i : perfectSquares) Q.push(i);
        int currCntPerfectSquare = 1;
        while (!Q.empty()) {
            currCntPerfectSquare++;
            int currSize = Q.size();
            for (int i = 0; i < currSize; i++) {
                int tmp = Q.front();
                for (auto& j : perfectSquares) {
                    if (tmp + j == n) {
                        return currCntPerfectSquare;
                    } else if ((tmp + j < n) &&
                               (cntPerfectSquares[tmp + j - 1] == 0)) {
                        cntPerfectSquares[tmp + j - 1] = currCntPerfectSquare;
                        Q.push(tmp + j);
                    } else if (tmp + j > n) {
                        break;
                    }
                }
                Q.pop();
            }
        }
        return 0;
    }
};

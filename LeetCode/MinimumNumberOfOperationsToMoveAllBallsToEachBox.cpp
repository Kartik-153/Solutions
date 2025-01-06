#include<bits/stdc++.h>
using namespace std;

class Solution { // Brute Force
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.size());
        for (int i = 0; i < boxes.size(); i++) {
            if (boxes[i] == '1') {
                for (int j = 0; j < boxes.size(); j++) {
                    ans[j] += abs(j - i);
                }
            }
        }
        return ans;
    }
};

class Solution { // Sum of left and Right moves
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> answer(n, 0);
        int ballsToLeft = 0, movesToLeft = 0;
        int ballsToRight = 0, movesToRight = 0;
        for (int i = 0; i < n; i++) {
            answer[i] += movesToLeft;
            ballsToLeft += boxes[i] - '0';
            movesToLeft += ballsToLeft;
            int j = n - 1 - i;
            answer[j] += movesToRight;
            ballsToRight += boxes[j] - '0';
            movesToRight += ballsToRight;
        }
        return answer;
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int res = 0;
        int n = values.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j > i && j < n; j++) {
                res = max(res, values[i] + values[j] + i - j);
            }
        }
        return res;
    }
};

// DP

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int> maxLeftScore(n);
        maxLeftScore[0] = values[0];

        int maxScore = 0;

        for(int i = 1; i < n; i++) {
            int currRightScore = values[i] - i;
            maxScore = max(maxScore, maxLeftScore[i-1] + currRightScore);
            int currLeftScore = values[i] + i;
            maxLeftScore[i] = max(maxLeftScore[i-1], currLeftScore);
        }
        return maxScore;
    }
};

// Space Optimized DP
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        // The left score is initially just the value of the first element.
        int maxLeftScore = values[0];

        int maxScore = 0;

        for (int i = 1; i < n; i++) {
            int currentRightScore = values[i] - i;
            // Update the maximum score by combining the best left score so far
            // with the current right score.
            maxScore = max(maxScore, maxLeftScore + currentRightScore);

            int currentLeftScore = values[i] + i;
            // Update the maximum left score up to the current index.
            maxLeftScore = max(maxLeftScore, currentLeftScore);
        }

        return maxScore;
    }
};
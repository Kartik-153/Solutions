#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        return LCS(text1, text2, 0,0);
    }
private:
    int LCS(string text1, string text2, int idx1, int idx2) {
        if(idx1 == text1.size() || idx2 == text2.size()) return 0;

        if(text1[idx1] == text2[idx2]) {
            return 1 + LCS(text1, text2, idx1 + 1, idx2 + 1);
        }

        int checkFirstString = LCS(text1, text2, idx1, idx2 + 1);
        int checkSecondString = LCS(text1, text2, idx1 + 1, idx2);
        
        return max(checkFirstString, checkSecondString);
    }
};


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return LCS(text1, text2, 0,0,dp);
    }

private:
    int LCS(string text1, string text2, int idx1, int idx2, vector<vector<int>> dp) {
        if(idx1 == text1.size() || idx2 == text2.size()) return 0;

        if(dp[idx1][idx2] == -1) {
            if(text1[idx1] == text2[idx2]) {
                dp[idx1][idx2] = 1 + LCS(text1, text2, idx1 + 1, idx2 + 1, dp);
            } else {
                int checkFirst = LCS(text1, text2, idx1, idx2 + 1, dp);
                int checkSecond = LCS(text1, text2, idx1 + 1, idx2, dp);
                dp[idx1][idx2] = max(checkFirst, checkSecond);
            }
        }

        return dp[idx1][idx2];
    }
};

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n+1, 0));

        int maxLen = 0;

        for(int idx1 = 1; idx1 <= m; idx1++) {
            for(int idx2 = 1; idx2 <= n; idx2++) {
                if(text1[idx1 - 1] == text2[idx2 - 1]) {
                    dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
                } else {
                    dp[idx1][idx2] = max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);
                }
                maxLen = max(maxLen, dp[idx1][idx2]);
            }
        }

        return maxLen;
    }
};
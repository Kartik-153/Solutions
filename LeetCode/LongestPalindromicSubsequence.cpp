#include<bits/stdc++.h>
using namespace std;

class Solution {  // Memory Limit Exceeded
public:
    int longestPalindromeSubseq(string s) {
        return recursive(s, 0, s.size() - 1);
    }

private:
    int recursive(string s, int start, int end) {
        if(start > end) return 0;
        if(start == end) return 1;

        if(s[start] == s[end]) {
            return 2 + recursive(s, start + 1, end - 1);
        }

        int startskip = recursive(s, start + 1, end);
        int endSkip = recursive(s, start, end - 1);

        return max(startskip, endSkip);
    }
};

class Solution {  // Top Dowm with memo
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return recursiveMemo(dp, s, 0, n-1);
    }
private:
    int recursiveMemo(vector<vector<int>>& dp, string& s, int start, int end) {
        if(start > end) return 0;
        if(start == end) return 1;

        if(dp[start][end] != -1) 
            return dp[start][end];
        
        if(s[start] == s[end]) {
            int remainingLength = end - start -1;
            if(remainingLength == recursiveMemo(dp, s, start + 1, end-1)) {
                dp[start][end] = remainingLength + 2;
                return dp[start][end];
            }
        }

        int skipStart = recursiveMemo(dp, s, start + 1, end);
        int skipEnd = recursiveMemo(dp, s, start, end-1);
        dp[start][end] = max(skipStart, skipEnd);

        return dp[start][end];
    }
};

class Solution {
public:
    int longestPalindromeSubseq(string str) {
        int n = str.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        for (int startIndex = n - 2; startIndex >= 0; startIndex--) {
            for (int endIndex = startIndex + 1; endIndex < n; endIndex++) {
                if (str[startIndex] == str[endIndex]) {
                    dp[startIndex][endIndex] =
                        2 + dp[startIndex + 1][endIndex - 1];
                } else {
                    dp[startIndex][endIndex] =
                        max(dp[startIndex + 1][endIndex],
                            dp[startIndex][endIndex - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
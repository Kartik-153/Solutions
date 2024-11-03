#include<bits/stdc++.h>
using namespace std;

class Solution { // Recursive Solution
public:
    int minInsertions(string s) {
        int n = s.length();
        string sReverse = s;
        reverse(sReverse.begin(), sReverse.end());
        vector<vector<int>> memo(n + 1, vector<int>(n+1, -1));
        return n - lcs(s, sReverse, n,n,memo);
    }

private:
    int lcs(string& s1, string& s2, int m, int n, vector<vector<int>>& memo) {
        if(m == 0 || n == 0)
            return 0;
        if(memo[m][n] != -1) 
            return memo[m][n];
        
        if(s1[m-1] == s2[n-1]) 
            return memo[m][n] = 1 + lcs(s1, s2, m-1, n-1, memo);

        return memo[m][n] = max(lcs(s1, s2, m-1, n, memo), lcs(s1,s2,m,n-1,memo));
    }
};


class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string sReverse = s;
        reverse(sReverse.begin(), sReverse.end());
        return n - lcs(s, sReverse, n,n);
    }

private:
    int lcs(string& s1, string& s2, int m, int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1));

        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};

class Solution { // Space Optimised
public:
    int lcs(string& s1, string& s2, int m, int n) {
        vector<int> dp(n + 1), dpPrev(n + 1);

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    // One of the two strings is empty.
                    dp[j] = 0;
                } else if (s1[i - 1] == s2[j - 1]) {
                    dp[j] = 1 + dpPrev[j - 1];
                } else {
                    dp[j] = max(dpPrev[j], dp[j - 1]);
                }
            }
            dpPrev = dp;
        }

        return dp[n];
    }

    int minInsertions(string s) {
        int n = s.length();
        string sReverse = s;
        reverse(sReverse.begin(), sReverse.end());

        return n - lcs(s, sReverse, n, n);
    }
};

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string str1, string str2) { 
        int m = str1.size(), n = str2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n+1, 0));
        int c = findLCSLen(str1, str2, dp);
        return m + n - 2 * c;
	} 
private:
    int findLCSLen(string s1, string s2, vector<vector<int>> dp) {
        int maxLen = 0;

        for(int i = 1; i <= s1.size(); i++) {
            for(int j = 1; j <= s2.size(); j++) {
                if(s1[i - 1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                maxLen = max(maxLen, dp[i][j]);
            }
        }
        return maxLen;
    }
};
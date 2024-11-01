#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = true;
            count++;
        }

        for (int start = s.size() - 1; start >= 0; start--) {
            for (int end = start + 1; end < s.size(); end++) {
                if (s[start] == s[end]) {
                    if (end - start == 1 || dp[start + 1][end - 1]) {
                        dp[start][end] = true;
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
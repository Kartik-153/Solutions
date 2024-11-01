#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        for(int length = s.size(); length > 0; length--) {
            for(int start = 0; start <= s.size()-length; start++) {
                if(check(s, start, start+length)) {
                    return s.substr(start, length);
                }
            }
        }

        return "";
    }
private:
    bool check(string s, int i, int j) {
        int left = i;
        int right = j - 1;

        while( left < right) {
            if(s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }
        return true;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        array<int, 2> ans = {0, 0};

        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                ans = {i, i + 1};
            }
        }

        for (int diff = 2; diff < n; ++diff) {
            for (int i = 0; i < n - diff; ++i) {
                int j = i + diff;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    ans = {i, j};
                }
            }
        }

        int i = ans[0];
        int j = ans[1];
        return s.substr(i, j - i + 1);
    }
};
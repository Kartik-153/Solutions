#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        return recursion(s, 0, s.size() -1);
    }

private:
    int recursion(string s, int start, int end) {
        if(start >= end || isPalindrome(s, start, end)) {
            return 0;
        }

        int minimumCuts = end - start;
        for(int i = start; i <= end; i++) {
            if(isPalindrome(s, start, i)) {
                minimumCuts = min(minimumCuts, 1 + recursion(s, i + 1, end));
            }
        }
        return minimumCuts;

    }

    bool isPalindrome(string s, int start, int end) {
        while(start < end) {
            if(s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

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
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<vector<int>> dpIsPalindrome(n, vector<int>(n, -1));


    }

private:
    int recursion(string s, int start, int end, vector<vector<int>>& dp, vector<vector<int>>& dpIsPalindrome) {
        if(start >= end || isPalindrome(s, start, end, dpIsPalindrome)) {
            return 0;
        }

        if(dp[start][end] != -1) {
            return dp[start][end];
        }

        int minimumCuts = end - start;
        for(int i = start; i <= end; i++) {
            if(isPalindrome(s, start, i, dpIsPalindrome)) {
                minimumCuts = min(minimumCuts, 1 + recursion(s, i+1, end, dp, dpIsPalindrome));
            }
        }
        dp[start][end] = minimumCuts;
        return dp[start][end];
    }

    bool isPalindrome(string s, int start, int end, vector<vector<int>>& dpIspalindrome) {
        if(dpIspalindrome[start][end] != -1) {
            return dpIspalindrome[start][end];
        }

        int i = start, j = end;
        while(i <= j) {
            if(s[i++] != s[j--]) {
                dpIspalindrome[start][end] = 0;
                return false;
            }

            if(i < j && dpIspalindrome[i][j] != -1) {
                dpIspalindrome[start][end] = dpIspalindrome[i][j];
                return dpIspalindrome[i][j];
            }
        }

        dpIspalindrome[start][end] = 1;
        return true;
    }
};

class Solution {
public: 
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

        for(int i = 0; i < n; i++) {
            isPalindrome[i][i] = true;
        }

        for(int start = n - 1; start >= 0; start--) {
            for(int end = start + 1; end < n; end++) {
                if(s[end] == s[start]) {
                    if(end - start == 1 || isPalindrome[start+1][end-1]) {
                        isPalindrome[start][end] = true;
                    }
                }
            }
        }

        vector<int> cuts(n, 0);
        for(int  start = n - 1; start >= 0; start--) {
            int minCuts = n;
            for(int end = n - 1; end >= start; end--) {
                if(isPalindrome[start][end]) {
                    minCuts = (end == n - 1) ? 0 : min(minCuts, 1 + cuts[end+1]);
                }
            }
            cuts[start] = minCuts;
        }

        return cuts[0];
    }
};
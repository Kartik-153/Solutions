#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string text, string pattern) {
        if (pattern.empty()) {
            return text.empty();
        }
        bool first_match = (!text.empty() && 
                            (pattern[0] == text[0] || pattern[0] == '.'));

        if (pattern.size() >= 2 && pattern[1] == '*') {
            return (isMatch(text, pattern.substr(2)) || 
                    (first_match && isMatch(text.substr(1), pattern)));
        } else {
            return first_match && isMatch(text.substr(1), pattern.substr(1));
        }
    }
};

enum class Result { TRUE, FALSE, NONE };

class Solution {
    vector<vector<Result>> memo;

public:
    bool isMatch(string text, string pattern) {
        memo = vector<vector<Result>>(
            text.size() + 1, vector<Result>(pattern.size() + 1, Result::NONE));
        return dp(0, 0, text, pattern);
    }

private:
    bool dp(int i, int j, const string& text, const string& pattern) {
        if (memo[i][j] != Result::NONE) {
            return memo[i][j] == Result::TRUE;
        }

        bool ans;
        if (j == pattern.size()) {
            ans = (i == text.size());
        } else {
            bool first_match = (i < text.size() &&
                                (pattern[j] == text[i] || pattern[j] == '.'));

            if (j + 1 < pattern.size() && pattern[j + 1] == '*') {
                ans = dp(i, j + 2, text, pattern) ||
                      (first_match && dp(i + 1, j, text, pattern));
            } else {
                ans = first_match && dp(i + 1, j + 1, text, pattern);
            }
        }

        memo[i][j] = ans ? Result::TRUE : Result::FALSE;
        return ans;
    }
};

class Solution {
public:
    bool isMatch(string text, string pattern) {
        int m = text.size(), n = pattern.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[m][n] = true;
        for (int i = m; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                bool first_match =
                    (i < m && (pattern[j] == text[i] || pattern[j] == '.'));
                if (j + 1 < n && pattern[j + 1] == '*') {
                    dp[i][j] = dp[i][j + 2] || (first_match && dp[i + 1][j]);
                } else {
                    dp[i][j] = first_match && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};

/*
    Given string & pattern, implement RegEx matching
    '.' -> matches any single character
    '*' -> matches zero or more of the preceding element
    Matching should cover the entire input string (not partial)
    Ex. s = "aa", p = "a" -> false, "a" doesn't match entire string "aa"

    DFS + memo, 2 choices at a *: either use it, or don't use it

    Time: O(m x n)
    Space: O(m x n)
*/

class Solution {
public:
    bool isMatch(string s, string p) { return dfs(s, p, 0, 0); }

private:
    map<pair<int, int>, bool> dp;

    bool dfs(string& s, string& p, int i, int j) {
        if (dp.find({i, j}) != dp.end()) {
            return dp[{i, j}];
        }

        if (i >= s.size() && j >= p.size()) {
            return true;
        }
        if (j >= p.size()) {
            return false;
        }

        bool match = i < s.size() && (s[i] == p[j] || p[j] == '.');
        if (j + 1 < p.size() && p[j + 1] == '*') {
            // choices: either (1) don't use *, or (2) use *
            dp[{i, j}] = dfs(s, p, i, j + 2) || (match && dfs(s, p, i + 1, j));
            return dp[{i, j}];
        }

        if (match) {
            dp[{i, j}] = dfs(s, p, i + 1, j + 1);
            return dp[{i, j}];
        }

        dp[{i, j}] = false;
        return dp[{i, j}];
    }
};

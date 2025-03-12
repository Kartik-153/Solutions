#include <bits/stdc++.h>
using namespace std;

class Solution { // Naive Iterative Method
public:
    int maxCommStr(string s1, string s2) { // Try all the substring
        int m = s1.size();
        int n = s2.size();

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int curr = 0;
                while ((i + curr) < m && (j + curr) < n &&
                       s1[i + curr] == s2[j + curr]) {
                    curr++;
                }
                res = max(res, curr);
            }
        }
        return res;
    }
};

class Solution2 { // Recursive Solution
public:
    int maxCommStr(string s1, string s2) {
        int res = 0;
        for (int i = 1; i <= s1.size(); i++) {
            for (int j = 1; j <= s2.size(); j++) {
                res = max(res, LCSuf(s1, s2, i, j));
            }
        }
        return res;
        // return LCSRecursive(s1, s2, 0, 0, 0);
    }

private:
    int LCSRecursive(string& s1, string& s2, int idx1, int idx2, int count) {
        if (idx1 == s1.size() || idx2 == s2.size())
            return count;
        int currentCnt = count;
        if (s1[idx1] == s2[idx2]) {
            currentCnt = LCSRecursive(s1, s2, idx1 + 1, idx2 + 1, count + 1);
        }
        int checkFirstString = LCSRecursive(s1, s2, idx1, idx2 + 1, 0);
        int checkSecondString = LCSRecursive(s1, s2, idx1 + 1, idx2, 0);

        return max(currentCnt, max(checkFirstString, checkSecondString));
    }

    int LCSuf(string& s1, string& s2, int m, int n) {
        if (m == 0 || n == 0 || s1[m - 1] != s2[n - 1])
            return 0;
        return 1 + LCSuf(s1, s2, m - 1, n - 1);
    }
};

class Solution {
public:
    int maxCommStr(string& s1, string s2) {
        int len = min(s1.size(), s2.size());
        vector<vector<int>> dp(len, vector<int>(len));
    }

    int findLCSLengthRecursive(const string& str1, const string& str2,
                               int index1, int index2, int count,
                               vector<vector<vector<int>>>& dp) {
        // Base case
        if (index1 == str1.length() || index2 == str2.length()) {
            return count;
        }

        if (dp[index1][index2][count] == -1) {
            int checkFirstString = count;
            if (str1[index1] == str2[index2]) {
                checkFirstString = findLCSLengthRecursive(
                    str1, str2, index1 + 1, index2 + 1, count + 1, dp);
            }

            int checkSecondString =
                findLCSLengthRecursive(str1, str2, index1, index2 + 1, 0, dp);
            int checkThirdString =
                findLCSLengthRecursive(str1, str2, index1 + 1, index2, 0, dp);

            dp[index1][index2][count] =
                max(checkFirstString, max(checkSecondString, checkThirdString));
        }
        return dp[index1][index2][count];
    }

    int findLCSLength(const string& str1, const string& str2) {
        int len1 = str1.length(), len2 = str2.length();
        vector<vector<vector<int>>> dp(
            len1, vector<vector<int>>(len2, vector<int>(max(len1, len2), -1)));
        return findLCSLengthRecursive(str1, str2, 0, 0, 0, dp);
    }
};

class Solution3 {
public:
    int maxCommStr(string& s1, string& s2) {
        int m = s1.length();
        int n = s2.length();

        vector<vector<int>> LCSSuf(m + 1, vector<int>(n + 1, 0));

        int res = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    LCSSuf[i][j] = LCSSuf[i - 1][j - 1] + 1;
                    res = max(res, LCSSuf[i][j]);
                } else {
                    LCSSuf[i][j] = 0;
                }
            }
        }
        return res;
    }
};

class Solution4 {
public:
    int maxCommStr(string& s1, string& s2) {
        int m = s1.size();
        int n = s2.size();

        vector<int> prev(n + 1, 0);
        int res = 0;
        for (int i = 1; i <= m; i++) {
            vector<int> curr(n + 1, 0);
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    curr[j] = prev[j - 1] + 1;
                    res = max(res, curr[j]);
                } else {
                    curr[j] = 0;
                }
            }
            prev = curr;
        }

        return res;
    }
};

int main() {
    string s1 = "geeksforgeeks";
    string s2 = "practicewritegeekscourses";
    Solution4 x;
    cout << x.maxCommStr(s1, s2) << endl;
    return 0;
}
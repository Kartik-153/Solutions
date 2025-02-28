#include <bits/stdc++.h>
using namespace std;

class Solution { // Brute Force
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // Base case: both strings are empty
        if (str1.empty() && str2.empty()) {
            return "";
        }

        // Base case: one string is empty, append the other string
        if (str1.empty()) {
            return str2;
        }

        if (str2.empty()) {
            return str1;
        }

        // If the first characters match, include it in the supersequence
        if (str1[0] == str2[0]) {
            return str1[0] +
                   shortestCommonSupersequence(str1.substr(1), str2.substr(1));
        } else {
            // Try both options: picking from str1 or str2, and choose the
            // shorter one
            string pickStr1 =
                str1[0] + shortestCommonSupersequence(str1.substr(1), str2);
            string pickStr2 =
                str2[0] + shortestCommonSupersequence(str1, str2.substr(1));

            return (pickStr1.length() < pickStr2.length()) ? pickStr1
                                                           : pickStr2;
        }
    }
};
class Solution { // Memoization
public:
    string shortestCommonSupersequence(string str1, string str2) {
        unordered_map<string, string> memo;
        return helper(str1, str2, memo);
    }

private:
    string helper(string str1, string str2,
                  unordered_map<string, string>& memo) {
        string memoKey = str1 + " " + str2;

        // Check if result is already computed
        if (memo.find(memoKey) != memo.end()) {
            return memo[memoKey];
        }

        // Base case: both strings are empty
        if (str1.empty() && str2.empty()) {
            return "";
        }

        // Base case: one string is empty, append the other string
        if (str1.empty()) {
            return str2;
        }
        if (str2.empty()) {
            return str1;
        }

        // If the first characters match, include it in the supersequence
        if (str1[0] == str2[0]) {
            return memo[memoKey] =
                       str1[0] + helper(str1.substr(1), str2.substr(1), memo);
        }

        // Try both options: picking from str1 or str2, and choose the shorter
        // one
        string pickStr1 = str1[0] + helper(str1.substr(1), str2, memo);
        string pickStr2 = str2[0] + helper(str1, str2.substr(1), memo);

        return memo[memoKey] = (pickStr1.length() < pickStr2.length())
                                   ? pickStr1
                                   : pickStr2;
    }
};

class Solution { // Bottom Up
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        vector<string> prevRow(m + 1);
        for (int col = 0; col <= m; col++) {
            prevRow[col] = str2.substr(0, col);
        }

        for (int row = 1; row <= n; row++) {
            vector<string> currRow(m + 1);
            currRow[0] = str1.substr(0, row);

            for (int col = 1; col <= m; col++) {
                if (str1[row - 1] == str2[col - 1]) {
                    currRow[col] = prevRow[col - 1] + str1[row - 1];
                } else {
                    string pickS1 = prevRow[col];
                    string pickS2 = currRow[col - 1];
                    currRow[col] = (pickS1.size() < pickS2.size())
                                       ? pickS1 + str1[row - 1]
                                       : pickS2 + str2[col - 1];
                }
            }
            prevRow = currRow;
        }
        return prevRow[m];
    }
};

class Solution { // Most optimal - Only this code was excepted
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int str1Length = str1.length();
        int str2Length = str2.length();

        vector<vector<int>> dp(str1Length + 1, vector<int>(str2Length + 1, 0));

        // Initialize the base cases
        // When str2 is empty, the supersequence is str1 itself
        // (length = row index)
        for (int row = 0; row <= str1Length; row++) {
            dp[row][0] = row;
        }
        // When str1 is empty, the supersequence is str2 itself
        // (length = col index)
        for (int col = 0; col <= str2Length; col++) {
            dp[0][col] = col;
        }

        // Fill the DP table
        for (int row = 1; row <= str1Length; row++) {
            for (int col = 1; col <= str2Length; col++) {
                if (str1[row - 1] == str2[col - 1]) {
                    // If characters match,
                    // inherit the length from the diagonal + 1
                    dp[row][col] = dp[row - 1][col - 1] + 1;
                } else {
                    // If characters do not match,
                    // take the minimum length option + 1
                    dp[row][col] = min(dp[row - 1][col], dp[row][col - 1]) + 1;
                }
            }
        }

        string supersequence = "";
        int row = str1Length, col = str2Length;

        while (row > 0 && col > 0) {
            if (str1[row - 1] == str2[col - 1]) {
                // If characters match, take it from diagonal
                supersequence += str1[row - 1];
                row--;
                col--;
            } else if (dp[row - 1][col] < dp[row][col - 1]) {
                // If str1’s character is part of the supersequence, move up
                supersequence += str1[row - 1];
                row--;
            } else {
                // If str2’s character is part of the supersequence, move left
                supersequence += str2[col - 1];
                col--;
            }
        }

        // Append any remaining characters
        // If there are leftover characters in str1
        while (row > 0) {
            supersequence += str1[row - 1];
            row--;
        }
        // If there are leftover characters in str2
        while (col > 0) {
            supersequence += str2[col - 1];
            col--;
        }

        // Reverse the built sequence to get the correct order
        reverse(supersequence.begin(), supersequence.end());
        return supersequence;
    }
};

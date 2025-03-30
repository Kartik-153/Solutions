#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s, string t) {
        vector<string> subs = getAllSubstrings(s);
        vector<string> subt = getAllSubstrings(t);

        int maxLen = 0;
        for (string str1 : subs) {
            for (string str2 : subt) {
                string concat = str1 + str2;
                if (isPalindrome(str1) && isPalindrome(str2)) {
                    maxLen = max(maxLen, max((int)str1.size(), (int)str2.size()));
                }
                
                if (isPalindrome(concat)) {
                    maxLen = max(maxLen, (int)concat.size());
                }
            }
        }

        return maxLen;
    }

private:
    vector<string> getAllSubstrings(string str) {
        int n = str.size();
        vector<string> substrings;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                substrings.push_back(str.substr(i, j - i + 1));
            }
        }
        return substrings;
    }

    bool isPalindrome(string str) {
        int l = 0, r = str.size() - 1;
        while (l < r) {
            if (str[l] != str[r])
                return false;
            l++, r--;
        }
        return true;
    }
};

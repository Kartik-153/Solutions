#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string reverseString = s;
        reverse(reverseString.begin(), reverseString.end());

        for(int i = 0; i < s.size(); i++) {
            if(!memcmp(s.c_str(), reverseString.c_str() + i, s.size() - i)) {
                return reverseString.substr(0, i) + s;
            }
        }

        return reverseString + s;
     }
};

class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if (n == 0)
            return s;

        int left = 0;
        for (int right = n - 1; right >= 0; right--) {
            if (s[right] == s[left]) {
                left++;
            }
        }

        if (left == n)
            return s;

        string nonPalinSuffix = s.substr(left);
        string reverseSuffix =
            string(nonPalinSuffix.rbegin(), nonPalinSuffix.rend());

        return reverseSuffix + shortestPalindrome(s.substr(0, left)) +
               nonPalinSuffix;
    }
};
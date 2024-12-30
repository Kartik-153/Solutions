#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<char, int> roman = {{'I', 1},   {'V', 5},   {'X', 10},
                                          {'L', 50},  {'C', 100}, {'D', 500},
                                          {'M', 1000}};

        for (int i = 0; i < s.size() - 1; i++) {
            if (roman[s[i]] < roman[s[i + 1]])
                res -= roman[s[i]];
            else
                res += roman[s[i]];
        }
        return res + roman[s[s.size() - 1]];
    }
};

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
            case 'I':
                if (s[i + 1] == 'V') {
                    ans += 4;
                    i++;
                } else if (s[i + 1] == 'X') {
                    ans += 9;
                    i++;
                } else {
                    ans += 1;
                }
                break;
            case 'V':
                ans += 5;
                break;
            case 'X':
                if (s[i + 1] == 'L') {
                    ans += 40;
                    i++;
                } else if (s[i + 1] == 'C') {
                    ans += 90;
                    i++;
                } else {
                    ans += 10;
                }
                break;
            case 'L':
                ans += 50;
                break;
            case 'C':
                if (s[i + 1] == 'D') {
                    ans += 400;
                    i++;
                } else if (s[i + 1] == 'M') {
                    ans += 900;
                    i++;
                } else {
                    ans += 100;
                }
                break;
            case 'D':
                ans += 500;
                break;
            case 'M':
                ans += 1000;
                break;
            }
        }
        return ans;
    }
};

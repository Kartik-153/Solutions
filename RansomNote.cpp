#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string r, string m) {
        unordered_map<char, int> di;
        for (char c : m) {
            if (di.find(c) == di.end()) {
                di[c] = 1;
            } else {
                di[c]++;
            }
        }

        for (char c : r) {
            if (di.find(c) != di.end() && di[c] > 0) {
                di[c]--;
            } else {
                return false;
            }
        }
        return true;
    }
};

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> v;
        string s = "";

        for (char c : target) {
            s += 'a';
            v.push_back(s);
            while (s.back() != c) {
                s.back() = (s.back() == 'z') ? 'a' : s.back() + 1;
                v.push_back(s);
            }
        }
        return v;
    }
};
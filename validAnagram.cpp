#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> alpha1(26, 0);
        vector<int> alpha2(26, 0);
        for(int i = 0; i < s.length(); i++) {
            alpha1[s[i]-'a'] += 1;
        }
        for(int i = 0; i < t.length(); i++) {
            alpha2[t[i]-'a'] += 1;
        }

        for(int i = 0; i < 26; i++) {
            if(alpha1[i] != alpha2[i]) {
                return false;
            }
        }
        return true;
    }
};

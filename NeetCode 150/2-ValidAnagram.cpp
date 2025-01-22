#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> chrA(26, 0);
        vector<int> chrB(26, 0);
        int n = s.size();
        int m = t.size();
        if(n != m) return false;

        for(char ch : s) chrA[ch-'a']++;
        for(char ch : t) chrB[ch-'a']++;
        return chrA==chrB;
    }
};

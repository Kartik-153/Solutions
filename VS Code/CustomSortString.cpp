#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> smap;
        for(char c: order){
            smap[c] = 0;
        }
        for(char c: s) {
            if(smap.find(c) != smap.end()) {
                smap[c]++;
            }
        }
        string result;
        for(char c: order) {
            result.append(smap[c], c);
        }
        for(char c: s) {
            if(smap.find(c) == smap.end()) {
                result.push_back(c);
            }
        }
        return result;
    }
};
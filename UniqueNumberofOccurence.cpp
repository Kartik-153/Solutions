#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;

        for(int num: arr) {
            mp[num]++;
        }

        unordered_map<int, int> tmp;

        for(auto& a: mp) {
            tmp[a.second]++;
        }

        for(auto& num: tmp) {
            if(num.second > 1) {
                return false;
            }
        }
        return true;
    }
};

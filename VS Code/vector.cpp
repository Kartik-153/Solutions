#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>& successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size();
        int m = potions.size();
        vector<int> res;
        for(int i = 0; i < n; i++) {
            int spell = spells[i];
            int s = 0;
            int e = m;
            while(s<e) {
                int mid = (s+e)/2;
                if(spell*potions[mid] >= success) {
                    e = mid;
                }
                else {
                    s = mid + 1;
                }
            }
            res.push_back(m-s);
        }
        return res;
    }

};
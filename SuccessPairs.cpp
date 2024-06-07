#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // Brute force will give TLE
        // sort(potions.begin(), potions.end());
        // vector<int> res;
        // for(int i = 0; i < spells.size(); i++) {
        //     int temp = 0;
        //     for(int j = 0; j < potions.size(); j++) {
        //         if(spells[i]*potions[j] >= success)
        //             temp++;
        //     }
        //     res.push_back(temp);
        // }
        // return res;
        
        sort(potions.begin(), potions.end());
        vector<int> res;
        int n = spells.size();
        int m = potions.size();
        for(int i = 0; i < n; i++) {
            long long spell = spells[i];
            int s = 0;
            int e = m;
            while(s<e) {
                int mid = (s + e)/2;
                if(spell*potions[mid] >= success) {
                    e = mid;
                } else {
                    s = mid + 1;
                }
            }
            res.push_back(m - s);
        }
        return res;

    }
};

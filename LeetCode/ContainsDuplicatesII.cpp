#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // int s = 0;
        // int e = nums.size() - 1;

        // while(s < e) {
        //     if(nums[s] == nums[e] && abs(s-e) <= k) {
        //         return true;
        //     }
        //     if(abs(s-e) > k)
        //         e--;
        //     s++;
        //     e--;
        // }
        // return false;

        unordered_set<int> nuset;
        for(int i = 0; i < nums.size(); i++) {
            if(nuset.find(nums[i]) != nuset.end()) {
                return true;
            }
            nuset.insert(nums[i]);
            if(nuset.size() > k) {
                nuset.erase(nums[i-k]);
            }
        }
        return false;
    }
};


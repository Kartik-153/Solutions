#include<bits/stdc++.h>
using namespace std;

class Solution { // Best Solution.
public:
    bool containsDuplicate(vector<int>& nums) {
        int mx = INT_MIN;
        int mn = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < mn || nums[i] > mx) {
                mn = min(mn, nums[i]);
                mx = max(mx, nums[i]);
                continue;
            }
            for (int j = 0; j < i; j++) {
                if (nums[j] == nums[i])
                    return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        set<int> s;
        for(auto num: nums) {
            if(s.find(num) != s.end()) return true;
            s.insert(num);
        }
        return false;
    }
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums
    , int target) {
        unordered_map<int,int> s;
        for(int i = 0; i < nums.size(); i++) {
            int comp = target - nums[i];
            if(s.count(comp)) {
                return {s[comp], i};
            }
            s[nums[i]] = i;
        }
    }
};
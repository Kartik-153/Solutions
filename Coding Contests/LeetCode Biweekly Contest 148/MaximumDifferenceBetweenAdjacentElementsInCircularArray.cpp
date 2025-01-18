#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int res = abs(nums[0] - nums[n-1]);
        for(int i = 1; i < n; i++) {
            res = max(res, abs(nums[i-1] - nums[i]));
        }
        return res;
    }
};

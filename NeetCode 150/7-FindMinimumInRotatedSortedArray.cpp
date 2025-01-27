#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int ans = INT_MAX;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(nums[l] <= nums[r]) {
                ans = min(ans, nums[l]);
                l = mid + 1;
            } else {
                ans = min(ans, nums[mid]);
                r = mid - 1;
            }
        }
        return ans;
    }
};
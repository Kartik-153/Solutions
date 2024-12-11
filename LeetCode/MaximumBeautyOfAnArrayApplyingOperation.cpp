#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int maxBeauty = 0;

        for(int i = 0; i < nums.size(); i++) {
            int upperBound = findUpperBound(nums, nums[i]-2*k);
            maxBeauty = max(maxBeauty, upperBound);
        }

        return maxBeauty;
    }

private:
    int findUpperBound(vector<int>& nums, int val) {
        int l = 0, h = nums.size() - 1, res = 0;

        while(l <= h) {
            int mid = l + (h - l)/2;
            if(nums[mid] <= val) {
                res = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return res;
    }
};
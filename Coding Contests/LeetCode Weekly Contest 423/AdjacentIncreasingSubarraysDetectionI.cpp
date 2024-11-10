#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2 * k)
            return false;

        for (int i = 0; i <= n - 2 * k; i++) {
            if (check(nums, i, k) && check(nums, i + k, k)) {
                return true;
            }
        }

        return false;
    }

private:
    bool check(vector<int>& nums, int start, int k) {
        for (int i = start; i < start + k - 1; i++) {
            if (nums[i] >= nums[i + 1]) {
                return false;
            }
        }
        return true;
    }
};
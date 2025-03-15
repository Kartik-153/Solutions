#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        int ans1 = robber(nums, 0, n - 2);
        int ans2 = robber(nums, 1, n - 1);
        return max(ans1, ans2);
    }

private:
    int robber(vector<int>& nums, int s, int e) {
        int prev = 0;
        int curr = 0;
        int next = 0;

        for (int i = s; i <= e; i++) {
            next = max(prev + nums[i], curr);
            prev = curr;
            curr = next;
        }
        return curr;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int minReward = 1, maxReward = *max_element(nums.begin(), nums.end());
        int n = nums.size();

        while (minReward < maxReward) {
            int midReward = (minReward + maxReward) / 2;
            int possibleThefts = 0;

            for (int idx = 0; idx < n; idx++) {
                if (nums[idx] <= midReward) {
                    possibleThefts += 1;
                    idx++;
                }
            }
            if (possibleThefts >= k) {
                maxReward = midReward;
            } else {
                minReward = midReward + 1;
            }
        }
        return minReward;
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution { // Brute force O(2^n)
public:
    int findMaxSteal(vector<int>& nums, int currIndex) {
        if(currIndex >= nums.size()) return 0;

        int stealCurr = nums[currIndex] + findMaxSteal(nums, currIndex + 2);

        int skipCurr = findMaxSteal(nums, currIndex + 1);

        return max(stealCurr, skipCurr);
    }
    int rob(vector<int>& nums) {
        return findMaxSteal(nums, 0);
    }
};

class Solution { // Top Down
public:
    int findMaxStealMemo(vector<int>& nums, int currIndex, vector<int>& dp) {
        if(currIndex >= nums.size()) return 0;

        int stealCurr = nums[currIndex] + findMaxStealMemo(nums, currIndex + 2, dp);

        int skipCurr = findMaxStealMemo(nums, currIndex + 1, dp);
        
        dp[currIndex] = max(stealCurr, skipCurr);

        return dp[currIndex];
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        return findMaxStealMemo(nums, 0, dp);
    }
};
class Solution { // Bottom Up 
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 0);

        dp[1] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            dp[i + 1] = max(nums[i] + dp[i - 1], dp[i]);
        }

        return dp[nums.size()];
    }
};

class Solution { // Bottom Up with memory optimization 
public:
    int rob(vector<int>& wealth) {
        if (wealth.empty()) return 0;

        int house1 = 0;
        int house2 = wealth[0];

        for (size_t i = 1; i < wealth.size(); i++) {
            int current = max(house1 + wealth[i], house2);
            house1 = house2;
            house2 = current;
        }

        return house2;
    }
};
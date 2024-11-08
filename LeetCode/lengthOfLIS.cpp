#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) {
            return -1;
        }        
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return recursive(nums, 0, -1);
    }

private:
    int recursive(vector<int>& nums, int currIndex, int prevIndex) {
        if(currIndex == nums.size()) return 0;

        int cnt1 = 0;
        if(prevIndex == -1 || nums[currIndex] > nums[prevIndex]) {
            cnt1 = 1 + recursive(nums, currIndex+1, currIndex);
        }

        int cnt2 = recursive(nums, currIndex+1, prevIndex);
        return max(cnt1, cnt2);
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp;
        return recursiveMemo(nums, 0, -1, dp);
    }
private:
    int recursiveMemo(vector<int>& nums, int currIndex, int prevIndex, vector<vector<int>>& dp) {
        if(currIndex == nums.size()) return 0;

        if(dp[currIndex][prevIndex + 1] == -1) {
            int cnt1 = 0;
            if(prevIndex == -1 || nums[currIndex] > nums[prevIndex]) {
                cnt1 = 1 + recursiveMemo(nums, currIndex + 1, currIndex, dp);
            } 

            int cnt2 = recursiveMemo(nums, currIndex + 1, prevIndex, dp);
            dp[currIndex][prevIndex + 1] = max(cnt1, cnt2);
        }

        return dp[currIndex][prevIndex + 1];
        
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, -1);
        int maxLen = 1;
        for(int i = 0; i < n; i++) {
            dp[i] = 1;
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j] && dp[i] <= dp[j]) {
                    dp[i] = dp[j] + 1;
                    maxLen = max(maxLen, dp[i]);
                }
            }
        }
        return maxLen;
    }
};
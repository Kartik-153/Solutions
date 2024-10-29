#include<bits/stdc++.h>
using namespace std;

class Solution {  // Brute Force - Time Limit Exceeded
public:
    int countMinJumpsRecursive(vector<int>& jumps, int jumpIndex) {
        if(jumpIndex >= jumps.size() - 1) return 0;

        if(jumps[jumpIndex] == 0) return INT_MAX;

        int totalJumps = INT_MAX;
        int start = jumpIndex + 1;
        int end = jumpIndex + jumps[jumpIndex];

        for(int i = start; i <= end && i < jumps.size(); i++) {
            int minJumps = countMinJumpsRecursive(jumps, i);

            if(minJumps != INT_MAX) {
                totalJumps = min(totalJumps, minJumps + 1);
            }
        }

        return totalJumps;
    }

    int jump(vector<int>& nums) {
        return countMinJumpsRecursive(nums, 0);
    }
};


class Solution2 { // TLE - Top Down DP
public:
    int countMinJumpsTopDown(vector<int>& jumps, int jumpIndex, vector<int>& dp) {
        if(jumpIndex >= jumps.size() - 1) return 0;

        if(jumps[jumpIndex] == 0) return INT_MAX;

        int totalJumps = INT_MAX;
        int start = jumpIndex + 1;
        int end = jumpIndex + jumps[jumpIndex];

        while(start < jumps.size() && start <= end) {
            int minJumps = countMinJumpsTopDown(jumps, start++, dp);

            if(minJumps != INT_MAX) {
                totalJumps = min(totalJumps, minJumps + 1);
            }
            dp[jumpIndex] = totalJumps;
        }
        return dp[jumpIndex];
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        return countMinJumpsTopDown(nums, 0, dp);
    }
};

class Solution3 {  // Bottom Up approach O(n) 
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX);
        dp[0] = 0;

        for(int start = 0; start < nums.size() - 1; start++) {
            for(int end = start + 1; end <= start + nums[start] && end < nums.size(); end++) {
                dp[end] = min(dp[end], dp[start] + 1);
            }
        }

        return dp[nums.size() - 1];
    }
};
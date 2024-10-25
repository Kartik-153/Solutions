#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cnt = 0;
    int findTargetSumWays(vector<int>& nums, int target) {
        calculate(nums, 0, 0, target);
        return cnt;
    }
private:
    void calculate(vector<int>& nums, int i, int sum, int target) {
        if(i == nums.size()) {
            if(sum==target) {
                cnt++;
            }
        } else {
            calculate(nums, i+1, sum + nums[i], target);
            calculate(nums, i+1, sum-nums[i], target);
        }
    }
};

class Solution2 {
public:
    int total;

    int findTargetSumWays(vector<int>& nums, int S) {
        total = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> memo(nums.size(), vector<int>(2*total + 1, INT_MIN));

    }

private:
    int calculate(vector<int>& nums, int i, int sum, int S, vector<vector<int>>& memo) {
        if(i == nums.size()) {
            return (sum==S) ? 1 : 0;
        } else {
            if(memo[i][sum+total] != INT_MIN) {
                return memo[i][sum+total];
            }
        }

        int add = calculate(nums, i+1, sum+nums[i], S, memo);
        int subtract = calculate(nums, i+1, sum-nums[i], S, memo);

        memo[i][sum+total]=add + subtract;
        return memo[i][sum+total];
    }
};
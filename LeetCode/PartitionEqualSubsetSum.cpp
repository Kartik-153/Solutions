#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition_bruteForce(vector<int>& nums) {
        int sum = 0;

        for(auto n : nums) {
            sum += n;
        }        

        if(sum % 2 != 0) {
            return false;
        }
        return canPartitionRecursive(nums, sum/2, 0);
    }
bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0)
            return false;

        int subset_sum = sum / 2;

        vector<vector<bool>> dp(subset_sum + 1,
                                vector<bool>(nums.size() + 1, false));

        for (int i = 0; i <= nums.size(); i++) {
            dp[0][i] = true;
        }

        for (int i = 1; i <= subset_sum; i++) {
            for (int j = 1; j <= nums.size(); j++) {
                if (nums[j - 1] > i) {
                    dp[i][j] = dp[i][j - 1];
                } else {
                    dp[i][j] = dp[i - nums[j - 1]][j - 1] || dp[i][j - 1];
                }
            }
        }
        return dp[subset_sum][nums.size()];
    }

bool canPartition_bottomUp(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for(int i : nums) {
        sum += i;
    }
    if(sum&1)
        return false;
    int subsetSum = sum/2;
    vector<vector<bool>> dp(n, vector<bool>(subsetSum+1, false));
    for(int i = 0; i < n; i++)
        dp[i][0] = true;
    for(int s = 1; s <= subsetSum; s++) 
        dp[0][s] = (nums[0] == s);
    
    for(int i = 1; i < n; i++) {
        for(int s = 1; s <= subsetSum; s++) {
            if(dp[i-1][s]) 
                dp[i][s] = dp[i-1][s];
            else if(s >= nums[i])
                dp[i][s] = dp[i-1][s-nums[i]];
        }
    }
    return dp[n-1][subsetSum];
}

private:
    bool canPartitionRecursive(vector<int>& num, int sum, int currIndex) {
        if(sum == 0) {
            return true;
        }

        if(num.empty() || currIndex >= num.size()) {
            return false;
        }

        if(num[currIndex] <= sum) {
            if(canPartitionRecursive(num, sum - num[currIndex], currIndex + 1)) {
                return true;
            }
        }

        return canPartitionRecursive(num, sum, currIndex + 1);
    }
};


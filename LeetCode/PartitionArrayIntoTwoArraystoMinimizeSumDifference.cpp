#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        if(nums.size() == 2) {
            return abs(nums[0] - nums[1]);
        }
        return canPartitionRecursive(nums, 0,0,0);
    }

private:
    int canPartitionRecursive(vector<int>& nums, int currIndex, int sum1, int sum2) {
        if(currIndex == nums.size()) return abs(sum1-sum2);

        int diff1 = canPartitionRecursive(nums, currIndex+1, sum1 + nums[currIndex], sum2);        
        int diff2 = canPartitionRecursive(nums, currIndex+1, sum1, sum2 + nums[currIndex]);
        return min(diff1, diff2);
    }
};
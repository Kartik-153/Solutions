#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixSum(n,0);
        prefixSum[0] = nums[0];

        for (int i = 1; i < n; i++)
            prefixSum[i] = prefixSum[i - 1] + nums[i];

        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            long long leftSum = prefixSum[i];
            long long rightSum = prefixSum[n - 1] - prefixSum[i];
            if (leftSum >= rightSum)
                cnt += 1;
        }
        return cnt;
    }
};

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long leftSum = 0, rightSum = 0;
        for(int num: nums)
            rightSum+=num;
        int cnt = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            leftSum += nums[i];
            rightSum -= nums[i];

            if(leftSum >= rightSum)
                cnt++;
        }   
        return cnt;
    }
};
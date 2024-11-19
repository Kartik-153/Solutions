#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long currentSum = 0;
        int begin = 0;
        int end = 0;

        unordered_map<int, int> numToIndex;
        
        while (end < n) {
            int currNum = nums[end];
            int lastOcc =
                (numToIndex.count(currNum) ? numToIndex[currNum] : -1);

            while (begin <= lastOcc || end - begin + 1 > k) {
                currentSum -= nums[begin++];
            }

            numToIndex[currNum] = end;
            currentSum += nums[end];
            if (end - begin + 1 == k)
                ans = max(ans, currentSum);
            end++;
        }
        return ans;
    }
};


class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res = 0;
        unordered_map<int, int> mp;
        long long currSum = 0;
        int l = 0;
        int r = 0;
        int n = nums.size();
        while (r < n) {
            currSum += nums[r];
            mp[nums[r]] += 1;
            if (r - l + 1 > k) {
                mp[nums[l]] -= 1;
                if (mp[nums[l]] == 0) {
                    mp.erase(nums[l]);
                }
                currSum -= nums[l];
                l += 1;
            }
            if (r - l + 1 == k && mp.size() == k) {
                res = max(res, currSum);
            }

            r += 1;
        }

        return res;
    }
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> Sum;
        int res = 0;
        int currSum = 0;
        for(int i = 0; i < n; i++) {
            currSum += nums[i];
            if(currSum == goal) {
                res++;
            }
            if(Sum.find(currSum-goal) != Sum.end()) {
                res+=(Sum[currSum-goal]);
            }
            Sum[currSum]++;
        }
        return res;
    }
};

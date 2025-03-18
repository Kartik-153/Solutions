#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int usedBits = 0;
        int maxLen = 0;
        for(int e = 0; e < n; e++) {
            while((usedBits & nums[e]) != 0) {
                usedBits ^= nums[s];
                s++;
            }
            usedBits |= nums[e];
            maxLen = max(maxLen, e - s + 1);
        }
        return maxLen;
    }
};
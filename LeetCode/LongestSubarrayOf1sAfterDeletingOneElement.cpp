#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeroCount = 0;
        int res = 0;
        int s = 0;

        for (int i = 0; i < nums.size(); i++) {
            zeroCount += (nums[i] == 0);

            while (zeroCount > 1) {
                zeroCount -= (nums[s] == 0);
                s++;
            }

            res = max(res, i - s);
        }
        return res;
    }
};
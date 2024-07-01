#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = 0;
        int curr_s = 0, min_ln = n + 1;
        
        while(e < n) {
            while(curr_s < target && e < n) {
                curr_s += nums[e++];
            }
            while(curr_s >= target && s < n) {
                min_ln = min(min_ln, e - s);
                curr_s -= nums[s++];
            }
        }
        
        return (min_ln == n + 1) ? 0 : min_ln;
    }
};

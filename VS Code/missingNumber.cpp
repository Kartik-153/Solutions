#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int max_ele = *max_element(nums.begin(), nums.end());
        int min_ele = *min_element(nums.begin(), nums.end());
        int n = nums.size();

        int total = ((n)*(n+1))/2;

        for(int i = 0; i < nums.size(); i++) {
            total = total - nums[i];
        }
        return total;
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        // Sort the numbers using cyclic sort
        while(i < n) {
            int j = nums[i];
            if(nums[i] < n && nums[i] != nums[j]) {
                // Swap the numbers
                swap(nums[i], nums[j]);
            } else {
                i++;
            }
        }

        // Find the first missing number
        for(i = 0; i < n; i++) {
            if(nums[i] != i) {
                return i;
            }
        }
        return n;
    }
};
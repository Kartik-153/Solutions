#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int n = nums.size();
    if (k <= 1) return 0; 
    int res = 0;
    int currProd = 1;
    int left = 0;
    for (int right = 0; right < n; right++) {
        currProd *= nums[right];
        while (currProd >= k) {
            currProd /= nums[left++];
        }
        res += right - left + 1; 
        }
    return res;
}

};

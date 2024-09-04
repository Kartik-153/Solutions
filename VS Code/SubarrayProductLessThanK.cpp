#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> prod;
        int res = 0;
        int currProd = 1;
        for(int i = 0; i < n; i++) {
            currProd *= nums[i];
            if(currProd < k) {
                res++;
            }
            if(prod.find(currProd-k) != prod.end()) {
                res += (prod[currProd-k]);
            }
            prod[currProd]++;
        }
        return res;
    }
};

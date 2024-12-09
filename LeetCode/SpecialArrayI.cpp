#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        bool res = true;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] % 2 == nums[i] % 2) {
                res = false;
                break;
            }
        }
        return res;
    }
};

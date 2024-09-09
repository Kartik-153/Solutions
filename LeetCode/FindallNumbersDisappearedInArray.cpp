#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int> res;
        int n = nums.size();
        int i = 0;

        while (i < n) {
            int j = nums[i] - 1;
            if (nums[i] != nums[j]) {
                swap(nums[i], nums[j]);
            } else {
                i++;
            }
        }

        for (i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                res.push_back(i + 1);
            }
        }

        return res;
    }
};
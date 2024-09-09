#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int i = 0;

        while(i < nums.size()) {
            int j = nums[i] - 1;
            if(nums[i] != nums[j]) {
                swap(nums[i], nums[j]);
            } else {
                i++;
            }
        }

        vector<int> res;

        for(i = 0; i < nums.size(); i++) {
            if(nums[i] != i + 1) {
                res.push_back(nums[i]);
            } 
        }

        return res;
    }
};

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subsets;

        subsets.push_back({});

        int start = 0, end = 0;

        for (int i = 0; i < nums.size(); i++) {
            // If the current element is the same as the previous one, only
            // create new subsets
            // from the subsets added in the previous step to avoid duplicates
            start = 0;
            if (i > 0 && nums[i] == nums[i - 1]) {
                start = end + 1;
            }

            end = subsets.size() - 1;

            for (int j = start; j <= end; j++) {
                vector<int> newSubset = subsets[j];
                newSubset.push_back(nums[i]);
                subsets.push_back(newSubset);
            }
        }
        return subsets;
    }
};
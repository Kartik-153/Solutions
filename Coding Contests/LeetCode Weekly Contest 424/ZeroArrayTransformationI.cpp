#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);

        for (auto& query : queries) {
            int i = query[0], j = query[1];
            diff[i]--;
            if (j + 1 < n) {
                diff[j + 1]++;
            }
        }

        int currDecrement = 0;
        for (int i = 0; i < n; i++) {
            currDecrement += diff[i];
            nums[i] += currDecrement;
            if (nums[i] > 0)
                return false;
        }

        return true;
    }
};
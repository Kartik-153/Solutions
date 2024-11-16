#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1) {
            return nums;
        }

        int n = nums.size();
        vector<int> res(n - k + 1, -1);
        int consCnt = 1;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] + 1 == nums[i + 1]) {
                consCnt += 1;
            } else {
                consCnt = 1;
            }

            if (consCnt >= k) {
                res[i - k + 2] = nums[i + 1];
            }
        }
        return res;
    }
};

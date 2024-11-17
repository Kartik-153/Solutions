#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        auto simulate = [](int start, bool direction, vector<int> nums_copy) {
            int curr = start;
            int n = nums_copy.size();
            while (curr >= 0 && curr < n) {
                if (nums_copy[curr] == 0) {
                    curr = direction ? curr + 1 : curr - 1;
                } else {
                    nums_copy[curr]--;
                    direction = !direction;
                    curr = direction ? curr + 1 : curr - 1;
                }
            }
            for (int val : nums_copy) {
                if (val != 0) {
                    return false;
                }
            }
            return true;
        };
        int validCount = 0;
        int n = nums.size();
        for (int start = 0; start < n; ++start) {
            if (nums[start] == 0) {
                for (bool direction : {true, false}) {
                    vector<int> nums_copy = nums;
                    if (simulate(start, direction, nums_copy)) {
                        validCount++;
                    }
                }
            }
        }

        return validCount;
    }
};

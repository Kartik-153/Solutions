#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        int n = nums.size();

        while (i < n) {
            if (nums[i] > 0 && nums[i] <= n) {
                int j = nums[i] - 1;
                if (nums[i] != nums[j]) {
                    swap(nums[i], nums[j]);
                } else {
                    i++;
                }
            } else {
                i++;
            }
        }

        for (i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return nums.size() + 1;
    }
};

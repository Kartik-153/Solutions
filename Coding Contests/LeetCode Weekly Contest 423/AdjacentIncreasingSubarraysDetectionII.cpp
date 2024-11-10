#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums, vector<int>& incrLength, int k) {
        int n = nums.size();
        for (int i = 0; i <= n - 2 * k; i++) {
            if (incrLength[i] >= k && incrLength[i + k] >= k) {
                return true;
            }
        }

        return false;
    }

    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int> incrLength(n, 1);
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                incrLength[i] = incrLength[i + 1] + 1;
            }
        }

        int left = 1, right = n / 2;
        int maxK = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (check(nums, incrLength, mid)) {
                maxK = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return maxK;
    }

private:
};
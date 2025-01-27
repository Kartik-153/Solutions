#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int k = getPivot(nums);
        if (target >= nums[k] && target <= nums[n - 1]) {
            return binarySearch(nums, k, n - 1, target);
        } else {
            return binarySearch(nums, 0, k - 1, target);
        }
    }

    int getPivot(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        int m;
        while (s < e) {
            m = s + ((e - s) / 2);
            if (nums[m] >= nums[0]) {
                s = m + 1;
            } else {
                e = m;
            }
        }
        return s;
    }

    int binarySearch(vector<int>& nums, int s, int e, int target) {
        int m = 0;
        while (s <= e) {
            m = s + ((e - s) / 2);
            if (nums[m] == target) {
                return m;
            } else if (nums[m] < target) {
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        return -1;
    }
};
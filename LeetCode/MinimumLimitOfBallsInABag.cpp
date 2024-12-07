#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1;
        int right = 0;

        right = *max_element(nums.begin(), nums.end());

        while (left < right) {
            int mid = (left + right) / 2;

            if (isPossible(mid, nums, maxOperations)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool isPossible(int maxBallsInBag, vector<int>& nums, int maxOperations) {
        int totalOperations = 0;

        for (int num : nums) {
            int operations = ceil(num / (double)maxBallsInBag) - 1;
            totalOperations += operations;
            if (totalOperations > maxOperations)
                return false;
        }
        return true;
    }
};

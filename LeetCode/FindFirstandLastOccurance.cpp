#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lower_bound(vector<int>& nums, int low, int high, int target) {
        while(low <= high) {
            int mid = (low+high)/2;
            if(nums[mid] < target)
                low = mid+1;
            else 
                high = mid-1;
        }
        return low;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int startingPosition = lower_bound(nums, low, high, target);
        int endingPosition = lower_bound(nums, low, high, target + 1) - 1;
        if(startingPosition < nums.size() && nums[startingPosition] == target) {
            return {startingPosition, endingPosition};
        }
        return {-1, -1};
    }
};

class Solution2 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        
        return {binSearch(true, nums, target), binSearch(false, nums, target)};
    }

private:

int binSearch(bool leftBias, vector<int>& nums, int target) {
            int l = 0, r = nums.size() - 1, i = -1;

            while(l <= r) {
                int mid = l + (r - l) / 2;

                if(nums[mid] < target) {
                    l = mid + 1;
                }

                else if (nums[mid] > target) {
                    r = mid - 1;
                } else {
                    i = mid;
                    if(leftBias) {
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
            }
            return i;
        }
};

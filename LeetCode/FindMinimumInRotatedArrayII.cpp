#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;

        while(start<=end) {
            int mid = start + (end - start) / 2;

            if(mid < end && nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }
            if(mid > start && nums[mid - 1] > nums[mid]) {
                return nums[mid];
            }

            // if numbers at indices start, mid, and end are same, we can't choose a side
    // the best we can do is to skip one number from both ends if they are not the smallest number
            if(nums[start] == nums[mid] && nums[end] == mid) {
                if(nums[start] > nums[start+1]) {
                    return nums[start+1];
                }
                start += 1;
                if(nums[end-1] > nums[end]) {
                    return nums[end];
                }
                end -= 1;
            } 
            else if(nums[start] < nums[mid] || (nums[start] == nums[mid] && nums[mid] > nums[end])) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return nums[start];
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        while (i < j) {
            int mid = (i + j) / 2;
            if (nums[mid] > nums[j]) {
                i = mid + 1;
            } else
                j--;
        }
        return nums[i];
    }
};
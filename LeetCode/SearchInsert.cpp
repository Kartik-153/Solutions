#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size();
        if(target > nums[e-1])
            return e;
        while(s<=e) {
            int mid = (s+e)/2;
            if(nums[mid] == target) 
                return mid;
            if(nums[mid] < target) 
                s = mid + 1;
            else 
                e = mid - 1;
        }
        return s;
    }
};

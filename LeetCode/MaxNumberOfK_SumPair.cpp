#include<bits/stdc++.h>
using namespace std;

class Solution {
public:                      
    int maxOperations(vector<int>& nums, int k) {
        int l = 0;
        int r = nums.size() - 1;
        int cnt = 0;
        sort(nums.begin(), nums.end());
        while(l < r) {
            if(nums[l] + nums[r] == k) {
                cnt++;
                l++;
                r--;
            }
            else if(nums[l] + nums[r] < k) 
                l++;
            else 
                r--;
        }
        return cnt;
    }
};

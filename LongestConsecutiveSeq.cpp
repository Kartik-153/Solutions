#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // unordered_map<int, bool> mp;
        // for(int i = 0; i < nums.size(); i++) {
        //     mp[nums[i]] = true;
        // }
        // for(int i = 0; i < nums.size(); i++) {
        //     if(mp.count(nums[i] - 1) > 0) {
        //         mp[nums[i]] = false;
        //     }
        // }
        // int maxLen = 0;
        // for(int i = 0; i < nums.size(); i++) {
        //     if(mp[nums[i]] == true) {
        //         int j = 0; int count = 0;
        //         while(mp.count(nums[i] + j) > 0) {
        //             j++;
        //             count++;
        //         }
        //         if(count > maxLen) {
        //             maxLen = count;
        //         }
        //     }
        // }
        // return maxLen;
        int n = nums.size();
        if(n==0) return 0;
        sort(nums.begin(), nums.end());
        int maxLen = 0, currLen = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i-1] + 1) {
                currLen++;
            }
            else if(nums[i] != nums[i-1]) {
                maxLen = max(maxLen, currLen);
                currLen = 1;
            }
        }
        maxLen = max(maxLen, currLen);
        return maxLen;
    }
};

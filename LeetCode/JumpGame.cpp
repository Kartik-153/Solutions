#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i, minjump = 0;
        for (i = nums.size() - 2; i >= 0; i--) {
            minjump++;
            if (nums[i] >= minjump)
                minjump = 0;
        }
        return (minjump == 0) ? true : false;
    }
};
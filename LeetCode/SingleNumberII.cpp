#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x1 = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            x1 ^= nums[i];
        }

        
    }
};
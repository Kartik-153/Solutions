#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum=0;
        int maxsum=INT_MIN;
        for(int i:nums)
        {
            currsum +=i;
            maxsum=max(currsum,maxsum);
            if(currsum<0)
            {
                currsum=0;
            }
        }
        return maxsum;
    }
};

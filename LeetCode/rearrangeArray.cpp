#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
    
        vector<int> posArray;
        vector<int> negArray;
        vector<int> result;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] < 0) {
                negArray.push_back(nums[i]);
            }
            if(nums[i] > 0) {
                posArray.push_back(nums[i]);
            }
        }
        int ind1 = 0, ind2 = 0;
        while(ind2 < n/2) {
            result.push_back(posArray[ind1]);
            ind1++;
            result.push_back(negArray[ind2]);
            ind2++;
        }
        return result;
    }
};


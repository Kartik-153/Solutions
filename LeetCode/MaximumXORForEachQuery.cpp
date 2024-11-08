#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> arrXOR(n);
        arrXOR[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            arrXOR[i] = arrXOR[i - 1] ^ nums[i];
        }

        vector<int> ans(n);
        int mask = (1 << maximumBit) - 1;
        for (int i = 0; i < n; i++) {
            int currXOR = arrXOR[n - i - 1];
            ans[i] = currXOR ^ mask;
        }
        return ans;
    }
};
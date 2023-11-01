#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        k = n - k;
        k = k % n;
        int i, j, k_, temp;
        int g_c_d = __gcd(k, n);
        for(i = 0; i < g_c_d; i++) {
            temp = nums[i];
            j = i;
            while(true) {
                k_ = j + k;
                if(k_ >= n)
                    k_ = k_ - n;
                if(k == i)
                    break;
                nums[j] = nums[k_];
                j = k_;
            }
            nums[j] = temp;
        }
    }
};
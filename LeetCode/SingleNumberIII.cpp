#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n1xn2 = 0;
        for(auto num : nums) {
            n1xn2 ^= num;
        }

        int right = 1;
        while((right & n1xn2) == 0) {
            right = right << 1;
        }

        int num1 = 0, num2 = 0;

        for(auto num: nums) {
            if((num & right) != 0) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }
        return {num1, num2};
    }
};
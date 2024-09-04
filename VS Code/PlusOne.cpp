#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<int> plusOne(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            sum = sum*10 + nums[i];
        }
        sum+=1;
        string temp = to_string(sum);
        vector<int> result(temp.length());
        for(int i = 0; i < temp.length(); ++i) {
            result[i] = temp[i] - '0';
        }
        return result;
    }

};
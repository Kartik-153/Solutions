#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Brute Force Approach.
        // Will give TLE.
        // sort(nums.begin(), nums.end());
        // set<vector<int>> s;
        // vector<vector<int>> output;
        // for(int i = 0; i < nums.size(); i++) {
        //     for(int j = i+1; j < nums.size(); j++) {
        //         for(int k = j+1; k < nums.size(); k++) {
        //             vector<int> temp;
        //             if(nums[i] + nums[j] + nums[k] == 0) {
        //                 temp.push_back(nums[i]);
        //                 temp.push_back(nums[j]);
        //                 temp.push_back(nums[k]);
        //                 s.insert(temp);
        //             }
        //         }
        //     }
        // }
        // for(auto x: s){
        //     output.push_back(x);
        // }
        // return output;
        // int target = 0;
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        for(int i = 0; i < nums.size(); i++){
            int j = i+1;
            int k = nums.size() - 1;
            while(j<k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if(sum<0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        for(auto x: s)
            output.push_back(x);
        return output;
    }
};

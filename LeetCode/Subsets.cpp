#include<bits/stdc++.h>
using namespace std;

class Solution_Recursive {                           // best method time wise
    public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> sub;
        subsets(nums, 0, sub, subs);
        return subs;
    }
private:
    void subsets(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subs) {
        subs.push_back(sub);
        for (int j = i; j < nums.size(); j++) {
            sub.push_back(nums[j]);
            subsets(nums, j + 1, sub, subs);
            sub.pop_back();
        }
    }
};

class Solution_Iterative {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs = {{}};
        for (int num : nums) {
            int n = subs.size();
            for (int i = 0; i < n; i++) {
                subs.push_back(subs[i]); 
                subs.back().push_back(num);
            }
        }
        return subs;
    }
};

class Solution_Bit_Manipulation {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(), p = 1 << n;
        vector<vector<int>> subs(p);
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    subs[i].push_back(nums[j]);
                }
            }
        }
        return subs;
    }
};

// JavaScript Equivalent Solution

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;

        // Start by adding the empty subset
        subsets.push_back({}); // equivalent to subsets.push([]) in JS

        // Iterate through each number in the input
        for (int i = 0; i < nums.size(); i++) {
            int currentNumber = nums[i];
            int n = subsets.size(); // Number of subsets currently

            // Iterate through each subset that already exists
            for (int j = 0; j < n; j++) {
                // Create a new subset by copying the existing subset and adding
                // the current number
                vector<int> newSubset = subsets[j]; // clone the subset
                newSubset.push_back(currentNumber); // add the current number to it
                subsets.push_back(newSubset); // add the new subset to the result
            }
        }
        return subsets;
    }
};

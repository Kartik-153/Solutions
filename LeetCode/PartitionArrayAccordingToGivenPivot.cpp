#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        list<int> less;
        list<int> equal;
        list<int> greator;

        for(auto num : nums) {
            if(num<pivot) {
                less.push_back(num);
            } else if(num > pivot) {
                greator.push_back(num);
            } else {
                equal.push_back(num);
            }
        }
        less.insert(less.end(), equal.begin(), equal.end());
        less.insert(less.end(), greator.begin(), greator.end());

        vector<int> ans;
        for(auto num: less) {
            ans.push_back(num);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int less = 0;
        int equal = 0;
        for(int num : nums) {
            if(num < pivot)
                less++;
            else if (num == pivot)
                equal++;
        }
        vector<int> ans(nums.size());
        int lessI = 0;
        int equalI = less;
        int greatorI = less + equal;

        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if(num < pivot) {
                ans[lessI] = num;
                lessI++;
            } else if(num > pivot) {
                ans[greatorI] = num;
                greatorI++;
            } else {
                ans[equalI] = num;
                equalI++;
            }
        }
        return ans;
    }
};
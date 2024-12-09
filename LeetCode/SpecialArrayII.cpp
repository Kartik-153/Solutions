#include<bits/stdc++.h>
using namespace std;

class Solution { // Brute Force, TLE
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        int n = queries.size();
        vector<bool> res;

        for (auto& query : queries) {
            int from = query[0];
            int to = query[1];
            bool spe = true;
            for (int i = from; i < to; ++i) {
                if (nums[i] % 2 == nums[i + 1] % 2) {
                    spe = false;
                    break;
                }
            }
            res.push_back(spe);
        }
        return res;
    }
};

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<bool> ans(n);
        vector<int> violatingIndices;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i-1]%2 == nums[i]%2) {
                violatingIndices.push_back(i);
            }
        }

        for(int i = 0; i < queries.size(); i++) {
            vector<int> query = queries[i];
            int s = query[0];
            int e = query[1];

            bool violate = binarySearch(s + 1, e, violatingIndices);

            if(violate)
                ans[i] = false;
            else 
                ans[i] = true;
        }
        return ans;
    }

private:
    bool binarySearch(int s, int e, vector<int>& violatingIndices) {
        int l = 0;
        int r = violatingIndices.size() - 1;
        while(l <= r) {
            int mid = l + (r-l)/2;
            int violatingIndex = violatingIndices[mid];
            if(violatingIndex < s) {
                l = mid + 1;
            } else if(violatingIndex > e) {
                r = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> maxReach(n);
        int e = 0;

        for(int s = 0; s < n; s++) {
            e = max(e, s);
            while(e < n - 1 && nums[e] %2 != nums[e + 1]%2) {
                ++e;
            }
            maxReach[s] = e;
        }

        vector<bool> ans(queries.size());
        for(int i = 0; i < queries.size(); i++) {
            vector<int> query = queries[i];
            int s = query[0];
            int e = query[1];

            ans[i] = e <= maxReach[s];
        }
        return ans;
    }
};
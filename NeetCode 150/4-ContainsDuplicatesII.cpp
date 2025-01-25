#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<pair<int, int>> temp;
        for (int i = 0; i < nums.size(); i++) {
            temp.push_back(make_pair(nums.at(i), i));
        }
        std::sort(temp.begin(), temp.end());
        for (size_t i = 1; i < temp.size(); i++) {
            if (temp.at(i - 1).first == temp.at(i).first) {
                if (abs(temp.at(i - 1).second - temp.at(i).second) <= k) {
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> nuset;
        for(int i = 0; i < nums.size(); i++) {
            if(nuset.find(nums[i]) != nuset.end()) {
                return true;
            }
            nuset.insert(nums[i]);
            if(nuset.size() > k) {
                nuset.erase(nums[i-k]);
            }
        }
        return false;
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        for (int num : nums) 
            counter[num]++;
        vector<pair<int, int>> sorted(counter.begin(), counter.end());
        sort(sorted.begin(), sorted.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.second > b.second;
        });
        vector<int> result;
        for (int i = 0; i < k && i < sorted.size(); ++i) 
            result.push_back(sorted[i].first);
        return result;
    }
};

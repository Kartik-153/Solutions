#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> answer;
        for (int i = 0; i <= n - k; ++i) {
            unordered_map<int, int> freq;
            for (int j = i; j < i + k; ++j) {
                freq[nums[j]]++;
            }
            vector<pair<int, int>> freqList;
            for (const auto& entry : freq) {
                freqList.push_back({entry.second, entry.first});
            }
            sort(freqList.begin(), freqList.end(),
                 [](const pair<int, int>& a, const pair<int, int>& b) {
                     if (a.first != b.first)
                         return a.first > b.first;
                     return a.second > b.second;
                 });
            int s = 0;
            int cnt = 0;
            for (const auto& entry : freqList) {
                int f = entry.first;
                int v = entry.second;
                if (cnt >= x)
                    break; 
                s += f * v;
                cnt++;
            }
            answer.push_back(s);
        }

        return answer;
    }
};
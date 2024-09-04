#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> frequency;
        for(auto i : arr) {
            frequency[i]++;
        }
        vector<pair<int, int>> sortedFrequency(frequency.begin(), frequency.end());
        sort(sortedFrequency.begin(), sortedFrequency.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });

        int removed = 0;
        for(const auto& pair: sortedFrequency) {
            if(removed >= k) {
                break;
            }
            removed+=pair.second;
        }
        return frequency.size() - (removed - k);
    }
};
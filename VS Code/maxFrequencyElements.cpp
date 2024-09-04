#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(auto i: nums) {
            freq[i] +=1;
        }

        int maxFreq = 0;
        for(const auto &i : freq) {
            maxFreq = max(maxFreq, i.second);
        }

        int result = 0;
        for(const auto &i : freq) {
            if(maxFreq == i.second) {
                result += 1;
            }
        }
        return result;
    }
};

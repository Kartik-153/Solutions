#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> count_map;
        for(char c : s) {
            count_map[c]+=1;
        }
        priority_queue<pair<int, char>> maxHeap;
        for(const auto& entry: count_map) {
            maxHeap.push({entry.second, entry.first});
        }
        // If the highest frequency character is more than (length + 1) / 2, it's invalid
        if (maxHeap.top().first > (s.length() + 1) / 2) {
            return "";
        }
        string res;
        while(!maxHeap.empty()) {
            auto [count1, char1] = maxHeap.top();
            maxHeap.pop();
            if(!maxHeap.empty()) {
                auto [count2, char2] = maxHeap.top();
                maxHeap.pop();
                res += char1;
                res += char2;
                if(--count1 > 0) maxHeap.push({count1, char1});
                if(--count2 > 0) maxHeap.push({count2, char2});
            } else {
                res += char1;
                if(--count1 > 0) maxHeap.push({count1, char1});
            }
        }
        return res;
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string rearrangeString(string str, int k) {
        if(str.size() < 2 || k == 0) return str;

        unordered_map<char, int> freqMap;
        for(char C: str) {
            freqMap[C]++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for(auto &entry: freqMap) {
            maxHeap.push({entry.second, entry.first});
        }

        string res = "";
        queue<pair<int, char>> waitQueue;

        while(!maxHeap.empty()) {
            auto current = maxHeap.top();
            maxHeap.pop();
            res += current.second;

            waitQueue.push({current.first - 1, current.second});

            if(waitQueue.size() == k) {
                auto front = waitQueue.front();
                waitQueue.pop();
                if(front.first > 0) {
                    maxHeap.push(front);
                }
            }
        }
        return res.size() == str.size() ? res : "";
    }
};

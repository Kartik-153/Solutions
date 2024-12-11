#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(auto i : stones) {
            maxHeap.push(i);
        }

        while(maxHeap.size() > 1) {
            int f = maxHeap.top();
            maxHeap.pop();
            int s = maxHeap.top();
            maxHeap.pop();
            int re = abs(f-s);
            maxHeap.push(re);
        }
        return maxHeap.top();
    }
};

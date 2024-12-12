#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> maxHeap;
        for (auto gift : gifts) {
            maxHeap.push(gift);
        }

        for (int i = 0; i < k; i++) {
            int gift = maxHeap.top();
            maxHeap.pop();
            int res = sqrt(gift);
            maxHeap.push(res);
        }

        long long int res = 0;
        while (!maxHeap.empty()) {
            res += maxHeap.top();
            maxHeap.pop();
        }
        return res;
    }
};
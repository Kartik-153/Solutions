#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> s(n);
        priority_queue<pair<int, int>> mxheap;
        for(int i = 0; i < n; i++) {
            mxheap.push({score[i], i});
        }
        int num = 1;
        while(!mxheap.empty()) {
            auto top = mxheap.top();
            mxheap.pop();
            int index = top.second;
            if(num == 1) {
                s[index] = "Gold Medal";
            }
            else if(num == 2) {
                s[index] = "Silver Medal";
            }
            else if(num == 3) {
                s[index] = "Bronze Medal";
            }
            else {
                s[index] = to_string(num);
            }
            num++;
        }
        return s;
    }
};

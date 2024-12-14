#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        vector<bool> marked(nums.size());

        auto cmp = [](pair<int, int>& pair1, pair<int, int>& pair2) {
            if (pair1.first != pair2.first)
                return pair1.first > pair2.first;
            return pair1.second > pair2.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>
            minHeap(cmp);

        for (int i = 0; i < nums.size(); ++i) {
            minHeap.push(make_pair(nums[i], i));
        }

        while (!minHeap.empty()) {
            pair<int, int> ele = minHeap.top();
            minHeap.pop();
            int num = ele.first;
            int i = ele.second;

            if (!marked[i]) {
                score += num;
                marked[i] = true;

                if (i - 1 >= 0) {
                    marked[i - 1] = true;
                }
                if (i + 1 < nums.size()) {
                    marked[i + 1] = true;
                }
            }
        }
        return score;
    }
};

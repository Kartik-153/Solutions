#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int> &nums, int k) {
        priority_queue<long, vector<long>, greater<long>> minHeap;
        int n = nums.size();
        // minHeap.push(nums[0]);
        for (int num : nums) {
            minHeap.push(num);
        }
        int op = 0;
        while (minHeap.top() < k) {
            long firstMin = minHeap.top();
            minHeap.pop();
            long secondMin = minHeap.top();
            minHeap.pop();
            long temp = min(firstMin, secondMin) * 2 + max(firstMin, secondMin);
            minHeap.push(temp);
            op += 1;
        }
        return op;
    }
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int> &nums, int k) {
        int n = nums.size();
        int res = INT_MAX;
        long long cum_s = 0;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> prefixSumHeap;

        for(int i = 0; i < n; i++) {
            cum_s += nums[i];

            if(cum_s >= k) {
                res = min(res, i + 1);
            }

            while(!prefixSumHeap.empty() && cum_s - prefixSumHeap.top().first >= k) {
                res = min(res, i - prefixSumHeap.top().second);
                prefixSumHeap.pop();
            }

            prefixSumHeap.emplace(cum_s, i);
        }

        return res == INT_MAX ? -1 : res;
    }
};

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<long long, int>> cumulativeSumStack;
        cumulativeSumStack.emplace_back(0LL, -1);

        long long runningCumulativeSum = 0;
        int shortestSubarrayLength = INT_MAX;

        for (int i = 0; i < n; i++) {
            runningCumulativeSum += nums[i];
            while (!cumulativeSumStack.empty() &&
                   runningCumulativeSum <= cumulativeSumStack.back().first) {
                cumulativeSumStack.pop_back();
            }
            cumulativeSumStack.emplace_back(runningCumulativeSum, i);

            int candidateIndex = findCandidateIndex(cumulativeSumStack,
                                                    runningCumulativeSum - k);
            if (candidateIndex != -1) {
                shortestSubarrayLength =
                    min(shortestSubarrayLength,
                        i - cumulativeSumStack[candidateIndex].second);
            }
        }
        return shortestSubarrayLength == INT_MAX ? -1 : shortestSubarrayLength;
    }

private:
    int findCandidateIndex(const vector<pair<long long, int>>& nums,
                           long long target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid].first <= target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return right;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution { // Wrong Answer.
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2,
                                 int k) {
        int n = nums1.size();
        vector<long long> res(n, 0);
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({nums1[i], i});
        }
        sort(v.begin(), v.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int heapSum = 0;
        vector<pair<int, int>> sortedNums2;
        int j = 0;
        for (int i = 0; i < n; i++) {
            int currentValue = v[i].first;
            int currentIndex = v[i].second;

            while (j < i) {
                sortedNums2.push_back({nums2[v[j].second], v[j].second});
                j++;
            }
            sort(sortedNums2.rbegin(), sortedNums2.rend());
            int tempSum = 0;
            for (int t = 0; t < min(k, (int)sortedNums2.size()); t++) {
                tempSum += sortedNums2[t].first;
            }
            res[currentIndex] = tempSum;
        }
        return res;
    }
};


class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2,
                                 int k) {
        int n = nums1.size();
        vector<long long> ans(n, 0);
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(),
             [&](int a, int b) { return nums1[a] < nums1[b]; });

        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum = 0;
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && nums1[idx[j]] == nums1[idx[i]]) {
                ans[idx[j]] = sum;
                j++;
            }
            for (int p = i; p < j; p++) {
                int val = nums2[idx[p]];
                if ((int)minHeap.size() < k) {
                    minHeap.push(val);
                    sum += val;
                } else if (!minHeap.empty() && minHeap.top() < val) {
                    sum -= minHeap.top();
                    minHeap.pop();
                    minHeap.push(val);
                    sum += val;
                }
            }
            i = j;
        }
        return ans;
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        map<int, int> freq;
        int l = 0, r = 0;
        int n = nums.size();
        long long count = 0;

        while (r < n) {
            freq[nums[r]]++;

            while (freq.rbegin()->first - freq.begin()->first > 2) {
                freq[nums[l]]--;
                if (freq[nums[l]] == 0) {
                    freq.erase(nums[l]);
                }
                l++;
            }
            count += r - l + 1;
            r++;
        }
        return count;
    }
};

class Solution {
public:
    long long continousSubarrays(vector<int>& nums) {
        int l = 0, r = 0;
        long long count = 0;
        // Custom heap which uses nums[a] and nums[b] for working
        priority_queue<int, vector<int>, function<bool(int, int)>> minHeap(
            [&nums](int a, int b) { return nums[a] > nums[b]; });
        priority_queue<int, vector<int>, function<bool(int, int)>> maxHeap(
            [&nums](int a, int b) { return nums[a] < nums[b]; });

        while(r < nums.size()) {
            minHeap.push(r);
            maxHeap.push(l);
            while(l < r && nums[maxHeap.top()] - nums[minHeap.top()] > 2) {
                l++;
                while(!maxHeap.empty() && maxHeap.top() < l) {
                    maxHeap.pop();
                }
                while(!minHeap.empty() && minHeap.top() < l) {
                    minHeap.pop();
                }
            }

            count += r - l + 1;
            r++;
        }
        return count;
    }
};
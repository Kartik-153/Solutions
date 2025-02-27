#include <bits/stdc++.h>
using namespace std;

class Solution { // Brute Force
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> numSet(arr.begin(), arr.end());
        int maxLen = 0;
        for (int s = 0; s < n; s++) {
            for (int i = s + 1; i < n; i++) {
                int prev = arr[i];
                int curr = arr[s] + arr[i];
                int len = 2;

                while (numSet.find(curr) != numSet.end()) {
                    int temp = curr;
                    curr += prev;
                    prev = temp;
                    maxLen = max(maxLen, len++);
                }
            }
        }
        return maxLen;
    }
};

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int maxLen = 0;
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        unordered_map<int, int> vallToIdx;
        for (int curr = 0; curr < n; curr++) {
            vallToIdx[arr[curr]] = curr;

            for (int prev = 0; prev < curr; prev++) {
                int diff = arr[curr] - arr[prev];
                int prevIdx = (vallToIdx.find(diff) != vallToIdx.end())
                                  ? vallToIdx[diff]
                                  : -1;
                dp[prev][curr] = (diff < arr[prev] && prevIdx >= 0)
                                     ? dp[prevIdx][prev] + 1
                                     : 2;
                maxLen = max(maxLen, dp[prev][curr]);
            }
        }
        return maxLen > 2 ? maxLen : 0;
    }
};

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int maxLen = 0;

        for(int curr = 2; curr < n; curr++) {
            int start = 0;
            int end = curr - 1;

            while(start < end) {
                int pairSum = arr[start] + arr[end];
                if(pairSum > arr[curr]) {
                    end--;
                } else if(pairSum < arr[curr]) {
                    start++;
                } else {
                    dp[end][curr] = dp[start][end] + 1;
                    maxLen = max(dp[end][curr], maxLen);
                    end--;
                    start++;
                }
            }
        }
        return maxLen == 0 ? 0 : maxLen + 2;
    }
};
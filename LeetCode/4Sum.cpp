#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void searchPairs(const vector<int>& arr, int targetSum, int first,
                     int second, vector<vector<int>>& quads) {
        int start = second + 1;
        int end = arr.size() - 1;

        while (start < end) {
            long long sum = static_cast<long long>(arr[first]) + arr[second] +
                            arr[start] + arr[end];

            if (sum == targetSum) {
                // Found the quadruplet
                quads.push_back(
                    {arr[first], arr[second], arr[start], arr[end]});
                start++;
                end--;

                // Skip the same element to avoid duplicate quadruplets
                while (start < end && arr[start] == arr[start - 1]) {
                    start++;
                }
                while (start < end && arr[end] == arr[end + 1]) {
                    end--;
                }
            } else if (sum < targetSum) {
                // We need a pair with a bigger sum
                start++;
            } else {
                // We need a pair with a smaller sum
                end--;
            }
        }
    }

    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        // Sort the array
        sort(arr.begin(), arr.end());
        vector<vector<int>> quads;
        if (arr.size() <= 3) {
            return {};
        }

        for (int i = 0; i < arr.size() - 3; i++) {
            // Skip the same element to avoid duplicate quadruplets
            if (i > 0 && arr[i] == arr[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < arr.size() - 2; j++) {
                // Skip the same element to avoid duplicate quadruplets
                if (j > i + 1 && arr[j] == arr[j - 1]) {
                    continue;
                }
                searchPairs(arr, target, i, j, quads);
            }
        }
        return quads;
    }
};

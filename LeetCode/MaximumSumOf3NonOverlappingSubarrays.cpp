#include<bits/stdc++.h>
using namespace std;

class Solution { // DP
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        // Number of possible subarray starting positions
        int n = nums.size() - k + 1;

        // Calculate sum of all possible k-length subarrays
        vector<int> sums(n);
        int windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }
        sums[0] = windowSum;

        // Sliding window to calculate remaining sums
        for (int i = k; i < nums.size(); i++) {
            windowSum = windowSum - nums[i - k] + nums[i];
            sums[i - k + 1] = windowSum;
        }

        // memo[i][j]: max sum possible starting from index i with j subarrays
        // remaining
        vector<vector<int>> memo(n, vector<int>(4, -1));
        vector<int> indices;

        // First find optimal sum using DP
        dp(sums, k, 0, 3, memo);

        // Then reconstruct the path to find indices
        dfs(sums, k, 0, 3, memo, indices);

        return indices;
    }

private:
    // DP function to find maximum possible sum
    int dp(vector<int>& sums, int k, int idx, int rem,
           vector<vector<int>>& memo) {
        if (rem == 0)
            return 0;
        if (idx >= sums.size()) {
            return rem > 0 ? INT_MIN : 0;
        }

        if (memo[idx][rem] != -1) {
            return memo[idx][rem];
        }

        // Try taking current subarray vs skipping it
        int withCurrent = sums[idx] + dp(sums, k, idx + k, rem - 1, memo);
        int skipCurrent = dp(sums, k, idx + 1, rem, memo);

        memo[idx][rem] = max(withCurrent, skipCurrent);
        return memo[idx][rem];
    }

    // DFS to reconstruct the solution path
    void dfs(vector<int>& sums, int k, int idx, int rem,
             vector<vector<int>>& memo, vector<int>& indices) {
        if (rem == 0)
            return;
        if (idx >= sums.size())
            return;

        int withCurrent = sums[idx] + dp(sums, k, idx + k, rem - 1, memo);
        int skipCurrent = dp(sums, k, idx + 1, rem, memo);

        // Choose path that gave optimal result in DP
        if (withCurrent >= skipCurrent) { // Take current subarray
            indices.push_back(idx);
            dfs(sums, k, idx + k, rem - 1, memo, indices);
        } else { // Skip current subarray
            dfs(sums, k, idx + 1, rem, memo, indices);
        }
    }
};

class Solution { // Tabulation
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        // Prefix sum array to calculate sum of any subarray in O(1) time
        vector<int> prefixSum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }

        // Arrays to store the best sum and starting indices for up to 3
        // subarrays
        vector<vector<int>> bestSum(4, vector<int>(n + 1, 0));
        vector<vector<int>> bestIndex(4, vector<int>(n + 1, 0));

        // Compute the best sum and indices for 1, 2, and 3 subarrays
        for (int subarrayCount = 1; subarrayCount <= 3; subarrayCount++) {
            for (int endIndex = k * subarrayCount; endIndex <= n; endIndex++) {
                int currentSum = prefixSum[endIndex] - prefixSum[endIndex - k] +
                                 bestSum[subarrayCount - 1][endIndex - k];

                // Check if the current configuration gives a better sum
                if (currentSum > bestSum[subarrayCount][endIndex - 1]) {
                    bestSum[subarrayCount][endIndex] = currentSum;
                    bestIndex[subarrayCount][endIndex] = endIndex - k;
                } else {
                    bestSum[subarrayCount][endIndex] =
                        bestSum[subarrayCount][endIndex - 1];
                    bestIndex[subarrayCount][endIndex] =
                        bestIndex[subarrayCount][endIndex - 1];
                }
            }
        }

        // Trace back the indices of the three subarrays
        vector<int> result(3, 0);
        int currentEnd = n;
        for (int subarrayIndex = 3; subarrayIndex >= 1; subarrayIndex--) {
            result[subarrayIndex - 1] = bestIndex[subarrayIndex][currentEnd];
            currentEnd = result[subarrayIndex - 1];
        }

        return result;
    }
};

class Solution { // Three Pointers
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxSum = 0;

        // Prefix sum array to calculate sum of any subarray
        vector<int> prefixSum(n + 1);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        // Arrays to store the best starting index for the left and right
        // subarrays
        vector<int> leftMaxIndex(n);
        vector<int> rightMaxIndex(n);

        // Result array to store the starting indices of the three subarrays
        vector<int> result(3);

        // Calculate the best starting index for the left subarray for each
        // position
        for (int i = k, currentMaxSum = prefixSum[k] - prefixSum[0]; i < n;
             i++) {
            if (prefixSum[i + 1] - prefixSum[i + 1 - k] > currentMaxSum) {
                leftMaxIndex[i] = i + 1 - k;
                currentMaxSum = prefixSum[i + 1] - prefixSum[i + 1 - k];
            } else {
                leftMaxIndex[i] = leftMaxIndex[i - 1];
            }
        }

        // Calculate the best starting index for the right subarray for each
        // position
        rightMaxIndex[n - k] = n - k;
        for (int i = n - k - 1, currentMaxSum = prefixSum[n] - prefixSum[n - k];
             i >= 0; i--) {
            if (prefixSum[i + k] - prefixSum[i] >= currentMaxSum) {
                rightMaxIndex[i] = i;
                currentMaxSum = prefixSum[i + k] - prefixSum[i];
            } else {
                rightMaxIndex[i] = rightMaxIndex[i + 1];
            }
        }

        // Iterate over the middle subarray and calculate the total sum for all
        // valid combinations
        for (int i = k; i <= n - 2 * k; i++) {
            int leftIndex = leftMaxIndex[i - 1];
            int rightIndex = rightMaxIndex[i + k];
            int totalSum = (prefixSum[i + k] - prefixSum[i]) +
                           (prefixSum[leftIndex + k] - prefixSum[leftIndex]) +
                           (prefixSum[rightIndex + k] - prefixSum[rightIndex]);

            if (totalSum > maxSum) {
                maxSum = totalSum;
                result[0] = leftIndex;
                result[1] = i;
                result[2] = rightIndex;
            }
        }

        return result;
    }
};

class Solution { // Sliding Window
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        // Variables to track the best indices for one, two, and three subarray
        // configurations
        int bestSingleStart = 0;
        vector<int> bestDoubleStart = {0, k};
        vector<int> bestTripleStart = {0, k, k * 2};

        // Compute the initial sums for the first three subarrays
        int currentWindowSumSingle = 0;
        for (int i = 0; i < k; i++) {
            currentWindowSumSingle += nums[i];
        }

        int currentWindowSumDouble = 0;
        for (int i = k; i < k * 2; i++) {
            currentWindowSumDouble += nums[i];
        }

        int currentWindowSumTriple = 0;
        for (int i = k * 2; i < k * 3; i++) {
            currentWindowSumTriple += nums[i];
        }

        // Track the best sums found so far
        int bestSingleSum = currentWindowSumSingle;
        int bestDoubleSum = currentWindowSumSingle + currentWindowSumDouble;
        int bestTripleSum = currentWindowSumSingle + currentWindowSumDouble +
                            currentWindowSumTriple;

        // Sliding window pointers for the subarrays
        int singleStartIndex = 1;
        int doubleStartIndex = k + 1;
        int tripleStartIndex = k * 2 + 1;

        // Slide the windows across the array
        while (tripleStartIndex <= nums.size() - k) {
            // Update the sums using the sliding window technique
            currentWindowSumSingle = currentWindowSumSingle -
                                     nums[singleStartIndex - 1] +
                                     nums[singleStartIndex + k - 1];
            currentWindowSumDouble = currentWindowSumDouble -
                                     nums[doubleStartIndex - 1] +
                                     nums[doubleStartIndex + k - 1];
            currentWindowSumTriple = currentWindowSumTriple -
                                     nums[tripleStartIndex - 1] +
                                     nums[tripleStartIndex + k - 1];

            // Update the best single subarray start index if a better sum is
            // found
            if (currentWindowSumSingle > bestSingleSum) {
                bestSingleStart = singleStartIndex;
                bestSingleSum = currentWindowSumSingle;
            }

            // Update the best double subarray start indices if a better sum is
            // found
            if (currentWindowSumDouble + bestSingleSum > bestDoubleSum) {
                bestDoubleStart[0] = bestSingleStart;
                bestDoubleStart[1] = doubleStartIndex;
                bestDoubleSum = currentWindowSumDouble + bestSingleSum;
            }

            // Update the best triple subarray start indices if a better sum is
            // found
            if (currentWindowSumTriple + bestDoubleSum > bestTripleSum) {
                bestTripleStart[0] = bestDoubleStart[0];
                bestTripleStart[1] = bestDoubleStart[1];
                bestTripleStart[2] = tripleStartIndex;
                bestTripleSum = currentWindowSumTriple + bestDoubleSum;
            }

            // Move the sliding windows forward
            singleStartIndex += 1;
            doubleStartIndex += 1;
            tripleStartIndex += 1;
        }

        // Return the starting indices of the three subarrays with the maximum
        // sum
        return bestTripleStart;
    }
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> sum;
        for (int num : nums) {
            int digitSum = _sum(num);
            sum.push_back({digitSum, num});
        }
        sort(sum.begin(), sum.end());
        int maxPairSum = -1;
        for (int i = 1; i < sum.size(); i++) {
            int currDigitSum = sum[i].first;
            int prevDigitSum = sum[i - 1].first;

            if (currDigitSum == prevDigitSum) {
                int currSum = sum[i].second + sum[i - 1].second;
                maxPairSum = max(maxPairSum, currSum);
            }
        }
        return maxPairSum;
    }

private:
    int _sum(int num) {
        int sum = 0;
        while (num) {
            int tmp = num % 10;
            sum += tmp;
            num /= 10;
        }
        return sum;
    }
};

class Solution {
private:
    int calculateDigitSum(int num) {
        int digitSum = 0;
        while (num > 0) {
            digitSum += num % 10;
            num /= 10;
        }
        return digitSum;
    }

public:
    int maximumSum(vector<int>& nums) {
        vector<priority_queue<int, vector<int>, greater<int>>> digitSumGroups(
            82);

        int maxPairSum = -1;
        for (int number : nums) {
            int digitSum = calculateDigitSum(number);
            digitSumGroups[digitSum].push(number);
            if (digitSumGroups[digitSum].size() > 2) {
                digitSumGroups[digitSum].pop();
            }
        }
        for (auto& minHeap : digitSumGroups) {
            if (minHeap.size() == 2) {
                int first = minHeap.top();
                minHeap.pop();
                int second = minHeap.top();
                maxPairSum = max(maxPairSum, first + second);
            }
        }

        return maxPairSum;
    }
};
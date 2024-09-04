#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> SubarrayOfAverageNumber(vector<int> &nums, int k)
    {
        vector<int> res;
        int windowSum = 0;
        int windowStart = 0;

        for (int windowEnd = 0; windowEnd < nums.size(); windowEnd++)
        {
            windowSum += nums[windowEnd];

            if (windowEnd >= k - 1)
            {
                res.push_back(windowSum / k);
                windowSum -= nums[windowStart];
                windowStart++;
            }
        }
        return res;
    }

    int maxSumSubarray(vector<int> &nums, int k)
    {
        int maxSum = 0;
        int windowSum = 0;
        int windowStart = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            windowSum += nums[i];

            if (i >= k - 1)
            {
                maxSum = max(maxSum, windowSum);
                windowSum -= nums[windowStart];
                windowStart++;
            }
        }
        return maxSum;
    }

    int smallestSubarrayWithGivenSum(vector<int> &nums, int sum)
    {
        int windowSum = 0;
        int minLength = INT_MAX;
        int windowStart = 0;

        for (int windowEnd = 0; windowEnd < nums.size(); windowEnd++)
        {
            windowSum += nums[windowEnd];
            while (windowSum >= sum)
            {
                minLength = min(minLength, windowEnd - windowStart + 1);
                windowSum -= nums[windowStart];
                windowStart++;
            }
        }
        if (minLength == INFINITY)
            return 0;
        return minLength;
    }

    int longestSubstringWithKdistinct(const string &str, int k)
    {
        int windowStart = 0;
        int maxLength = 0;
        unordered_map<char, int> charFrequency;

        for (int windowEnd = 0; windowEnd < str.length(); windowEnd++)
        {
            char endChar = str[windowEnd];
            charFrequency[endChar]++;

            while (charFrequency.size() > k)
            {
                char startChar = str[windowStart];
                charFrequency[startChar]--;
                if (charFrequency[startChar] == 0)
                {
                    charFrequency.erase(startChar);
                }
                windowStart++;
            }

            maxLength = max(maxLength, windowEnd - windowStart + 1);
        }

        return maxLength;
    }

    int totalFruits(vector<int> &fruits)
    {
        int windowStart = 0;
        int wiindowMax = 0;
        unordered_map<int, int> fruitMap;

        for (int windowEnd = 0; windowEnd < fruits.size(); windowEnd++)
        {
            int endFruit = fruits[windowEnd];
            fruitMap[endFruit]++;
        }
    }

    int funv()
    {
        return (double)(char)5.0;
    }
};

int main()
{
    vector<int> nums = {1, 23, -1, 10, 23};
    Solution n;
    cout << n.funv();
    // cout << INFINITY << endl;
    return 0;
}
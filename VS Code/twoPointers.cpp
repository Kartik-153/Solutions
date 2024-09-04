#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int i = 1;
    int nextNonDupe = 1;

    while (i < nums.size())
    {
        if (nums[nextNonDupe - 1] != nums[i])
        {
            nums[nextNonDupe] = nums[i];
            nextNonDupe++;
        }
        i++;
    }
    return nextNonDupe;
}

int removeElementInplace(vector<int> &nums, int key)
{
    int nextElement = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != key)
        {
            nums[nextElement] = nums[i];
            nextElement++;
        }
    }
    return nextElement;
}

vector<int> squareOfTheArray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> squares(n);
    int s = 0;
    int e = n - 1;
    int highestSquareIndex = n - 1;
    while (s <= e)
    {
        int startSquare = nums[s] * nums[s];
        int endSquare = nums[e] * nums[e];

        if (startSquare > endSquare)
        {
            squares[highestSquareIndex] = startSquare;
            s++;
        }
        else
        {
            squares[highestSquareIndex] = endSquare;
            e--;
        }
        highestSquareIndex--;
    }
    return squares;
}

vector<vector<int>> searchTriplets(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> triplets;

    for (int i = 0; i < arr.size(); i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
        {
            // skip the same element to avoid duplicates
            continue;
        }
        searchPair(arr, -arr[i], i + 1, triplets);
    }
    return triplets;
}

void searchPair(vector<int> &arr, int targetSum, int start, vector<vector<int>> &triplets)
{
    int end = arr.size() - 1;

    while (start < end)
    {
        int currentSum = arr[start] + arr[end];
        if (currentSum == targetSum)
        {
            // found the triplet
            triplets.push_back({-targetSum, arr[start], arr[end]});
            start++;
            end--;
            while (start < end && arr[start] == arr[start - 1])
            {
                // skip the same element to avoid duplicates
                start++;
            }
            while (start < end && arr[end] == arr[end + 1])
            {
                // skip the same element to avoid duplicates
                end--;
            }
        }
        else if (currentSum < targetSum)
        {
            // we need a pair with a bigger sum
            start++;
        }
        else
        {
            // we need a pair with a smaller sum
            end--;
        }
    }
}

int tripletSumCloseToTarget(vector<int> &arr, int targetSum)
{
    sort(arr.begin(), arr.end());
    int smallestDifference = INT_MAX;

    for (int i = 0; i < arr.size() - 2; i++)
    {
        int start = i + 1;
        int end = arr.size() - 1;

        while (start < end)
        {
            int targetDifference = targetSum - arr[i] - arr[start] - arr[end];

            if (targetDifference == 0)
            {
                return targetSum - targetDifference;
            }

            if (abs(targetDifference) < abs(smallestDifference))
            {
                smallestDifference = targetDifference;
            }

            if (abs(targetDifference) < abs(smallestDifference) ||
                (abs(targetDifference) == abs(smallestDifference) && targetDifference > smallestDifference))
            {
                smallestDifference = targetDifference;
            }

            if (targetDifference > 0)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
    }
    return targetSum - smallestDifference;
}

int searchPair(vector<int> &nums, int targetSum, int first)
{
    int count = 0;
    int start = first + 1;
    int end = nums.size() - 1;

    while (start < end)
    {
        if (nums[start] + nums[end] < targetSum) {
            count+=end-start;
            start++;
        }
        else {
            end--;
        }
    }
    return count;
}

int tripletWithSmallerSum(vector<int> &nums, int target)
{
    int res = 0;
    for(int i = 0; i < nums.size() - 2; i--) {
        res = searchPair(nums, target-nums[i], i + 1);
    }
    return res;
}



int main()
{
    vector<int> vect = {-3, -2, 3, 6, 3, -10, 9, 3};
    vector<vector<int>> res;

    res = searchTriplets(vect);
    for (int i = 0; i < res.size(); i++)
    {
        for (int y = 0; y < res[0].size(); y++)
        {
            cout << res[i][y] << " ";
        }
    }
    return 0;
}
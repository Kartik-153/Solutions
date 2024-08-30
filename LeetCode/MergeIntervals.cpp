#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() < 2)
            return intervals;

        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });

        for (int i = 1; i < intervals.size(); i++)
        {
            vector<int> &curr = intervals[i];
            vector<int> &prev = intervals[i - 1];

            if (curr[0] <= prev[1])
            {
                intervals[i] = {prev[0], max(prev[1], curr[1])};
                intervals.erase(intervals.begin() + i - 1);
                i--;
            }
        }
        return intervals;
    }
};
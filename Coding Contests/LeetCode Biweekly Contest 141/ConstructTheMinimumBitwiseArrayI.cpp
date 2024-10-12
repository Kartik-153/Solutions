#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> minBitwiseArray(vector<int> &nums)
    {
        vector<int> ans;

        for (int num : nums)
        {
            bool found = false;
            for (int cand = 0; cand <= num; cand++)
            {
                if ((cand | (cand + 1)) == num)
                {
                    ans.push_back(cand);
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
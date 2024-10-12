#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> minBitwiseArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        for (int num : nums)
        {
            bool found = false;
            int temp = INT_MAX;
            for (int b = 0; b <= 30; b++)
            {
                if ((num >> b) & 1 == 1)
                {
                    int cand = num & ~(1 << b);
                    if (cand < 0)
                        continue;
                    if ((cand | (cand + 1)) == num)
                    {
                        if (cand < temp)
                        {
                            temp = cand;
                            found = true;
                        }
                    }
                }
            }
            if (found)
            {
                ans.push_back(temp);
            }
            else
            {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        int n = code.size();
        vector<int> res(n, 0);

        // when k == 0, 3rd condition
        if (k == 0)
            return res;

        // Original logic for k > 0
        for (int i = 0; i < n; i++)
            if (k > 0)
                for (int j = i + 1; j < k + i + 1; j++)
                    res[i] += code[j % n];
            else
                for (int j = i - abs(k); j < i; j++)
                    res[i] += code[(j + n) % n];

        return res;
    }
};

class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        int n = code.size();
        vector<int> res(n, 0);
        if (k == 0)
            return res;

        int s = 1, e = k, sum = 0;

        if (k < 0)
        {
            s = n - abs(k);
            e = n - 1;
        }

        for (int i = s; i <= e; i++)
            sum += code[i];

        for (int i = 0; i < n; i++)
        {
            res[i] = sum;
            sum -= code[s % n];
            sum += code[(e + 1) % n];
            s += 1;
            e += 1;
        }
        return res;
    }
};